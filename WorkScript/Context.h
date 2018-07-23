#pragma once

#include <iostream>
#include <vector>

class TypeExpression;
class Expression;

class Context
{
public:
	Context();
	virtual ~Context();

	void pushExpression(const std::shared_ptr<const Expression> &);
	const std::vector<std::shared_ptr<const Expression>>& getExpressions() const;

	void addType(const std::shared_ptr<const TypeExpression>&);
	const std::shared_ptr<const TypeExpression> findType(const std::string &typeName,bool isGenericType, const std::vector<std::shared_ptr<const TypeExpression>> &genericTypes = std::vector<std::shared_ptr<const TypeExpression>>()) const;

	Context * getBaseContext() const;
	void setBaseContext(Context *const);

	const std::shared_ptr<const Expression> getCurrentExpression() const;
	void setCurrentExpression(const std::shared_ptr<const Expression> &);
protected:
	Context * baseContext = nullptr;
	std::vector<std::shared_ptr<const Expression>> expressions;
	std::vector<std::shared_ptr<const TypeExpression>> types;
	std::shared_ptr<const Expression> currentExpression;
};