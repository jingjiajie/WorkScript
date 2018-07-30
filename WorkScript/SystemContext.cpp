#include <memory>
#include <cmath>
#include "SystemContext.h"
#include "TypeExpression.h"
#include "TypeMemberExpression.h"
#include "RelationExpression.h"
#include "PolynomialExpression.h"
#include "IdentifierExpression.h"
#include "GetTypeExpression.h"
#include "ParentheseExpression.h"
#include "MemberEvaluateExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "ThisExpression.h"
#include "VariableExpression.h"
#include "PrintExpression.h"
#include "ExecuteCppCodeExpression.h"
#include "FunctionExpression.h"

using namespace std;

SystemContext::SystemContext()
{
	vector<shared_ptr<TypeExpression>> types;
	auto objectType = SPTYPEEXPRESSION(new TypeExpression(this, nullptr))->setName(TYPENAME_OBJECT);
	objectType->setBaseType(objectType);

	auto expressionType = SPTYPEEXPRESSION (new TypeExpression(this, objectType))->setName(TYPENAME_EXPRESSION);
	auto typeExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_TYPE_EXPRESSION);
	auto typeMemberExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_TYPE_MEMBER_EXPRESSION);
	auto relationExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_RELATION_EXPRESSION);
	auto valueExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_VALUE_EXPRESSION);
	auto polynomialExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_POLYNOMIAL_EXPRESSION);
	auto functionExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, polynomialExpressionType))->setName(TYPENAME_FUNCTION_EXPRESSION);
	auto termExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_TERM_EXPRESSION);
	auto greaterThanExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_GREATER_THAN_EXPRESSION);
	auto greaterThanEqualExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_GREATER_THAN_EQUAL_EXPRESSION);
	auto lessThanExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_LESS_THAN_EXPRESSION);
	auto lessThanEqualExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_LESS_THAN_EQUAL_EXPRESSION);
	auto plusExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_PLUS_EXPRESSION);
	auto minusExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_MINUS_EXPRESSION);
	auto multiplyExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_MULTIPLY_EXPRESSION);
	auto divideExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_DIVIDE_EXPRESSION);
	auto executeCppCodeExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_EXECUTE_CPP_CODE_EXPRESSION);
	auto printExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_PRINT_EXPRESSION);
	auto thisExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_THIS_EXPRESSION);
	auto memberEvaluateExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_MEMBER_EVALUATE_EXPRESSION);
	auto getTypeNameExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_GET_TYPE_EXPRESSION);
	auto identifierExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_IDENTIFIER_EXPRESSION);
	auto variableExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, identifierExpressionType))->setName(TYPENAME_VARIABLE_EXPRESSION);
	auto parentheseExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_PARENTHESE_EXPRESSION);
	auto stringExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_STRING_EXPRESSION);
	auto numberExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_NUMBER_EXPRESSION);
	auto booleanExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, termExpressionType))->setName(TYPENAME_BOOLEAN_EXPRESSION);

	types.push_back(objectType);
	types.push_back(expressionType);
	types.push_back(typeExpressionType);
	types.push_back(typeMemberExpressionType);
	types.push_back(relationExpressionType);
	types.push_back(polynomialExpressionType);
	types.push_back(functionExpressionType);
	types.push_back(greaterThanExpressionType);
	types.push_back(greaterThanEqualExpressionType);
	types.push_back(lessThanExpressionType);
	types.push_back(lessThanEqualExpressionType);
	types.push_back(plusExpressionType);
	types.push_back(minusExpressionType);
	types.push_back(multiplyExpressionType);
	types.push_back(divideExpressionType);
	types.push_back(executeCppCodeExpressionType);
	types.push_back(printExpressionType);
	types.push_back(thisExpressionType);
	types.push_back(memberEvaluateExpressionType);
	types.push_back(getTypeNameExpressionType);
	types.push_back(identifierExpressionType);
	types.push_back(variableExpressionType);
	types.push_back(parentheseExpressionType);
	types.push_back(stringExpressionType);
	types.push_back(numberExpressionType);
	types.push_back(booleanExpressionType);

	for (auto &type : types) {
		this->addType(type);
	}

	this->toStringExpression = SPCEXPRESSION(new PolynomialExpression(this, { SPCEXPRESSION(new IdentifierExpression(this, "toString")), SPCEXPRESSION(new ParentheseExpression(this, nullptr)) }));


	this->initObjectToString(objectType);
	this->initPrintExpression(printExpressionType);

	for (auto &type : types) {
		this->initTypeToStringFunction(type);
	}

  /*this->initTypeExpressionToString(typeExpressionType);
	this->initStringExpressionToString(stringExpressionType);
	this->initNumberExpressionTypeToString(numberExpressionType);
	this->initIdentifierExpressionToString(identifierExpressionType);*/
}

void SystemContext::initObjectToString(const shared_ptr<TypeExpression> &objectType)
{
	//设置Object的toString()函数
	SPCEXPRESSION objectToStringRight(shared_ptr<const MemberEvaluateExpression>(new MemberEvaluateExpression(this, shared_ptr<const GetTypeExpression>(new GetTypeExpression(this, SPCEXPRESSION(new ThisExpression(this)))), toStringExpression)));
	this->setTypeToStringExpression(objectType,objectToStringRight);
}

void SystemContext::initIdentifierExpressionToString(const std::shared_ptr<TypeExpression> &identifierType)
{
	//重写TypeExpression的toString()函数
	auto toStringRight = SPCEXPRESSION(new ExecuteCppCodeExpression(this, [this](const ExpressionBind &expressionBind) {
		SPCEXPRESSION thisExpression(new ThisExpression(this));
		auto identifierExpression = dynamic_pointer_cast<const IdentifierExpression>(thisExpression->evaluate(expressionBind));
		SPCEXPRESSION resultStringExpr(new StringExpression(this, identifierExpression->getIdentifierName()));
		return resultStringExpr;
	}));
	this->setTypeToStringExpression(identifierType, toStringRight);
}

void SystemContext::initStringExpressionToString(const shared_ptr<TypeExpression> &stringExpressionType)
{
	//重写StringExpression的toString()函数
	auto toStringRight = SPCEXPRESSION(new ExecuteCppCodeExpression(this, [this](const ExpressionBind &expressionBind) {
		SPCEXPRESSION thisExpression(new ThisExpression(this));
		return thisExpression->evaluate(expressionBind);
	}));
	this->setTypeToStringExpression(stringExpressionType,toStringRight);
}



void SystemContext::initNumberExpressionTypeToString(const shared_ptr<TypeExpression> &numberExpressionType)
{
	//重写NumberExpression的toString()函数
	auto toStringRight = SPCEXPRESSION(new ExecuteCppCodeExpression(this, [this](const ExpressionBind &expressionBind) {
		SPCEXPRESSION thisExpression(new ThisExpression(this));
		auto numberExpr = dynamic_pointer_cast<const NumberExpression>(thisExpression->evaluate(expressionBind));
		double number = numberExpr->getValue();
		string numberStr;
		if (fabs(number - (int)number) < 1e-8) {
			numberStr = to_string((int)number);
		}
		else {
			numberStr = to_string(number);
		}
		auto numberStrExpr = SPCEXPRESSION(new StringExpression(this, numberStr));
		return numberStrExpr;
	}));
	this->setTypeToStringExpression(numberExpressionType,toStringRight);
}

void SystemContext::initTypeExpressionToString(const shared_ptr<TypeExpression> &typeExpressionType)
{
	//重写TypeExpression的toString()函数
	
	auto toStringRight = SPCEXPRESSION(new ExecuteCppCodeExpression(this, [this](const ExpressionBind &expressionBind) {
		SPCEXPRESSION thisExpression(new ThisExpression(this));
		auto typeExpr = dynamic_pointer_cast<const TypeExpression>(thisExpression->evaluate(expressionBind));
		auto typeNameExpr = SPCEXPRESSION(new StringExpression(this, typeExpr->getName()));
		return typeNameExpr;
	}));
	this->setTypeToStringExpression(typeExpressionType,toStringRight);
}

void SystemContext::setTypeToStringExpression(const std::shared_ptr<TypeExpression> &typeExpr, const shared_ptr<const Expression> &toStringRightExpr) 
{
	shared_ptr<const RelationExpression> relation(new RelationExpression(this, toStringExpression, toStringRightExpr));
	auto memberExpression = shared_ptr<const TypeMemberExpression>(new TypeMemberExpression(this, typeExpr, Authority::PUBLIC, relation));
	typeExpr->addMemberExpression(memberExpression);
}

void SystemContext::initTypeToStringFunction(const std::shared_ptr<TypeExpression> &typeExpr)
{
	auto toStringRight = SPCEXPRESSION(new ExecuteCppCodeExpression(this, [this](const ExpressionBind &expressionBind) {
		SPCEXPRESSION thisExpression(new ThisExpression(this));
		auto expr = dynamic_pointer_cast<const Expression>(thisExpression->evaluate(expressionBind));
		return SPCEXPRESSION(new StringExpression(this, expr->toString()));
	}));
	shared_ptr<const RelationExpression> relation(new RelationExpression(this, toStringExpression, toStringRight));
	auto memberExpression = shared_ptr<const TypeMemberExpression>(new TypeMemberExpression(this, typeExpr, Authority::PUBLIC, relation));
	typeExpr->addMemberExpression(memberExpression);
}

//初始化print函数
void SystemContext::initPrintExpression(const shared_ptr<TypeExpression> &printExpressionType)
{
	Context *const &context = this;
	shared_ptr<const VariableExpression> varExpr(new VariableExpression(context, "x"));
	shared_ptr<const IdentifierExpression> printIdentifierExpr(new IdentifierExpression(context, "print"));
	shared_ptr<const ParentheseExpression> parentheseExpr(new ParentheseExpression(context, varExpr));
	shared_ptr<const FunctionExpression> printFunctionExpr(new FunctionExpression(context, true, { printIdentifierExpr ,parentheseExpr }));

	shared_ptr<const RelationExpression> relation(new RelationExpression(context, printFunctionExpr,shared_ptr<const PrintExpression>(new PrintExpression(context, varExpr))));
	context->pushExpression(relation);
}