#include "stdafx.h"
#include "FormalParametersResolver.h"
#include "Expression.h"
#include "Parameter.h"
#include "VariableExpression.h"
#include "BinaryCompareExpression.h"
#include "SyntaxErrorException.h"
#include "AssignmentExpression.h"

using namespace std;
using namespace WorkScript;

FormalParametersResolver::ResolveResult FormalParametersResolver::resolve(
	const ExpressionInfo &exprInfo,
	InstantializeContext *ctx, 
	std::vector<Type*> paramDeclTypes,
	std::vector<Expression*> declParams, 
	std::vector<Expression*> additionalConstraints)
{
	size_t paramCount = declParams.size();
	vector<Parameter*> params(paramCount, nullptr);
	vector<Type*> paramTypes(paramCount, nullptr);
	vector<Expression*> constraints;

	//处理参数声明，将参数和限制分别放入参数列表和限制列表中
	for (size_t i = 0; i < paramCount; ++i) {
		Expression *curExpr = declParams[i];
		if (paramDeclTypes[i]) {
			paramTypes[i] = paramDeclTypes[i];
		}
		else {
			paramTypes[i] = curExpr->getType(ctx);
		}
		Type *curType = paramTypes[i];

		switch (curExpr->getExpressionType())
		{
		case ExpressionType::VARIABLE_EXPRESSION: {
			VariableExpression* varExpr = (VariableExpression*)curExpr;
			Parameter *param = new Parameter(varExpr->getName(), curType);
			params[i] = param;
			break;
		}
		case ExpressionType::BINARY_COMPARE_EXPRESSION: {
			Expression* left = ((BinaryCompareExpression*)curExpr)->getLeftExpression();
			if (left->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				throw std::move(SyntaxErrorException(curExpr->getLocation(), L"函数参数约束左部必须为变量！"));
			}
			VariableExpression *leftVar = (VariableExpression*)left;
			Parameter *param = new Parameter(leftVar->getName(), curType);
			params[i] = param;
			constraints.push_back(curExpr);
			break;
		}
		//TODO 默认参数如何处理
		//case ExpressionType::ASSIGNMENT_EXPRESSION: {
		//	AssignmentExpression* assignmentExpr = (AssignmentExpression*)curExpr;
		//	auto leftExpr = assignmentExpr->getLeftExpression();
		//	if (leftExpr->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
		//		throw std::move(SyntaxErrorException(curExpr->getLocation(), L"参数默认值左部必须为参数名！"));
		//	}
		//	auto leftVar = (VariableExpression*)leftExpr;
		//	//TODO 参数默认值处理
		//	Parameter *param = new Parameter(leftVar->getName(), leftVar->getType(ctx), nullptr);
		//	params[i] = param;
		//	break;
		//}
		default: {
			wstring tmpVarName = L"@_" + to_wstring(i);
			Parameter *param = new Parameter(tmpVarName, curType);
			params[i] = param;
			VariableExpression *var = new VariableExpression(exprInfo, tmpVarName);
			BinaryCompareExpression *constraint = new BinaryCompareExpression(exprInfo, var, curExpr, BinaryCompareExpression::EQUAL);
			constraints.push_back(constraint);
			break;
		}
		}
	}

	//将额外声明的限制也加入限制列表
	constraints.insert(constraints.end(), additionalConstraints.begin(), additionalConstraints.end());
	return ResolveResult(params, constraints, paramTypes);
}
