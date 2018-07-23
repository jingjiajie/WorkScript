#pragma once
#include <memory>
#include "Context.h"

class TypeExpression;

class SystemContext : public Context
{
public:
	SystemContext();
	void initPrintExpression(const std::shared_ptr<TypeExpression>&);
	void initObjectToString(const std::shared_ptr<TypeExpression>&);
	void initStringExpressionToString(const std::shared_ptr<TypeExpression>&);
	void initNumberExpressionTypeToString(const std::shared_ptr<TypeExpression>&);
	void initTypeExpressionToString(const std::shared_ptr<TypeExpression>&);
};