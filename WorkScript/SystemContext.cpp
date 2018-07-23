#include <memory>
#include <cmath>
#include "SystemContext.h"
#include "TypeExpression.h"
#include "TypeMemberExpression.h"
#include "RelationExpression.h"
#include "MultiTermExpression.h"
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

using namespace std;

SystemContext::SystemContext()
{
	auto objectType = SPTYPEEXPRESSION(new TypeExpression(this, nullptr))->setName(TYPENAME_OBJECT);
	objectType->setBaseType(objectType);

	auto expressionType = SPTYPEEXPRESSION (new TypeExpression(this, objectType))->setName(TYPENAME_EXPRESSION);
	auto typeExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_TYPE_EXPRESSION);
	auto typeMemberExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_TYPE_MEMBER_EXPRESSION);
	auto relationExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_RELATION_EXPRESSION);
	auto valueExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_VALUE_EXPRESSION);
	auto plusExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_PLUS_EXPRESSION);
	auto executeCppCodeExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_EXECUTE_CPP_CODE_EXPRESSION);
	auto printExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_PRINT_EXPRESSION);
	auto thisExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_THIS_EXPRESSION);
	auto memberEvaluateExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_MEMBER_EVALUATE_EXPRESSION);
	auto getTypeNameExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, expressionType))->setName(TYPENAME_GET_TYPE_EXPRESSION);
	auto multiValueExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_MULTI_TERM_EXPRESSION);
	auto identifierExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_IDENTIFIER_EXPRESSION);
	auto variableExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, identifierExpressionType))->setName(TYPENAME_VARIABLE_EXPRESSION);
	auto parentheseExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_PARENTHESE_EXPRESSION);
	auto rawValueExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, valueExpressionType))->setName(TYPENAME_RAW_VALUE_EXPRESSION);
	auto stringExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, rawValueExpressionType))->setName(TYPENAME_STRING_EXPRESSION);
	auto numberExpressionType = SPTYPEEXPRESSION(new TypeExpression(this, rawValueExpressionType))->setName(TYPENAME_NUMBER_EXPRESSION);

	this->addType(objectType);
	this->addType(expressionType);
	this->addType(typeExpressionType);
	this->addType(typeMemberExpressionType);
	this->addType(relationExpressionType);
	//this->addType(EvaluableExpressionType);
	this->addType(valueExpressionType);
	this->addType(plusExpressionType);
	this->addType(executeCppCodeExpressionType);
	this->addType(printExpressionType);
	this->addType(thisExpressionType);
	this->addType(memberEvaluateExpressionType);
	this->addType(multiValueExpressionType);
	this->addType(getTypeNameExpressionType);
	this->addType(rawValueExpressionType);
	this->addType(identifierExpressionType);
	this->addType(variableExpressionType);
	this->addType(parentheseExpressionType);
	this->addType(stringExpressionType);
	this->addType(numberExpressionType);

	this->initObjectToString(objectType);
	this->initTypeExpressionToString(typeExpressionType);
	this->initStringExpressionToString(stringExpressionType);
	this->initNumberExpressionTypeToString(numberExpressionType);
	this->initPrintExpression(printExpressionType);
}

void SystemContext::initObjectToString(const shared_ptr<TypeExpression> &objectType)
{
	//设置Object的toString()函数
	SPCEXPRESSION toStringLeft(new MultiTermExpression(this, { SPCEXPRESSION(new IdentifierExpression(this, "toString")), SPCEXPRESSION(new ParentheseExpression(this, nullptr)) }));
	SPCEXPRESSION objectToStringRight(shared_ptr<const MemberEvaluateExpression>(new MemberEvaluateExpression(this, shared_ptr<const GetTypeExpression>(new GetTypeExpression(this, SPCEXPRESSION(new ThisExpression(this)))), toStringLeft)));
	SPCEXPRESSION objectToStringRelation(new RelationExpression(this, toStringLeft, objectToStringRight));
	SPCTYPEMEMBEREXPRESSION objectToStringMember(
		new const TypeMemberExpression(
			this,
			objectType,
			Authority::PUBLIC,
			objectToStringRelation));
	objectType->addMemberExpression(objectToStringMember);
}

void SystemContext::initStringExpressionToString(const shared_ptr<TypeExpression> &stringExpressionType)
{
	//重写TypeExpression的toString()函数
	SPCEXPRESSION toStringLeft(new MultiTermExpression(this, { SPCEXPRESSION(new IdentifierExpression(this, "toString")), SPCEXPRESSION(new ParentheseExpression(this, nullptr)) }));
	auto toStringRight = SPCEXPRESSION(new ExecuteCppCodeExpression(this, [this](const ExpressionBind &expressionBind) {
		SPCEXPRESSION thisExpression(new ThisExpression(this));
		return thisExpression->evaluate(expressionBind);
	}));
	shared_ptr<const RelationExpression> relation(new RelationExpression(this, toStringLeft, toStringRight));
	auto memberExpression = shared_ptr<const TypeMemberExpression>(new TypeMemberExpression(this, stringExpressionType, Authority::PUBLIC, relation));
	stringExpressionType->addMemberExpression(memberExpression);
}

void SystemContext::initNumberExpressionTypeToString(const shared_ptr<TypeExpression> &numberExpressionType)
{
	//重写NumberExpression的toString()函数
	SPCEXPRESSION toStringLeft(new MultiTermExpression(this, { SPCEXPRESSION(new IdentifierExpression(this, "toString")), SPCEXPRESSION(new ParentheseExpression(this, nullptr)) }));
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
	shared_ptr<const RelationExpression> relation(new RelationExpression(this, toStringLeft, toStringRight));
	auto memberExpression = shared_ptr<const TypeMemberExpression>(new TypeMemberExpression(this, numberExpressionType, Authority::PUBLIC, relation));
	numberExpressionType->addMemberExpression(memberExpression);
}

void SystemContext::initTypeExpressionToString(const shared_ptr<TypeExpression> &typeExpressionType)
{
	//重写TypeExpression的toString()函数
	SPCEXPRESSION toStringLeft(new MultiTermExpression(this, { SPCEXPRESSION(new IdentifierExpression(this, "toString")), SPCEXPRESSION(new ParentheseExpression(this, nullptr)) }));
	auto toStringRight = SPCEXPRESSION(new ExecuteCppCodeExpression(this, [this](const ExpressionBind &expressionBind) {
		SPCEXPRESSION thisExpression(new ThisExpression(this));
		auto typeExpr = dynamic_pointer_cast<const TypeExpression>(thisExpression->evaluate(expressionBind));
		auto typeNameExpr = SPCEXPRESSION(new StringExpression(this, typeExpr->getName()));
		return typeNameExpr;
	}));
	shared_ptr<const RelationExpression> relation(new RelationExpression(this, toStringLeft, toStringRight));
	auto memberExpression = shared_ptr<const TypeMemberExpression>(new TypeMemberExpression(this, typeExpressionType, Authority::PUBLIC, relation));
	typeExpressionType->addMemberExpression(memberExpression);
}

//初始化print函数
void SystemContext::initPrintExpression(const shared_ptr<TypeExpression> &printExpressionType)
{
	Context *const &context = this;
	shared_ptr<const VariableExpression> varExpr(new VariableExpression(context,"x"));
	shared_ptr<const IdentifierExpression> printIdentifierExpr(new IdentifierExpression(context,"print"));
	shared_ptr<const ParentheseExpression> parentheseExpr(new ParentheseExpression(context,varExpr));
	shared_ptr<const MultiTermExpression> printFunctionExpr(new MultiTermExpression(context, { printIdentifierExpr ,parentheseExpr }));

	shared_ptr<const RelationExpression> relation(new RelationExpression(context, printFunctionExpr, shared_ptr<const PrintExpression>(new PrintExpression(context, varExpr))));
	context->pushExpression(relation);
}