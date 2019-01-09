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

	//������������������������Ʒֱ��������б�������б���
	for (size_t i = 0; i < paramCount; ++i) {
		Expression *curExpr = declParams[i];
		if (paramDeclTypes[i]) {
			paramTypes[i] = paramDeclTypes[i];
		}
		else {
			paramTypes[i] = curExpr->getType(ctx);
		}
		Type *curType = paramTypes[i];
		bool isDeclaredType = paramDeclTypes[i] != nullptr;

		switch (curExpr->getExpressionType())
		{
		case ExpressionType::VARIABLE_EXPRESSION: {
			VariableExpression* varExpr = (VariableExpression*)curExpr;
			Parameter *param = new Parameter(varExpr->getName(), curType, isDeclaredType);
			params[i] = param;
			break;
		}
		case ExpressionType::BINARY_COMPARE_EXPRESSION: {
			Expression* left = ((BinaryCompareExpression*)curExpr)->getLeftExpression();
			if (left->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				throw std::move(SyntaxErrorException(curExpr->getLocation(), L"��������Լ���󲿱���Ϊ������"));
			}
			VariableExpression *leftVar = (VariableExpression*)left;
			Parameter *param = new Parameter(leftVar->getName(), curType, isDeclaredType);
			params[i] = param;
			constraints.push_back(curExpr);
			break;
		}
		//TODO Ĭ�ϲ�����δ���
		//case ExpressionType::ASSIGNMENT_EXPRESSION: {
		//	AssignmentExpression* assignmentExpr = (AssignmentExpression*)curExpr;
		//	auto leftExpr = assignmentExpr->getLeftExpression();
		//	if (leftExpr->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
		//		throw std::move(SyntaxErrorException(curExpr->getLocation(), L"����Ĭ��ֵ�󲿱���Ϊ��������"));
		//	}
		//	auto leftVar = (VariableExpression*)leftExpr;
		//	//TODO ����Ĭ��ֵ����
		//	Parameter *param = new Parameter(leftVar->getName(), leftVar->getType(ctx), nullptr);
		//	params[i] = param;
		//	break;
		//}
		default: {
			wstring tmpVarName = L"@_" + to_wstring(i);
			Parameter *param = new Parameter(tmpVarName, curType, isDeclaredType);
			params[i] = param;
			VariableExpression *var = new VariableExpression(exprInfo, tmpVarName);
			BinaryCompareExpression *constraint = new BinaryCompareExpression(exprInfo, var, curExpr, BinaryCompareExpression::EQUAL);
			constraints.push_back(constraint);
			break;
		}
		}
	}

	//����������������Ҳ���������б�
	constraints.insert(constraints.end(), additionalConstraints.begin(), additionalConstraints.end());
	return ResolveResult(params, constraints, paramTypes);
}
