#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include "WorkScriptVisitorImpl.h"
#include "StringExpression.h"
#include "NumberExpression.h"
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
#include "EqualExpression.h"

using namespace std;

antlrcpp::Any WorkScriptVisitorImpl::visitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx)
{
	string text = ctx->NUMBER()->getText();
	double value = 0;
	int len = sscanf(text.c_str(), "%lf", &value);
	if (len == 0) {
		throw new exception(("无法识别的数字：" + text).c_str());
	}
	auto lpExpr = NumberExpression::newInstance(value, StorageLevel::LITERAL);
	auto wrapper = ExpressionWrapper(lpExpr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string textWithQuotationMark = ctx->STRING()->getText();
	string text = textWithQuotationMark.substr(1, textWithQuotationMark.length() - 2);
	auto lpExpr = StringExpression::newInstance(text.c_str(), StorageLevel::LITERAL);
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->IDENTIFIER()->getText();
	return ExpressionWrapper(new VariableExpression(varName.c_str(), StorageLevel::LITERAL));
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	const string funcName = ctx->IDENTIFIER()->getText();
	ExpressionWrapper paramsWrapper = ctx->listExpression()->accept(this);
	auto params = (ListExpression *const&)(paramsWrapper.getExpression());
	ExpressionWrapper implWrapper = ctx->termExpression()->accept(this);
	auto impl = (Expression *const&)(implWrapper.getExpression());

	vector<string> paramVarNames;
	vector<Expression *> vecConstraints;
	for (size_t i = 0; i < params->getCount(); i++) {
		if (params->getItem(i)->getType(nullptr)->equals(nullptr, &TypeExpression::VARIABLE_EXPRESSION)) {
			paramVarNames.push_back(((VariableExpression *const)params->getItem(i))->getName());
		}
		else {
			string tmpVarName = "_" + to_string(i);
			paramVarNames.push_back(tmpVarName);
			EqualExpression * constraint(new EqualExpression(StorageLevel::LITERAL));
			constraint->setLeftExpression(new VariableExpression(tmpVarName.c_str(), StorageLevel::LITERAL));
			constraint->setRightExpression(params->getItem(i));
			vecConstraints.push_back(constraint);
		}
	}

	FunctionExpression * funcExpr = new FunctionExpression(StorageLevel::LITERAL);
	funcExpr->setName(funcName.c_str());

	Expression **constraints = new Expression*[vecConstraints.size()];
	for (size_t i = 0; i < vecConstraints.size(); i++) {
		constraints[i] = vecConstraints[i];
	}

	auto overload = new FunctionExpression::Overload;
	overload->setParameterNames(paramVarNames);
	overload->setConstraints(constraints, vecConstraints.size());
	overload->setImplement(impl);
	funcExpr->addOverload(overload);
	return ExpressionWrapper(funcExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext *ctx)
{
	ExpressionWrapper termExpressionWrapper = ctx->termExpression()->accept(this);
	ExpressionWrapper paramExpressionWrapper = ctx->listExpression()->accept(this);
	auto termExpr = (Expression *const&)(termExpressionWrapper.getExpression());
	auto paramExpr = (ListExpression *const&)(paramExpressionWrapper.getExpression());
	FunctionInvocationExpression * expr(new FunctionInvocationExpression(StorageLevel::LITERAL));
	expr->setLeftExpression(termExpr);
	expr->setParameters(paramExpr);
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitExpression(WorkScriptParser::ExpressionContext *ctx)
{
	ExpressionWrapper wrapper = ctx->termExpression()->accept(this);
	this->program->pushExpression(wrapper.getExpression());
	return nullptr;
}

//antlrcpp::Any WorkScriptVisitorImpl::visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext *ctx)
//{
//	auto objExprCtx = ctx->termExpression()[0];
//	ExpressionWrapper objExprWrapper = objExprCtx->accept(this);
//	auto objExpr = objExprWrapper.getExpression();
//	auto memberExprCtx = ctx->termExpression()[1];
//	ExpressionWrapper memberExprWrapper = memberExprCtx->accept(this);
//	auto memberExpr = memberExprWrapper.getExpression();
//	return ExpressionWrapper(Expression *(new MemberEvaluateExpression(this->context,objExpr,memberExpr)));
//}

antlrcpp::Any WorkScriptVisitorImpl::visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx)
{
	const ExpressionWrapper &leftExpressionWrapper = ctx->termExpression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getTermExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->termExpression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getTermExpression();
	if (ctx->PLUS()) {
		return ExpressionWrapper(new PlusExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
	else { //MINUS
		return ExpressionWrapper(new MinusExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiplyDivideExpression(WorkScriptParser::MultiplyDivideExpressionContext *ctx)
{
	const ExpressionWrapper &leftExpressionWrapper = ctx->termExpression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getTermExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->termExpression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getTermExpression();
	if (ctx->MULTIPLY()) {
		return ExpressionWrapper(new MultiplyExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
	else { //MINUS
		return ExpressionWrapper(new DivideExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	return ctx->termExpression()->accept(this);
}

antlrcpp::Any WorkScriptVisitorImpl::visitCompareExpression(WorkScriptParser::CompareExpressionContext *ctx)
{
	ExpressionWrapper wrapperLeft = ctx->termExpression()[0]->accept(this);
	ExpressionWrapper wrapperRight = ctx->termExpression()[1]->accept(this);
	auto leftExpression = wrapperLeft.getTermExpression();
	auto rightExpression = wrapperLeft.getTermExpression();
	if (ctx->GREATER_THAN()) {
		GreaterThanExpression * greaterThanExpr(new GreaterThanExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
		return ExpressionWrapper(greaterThanExpr);
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
{
	auto subContext = ctx->termExpression();
	size_t subContextCount = subContext.size();
	ListExpression * expr(new ListExpression(StorageLevel::LITERAL));
	for (size_t i = 0; i < subContextCount; i++) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getTermExpression();
		expr->addItem(itemExpr);
	}
	return ExpressionWrapper(expr);
}

WorkScriptVisitorImpl::WorkScriptVisitorImpl(Program *lpProgram)
{
	this->program = lpProgram;
}

WorkScriptVisitorImpl::~WorkScriptVisitorImpl()
{
}
