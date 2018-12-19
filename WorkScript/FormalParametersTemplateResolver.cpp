#include "stdafx.h"
#include "FormalParametersTemplateResolver.h"
#include "Expression.h"
#include "ParameterTemplate.h"
#include "VariableExpression.h"
#include "BinaryCompareExpression.h"
#include "SyntaxErrorException.h"
#include "AssignmentExpression.h"
#include "OverloadBranchTemplate.h"

using namespace std;
using namespace WorkScript;

FormalParametersTemplateResolver::ResolveResult FormalParametersTemplateResolver::resolve(EXPRESSION_CTOR_FORMAL_PARAMS, SymbolTable *symbolTable, std::vector<Expression*> declParams, std::vector<Expression*> additionalConstraints)
{
	size_t paramCount = declParams.size();
	vector<ParameterTemplate*> paramTemplates(paramCount);
	vector<Type*> paramTypes(paramCount);
	vector<Expression*> constraints;

	//������������������������Ʒֱ��������б�������б���
	for (size_t i = 0; i < paramCount; ++i) {
		Expression *curExpr = declParams[i];
		Type *curType = curExpr->getType();
		paramTypes[i] = curType;

		switch (curExpr->getExpressionType())
		{
		case ExpressionType::VARIABLE_EXPRESSION: {
			VariableExpression* varExpr = (VariableExpression*)curExpr;
			ParameterTemplate *param = new ParameterTemplate(varExpr->getName(),varExpr->getType());
			paramTemplates[i] = param;
			break;
		}
		case ExpressionType::BINARY_COMPARE_EXPRESSION: {
			Expression* left = ((BinaryCompareExpression*)curExpr)->getLeftExpression();
			if (left->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				throw std::move(SyntaxErrorException(curExpr->getLocation(), L"��������Լ���󲿱���Ϊ������"));
			}
			VariableExpression *leftVar = (VariableExpression*)left;
			ParameterTemplate *param = new ParameterTemplate(leftVar->getName(), leftVar->getType());
			paramTemplates[i] = param;
			constraints.push_back(curExpr);
			break;
		}
		case ExpressionType::ASSIGNMENT_EXPRESSION: {
			AssignmentExpression* assignmentExpr = (AssignmentExpression*)curExpr;
			auto leftExpr = assignmentExpr->getLeftExpression();
			if (leftExpr->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				throw std::move(SyntaxErrorException(curExpr->getLocation(), L"����Ĭ��ֵ�󲿱���Ϊ��������"));
			}
			auto leftVar = (VariableExpression*)leftExpr;
			ParameterTemplate *param = new ParameterTemplate(leftVar->getName(), leftVar->getType(), assignmentExpr->getRightExpression());
			paramTemplates[i] = param;
			break;
		}
		default: {
			wstring tmpVarName = L"@" + to_wstring(i);
			ParameterTemplate *param = new ParameterTemplate(tmpVarName);
			paramTemplates[i] = param;
			VariableExpression *var = new VariableExpression(EXPRESSION_MEMBERS, tmpVarName, symbolTable, curType);
			BinaryCompareExpression *constraint = new BinaryCompareExpression(EXPRESSION_MEMBERS, var, curExpr, BinaryCompareExpression::EQUAL);
			constraints.push_back(constraint);
			break;
		}
		}
	}

	//����������������Ҳ���������б�
	constraints.insert(constraints.end(), additionalConstraints.begin(), additionalConstraints.end());
	return ResolveResult(paramTemplates, constraints, paramTypes);
}
