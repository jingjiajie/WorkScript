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
#include "AssignmentExpression.h"
#include "ParameterExpression.h"

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
	ExpressionWrapper paramsWrapper = ctx->parameterExpression()->accept(this);
	auto params = (ParameterExpression *const&)(paramsWrapper.getExpression());
	ExpressionWrapper implWrapper = ctx->expression()->accept(this);
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
	ExpressionWrapper expressionWrapper = ctx->expression()->accept(this);
	ExpressionWrapper paramExpressionWrapper = ctx->parameterExpression()->accept(this);
	auto termExpr = (Expression *const&)(expressionWrapper.getExpression());
	auto paramExpr = (ParameterExpression *const&)(paramExpressionWrapper.getExpression());
	auto expr = new FunctionInvocationExpression(StorageLevel::LITERAL);
	expr->setLeftExpression(termExpr);
	expr->setParameters(paramExpr);
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	auto exprs = ctx->expression();
	for (auto &expr : exprs)
	{
		this->program->pushExpression(((ExpressionWrapper)expr->accept(this)).getExpression());
	}
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	return ExpressionWrapper(new AssignmentExpression(left, right, StorageLevel::LITERAL));
}

antlrcpp::Any WorkScriptVisitorImpl::visitParameterExpression(WorkScriptParser::ParameterExpressionContext *ctx)
{
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	auto expr = new ParameterExpression(subContextCount, StorageLevel::LITERAL);
	for (size_t i = 0; i < subContextCount; i++) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
		expr->setItem(i, itemExpr);
	}
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
	const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	if (ctx->PLUS()) {
		return ExpressionWrapper(new PlusExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
	else { //MINUS
		return ExpressionWrapper(new MinusExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiplyDivideExpression(WorkScriptParser::MultiplyDivideExpressionContext *ctx)
{
	const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	if (ctx->MULTIPLY()) {
		return ExpressionWrapper(new MultiplyExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
	else { //MINUS
		return ExpressionWrapper(new DivideExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	return ctx->expression()->accept(this);
}

antlrcpp::Any WorkScriptVisitorImpl::visitCompareExpression(WorkScriptParser::CompareExpressionContext *ctx)
{
	ExpressionWrapper wrapperLeft = ctx->expression()[0]->accept(this);
	ExpressionWrapper wrapperRight = ctx->expression()[1]->accept(this);
	auto leftExpression = wrapperLeft.getExpression();
	auto rightExpression = wrapperLeft.getExpression();
	if (ctx->GREATER_THAN()) {
		GreaterThanExpression * greaterThanExpr(new GreaterThanExpression(leftExpression, rightExpression, StorageLevel::LITERAL));
		return ExpressionWrapper(greaterThanExpr);
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
{
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	auto expr = new ListExpression(StorageLevel::LITERAL);
	for (size_t i = 0; i < subContextCount; i++) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
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
