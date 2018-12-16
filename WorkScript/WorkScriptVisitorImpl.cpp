#include "stdafx.h"
#include "WorkScriptVisitorImpl.h"
#include "ExpressionWrapper.h"
#include "Type.h"
#include "MemberEvaluateExpression.h"
#include "CallExpression.h"
#include "VariableExpression.h"
#include "AssignmentExpression.h"
#include "MultiValueExpression.h"
#include "IntegerExpression.h"
#include "FloatExpression.h"
#include "StringExpression.h"
#include "SyntaxErrorException.h"
#include "Parameter.h"
#include "Function.h"
#include "FunctionTemplate.h"
#include "BranchOverloadTemplate.h"
#include "Program.h"
#include "BinaryCompareExpression.h"
#include "BinaryCalculateExpression.h"
#include "UnaryOperatorExpression.h"
#include "Locale.h"

#define FORBID_ASSIGN \
this->assignable = false; 

#define ALLOW_ASSIGN \
this->assignable = true; 

#define STORE_FORBID_ASSIGN \
bool oriAssignable = this->assignable; \
FORBID_ASSIGN 

#define STORE_ALLOW_ASSIGN \
bool oriAssignable = this->assignable; \
ALLOW_ASSIGN 

#define RESTORE_ASSIGNABLE \
this->assignable = oriAssignable; 

using namespace std;
using namespace WorkScript;

antlrcpp::Any WorkScriptVisitorImpl::visitIncludeCommand(WorkScriptParser::IncludeCommandContext *ctx)
{
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx)
{
	if (ctx->DOUBLE()) {
		double value = 0;
		int len = sscanf(ctx->DOUBLE()->getText().c_str(), "%lf", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new FloatExpression(program, program->getFloat64Type(), value));
	}
	else {
		int value = 0;
		int len = sscanf(ctx->INTEGER()->getText().c_str(), "%d", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new IntegerExpression(program,program->getSInt32Type(), value));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string text = ctx->STRING()->getText();
	text = text.substr(1, text.length() - 2);
	wstring wtext = Locale::ansiToUnicode(text);

	wchar_t *unescapedText = new wchar_t[wtext.length() + 1];
	try {
		this->handleEscapeCharacters(wtext.c_str(), unescapedText, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1);
	}
	catch(...){
		delete[]unescapedText;
		throw;
	}
	auto lpExpr = new StringExpression(program, unescapedText);
	delete[]unescapedText;
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx)
{
	string boolStr = ctx->BOOLEAN()->getText();
	if (boolStr == "true" || boolStr == "yes" || boolStr == "ok" || boolStr == "good") {
		return ExpressionWrapper(new IntegerExpression(program,program->getUInt1Type(),1));
	}
	else if (boolStr == "false" || boolStr == "no" || boolStr == "bad") {
		return ExpressionWrapper(new IntegerExpression(program, program->getUInt1Type(), 0));
	}
	else {
		throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, (L"无法识别的布尔值：" + Locale::ansiToUnicode(boolStr))));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->identifier()->getText();
	auto expr = new VariableExpression(program, Locale::ansiToUnicode(varName));
	expr->setDeclarable(this->declarable); //等号左边的变量才可以创建声明
	auto wrapper = ExpressionWrapper(expr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ALLOW_ASSIGN;
	/*====深入下一层====*/
	++this->curDepth;
	//函数的实现
	vector<Expression*> impls;
	if (ctx->functionImplementationExpression()->expression() != nullptr) {
		auto expr = ctx->functionImplementationExpression()->expression()->accept(this).as<ExpressionWrapper>();
		impls.push_back(expr.getExpression());
	}
	else {
		auto exprs = ctx->functionImplementationExpression()->blockExpression()->expression();
		impls.reserve(exprs.size());
		for (size_t i = 0; i < exprs.size(); ++i)
		{
			auto wrapper = exprs[i]->accept(this).as<ExpressionWrapper>();
			impls[i] = wrapper.getExpression();
		}
	}
	
	FORBID_ASSIGN;

	//函数的参数和限制
	ExpressionWrapper paramsWrapper = ctx->functionDeclarationExpression()->formalParameterExpression()->accept(this);
	auto paramExpr = (MultiValueExpression *)paramsWrapper.getExpression();
	size_t paramCount = paramExpr->getItems().size();
	vector<ParameterTemplate*> paramInfos;
	paramInfos.reserve(paramCount);
	vector<Expression*> vecConstraints; //函数的限制，由字面声明和语法糖编译两部分组成
	//首先是语法糖编译，包括约束和默认值
	for (size_t i = 0; i < paramCount; ++i) {
		paramInfos.push_back(new ParameterTemplate());
		if (paramExpr->getItem(i)->getExpressionType() == ExpressionType::VARIABLE_EXPRESSION) {
			VariableExpression* varExpr = (VariableExpression*)paramExpr->getItem(i);
			paramInfos[i]->setName(varExpr->getName());
			paramInfos[i]->setVarargs(varExpr->isVarargs());
		}
		//else if (paramExpr->getItem(i)->getExpressionType()->isSubTypeOf(nullptr, Type::BINARY_COMPARE_EXPRESSION)) {
		//	VariableExpression*leftVar = ((BinaryCompareExpression*)paramExpr->getItem(i))->getLeftVariable();
		//	if (leftVar == nullptr) {
		//		throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, L"函数参数约束左部必须为变量！"));
		//	}
		//	vecConstraints.push_back(paramExpr->getItem(i));
		//	paramInfos[i].setParameterName(leftVar->getName());
		//}
		//else if (paramExpr->getItem(i)->getType(nullptr)->isSubTypeOf(nullptr, Type::ASSIGNMENT_EXPRESSION)) {
		//	AssignmentExpression*assignmentExpr = (AssignmentExpression*)paramExpr->getItem(i);
		//	auto leftExpr = assignmentExpr->getLeftExpression();
		//	if (!leftExpr->getType(nullptr)->equals(nullptr, Type::VARIABLE_EXPRESSION)){
		//		throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, L"参数默认值左部必须为参数名！"));
		//	}
		//	auto leftVar = (VariableExpression*)leftExpr;
		//	paramInfos[i].setParameterName(leftVar->getName());
		//	paramInfos[i].setDefaultValue(assignmentExpr->getRightExpression());
//		}
		//else{
		//	wstring tmpVarName = L"_" + to_wstring(i);
		//	paramInfos[i].setParameterName(tmpVarName.c_str());
		//	const EqualsExpression*constraint = new EqualsExpression();
		//	VariableExpression* paramVar = new VariableExpression(tmpVarName.c_str());
		//	paramVar->setDomain(this->domain);
		//	paramVar->setDomainAccess(DomainAccess::PUBLIC);
		//	constraint->setLeftExpression(paramVar);
		//	constraint->setRightExpression(paramExpr->getItem(i));
		//	vecConstraints.push_back(constraint);
		//}
	}
	////然后是字面声明
	//if (ctx->functionConstraintExpression() != nullptr) {
	//	if (ctx->functionConstraintExpression()->expression() != nullptr) {
	//		auto expr = ((ExpressionWrapper)ctx->functionConstraintExpression()->expression()->accept(this)).getExpression();
	//		vecConstraints.push_back(expr);
	//	}
	//	else {
	//		for (auto &subCtx : ctx->functionConstraintExpression()->blockExpression()->expression()) {
	//			vecConstraints.push_back(((ExpressionWrapper)subCtx->accept(this)).getExpression());
	//		}
	//	}
	//}

	/*====恢复上一层====*/
	--this->curDepth;

	auto funcNameCtx = ctx->functionDeclarationExpression()->identifier();
	wstring funcName;
	if(funcNameCtx != nullptr) {
		funcName = Locale::ansiToUnicode(funcNameCtx->getText());
	}
	FunctionTemplate* funcTemplate = this->program->getFunctionTemplate(funcName);
	if (!funcTemplate) {
		funcTemplate = new FunctionTemplate(this->program, funcName);
		this->program->addFunctionTemplate(funcTemplate);
	}
	
	auto overloadTemplate = new BranchOverloadTemplate(funcTemplate, paramInfos);
	auto branch = new OverloadBranchTemplate(vecConstraints, impls);
	overloadTemplate->setParameters(paramInfos);
	overloadTemplate->setBranches({ branch });
	funcTemplate->addOverload(overloadTemplate);

	RESTORE_ASSIGNABLE;
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitCallExpression(WorkScriptParser::CallExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper paramExpressionWrapper = ctx->multiValueExpression()->accept(this);
	auto funcName = Locale::ansiToUnicode(ctx->identifier()->getText());
	auto paramExpr = (MultiValueExpression*)paramExpressionWrapper.getExpression();
	Overload *overload = program->getFunctionOverload(funcName, paramExpr->getTypes());
	auto expr = new CallExpression(program, overload, paramExpr);
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	auto exprs = ctx->expression();
	for (auto &expr : exprs)
	{
		ALLOW_ASSIGN; //每次新的一行都允许赋值
		expr->accept(this); //假设只有函数声明，会自动加入到program里
	}
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx)
{
	if (this->assignable) {
		STORE_FORBID_ASSIGN;
		this->declarable = true;
		auto left = ctx->expression()[0]->accept(this).as<ExpressionWrapper>().getExpression();
		this->declarable = false;
		auto right = ctx->expression()[1]->accept(this).as<ExpressionWrapper>().getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new AssignmentExpression(program, left, right));
	}
	else {
		STORE_FORBID_ASSIGN;
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
		auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new BinaryCompareExpression(program, BinaryCompareExpression::CompareType::EQUAL, left, right));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE;
	auto expr = new AssignmentExpression(program, left, right);
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiValueExpression(WorkScriptParser::MultiValueExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	vector<Expression*> items;
	items.reserve(subContextCount);
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
		items[i] = itemExpr;
	}
	auto expr = new WorkScript::MultiValueExpression(program, items);
	RESTORE_ASSIGNABLE
	return ExpressionWrapper(expr);
}

//antlrcpp::Any WorkScriptVisitorImpl::visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext *ctx)
//{
//	auto objExprCtx = ctx->expression()[0];
//	ExpressionWrapper objExprWrapper = objExprCtx->accept(this);
//	auto objExpr = objExprWrapper.getExpression();
//	auto memberExprCtx = ctx->expression()[1];
//	ExpressionWrapper memberExprWrapper = memberExprCtx->accept(this);
//	auto memberExpr = memberExprWrapper.getExpression();
//	return ExpressionWrapper(Expression*(new MemberEvaluateExpression(this->context,objExpr,memberExpr)));
//}

antlrcpp::Any WorkScriptVisitorImpl::visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE
	if (ctx->PLUS()) {
		return ExpressionWrapper(new BinaryCalculateExpression(program,BinaryCalculateExpression::PLUS,leftExpression, rightExpression));
	}
	else { //MINUS
		return ExpressionWrapper(new BinaryCalculateExpression(program, BinaryCalculateExpression::MINUS, leftExpression, rightExpression));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE;
	if (ctx->MULTIPLY()) {
		return ExpressionWrapper(new BinaryCalculateExpression(program, BinaryCalculateExpression::MULTIPLY, leftExpression, rightExpression));
	}
	else if (ctx->DIVIDE()) {
		return ExpressionWrapper(new BinaryCalculateExpression(program, BinaryCalculateExpression::DIVIDE, leftExpression, rightExpression));
	}
	else { //MODULUS
		return ExpressionWrapper(new BinaryCalculateExpression(program, BinaryCalculateExpression::MODULUS, leftExpression, rightExpression));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto ret = ctx->expression()->accept(this);
	RESTORE_ASSIGNABLE;
	return ret;
}

antlrcpp::Any WorkScriptVisitorImpl::visitBinaryCompareExpression(WorkScriptParser::BinaryCompareExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	ExpressionWrapper wrapperLeft = ctx->expression()[0]->accept(this);
	ExpressionWrapper wrapperRight = ctx->expression()[1]->accept(this);
	auto leftExpression = wrapperLeft.getExpression();
	auto rightExpression = wrapperRight.getExpression();
	BinaryCompareExpression::CompareType compareType;
	RESTORE_ASSIGNABLE;
	if (ctx->DOUBLE_EQUAL()) {
		compareType = BinaryCompareExpression::CompareType::EQUAL;
	}
	else if (ctx->GREATER_THAN()) {
		compareType = BinaryCompareExpression::CompareType::GREATER_THAN;
	}
	else if (ctx->GREATER_THAN_EQUAL()) {
		compareType = BinaryCompareExpression::CompareType::GREATER_THAN_EQUAL;
	}
	else if (ctx->LESS_THAN()) {
		compareType = BinaryCompareExpression::CompareType::LESS_THAN;
	}
	else {
		compareType = BinaryCompareExpression::CompareType::LESS_THAN_EQUAL;
	}
	return new BinaryCompareExpression(program, compareType, leftExpression, rightExpression);
}

//antlrcpp::Any WorkScriptVisitorImpl::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
//{
//	STORE_FORBID_ASSIGN
//	auto subContext = ctx->expression();
//	size_t subContextCount = subContext.size();
//	auto expr = new ListExpression();
//	for (size_t i = 0; i < subContextCount; ++i) {
//		ExpressionWrapper wrapper = subContext[i]->accept(this);
//		auto itemExpr = wrapper.getExpression();
//		expr->addItem(itemExpr);
//	}
//	RESTORE_ASSIGNABLE
//	return ExpressionWrapper(expr);
//}

antlrcpp::Any WorkScriptVisitorImpl::visitNegativeExpression(WorkScriptParser::NegativeExpressionContext *ctx)
{
	ExpressionWrapper wrapper = ctx->expression()->accept(this);
	auto expr = new UnaryOperatorExpression(program, UnaryOperatorExpression::NEGATIVE, wrapper.getExpression());
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitPositiveExpression(WorkScriptParser::PositiveExpressionContext *ctx)
{
	return ctx->expression()->accept(this);
}

antlrcpp::Any WorkScriptVisitorImpl::visitVarargsExpression(WorkScriptParser::VarargsExpressionContext *ctx)
{
	ExpressionWrapper varWrapper = ctx->variableExpression()->accept(this);
	auto varExpr = (VariableExpression *)varWrapper.getExpression();
	varExpr->setVarargs(true);
	return varWrapper;
}

antlrcpp::Any WorkScript::WorkScriptVisitorImpl::visitFormalParameterExpression(WorkScriptParser::FormalParameterExpressionContext * ctx)
{
	auto params = ctx->identifier();
	vector<Expression*> itemExprs;
	itemExprs.reserve(params.size());

	for (size_t i = 0; i < params.size(); ++i)
	{
		itemExprs.push_back(params[i]->getText());
	}
	MultiValueExpression *expr = new MultiValueExpression(program, itemExprs);
	return ExpressionWrapper(expr);
}

WorkScriptVisitorImpl::WorkScriptVisitorImpl(Program *lpProgram)
{
	this->program = lpProgram;
}

WorkScriptVisitorImpl::~WorkScriptVisitorImpl()
{
}

void WorkScriptVisitorImpl::handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr, size_t line, size_t column)const
{
#define SINGLE_ESCAPE_CASE(escapedChar,unescapedChar) \
		case escapedChar: \
		targetStr[targetPos] = unescapedChar; \
		++srcPos; \
		++targetPos; \
		state = NORMAL; \
		break; 

	//有限状态机解析转义符
	enum State {
		NORMAL, FINISH, ESCAPE_START, ESCAPE_OCT, ESCAPE_HEX
	};
	size_t escapeStartPos = 0;
	State state = NORMAL;
	size_t srcPos = 0, targetPos = 0;
	while (state != FINISH)
	{
		switch (state)
		{
		case NORMAL:{
			switch (srcStr[srcPos])
			{
			case L'\\':
				state = ESCAPE_START;
				++srcPos;
				break;
			case L'\0':
				state = FINISH;
				break;
			default:
				targetStr[targetPos] = srcStr[srcPos];
				++srcPos;
				++targetPos;
				break;
			}
			break;
		}
		case ESCAPE_START: {
			switch (srcStr[srcPos])
			{
				SINGLE_ESCAPE_CASE(L'n', L'\n');
				SINGLE_ESCAPE_CASE(L't', L'\t');
				SINGLE_ESCAPE_CASE(L'r', L'\r');
				SINGLE_ESCAPE_CASE(L'0', L'\0');
				SINGLE_ESCAPE_CASE(L'v', L'\v');
				SINGLE_ESCAPE_CASE(L'a', L'\a');
				SINGLE_ESCAPE_CASE(L'b', L'\b');
				SINGLE_ESCAPE_CASE(L'f', L'\f');
				SINGLE_ESCAPE_CASE(L'\'', L'\'');
				SINGLE_ESCAPE_CASE(L'\"', L'\"');
				SINGLE_ESCAPE_CASE(L'\\', L'\\');
			case 'x':
				state = ESCAPE_HEX;
				escapeStartPos = srcPos;
				++srcPos;
				break;
			case L'1':case L'2':case L'3':case L'4':case L'5':case L'6':case L'7':case L'8':case L'9':
				state = ESCAPE_OCT;
				escapeStartPos = srcPos;
				++srcPos;
				break;
			case L'\0':
				throw std::move(SyntaxErrorException(line, column, (L"转义符未结束：\"" + wstring(srcStr) + L"\"").c_str()));
			default:
				throw std::move(SyntaxErrorException(line, column, (wstring(L"不能识别的转义符\"\\") + srcStr[srcPos] + L"\"").c_str()));
			}
			break;
		}
		case ESCAPE_OCT: {
			switch (srcStr[srcPos])
			{
			case L'0': case L'1':case L'2':case L'3':case L'4':case L'5':case L'6':case L'7':case L'8':case L'9':
				++srcPos;
				break;
			default:
				size_t octLen = srcPos - escapeStartPos;
				wchar_t *dstr = new wchar_t[octLen + 1];
				for (int i = 0; i < octLen; i++) {
					dstr[i] = srcStr[escapeStartPos + i];
				}
				dstr[octLen] = L'\0';
				int octNum; //八进制数结果
				swscanf(dstr, L"%o", &octNum);
				delete[]dstr;
				targetStr[targetPos] = (wchar_t)octNum;
				++targetPos;
				state = NORMAL;
				break;
			}
		}
		case ESCAPE_HEX: {
			switch (srcStr[srcPos])
			{
			case L'0': case L'1':case L'2':case L'3':case L'4':case L'5':
			case L'6':case L'7':case L'8':case L'9':case L'a':case L'b':
			case L'c':case L'd':case L'e':case L'f':case L'A':case L'B':
			case L'C':case L'D':case L'E':case L'F':
				++srcPos;
				break;
			default:
				size_t hexLen = srcPos - escapeStartPos - 1;
				wchar_t *dstr = new wchar_t[hexLen + 1];
				for (int i = 0; i < hexLen; i++) {
					dstr[i] = srcStr[escapeStartPos + 1 + i];
				}
				dstr[hexLen] = L'\0';
				int hexNum; //十六进制数结果
				swscanf(dstr, L"%x", &hexNum);
				delete[]dstr;
				targetStr[targetPos] = (wchar_t)hexNum;
				++targetPos;
				state = NORMAL;
				break;
			}
		}
		}
	}
	targetStr[targetPos] = L'\0';
}

