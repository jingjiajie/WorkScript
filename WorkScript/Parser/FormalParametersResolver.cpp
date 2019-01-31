#include "FormalParametersResolver.h"
#include "Expression.h"
#include "Parameter.h"
#include "Variable.h"
#include "BinaryCompare.h"
#include "Report.h"
#include "Assignment.h"

using namespace std;
using namespace WorkScript;

FormalParametersResolver::ResolveResult FormalParametersResolver::resolve(
	const ExpressionInfo &exprInfo,
	InstantialContext *ctx, 
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
		bool isDeclaredType = paramDeclTypes[i] != nullptr;

		switch (curExpr->getExpressionType())
		{
		case ExpressionType::VARIABLE_EXPRESSION: {
			Variable* varExpr = (Variable*)curExpr;
			Parameter *param = new Parameter(varExpr->getName(), curType, isDeclaredType);
			params[i] = param;
			break;
		}
		case ExpressionType::BINARY_COMPARE_EXPRESSION: {
			Expression* left = ((BinaryCompare*)curExpr)->getLeftExpression();
			if (left->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
				throw std::move(SyntaxError(curExpr->getDebugInfo(), L"函数参数约束左部必须为变量！"));
			}
			Variable *leftVar = (Variable*)left;
			Parameter *param = new Parameter(leftVar->getName(), curType, isDeclaredType);
			params[i] = param;
			constraints.push_back(curExpr);
			break;
		}
		//TODO 默认参数如何处理
		//case ExpressionType::ASSIGNMENT_EXPRESSION: {
		//	Assignment* assignmentExpr = (Assignment*)curExpr;
		//	auto leftExpr = assignmentExpr->getLeftExpression();
		//	if (leftExpr->getExpressionType() != ExpressionType::VARIABLE_EXPRESSION) {
		//		throw std::move(SyntaxError(curExpr->getDebugInfo(), L"参数默认值左部必须为参数名！"));
		//	}
		//	auto leftVar = (Variable*)leftExpr;
		//	//TODO 参数默认值处理
		//	Parameter *param = new Parameter(leftVar->getName(), leftVar->getAbstractType(ctx), nullptr);
		//	params[i] = param;
		//	break;
		//}
		default: {
			wstring tmpVarName = L"@_" + to_wstring(i);
			Parameter *param = new Parameter(tmpVarName, curType, isDeclaredType);
			params[i] = param;
			Variable *var = new Variable(exprInfo, tmpVarName);
			BinaryCompare *constraint = new BinaryCompare(exprInfo, var, curExpr, BinaryCompare::EQUAL);
			constraints.push_back(constraint);
			break;
		}
		}
	}

	//将额外声明的限制也加入限制列表
	constraints.insert(constraints.end(), additionalConstraints.begin(), additionalConstraints.end());
	return ResolveResult(params, constraints, paramTypes);
}
