#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include "WorkScriptVisitorImpl.h"
#include "IdentifierExpression.h"
#include "RelationExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "ExpressionWrapper.h"
#include "ParentheseExpression.h"
#include "MultiTermExpression.h"
#include "VariableExpression.h"
#include "TypeExpression.h"
#include "PlusExpression.h"
#include "MinusExpression.h"
#include "MemberEvaluateExpression.h"

using namespace std;

antlrcpp::Any WorkScriptVisitorImpl::visitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx)
{
	string text = ctx->NUMBER()->getText();
	double value = 0;
	int len = sscanf(text.c_str(), "%lf", &value);
	if (len == 0) {
		throw new exception(("无法识别的数字：" + text).c_str());
	}
	auto lpType = this->context->findType(TYPENAME_NUMBER_EXPRESSION,false);
	auto lpExpr = make_shared<const NumberExpression>(this->context, value);
	auto wrapper = ExpressionWrapper(lpExpr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string textWithQuotationMark = ctx->STRING()->getText();
	string text = textWithQuotationMark.substr(1, textWithQuotationMark.length() - 2);
	auto lpType = this->context->findType(TYPENAME_STRING_EXPRESSION,false);
	auto lpExpr = make_shared<const StringExpression>(this->context, text);
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitIdentifierExpression(WorkScriptParser::IdentifierExpressionContext *ctx)
{
	string identifierName = ctx->IDENTIFIER()->getText();
	//如果在关系表达式左部的括号表达式中声明的标识符，则识别为变量
	if (this->inRelationExpressionLeft && this->parenthereLevel > 0) {
		auto expr = make_shared<const VariableExpression>(this->context, identifierName);
		this->relationLeftVariables.push_back(expr);
		return ExpressionWrapper(expr);
	} //如果在关系表达式右部存在已经在左部被识别为变量的同名标识符，则右部该标识符也识别为变量
	else if (this->inRelationExpressionRight) {
		for (auto &varExpr : this->relationLeftVariables) {
			if (varExpr->getIdentifierName() == identifierName) {
				return ExpressionWrapper(varExpr);
			}
		}
		auto expr = make_shared<const IdentifierExpression>(this->context, identifierName);
		return ExpressionWrapper(expr);
	} //否则识别为标识符
	else {
		auto expr = make_shared<const IdentifierExpression>(this->context, identifierName);
		return ExpressionWrapper(expr);
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitRelationExpression(WorkScriptParser::RelationExpressionContext *ctx)
{
	this->inRelationExpressionLeft = true;
	this->relationLeftVariables.clear();
	const ExpressionWrapper &leftExpressionWrapper = ctx->polynomialExpression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	this->inRelationExpressionLeft = false;
	this->inRelationExpressionRight = true;
	const ExpressionWrapper &rightExpressionWrapper = ctx->polynomialExpression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	this->inRelationExpressionRight = false;
	auto lpExpr = make_shared<const RelationExpression>(this->context, leftExpression, rightExpression);
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	this->parenthereLevel++;
	shared_ptr<const Expression> subExpression;
	if (ctx->polynomialExpression() != nullptr) {
		const ExpressionWrapper wrapper = ctx->polynomialExpression()->accept(this);
		subExpression = wrapper.getExpression();
	}
	auto lpExpr = new ParentheseExpression(context,subExpression);
	this->parenthereLevel--;

	return ExpressionWrapper(shared_ptr<const ParentheseExpression>(lpExpr));
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiTermExpression(WorkScriptParser::MultiTermExpressionContext *ctx)
{
	vector<shared_ptr<const Expression>> subExpressions;
	for (auto &subCtx : ctx->termExpression()) {
		const ExpressionWrapper &wrapper = subCtx->accept(this);
		subExpressions.push_back(wrapper.getExpression());
	}
	auto multiValueExpession = make_shared<const MultiTermExpression>(this->context,subExpressions);
	return ExpressionWrapper(multiValueExpession);
}

antlrcpp::Any WorkScriptVisitorImpl::visitExpression(WorkScriptParser::ExpressionContext *ctx)
{
	ExpressionWrapper wrapper;
	if (ctx->polynomialExpression() != nullptr) {
		wrapper = ctx->polynomialExpression()->accept(this);
	}
	else {
		wrapper = ctx->relationExpression()->accept(this);
	}
	auto expression = wrapper.getExpression();
	this->context->pushExpression(expression);
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext *ctx)
{
	auto objExprCtx = ctx->termExpression()[0];
	ExpressionWrapper objExprWrapper = objExprCtx->accept(this);
	auto objExpr = objExprWrapper.getExpression();
	auto memberExprCtx = ctx->termExpression()[1];
	ExpressionWrapper memberExprWrapper = memberExprCtx->accept(this);
	auto memberExpr = memberExprWrapper.getExpression();
	return ExpressionWrapper(shared_ptr<const Expression>(new MemberEvaluateExpression(this->context,objExpr,memberExpr)));
}

antlrcpp::Any WorkScriptVisitorImpl::visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx)
{
	const ExpressionWrapper &leftExpressionWrapper = ctx->polynomialExpression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->polynomialExpression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	if (ctx->PLUS()) {
		return ExpressionWrapper(make_shared<const PlusExpression>(this->context, leftExpression, rightExpression));
	}
	else { //MINUS
		return ExpressionWrapper(make_shared<const MinusExpression>(this->context, leftExpression, rightExpression));
	}

}

WorkScriptVisitorImpl::WorkScriptVisitorImpl(Context *lpContext)
{
	this->context = lpContext;
}

WorkScriptVisitorImpl::~WorkScriptVisitorImpl()
{
}
