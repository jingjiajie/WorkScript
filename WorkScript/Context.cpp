#include "Context.h"
#include "TypeExpression.h"
#include "Expression.h"
using namespace std;

Context::Context()
{
	this->baseContext = nullptr;
}

Context::~Context()
{

}

void Context::pushExpression(const shared_ptr<const Expression> &expr)
{
	this->expressions.push_back(expr);
}

const std::vector<shared_ptr<const Expression>>& Context::getExpressions() const
{
	return  this->expressions;
}

void Context::addType(const std::shared_ptr<const TypeExpression> &type)
{
	this->types.push_back(type);
}

const std::shared_ptr<const TypeExpression> Context::findType(const std::string &typeName,bool isGenericType, const std::vector<std::shared_ptr<const TypeExpression>> &genericTypes) const
{
	//遍历查找本Context中的类型定义
	for (auto lpCurType : this->types) {
		//变量名不同，匹配失败
		if (lpCurType->getName() != typeName) continue;
		//泛型不同，匹配失败
		if (lpCurType->isGenericType() != isGenericType)continue;
		auto &curGenericTypes = lpCurType->getGenericTypes();
		if (curGenericTypes.size() != genericTypes.size()) continue;
		for (size_t i = 0; i < genericTypes.size(); i++) {
			if (!curGenericTypes[i]->equals(genericTypes[i])) continue;
		}
		return lpCurType;
	}
	//如果找不到，进入父级Context查找
	if (this->baseContext == nullptr) return nullptr;
	return this->baseContext->findType(typeName,isGenericType);
}

Context * Context::getBaseContext() const
{
	return this->baseContext;
}

void Context::setBaseContext(Context *const ctx)
{
	this->baseContext = ctx;
}

const std::shared_ptr<const Expression> Context::getCurrentExpression() const
{
	if (this->baseContext != nullptr) {
		return this->baseContext->getCurrentExpression();
	}
	else {
		return this->currentExpression;
	}
}

void Context::setCurrentExpression(const std::shared_ptr<const Expression> &expr)
{
	if (this->baseContext != nullptr) {
		this->baseContext->setCurrentExpression(expr);
	}
	else {
		this->currentExpression = expr;
	}
}
