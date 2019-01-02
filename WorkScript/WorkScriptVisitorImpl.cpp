#include "stdafx.h"
#include "WorkScriptVisitorImpl.h"
#include "ExpressionWrapper.h"
#include "Type.h"
#include "VoidType.h"
#include "CallExpression.h"
#include "VariableExpression.h"
#include "AssignmentExpression.h"
#include "MultiValueExpression.h"
#include "SyntaxErrorException.h"
#include "Parameter.h"
#include "Function.h"
#include "BranchFunction.h"
#include "FunctionBranch.h"
#include "Program.h"
#include "BinaryCompareExpression.h"
#include "BinaryCalculateExpression.h"
#include "UnaryOperatorExpression.h"
#include "Locale.h"
#include "Location.h"
#include "FormalParametersResolver.h"
#include "ConstantExpression.h"
#include "FloatConstant.h"
#include "IntegerConstant.h"
#include "StringConstant.h"

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

static void handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr, Location loc);

inline static Location getLocation(antlr4::ParserRuleContext *ctx) 
{
	Location l(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1);
	return l;
}

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
		return ExpressionWrapper(new ConstantExpression(ExpressionInfo(program, getLocation(ctx)), new FloatConstant(program->getFloat64Type(), value)));
	}
	else {
		int value = 0;
		int len = sscanf(ctx->INTEGER()->getText().c_str(), "%d", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new ConstantExpression(ExpressionInfo(program, getLocation(ctx)), new IntegerConstant(program->getSInt32Type(), value)));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string text = ctx->STRING()->getText();
	text = text.substr(1, text.length() - 2);
	wstring wtext = Locale::ansiToUnicode(text);

	wchar_t *unescapedText = new wchar_t[wtext.length() + 1];
	try {
		handleEscapeCharacters(wtext.c_str(), unescapedText, getLocation(ctx));
	}
	catch(...){
		delete[]unescapedText;
		throw;
	}
	auto lpExpr = new ConstantExpression(ExpressionInfo(program, getLocation(ctx)), new StringConstant(unescapedText));
	delete[]unescapedText;
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx)
{
	string boolStr = ctx->BOOLEAN()->getText();
	if (boolStr == "true" || boolStr == "yes" || boolStr == "ok" || boolStr == "good") {
		return ExpressionWrapper(new ConstantExpression(ExpressionInfo(program, getLocation(ctx)), new IntegerConstant(program->getUInt1Type(), 1)));
	}
	else if (boolStr == "false" || boolStr == "no" || boolStr == "bad") {
		return ExpressionWrapper(new ConstantExpression(ExpressionInfo(program, getLocation(ctx)), new IntegerConstant(program->getUInt1Type(), 0)));
	}
	else {
		throw std::move(SyntaxErrorException(getLocation(ctx), L"无法识别的布尔值：" + Locale::ansiToUnicode(boolStr)));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->identifier()->getText();
	auto expr = new VariableExpression(ExpressionInfo(program, getLocation(ctx)), Locale::ansiToUnicode(varName));
	expr->setDeclarable(this->declarable); //等号左边的变量才可以创建声明
	auto wrapper = ExpressionWrapper(expr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	/*====深入下一层====*/
	++this->curDepth;

	/*根据函数名找到或新建相应的函数模板*/
	auto funcNameCtx = ctx->functionDeclarationExpression()->identifier();
	wstring funcName;
	if (funcNameCtx != nullptr) {
		funcName = Locale::ansiToUnicode(funcNameCtx->getText());
	}

	/*处理函数的参数和限制*/
	//参数声明
	auto paramsDeclCtx = ctx->functionDeclarationExpression()->formalParameterExpression()->multiValueExpression()->expression();
	vector<Expression*> paramDeclExprs;
	paramDeclExprs.reserve(paramsDeclCtx.size());

	for (size_t i = 0; i < paramsDeclCtx.size(); ++i)
	{
		paramDeclExprs.push_back(paramsDeclCtx[i]->accept(this).as<ExpressionWrapper>().getExpression());
	}

	//限制声明
	vector<Expression*> constraintsDecl;
	auto constraintCtx = ctx->functionConstraintExpression();
	if (constraintCtx) {
		if (constraintCtx->expression())
		{
			auto expr = constraintCtx->expression()->accept(this).as<ExpressionWrapper>().getExpression();
			constraintsDecl.push_back(expr);
		}
		else {
			for (auto curCtx : constraintCtx->blockExpression()->expression()) {
				auto expr = curCtx->accept(this).as<Expression*>();
				constraintsDecl.push_back(expr);
			}
		}
	}
	//解析参数和限制
	auto resolveRes = FormalParametersResolver::resolve(ExpressionInfo(program, getLocation(ctx)), this->symbolTables.top(), paramDeclExprs, constraintsDecl);
	auto paramTypes = resolveRes.getParameterTypes();
	auto params = resolveRes.getParameters();
	auto constraints = resolveRes.getConstraints();

	//TODO 检查是否为extern函数
	auto funcs = this->program->getFunctions(funcName, paramTypes);
	if (funcs.size() == 0) {
		//此时还不知道返回值类型
		auto newFunc = new BranchFunction(this->program, funcName, paramTypes, nullptr);
		funcs.push_back(newFunc);
		this->program->addFunction(newFunc);
	}
	//为所有符合条件的函数重载添加函数分支
	for (size_t i = 0; i < funcs.size(); ++i) {
		BranchFunction *func = (BranchFunction*)funcs[i];
		size_t branchID = func->getBranchCount();
		auto branch = new FunctionBranch(func, branchID, getLocation(ctx));
		branch->setParameters(params);
		func->addBranch(branch);
		this->branchIDs.push(branchID);
		this->symbolTables.push(branch->getAbstractSymbolTable());

		/*将函数声明添加到相应的重载分支中*/
		//寻找重载，同时判断是否和已有返回值类型相同，如果不存在则新建。

		/*函数的实现*/
		ALLOW_ASSIGN;
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
				impls.push_back(wrapper.getExpression());
			}
		}

		branch->setConstraints(constraints);
		branch->setImplements(impls);
		FORBID_ASSIGN;
		InstantializeContext innerInstCtx(this->branchIDs.top(), this->symbolTables.top());
		//恢复当前分支
		this->symbolTables.pop();
		this->branchIDs.pop();

		/*检查重载和当前重载分支的返回值类型是否相同*/
		//TODO 若不相同，可以取两个返回值类型中的更高类型
		InstantializeContext outerInstCtx(this->branchIDs.top(), this->symbolTables.top());
		Type * returnType = nullptr;
		if (impls.size() == 0) {
			returnType = this->program->getVoidType();
		}
		else {
			returnType = impls[impls.size() - 1]->getType(&innerInstCtx);
		}
		Type *funcReturnType = func->getReturnType(&outerInstCtx);
		if (!funcReturnType) {
			func->setReturnType(returnType);
		}
		else if (returnType && !returnType->equals(funcReturnType)) {
			throw SyntaxErrorException(getLocation(ctx), L"返回值必须为" + funcReturnType->getName() + L"类型");
		}
	}
	/*====恢复上一层====*/
	--this->curDepth;
	RESTORE_ASSIGNABLE;
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitCallExpression(WorkScriptParser::CallExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper paramExpressionWrapper = ctx->multiValueExpression()->accept(this);
	auto funcName = Locale::ansiToUnicode(ctx->identifier()->getText());
	auto paramExpr = (MultiValueExpression*)paramExpressionWrapper.getExpression();
	auto expr = new CallExpression(ExpressionInfo(program, getLocation(ctx)), funcName, paramExpr);
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
		//将赋值变量加入符号表
		InstantializeContext instCtx(this->branchIDs.top(), this->symbolTables.top());
		if (left->getExpressionType() == ExpressionType::VARIABLE_EXPRESSION) {
			auto leftVar = (VariableExpression*)left;
			this->symbolTables.top()->setSymbol(leftVar->getName(), right->getType(&instCtx));
		}
		return ExpressionWrapper(new AssignmentExpression(ExpressionInfo(program, getLocation(ctx)), left, right));
	}
	else {
		STORE_FORBID_ASSIGN;
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
		auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new BinaryCompareExpression(ExpressionInfo(program, getLocation(ctx)), left, right, BinaryCompareExpression::CompareType::EQUAL));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE;
	auto expr = new AssignmentExpression(ExpressionInfo(program, getLocation(ctx)), left, right);
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
		items.push_back(itemExpr);
	}
	auto expr = new WorkScript::MultiValueExpression(ExpressionInfo(program, getLocation(ctx)), items);
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
		Expression *expr = new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::PLUS);
		return ExpressionWrapper(expr);
	}
	else { //MINUS
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::MINUS));
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
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::MULTIPLY));
	}
	else if (ctx->DIVIDE()) {
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::DIVIDE));
	}
	else { //MODULUS
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::MODULUS));
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
	return new BinaryCompareExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, compareType);
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
	auto expr = new UnaryOperatorExpression(ExpressionInfo(program, getLocation(ctx)), wrapper.getExpression(), UnaryOperatorExpression::NEGATIVE);
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

WorkScriptVisitorImpl::WorkScriptVisitorImpl(Program *lpProgram)
{
	this->program = lpProgram;
	this->symbolTables.push(lpProgram->getGlobalSymbolTable());
	this->branchIDs.push(0);
}

WorkScriptVisitorImpl::~WorkScriptVisitorImpl()
{
}

static void handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr, Location loc)
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
				throw std::move(SyntaxErrorException(loc, (L"转义符未结束：\"" + wstring(srcStr) + L"\"").c_str()));
			default:
				throw std::move(SyntaxErrorException(loc, (wstring(L"不能识别的转义符\"\\") + srcStr[srcPos] + L"\"").c_str()));
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

