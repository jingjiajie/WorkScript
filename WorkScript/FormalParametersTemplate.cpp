#include "stdafx.h"
#include "FormalParametersTemplate.h"
#include "Expression.h"
#include "ParameterTemplate.h"
#include "VariableExpression.h"
#include "BinaryCompareExpression.h"
#include "SyntaxErrorException.h"
#include "AssignmentExpression.h"
#include "OverloadBranchTemplate.h"

using namespace std;
using namespace WorkScript;

WorkScript::FormalParametersTemplate::FormalParametersTemplate(OverloadBranchTemplate * overloadBranch, std::vector<Expression*> declParams)
{
	this->overloadBranch = overloadBranch;
	size_t paramCount = declParams.size();
	this->parameterTemplates.reserve(paramCount);

	for (size_t i = 0; i < paramCount; ++i) {
		Expression *curExpr = declParams[i];
		switch (curExpr->getExpressionType())
		{
		case ExpressionType::VARIABLE_EXPRESSION: {
			VariableExpression* varExpr = (VariableExpression*)curExpr;
			ParameterTemplate *param = new ParameterTemplate(varExpr->getName(),varExpr->getType());
			this->parameterTemplates.push_back(param);
			break;
		}
		case ExpressionType::BINARY_COMPARE_EXPRESSION: {
			Expression* left = ((BinaryCompareExpression*)curExpr)->getLeftExpression();
			if (left->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				//TODO Expression中要存储代码位置！
				throw std::move(SyntaxErrorException(-1,-1, L"函数参数约束左部必须为变量！"));
			}
			VariableExpression *leftVar = (VariableExpression*)left;
			ParameterTemplate *param = new ParameterTemplate(leftVar->getName(), leftVar->getType());
			this->parameterTemplates.push_back(param);
			this->constraints.push_back(curExpr);
			break;
		}
		case ExpressionType::ASSIGNMENT_EXPRESSION: {
			AssignmentExpression* assignmentExpr = (AssignmentExpression*)curExpr;
			auto leftExpr = assignmentExpr->getLeftExpression();
			if (leftExpr->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				//TODO Expression中要存储代码位置！
				throw std::move(SyntaxErrorException(-1, -1, L"参数默认值左部必须为参数名！"));
			}
			auto leftVar = (VariableExpression*)leftExpr;
			ParameterTemplate *param = new ParameterTemplate(leftVar->getName(), leftVar->getType(), assignmentExpr->getRightExpression());
			this->parameterTemplates.push_back(param);
			break;
		}
		default: {
				Program *program = this->overloadBranch->
				wstring tmpVarName = L"@" + to_wstring(i);
				ParameterTemplate *param = new ParameterTemplate(tmpVarName);
				this->parameterTemplates.push_back(param);
				VariableExpression *var = new VariableExpression(program, tmpVarName);
				BinaryCompareExpression *constraint = new BinaryCompareExpression(program, BinaryCompareExpression::EQUAL, var, curExpr);
				this->constraints.push_back(constraint);
			break;
		}
		}
	}
}
