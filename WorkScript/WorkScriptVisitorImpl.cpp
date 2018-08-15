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
	auto lpExpr = make_shared<NumberExpression>(value);
	auto wrapper = ExpressionWrapper(lpExpr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string textWithQuotationMark = ctx->STRING()->getText();
	string text = textWithQuotationMark.substr(1, textWithQuotationMark.length() - 2);
	auto lpExpr = make_shared<StringExpression>(text);
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->IDENTIFIER()->getText();
	return ExpressionWrapper(shared_ptr<VariableExpression>(new VariableExpression(varName)));
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	const string funcName = ctx->IDENTIFIER()->getText();
	ExpressionWrapper paramsWrapper = ctx->listExpression()->accept(this);
	auto params = dynamic_pointer_cast<ListExpression>(paramsWrapper.getExpression());
	ExpressionWrapper implWrapper = ctx->termExpression()->accept(this);
	auto impl = dynamic_pointer_cast<TermExpression>(implWrapper.getExpression());

	vector<string> paramVarNames;
	vector<shared_ptr<TermExpression>> constraints;
	for (size_t i = 0; i < params->getCount(); i++) {
		if (params->getItem(i)->getType()->equals(TypeExpression::VARIABLE_EXPRESSION)) {
			paramVarNames.push_back(dynamic_pointer_cast<VariableExpression>(params->getItem(i))->getName());
		}
		else {
			string tmpVarName = "_" + i;
			paramVarNames.push_back(tmpVarName);
			shared_ptr<EqualExpression> constraint(new EqualExpression);
			constraint->setLeftExpression(shared_ptr<VariableExpression>(new VariableExpression(tmpVarName)));
			constraint->setRightExpression(params->getItem(i));
			constraints.push_back(constraint);
		}
	}

	shared_ptr<FunctionExpression> funcExpr(new FunctionExpression);
	funcExpr->setFunctionName(funcName);

	auto overload = shared_ptr<FunctionExpression::Overload>(new FunctionExpression::Overload);
	overload->setParameterNames(paramVarNames);
	overload->setConstraints(constraints);
	overload->setImplement(impl);
	funcExpr->addOverload(overload);
	return ExpressionWrapper(funcExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext *ctx)
{
	ExpressionWrapper termExpressionWrapper = ctx->termExpression()->accept(this);
	ExpressionWrapper paramExpressionWrapper = ctx->listExpression()->accept(this);
	auto termExpr = dynamic_pointer_cast<TermExpression>(termExpressionWrapper.getExpression());
	auto paramExpr = dynamic_pointer_cast<ListExpression>(paramExpressionWrapper.getExpression());
	shared_ptr<FunctionInvocationExpression> expr(new FunctionInvocationExpression);
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
//	return ExpressionWrapper(shared_ptr<Expression>(new MemberEvaluateExpression(this->context,objExpr,memberExpr)));
//}

antlrcpp::Any WorkScriptVisitorImpl::visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx)
{
	const ExpressionWrapper &leftExpressionWrapper = ctx->termExpression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getTermExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->termExpression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getTermExpression();
	if (ctx->PLUS()) {
		return ExpressionWrapper(make_shared<PlusExpression>(leftExpression, rightExpression));
	}
	else { //MINUS
		return ExpressionWrapper(make_shared<MinusExpression>(leftExpression, rightExpression));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiplyDivideExpression(WorkScriptParser::MultiplyDivideExpressionContext *ctx)
{
	const ExpressionWrapper &leftExpressionWrapper = ctx->termExpression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getTermExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->termExpression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getTermExpression();
	if (ctx->MULTIPLY()) {
		return ExpressionWrapper(make_shared<MultiplyExpression>(leftExpression, rightExpression));
	}
	else { //MINUS
		return ExpressionWrapper(make_shared<DivideExpression>(leftExpression, rightExpression));
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
		shared_ptr<GreaterThanExpression> greaterThanExpr(new GreaterThanExpression(leftExpression, rightExpression));
		return ExpressionWrapper(greaterThanExpr);
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
{
	auto subContext = ctx->termExpression();
	size_t subContextCount = subContext.size();
	shared_ptr<ListExpression> expr(new ListExpression);
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
