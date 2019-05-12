#include "FormalParametersResolver.h"
#include "Expression.h"
#include "ParameterDecl.h"
#include "Variable.h"
#include "BinaryCompare.h"
#include "Report.h"
#include "Assignment.h"
#include "Constant.h"

using namespace std;
using namespace WorkScript;

FormalParametersResolver::ResolveResult FormalParametersResolver::resolve(
	const ExpressionInfo &exprInfo,
	std::vector<Type*> paramDeclTypes,
	std::vector<Expression*> declParams, 
	std::vector<Expression*> additionalConstraints)
{
	auto report = exprInfo.getDebugInfo().getReport();
	size_t paramCount = declParams.size();
	vector<ParameterDecl*> params(paramCount, nullptr);
	vector<Expression*> constraints;

	//处理参数声明，将参数和限制分别放入参数列表和限制列表中
	for (size_t i = 0; i < paramCount; ++i) {
		Expression *curExpr = declParams[i];
		Type *curType = paramDeclTypes[i];

		switch (curExpr->getExpressionType())
		{
		case ExpressionType::VARIABLE: {
			Variable* varExpr = (Variable*)curExpr;
			ParameterDecl *param = new ParameterDecl(varExpr->getName(), curType);
			params[i] = param;
			break;
		}
		case ExpressionType::BINARY_COMPARE: {
			Expression* left = ((BinaryCompare*)curExpr)->getLeftExpression();
			if (left->getExpressionType() != ExpressionType::VARIABLE) {
			    report->error(SyntaxError(exprInfo.getDebugInfo(), L"函数参数约束左部必须为变量！"));
                continue;
			}
			Variable *leftVar = (Variable*)left;
			ParameterDecl *param = new ParameterDecl(leftVar->getName(), curType);
			params[i] = param;
			constraints.push_back(curExpr);
			break;
		}
		case ExpressionType::ASSIGNMENT: {
			auto* assignmentExpr = (Assignment*)curExpr;
			auto leftExpr = assignmentExpr->getLeftExpression();
			if (leftExpr->getExpressionType() != ExpressionType::VARIABLE) {
				 report->error(SyntaxError(curExpr->getDebugInfo(), L"参数默认值左部必须为参数名！"));
			}
			auto leftVar = (Variable*)leftExpr;
			auto *param = new ParameterDecl(leftVar->getName(), curType, assignmentExpr->getRightExpression());
			params[i] = param;
			break;
		}
		default: {
			wstring tmpVarName = L"@_" + to_wstring(i);
			//如果是常量，则直接获取常量的类型作为函数的参数约束
			//TODO ARRAY怎么处理
			if(!curType)
			{
				auto constantExpr = dynamic_cast<Constant*>(curExpr);
				if(constantExpr)curType = constantExpr->deduce(nullptr);
			}
			auto *param = new ParameterDecl(tmpVarName, curType);
			params[i] = param;
			auto *var = new Variable(exprInfo, tmpVarName);
			auto *constraint = new BinaryCompare(exprInfo, var, curExpr, BinaryCompare::EQUAL);
			constraints.push_back(constraint);
			break;
		}
		}
	}

	//将额外声明的限制也加入限制列表
	constraints.insert(constraints.end(), additionalConstraints.begin(), additionalConstraints.end());
	return ResolveResult(params, constraints, paramDeclTypes);
}
