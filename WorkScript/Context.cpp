#include "Context.h"
#include "TypeExpression.h"
#include "FunctionExpression.h"
#include "Expression.h"
#include "FunctionInvocationExpression.h"
#include "VariableExpression.h"

using namespace std;

Context::Context(size_t localVariableCount)
{
	this->baseContext = nullptr;
	this->localVariables = new shared_ptr<TermExpression>[localVariableCount];
}

Context::Context(Context * baseContext, size_t localVariableCount)
	:Context(localVariableCount)
{
	this->setBaseContext(baseContext);
}

Context::~Context()
{
	delete []this->localVariables;
}

void Context::addType(const std::shared_ptr<TypeExpression> &type)
{
	this->types.push_back(type);
}

const std::shared_ptr<TypeExpression> Context::findType(const std::string &typeName,bool isGenericType, const std::vector<std::shared_ptr<TypeExpression>> &genericTypes) const
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

const std::shared_ptr<TermExpression> Context::getCurrentExpression() const
{
	if (this->baseContext != nullptr) {
		return this->baseContext->getCurrentExpression();
	}
	else {
		return this->currentExpression;
	}
}

void Context::setCurrentExpression(const std::shared_ptr<TermExpression> &expr)
{
	if (this->baseContext != nullptr) {
		this->baseContext->setCurrentExpression(expr);
	}
	else {
		this->currentExpression = expr;
	}
}

const std::shared_ptr<TermExpression> Context::getLocalVariable(size_t offset) const
{
	return this->localVariables[offset];
}

void Context::setLocalVariable(size_t offset, const std::shared_ptr<TermExpression>& value)
{
	this->localVariables[offset] = value;
}
