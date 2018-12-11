#include "stdafx.h"
#include "WorkScriptVisitorImpl.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "ExpressionWrapper.h"
#include "Type.h"
#include "PlusExpression.h"
#include "MinusExpression.h"
#include "MemberEvaluateExpression.h"
#include "MultiplyExpression.h"
#include "DivideExpression.h"
#include "FunctionInvocationExpression.h"
#include "GreaterThanExpression.h"
#include "VariableExpression.h"
#include "EqualsExpression.h"
#include "AssignmentExpression.h"
#include "ParameterExpression.h"
#include "GreaterThanEqualExpression.h"
#include "LessThanEqualExpression.h"
#include "LessThanExpression.h"
#include "NegativeExpression.h"
#include "IntegerExpression.h"
#include "ModulusExpression.h"
#include "ByteExpression.h"
#include "ParameterExpression.h"
#include "SyntaxErrorException.h"
#include "Parameter.h"
#include "Function.h"
#include "FunctionTemplate.h"
#include "BranchOverloadTemplate.h"
#include "Program.h"

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
	//string utf8FileName = ctx->STRING()->getText();
	//utf8FileName = utf8FileName.substr(1, utf8FileName.size() - 2);
	//wstring wFileName = boost::locale::conv::to_utf<wchar_t>(utf8FileName, "UTF-8");
	//this->program->addIncludeFile(wFileName.c_str());
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
		return ExpressionWrapper(new DoubleExpression(value));
	}
	else {
		int value = 0;
		int len = sscanf(ctx->INTEGER()->getText().c_str(), "%d", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new IntegerExpression(value));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string text = ctx->STRING()->getText();
	text = text.substr(1, text.length() - 2);
	wstring wtext = boost::locale::conv::to_utf<wchar_t>(text, "UTF-8");

	wchar_t *unescapedText = new wchar_t[wtext.length() + 1];
	try {
		this->handleEscapeCharacters(wtext.c_str(), unescapedText, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1);
	}
	catch(...){
		delete[]unescapedText;
		throw;
	}
	auto lpExpr = new StringExpression(unescapedText);
	delete[]unescapedText;
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx)
{
	string boolStr = ctx->BOOLEAN()->getText();
	if (boolStr == "true") {
		return ExpressionWrapper(&BooleanExpression::TRUE);
	}
	else if (boolStr == "yes") {
		return ExpressionWrapper(&BooleanExpression::YES);
	}
	else if (boolStr == "ok") {
		return ExpressionWrapper(&BooleanExpression::OK);
	}
	else if (boolStr == "good") {
		return ExpressionWrapper(&BooleanExpression::GOOD);
	}
	else if (boolStr == "false") {
		return ExpressionWrapper(&BooleanExpression::FALSE);
	}
	else if (boolStr == "no") {
		return ExpressionWrapper(&BooleanExpression::NO);
	}
	else if (boolStr == "bad") {
		return ExpressionWrapper(&BooleanExpression::BAD);
	}
	else {
		throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, (L"�޷�ʶ��Ĳ���ֵ��" + boost::locale::conv::to_utf<wchar_t>(boolStr, "UTF-8")).c_str()));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->identifier()->getText();
	auto expr = new VariableExpression(boost::locale::conv::to_utf<wchar_t>(varName, "UTF-8").c_str());
	expr->setDeclarable(this->declarable); //�Ⱥ���ߵı����ſ��Դ�������
	auto wrapper = ExpressionWrapper(expr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ALLOW_ASSIGN;
	/*====������һ��====*/
	++this->curDepth;
	//������ʵ��
	vector<Expression*> impls;
	if (ctx->functionImplementationExpression()->expression() != nullptr) {
		auto expr = (ExpressionWrapper)ctx->functionImplementationExpression()->expression()->accept(this);
		impls.push_back(expr.getExpression());
	}
	else {
		auto exprs = ctx->functionImplementationExpression()->blockExpression()->expression();
		impls.reserve(exprs.size());
		for (size_t i = 0; i < exprs.size(); ++i)
		{
			auto wrapper = (ExpressionWrapper)exprs[i]->accept(this);
			impls[i] = wrapper.getExpression();
		}
	}
	
	FORBID_ASSIGN;

	//�����Ĳ���������
	ExpressionWrapper paramsWrapper = ctx->functionDeclarationExpression()->parameterExpression()->accept(this);
	auto paramExpr = (ParameterExpression *)paramsWrapper.getExpression();
	size_t paramCount = paramExpr->getItems().size();
	vector<ParameterTemplate*> paramInfos;
	paramInfos.reserve(paramCount);
	vector<Expression*> vecConstraints; //���������ƣ��������������﷨�Ǳ������������
	//�������﷨�Ǳ��룬����Լ����Ĭ��ֵ
	for (size_t i = 0; i < paramCount; ++i) {
		paramInfos[i] = new ParameterTemplate();
		if (paramExpr->getItem(i)->getExpressionType() == ExpressionType::VARIABLE_EXPRESSION) {
			VariableExpression* varExpr = (VariableExpression*)paramExpr->getItem(i);
			paramInfos[i]->setName(varExpr->getName());
			paramInfos[i]->setVarargs(varExpr->isVarargs());
		}
		//else if (paramExpr->getItem(i)->getExpressionType()->isSubTypeOf(nullptr, Type::BINARY_COMPARE_EXPRESSION)) {
		//	VariableExpression*leftVar = ((BinaryCompareExpression*)paramExpr->getItem(i))->getLeftVariable();
		//	if (leftVar == nullptr) {
		//		throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, L"��������Լ���󲿱���Ϊ������"));
		//	}
		//	vecConstraints.push_back(paramExpr->getItem(i));
		//	paramInfos[i].setParameterName(leftVar->getName());
		//}
		//else if (paramExpr->getItem(i)->getType(nullptr)->isSubTypeOf(nullptr, Type::ASSIGNMENT_EXPRESSION)) {
		//	AssignmentExpression*assignmentExpr = (AssignmentExpression*)paramExpr->getItem(i);
		//	auto leftExpr = assignmentExpr->getLeftExpression();
		//	if (!leftExpr->getType(nullptr)->equals(nullptr, Type::VARIABLE_EXPRESSION)){
		//		throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, L"����Ĭ��ֵ�󲿱���Ϊ��������"));
		//	}
		//	auto leftVar = (VariableExpression*)leftExpr;
		//	paramInfos[i].setParameterName(leftVar->getName());
		//	paramInfos[i].setDefaultValue(assignmentExpr->getRightExpression());
		//}else{
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
	////Ȼ������������
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

	/*====�ָ���һ��====*/
	--this->curDepth;

	auto funcNameCtx = ctx->functionDeclarationExpression()->identifier();
	wstring funcName;
	if(funcNameCtx != nullptr) {
		funcName = boost::locale::conv::to_utf<wchar_t>(funcNameCtx->getText(), LOCAL_BOOST_ENCODING);
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

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper paramExpressionWrapper = ctx->parameterExpression()->accept(this);
	auto funcName = boost::locale::conv::to_utf<wchar_t>(ctx->identifier()->getText(), "UTF-8");
	auto paramExpr = (ParameterExpression*)paramExpressionWrapper.getExpression();
	auto expr = new FunctionInvocationExpression();
	expr->setFunctionName(funcName);
	expr->setParameters(paramExpr);
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	//auto includeCommands = ctx->includeCommand();
	//for (auto &command : includeCommands) {
	//	command->accept(this);
	//}

	auto exprs = ctx->expression();
	for (auto &expr : exprs)
	{
		ALLOW_ASSIGN; //ÿ���µ�һ�ж�����ֵ
		expr->accept(this); //����ֻ�к������������Զ����뵽program��
	}
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx)
{
	if (this->assignable) {
		STORE_FORBID_ASSIGN;
		this->declarable = true;
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
		this->declarable = false;
		auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new AssignmentExpression(left, right));
	}
	else {
		STORE_FORBID_ASSIGN;
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
		auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new EqualsExpression(left, right));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(new AssignmentExpression(left, right));
}

antlrcpp::Any WorkScriptVisitorImpl::visitEqualsExpression(WorkScriptParser::EqualsExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(new EqualsExpression(left, right));
}

antlrcpp::Any WorkScriptVisitorImpl::visitParameterExpression(WorkScriptParser::ParameterExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->parameterExpressionItem();
	size_t subContextCount = subContext.size();
	vector<Expression*> items;
	items.reserve(subContextCount);
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
		items[i] = itemExpr;
	}
	auto expr = new WorkScript::ParameterExpression(items);
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
		return ExpressionWrapper(new PlusExpression(leftExpression, rightExpression));
	}
	else { //MINUS
		return ExpressionWrapper(new MinusExpression(leftExpression, rightExpression));
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
	if (ctx->DIVIDE()) { //DIVIDE
		return ExpressionWrapper(new DivideExpression(leftExpression, rightExpression));
	}
	else if (ctx->MODULUS()) {
		return ExpressionWrapper(new ModulusExpression(leftExpression, rightExpression));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto ret = ctx->expression()->accept(this);
	RESTORE_ASSIGNABLE;
	return ret;
}

antlrcpp::Any WorkScriptVisitorImpl::visitCompareExpression(WorkScriptParser::CompareExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	ExpressionWrapper wrapperLeft = ctx->expression()[0]->accept(this);
	ExpressionWrapper wrapperRight = ctx->expression()[1]->accept(this);
	auto leftExpression = wrapperLeft.getExpression();
	auto rightExpression = wrapperRight.getExpression();
	RESTORE_ASSIGNABLE;
	if (ctx->GREATER_THAN()) {
		return ExpressionWrapper(new GreaterThanExpression(leftExpression, rightExpression));
	}
	else if (ctx->GREATER_THAN_EQUAL()) {
		return ExpressionWrapper(new GreaterThanEqualExpression(leftExpression, rightExpression));
	}
	else if (ctx->LESS_THAN()) {
		return ExpressionWrapper(new LessThanExpression(leftExpression, rightExpression));
	}
	else {
		return ExpressionWrapper(new LessThanEqualExpression(leftExpression, rightExpression));
	}
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
	auto expr = new NegativeExpression(wrapper.getExpression());
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

antlrcpp::Any WorkScriptVisitorImpl::visitParameterExpressionItem(WorkScriptParser::ParameterExpressionItemContext *ctx)
{
	if (ctx->expression()) {
		return ctx->expression()->accept(this);
	}
	else {
		return ctx->varargsExpression()->accept(this);
	}
}

//antlrcpp::Any WorkScriptVisitorImpl::visitAccessLevelExpression(WorkScriptParser::AccessLevelExpressionContext *ctx)
//{
//	string level = ctx->ACCESS_LEVEL()->getText();
//	if (level == "public") {
//		this->setDomainAccess(this->curDepth, DomainAccess::PUBLIC);
//	}
//	else if (level == "private") {
//		this->setDomainAccess(this->curDepth, DomainAccess::PRIVATE);
//	}
//	ExpressionWrapper ret;
//	ret.setLifeCycle(ExpressionLifeCycle::COMPILE);
//	return ret;
//}

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

	//����״̬������ת���
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
				throw std::move(SyntaxErrorException(line, column, (L"ת���δ������\"" + wstring(srcStr) + L"\"").c_str()));
			default:
				throw std::move(SyntaxErrorException(line, column, (wstring(L"����ʶ���ת���\"\\") + srcStr[srcPos] + L"\"").c_str()));
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
				int octNum; //�˽��������
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
				int hexNum; //ʮ�����������
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

