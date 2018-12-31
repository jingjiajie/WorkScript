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

FormalParametersResolver::ResolveResult FormalParametersResolver::resolve(const ExpressionInfo &exprInfo, SymbolTable *abstractSymbolTable, std::vector<Expression*> declParams, std::vector<Expression*> additionalConstraints)
{
	size_t paramCount = declParams.size();
	vector<Parameter*> paramTemplates(paramCount);
	vector<Type*> paramTypes(paramCount);
	vector<Expression*> constraints;
	InstantializeContext ctx(abstractSymbolTable);

	//处理参数声明，将参数和限制分别放入参数列表和限制列表中
	for (size_t i = 0; i < paramCount; ++i) {
		Expression *curExpr = declParams[i];
		Type *curType = curExpr->getType(&ctx);
		paramTypes[i] = curType;

		switch (curExpr->getExpressionType())
		{
		case ExpressionType::VARIABLE_EXPRESSION: {
			VariableExpression* varExpr = (VariableExpression*)curExpr;
			Parameter *param = new Parameter(varExpr->getName(),varExpr->getType(&ctx));
			paramTemplates[i] = param;
			break;
		}
		case ExpressionType::BINARY_COMPARE_EXPRESSION: {
			Expression* left = ((BinaryCompareExpression*)curExpr)->getLeftExpression();
			if (left->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				throw std::move(SyntaxErrorException(curExpr->getLocation(), L"函数参数约束左部必须为变量！"));
			}
			VariableExpression *leftVar = (VariableExpression*)left;
			Parameter *param = new Parameter(leftVar->getName(), leftVar->getType(&ctx));
			paramTemplates[i] = param;
			constraints.push_back(curExpr);
			break;
		}
		case ExpressionType::ASSIGNMENT_EXPRESSION: {
			AssignmentExpression* assignmentExpr = (AssignmentExpression*)curExpr;
			auto leftExpr = assignmentExpr->getLeftExpression();
			if (leftExpr->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				throw std::move(SyntaxErrorException(curExpr->getLocation(), L"参数默认值左部必须为参数名！"));
			}
			auto leftVar = (VariableExpression*)leftExpr;
			//TODO 参数默认值处理
			Parameter *param = new Parameter(leftVar->getName(), leftVar->getType(&ctx), nullptr);
			paramTemplates[i] = param;
			break;
		}
		default: {
			wstring tmpVarName = L"@" + to_wstring(i);
			Parameter *param = new Parameter(tmpVarName, curType);
			paramTemplates[i] = param;
			VariableExpression *var = new VariableExpression(exprInfo, tmpVarName);
			BinaryCompareExpression *constraint = new BinaryCompareExpression(exprInfo, var, curExpr, BinaryCompareExpression::EQUAL);
			constraints.push_back(constraint);
			break;
		}
		}
	}

	//将额外声明的限制也加入限制列表
	constraints.insert(constraints.end(), additionalConstraints.begin(), additionalConstraints.end());
	return ResolveResult(paramTemplates, constraints, paramTypes);
}
