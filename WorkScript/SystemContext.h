#pragma once
#include <memory>
#include "Context.h"

class TypeExpression;
class Expression;

class SystemContext : public Context
{
public:
	SystemContext();

private:
	std::shared_ptr<const Expression> toStringExpression;
	void setTypeToStringExpression(const std::shared_ptr<TypeExpression>&,const std::shared_ptr<const Expression>&);
	void initTypeToStringFunction(const std::shared_ptr<TypeExpression> &);

	void initPrintExpression(const std::shared_ptr<TypeExpression>&);
	void initObjectToString(const std::shared_ptr<TypeExpression>&);
	void initIdentifierExpressionToString(const std::shared_ptr<TypeExpression>&);
	void initStringExpressionToString(const std::shared_ptr<TypeExpression>&);
	void initNumberExpressionTypeToString(const std::shared_ptr<TypeExpression>&);
	void initTypeExpressionToString(const std::shared_ptr<TypeExpression>&);
};