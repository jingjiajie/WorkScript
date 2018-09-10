#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <boost/locale.hpp>
#include <math.h>
#include <limits.h>
#include "WorkScriptVisitorImpl.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "ExpressionWrapper.h"
#include "TypeExpression.h"
#include "PlusExpression.h"
#include "MinusExpression.h"
#include "MemberEvaluateExpression.h"
#include "MultiplyExpression.h"
#include "DivideExpression.h"
#include "FunctionInvocationExpression.h"
#include "FunctionExpression.h"
#include "GreaterThanExpression.h"
#include "ListExpression.h"
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
#include "Pointer.h"
#include "SyntaxErrorException.h"

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

antlrcpp::Any WorkScriptVisitorImpl::visitIncludeCommand(WorkScriptParser::IncludeCommandContext *ctx)
{
	string utf8FileName = ctx->STRING()->getText();
	utf8FileName = utf8FileName.substr(1, utf8FileName.size() - 2);
	wstring wFileName = boost::locale::conv::to_utf<wchar_t>(utf8FileName, "UTF-8");
	this->program->addIncludeFile(wFileName.c_str());
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
		return ExpressionWrapper(DoubleExpression::newInstance(value));
	}
	else {
		int value = 0;
		int len = sscanf(ctx->INTEGER()->getText().c_str(), "%d", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(IntegerExpression::newInstance(value));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string text = ctx->STRING()->getText();
	text = text.substr(1, text.length() - 2);
	wstring wtext = boost::locale::conv::to_utf<wchar_t>(text, "UTF-8");

	wchar_t *unescapedText = new wchar_t[wtext.length() + 1];
	this->handleEscapeCharacters(wtext.c_str(), unescapedText, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1);
	auto lpExpr = StringExpression::newInstance(unescapedText);
	delete []unescapedText;
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx)
{
	string boolStr = ctx->BOOLEAN()->getText();
	if (boolStr == "true") {
		return ExpressionWrapper(BooleanExpression::VAL_TRUE);
	}
	else if (boolStr == "yes") {
		return ExpressionWrapper(BooleanExpression::VAL_YES);
	}
	else if (boolStr == "ok") {
		return ExpressionWrapper(BooleanExpression::VAL_OK);
	}
	else if (boolStr == "good") {
		return ExpressionWrapper(BooleanExpression::VAL_GOOD);
	}
	else if (boolStr == "false") {
		return ExpressionWrapper(BooleanExpression::VAL_FALSE);
	}
	else if (boolStr == "no") {
		return ExpressionWrapper(BooleanExpression::VAL_NO);
	}
	else if (boolStr == "bad") {
		return ExpressionWrapper(BooleanExpression::VAL_BAD);
	}
	else {
		throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, (L"无法识别的布尔值：" + boost::locale::conv::to_utf<wchar_t>(boolStr, "UTF-8")).c_str()));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->identifier()->getText();
	auto wrapper = ExpressionWrapper(new VariableExpression(boost::locale::conv::to_utf<wchar_t>(varName,"UTF-8").c_str()));
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	ALLOW_ASSIGN
	//函数的实现
	Pointer<Expression>*impls;
	size_t implCount;
	if (ctx->functionImplementationExpression()->expression() != nullptr) {
		implCount = 1;
		impls = new Pointer<Expression>[1];
		auto tmp = (ExpressionWrapper)ctx->functionImplementationExpression()->expression()->accept(this);
		impls[0] = (tmp).getExpression();
	}
	else {
		auto exprs = ctx->functionImplementationExpression()->blockExpression()->expression();
		implCount = exprs.size();
		impls = new Pointer<Expression>[implCount];
		for (size_t i = 0; i < implCount; ++i)
		{
			impls[i] = ((ExpressionWrapper)exprs[i]->accept(this)).getExpression();
		}
	}
	FORBID_ASSIGN

	//函数的参数和限制
	ExpressionWrapper paramsWrapper = ctx->functionDeclarationExpression()->parameterExpression()->accept(this);
	auto paramExpr = (const Pointer<ParameterExpression> &)(paramsWrapper.getExpression());
	size_t paramCount = paramExpr->getCount();
	ParameterInfo *paramInfos = new ParameterInfo[paramCount]();
	vector<Pointer<Expression>> vecConstraints; //函数的限制，由字面声明和语法糖编译两部分组成
	//首先是语法糖编译，包括约束和默认值
	for (size_t i = 0; i < paramCount; ++i) {
		if (paramExpr->getItem(i)->getType(nullptr)->equals(nullptr, TypeExpression::VARIABLE_EXPRESSION)) {
			Pointer<VariableExpression> varExpr = paramExpr->getItem(i);
			paramInfos[i].setParameterName(varExpr->getName());
			paramInfos[i].setVarargs(varExpr->isVarargs());
		}
		else if (paramExpr->getItem(i)->getType(nullptr)->isSubTypeOf(nullptr, TypeExpression::BINARY_COMPARE_EXPRESSION)) {
			Pointer<VariableExpression>leftVar = ((Pointer<BinaryCompareExpression>)paramExpr->getItem(i))->getLeftVariable();
			if (leftVar == nullptr) {
				throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, L"函数参数约束左部必须为变量！"));
			}
			vecConstraints.push_back(paramExpr->getItem(i));
			paramInfos[i].setParameterName(leftVar->getName());
		}
		else if (paramExpr->getItem(i)->getType(nullptr)->isSubTypeOf(nullptr, TypeExpression::ASSIGNMENT_EXPRESSION)) {
			Pointer<AssignmentExpression>assignmentExpr = (Pointer<AssignmentExpression>)paramExpr->getItem(i);
			auto leftExpr = assignmentExpr->getLeftExpression();
			if (!leftExpr->getType(nullptr)->equals(nullptr, TypeExpression::VARIABLE_EXPRESSION)){
				throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, L"参数默认值左部必须为参数名！"));
			}
			auto leftVar = (Pointer<VariableExpression>)leftExpr;
			paramInfos[i].setParameterName(leftVar->getName());
			paramInfos[i].setDefaultValue(assignmentExpr->getRightExpression());
		}else{
			wstring tmpVarName = L"_" + to_wstring(i);
			paramInfos[i].setParameterName(tmpVarName.c_str());
			const Pointer<EqualsExpression>constraint = new EqualsExpression();
			constraint->setLeftExpression(new VariableExpression(tmpVarName.c_str()));
			constraint->setRightExpression(paramExpr->getItem(i));
			vecConstraints.push_back(constraint);
		}
	}
	//然后是字面声明
	if (ctx->functionConstraintExpression() != nullptr) {
		if (ctx->functionConstraintExpression()->expression() != nullptr) {
			auto expr = ((ExpressionWrapper)ctx->functionConstraintExpression()->expression()->accept(this)).getExpression();
			vecConstraints.push_back(expr);
		}
		else {
			for (auto &subCtx : ctx->functionConstraintExpression()->blockExpression()->expression()) {
				vecConstraints.push_back(((ExpressionWrapper)subCtx->accept(this)).getExpression());
			}
		}
	}

	Pointer<FunctionExpression> funcExpr = new FunctionExpression();
	auto funcNameCtx = ctx->functionDeclarationExpression()->identifier();
	if (funcNameCtx == nullptr) {
		funcExpr->setName(nullptr);
	}
	else {
		string funcName = funcNameCtx->getText();
		funcExpr->setName(boost::locale::conv::to_utf<wchar_t>(funcName, "UTF-8").c_str());
	}

	Pointer<Expression> *constraints = new Pointer<Expression>[vecConstraints.size()];
	for (size_t i = 0; i < vecConstraints.size(); ++i) {
		constraints[i] = vecConstraints[i];
	}

	auto overload = new Overload;
	overload->setParameterInfos(paramInfos,paramCount);
	overload->setConstraints(constraints, vecConstraints.size());
	overload->setImplements(impls, implCount);
	funcExpr->addOverload(overload);

	RESTORE_ASSIGNABLE
	return ExpressionWrapper(funcExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper expressionWrapper = ctx->expression()->accept(this);
	ExpressionWrapper paramExpressionWrapper = ctx->parameterExpression()->accept(this);
	auto termExpr = (const Pointer<Expression> &)(expressionWrapper.getExpression());
	auto paramExpr = (const Pointer<ParameterExpression> &)(paramExpressionWrapper.getExpression());
	auto expr = new FunctionInvocationExpression();
	expr->setLeftExpression(termExpr);
	expr->setParameters(paramExpr);
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	auto commands = ctx->command();
	for (auto &command : commands) {
		command->accept(this);
	}

	auto exprs = ctx->expression();
	for (auto &expr : exprs)
	{
		this->assignable = true; //每次新的一行都允许赋值
		auto ret = (ExpressionWrapper)expr->accept(this);
		this->program->pushExpression(ret.getExpression());
	}
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE
	if (this->assignable) {
		return ExpressionWrapper(new AssignmentExpression(left, right));
	}
	else {
		return ExpressionWrapper(new EqualsExpression(left, right));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE
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
	auto items = new Pointer<Expression>[subContextCount];
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		Pointer<Expression> itemExpr = wrapper.getExpression();
		items[i] = itemExpr;
	}
	auto expr = new ParameterExpression(items, subContextCount);
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
//	return ExpressionWrapper(Pointer<Expression>(new MemberEvaluateExpression(this->context,objExpr,memberExpr)));
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
	RESTORE_ASSIGNABLE
		if (ctx->DIVIDE()) { //DIVIDE
			return ExpressionWrapper(new DivideExpression(leftExpression, rightExpression));
		}
		else if (ctx->MODULUS()) {
			return ExpressionWrapper(new ModulusExpression(leftExpression,rightExpression));
		}//乘号可以省略
		else{
			return ExpressionWrapper(new MultiplyExpression(leftExpression, rightExpression));
		}
}

antlrcpp::Any WorkScriptVisitorImpl::visitNonSignMultiplyExpression(WorkScriptParser::NonSignMultiplyExpressionContext *ctx)
{
	ExpressionWrapper leftWrapper = ctx->numberExpression()->accept(this);
	ExpressionWrapper rightWrapper = ctx->variableExpression()->accept(this);
	auto expr = new MultiplyExpression(leftWrapper.getExpression(), rightWrapper.getExpression());
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		auto ret = ctx->expression()->accept(this);
	RESTORE_ASSIGNABLE
		return ret;
}

antlrcpp::Any WorkScriptVisitorImpl::visitCompareExpression(WorkScriptParser::CompareExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	ExpressionWrapper wrapperLeft = ctx->expression()[0]->accept(this);
	ExpressionWrapper wrapperRight = ctx->expression()[1]->accept(this);
	auto leftExpression = wrapperLeft.getExpression();
	auto rightExpression = wrapperRight.getExpression();
	RESTORE_ASSIGNABLE
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

antlrcpp::Any WorkScriptVisitorImpl::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	auto expr = new ListExpression();
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
		expr->addItem(itemExpr);
	}
	RESTORE_ASSIGNABLE
	return ExpressionWrapper(expr);
}

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
	Pointer<VariableExpression> varExpr = varWrapper.getExpression();
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

WorkScriptVisitorImpl::WorkScriptVisitorImpl(Program *lpProgram)
{
	this->program = lpProgram;
}

WorkScriptVisitorImpl::~WorkScriptVisitorImpl()
{
}

void WorkScriptVisitorImpl::handleEscapeCharacters(const wchar_t *srcStr,wchar_t *targetStr, size_t line, size_t column)const
{
	enum State {
		NORMAL,ESCAPE_START
	};
	State state = NORMAL;
	size_t srcPos = 0, targetPos = 0;
	while (srcStr[srcPos] != L'\0')
	{
		switch (state)
		{
		case NORMAL:
			if (srcStr[srcPos] != L'\\') {
				targetStr[targetPos] = srcStr[srcPos];
				++srcPos;
				++targetPos;
			}
			else {
				state = ESCAPE_START;
				++srcPos;
			}
			break;
		case ESCAPE_START:
			switch (srcStr[srcPos])
			{
			case L'n':
				targetStr[targetPos] = L'\n';
				++srcPos;
				++targetPos;
				state = NORMAL;
				break;
			case L't':
				targetStr[targetPos] = L'\t';
				++srcPos;
				++targetPos;
				state = NORMAL;
				break;
			default:
				throw std::move(SyntaxErrorException(line,column,(wstring(L"不能识别的转义符：\\") + srcStr[srcPos]).c_str()));
			}
			break;
		}
	}
	targetStr[targetPos] = L'\0';
}