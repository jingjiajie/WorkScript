#pragma once
#include<vector>
#include<string>
#include<memory>

class Expression;

class ExpressionBind
{
public:
	ExpressionBind();
	ExpressionBind(const ExpressionBind&);
	const ExpressionBind& operator=(const ExpressionBind &);

	void addExpressionMap(const std::shared_ptr<const Expression> &sourceExpression,const std::shared_ptr<const Expression> &mappedExpression);
	const std::shared_ptr<const Expression> getMappedExpression(const std::shared_ptr<const Expression>&) const;
protected:
	std::vector<std::pair<std::shared_ptr<const Expression>,std::shared_ptr< const Expression>>> expressionMap;
};