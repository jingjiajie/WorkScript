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

antlrcpp::Any WorkScriptVisitorImpl::visitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx)
{
	string text = ctx->NUMBER()->getText();
	double value = 0;
	int len = sscanf(text.c_str(), "%lf", &value);
	if (len == 0) {
		throw new exception(("无法识别的数字：" + text).c_str());
	}
	if (ctx->MINUS()) {
		value = -value;
	}
	Expression *lpExpr = nullptr;
	double decimalPart = value - (int)value;
	//根据实际数值，判断是double,integer还是byte
	if (decimalPart < -1e-8 || decimalPart > 1e-8) { //是Double
		lpExpr = DoubleExpression::newInstance(value, StorageLevel::LITERAL);
	}
	else { //是整数
		//if (value < 0 || value > UCHAR_MAX) { //是Integer
			lpExpr = IntegerExpression::newInstance(value, StorageLevel::LITERAL);
		//}
		//else { //是Byte
		//	lpExpr = ByteExpression::newInstance(value, StorageLevel::LITERAL);
		//}
	}
	auto wrapper = ExpressionWrapper(lpExpr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string textWithQuotationMark = ctx->STRING()->getText();
	wstring wtext = boost::locale::conv::to_utf<wchar_t>(textWithQuotationMark, "UTF-8");
	wtext = wtext.substr(1, wtext.length() - 2);
	auto lpExpr = StringExpression::newInstance(wtext.c_str(), StorageLevel::LITERAL);
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->identifier()->getText();
	return ExpressionWrapper(new VariableExpression(boost::locale::conv::to_utf<wchar_t>(varName,"UTF-8").c_str(), StorageLevel::LITERAL));
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	string funcName = ctx->functionDeclarationExpression()->identifier()->getText();
	//函数的实现
	Expression **impls;
	size_t implCount;
	if (ctx->functionImplementationExpression()->expression() != nullptr) {
		implCount = 1;
		impls = new Expression*[1];
		auto tmp = (ExpressionWrapper)ctx->functionImplementationExpression()->expression()->accept(this);
		impls[0] = (tmp).getExpression();
	}
	else {
		ALLOW_ASSIGN
		auto exprs = ctx->functionImplementationExpression()->blockExpression()->expression();
		implCount = exprs.size();
		impls = new Expression*[implCount];
		for (size_t i = 0; i < implCount; ++i)
		{
			impls[i] = ((ExpressionWrapper)exprs[i]->accept(this)).getExpression();
		}
	}
	FORBID_ASSIGN

	//函数的参数和限制
	ExpressionWrapper paramsWrapper = ctx->functionDeclarationExpression()->parameterExpression()->accept(this);
	auto paramExpr = (ParameterExpression *const&)(paramsWrapper.getExpression());
	size_t paramCount = paramExpr->getCount();
	ParameterInfo *paramInfos = new ParameterInfo[paramCount]();
	vector<Expression *> vecConstraints; //函数的限制，由字面声明和语法糖编译两部分组成
	//首先是语法糖编译，包括约束和默认值
	for (size_t i = 0; i < paramCount; ++i) {
		if (paramExpr->getItem(i)->getType(nullptr)->equals(nullptr, &TypeExpression::VARIABLE_EXPRESSION)) {
			paramInfos[i].setParameterName(((VariableExpression *const)paramExpr->getItem(i))->getName());
		}
		else if (paramExpr->getItem(i)->getType(nullptr)->isSubTypeOf(nullptr, &TypeExpression::BINARY_COMPARE_EXPRESSION)) {
			VariableExpression *leftVar = ((BinaryCompareExpression*)paramExpr->getItem(i))->getLeftVariable();
			if (leftVar == nullptr) {
				throw std::move(WorkScriptException(L"函数参数约束左部必须为变量！"));
			}
			vecConstraints.push_back(paramExpr->popItem(i));
			paramInfos[i].setParameterName(leftVar->getName());
		}
		else if (paramExpr->getItem(i)->getType(nullptr)->isSubTypeOf(nullptr, &TypeExpression::ASSIGNMENT_EXPRESSION)) {
			AssignmentExpression *assignmentExpr = (AssignmentExpression *)paramExpr->getItem(i);
			auto leftExpr = assignmentExpr->getLeftExpression();
			if (!leftExpr->getType(nullptr)->equals(nullptr, &TypeExpression::VARIABLE_EXPRESSION)){
				throw std::move(WorkScriptException(L"参数默认值左部必须为参数名！"));
			}
			auto leftVar = (VariableExpression*)leftExpr;
			paramInfos[i].setParameterName(leftVar->getName());
			paramInfos[i].setDefaultValue(assignmentExpr->popRightExpression());
		}else{
			wstring tmpVarName = L"_" + to_wstring(i);
			paramInfos[i].setParameterName(tmpVarName.c_str());
			EqualsExpression * constraint = new EqualsExpression(StorageLevel::LITERAL);
			constraint->setLeftExpression(new VariableExpression(tmpVarName.c_str(), StorageLevel::LITERAL));
			constraint->setRightExpression(paramExpr->popItem(i));
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

	FunctionExpression * funcExpr = new FunctionExpression(StorageLevel::LITERAL);
	funcExpr->setName(boost::locale::conv::to_utf<wchar_t>(funcName, "UTF-8").c_str());

	Expression **constraints = new Expression*[vecConstraints.size()];
	for (size_t i = 0; i < vecConstraints.size(); ++i) {
		constraints[i] = vecConstraints[i];
	}

	auto overload = new Overload;
	overload->setParameterInfos(paramInfos,paramCount);
	overload->setConstraints(constraints, vecConstraints.size());
	overload->setImplements(impls, implCount);
	funcExpr->addOverload(overload);

	paramExpr->releaseLiteral();
	RESTORE_ASSIGNABLE
	return ExpressionWrapper(funcExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper expressionWrapper = ctx->expression()->accept(this);
	ExpressionWrapper paramExpressionWrapper = ctx->parameterExpression()->accept(this);
	auto termExpr = (Expression *const&)(expressionWrapper.getExpression());
	auto paramExpr = (ParameterExpression *const&)(paramExpressionWrapper.getExpression());
	auto expr = new FunctionInvocationExpression(StorageLevel::LITERAL);
	expr->setLeftExpression(termExpr);
	expr->setParameters(paramExpr);
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	auto exprs = ctx->expression();
	for (auto &expr : exprs)
	{
		this->assignable = true; //每次新的一行都允许赋值
		this->program->pushExpression(((ExpressionWrapper)expr->accept(this)).getExpression());
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
		return ExpressionWrapper(new AssignmentExpression(left, right, StorageLevel::LITERAL));
	}
	else {
		return ExpressionWrapper(new EqualsExpression(left, right, StorageLevel::LITERAL));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE
		return ExpressionWrapper(new AssignmentExpression(left, right, StorageLevel::LITERAL));
}

antlrcpp::Any WorkScriptVisitorImpl::visitEqualsExpression(WorkScriptParser::EqualsExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(new EqualsExpression(left, right, StorageLevel::LITERAL));
}

antlrcpp::Any WorkScriptVisitorImpl::visitParameterExpression(WorkScriptParser::ParameterExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	auto items = new Expression*[subContextCount];
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
		items[i] = itemExpr;
	}
	auto expr = new ParameterExpression(items, subContextCount, StorageLevel::LITERAL);
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
//	return ExpressionWrapper(Expression *(new MemberEvaluateExpression(this->context,objExpr,memberExpr)));
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
		return ExpressionWrapper(new PlusExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
	else { //MINUS
		return ExpressionWrapper(new MinusExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
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
			return ExpressionWrapper(new DivideExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
		}
		else if (ctx->MODULUS()) {
			return ExpressionWrapper(new ModulusExpression(leftExpression,rightExpression));
		}//乘号可以省略
		else{
			return ExpressionWrapper(new MultiplyExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
		}
}

antlrcpp::Any WorkScriptVisitorImpl::visitNonSignMultiplyExpression(WorkScriptParser::NonSignMultiplyExpressionContext *ctx)
{
	ExpressionWrapper leftWrapper = ctx->numberExpression()->accept(this);
	ExpressionWrapper rightWrapper = ctx->variableExpression()->accept(this);
	auto expr = new MultiplyExpression(leftWrapper.getExpression(), rightWrapper.getExpression(), StorageLevel::LITERAL);
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
		return ExpressionWrapper(new GreaterThanExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
	else if (ctx->GREATER_THAN_EQUAL()) {
		return ExpressionWrapper(new GreaterThanEqualExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
	else if (ctx->LESS_THAN()) {
		return ExpressionWrapper(new LessThanExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
	else {
		return ExpressionWrapper(new LessThanEqualExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	auto expr = new ListExpression(StorageLevel::LITERAL);
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
	auto expr = new NegativeExpression(wrapper.getExpression(), StorageLevel::LITERAL);
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitPositiveExpression(WorkScriptParser::PositiveExpressionContext *ctx)
{
	return ctx->expression()->accept(this);
}

WorkScriptVisitorImpl::WorkScriptVisitorImpl(Program *lpProgram)
{
	this->program = lpProgram;
}

WorkScriptVisitorImpl::~WorkScriptVisitorImpl()
{
}
