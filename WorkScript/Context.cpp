#include "Context.h"
#include "TypeExpression.h"
#include "FunctionExpression.h"
#include "Expression.h"
#include "FunctionInvocationExpression.h"
#include "VariableExpression.h"

using namespace std;

Context::Context(Program *program, size_t localVariableCount)
{
	this->program = program;
	this->localVariableCount = localVariableCount;
	this->localVariables = new Expression*[localVariableCount]();
}

Context::Context(Context * baseContext, size_t localVariableCount)
{
	this->program = baseContext->program;
	this->setBaseContext(baseContext);
	this->localVariableCount = localVariableCount;
	this->localVariables = new Expression*[localVariableCount]();
}

Context::~Context()
{
	for (size_t i = 0; i < this->localVariableCount; i++) {
		if (this->localVariables[i]) this->localVariables[i]->releaseLocal();
	}
	delete []this->localVariables;
}

//void Context::addType(TypeExpression* const &type)
//{
//	this->types.push_back(type);
//}

//TypeExpression* const Context::findType(const std::string &typeName,bool isGenericType, const std::vector<TypeExpression *> &genericTypes)
//{
//	//�������ұ�Context�е����Ͷ���
//	for (auto lpCurType : this->types) {
//		//��������ͬ��ƥ��ʧ��
//		if (lpCurType->getName() != typeName) continue;
//		//���Ͳ�ͬ��ƥ��ʧ��
//		if (lpCurType->isGenericType() != isGenericType)continue;
//		auto &curGenericTypes = lpCurType->getGenericTypes();
//		if (curGenericTypes.size() != genericTypes.size()) continue;
//		for (size_t i = 0; i < genericTypes.size(); i++) {
//			if (!curGenericTypes[i]->equals(this, genericTypes[i])) continue;
//		}
//		return lpCurType;
//	}
//	//����Ҳ��������븸��Context����
//	if (this->baseContext == nullptr) return nullptr;
//	return this->baseContext->findType(typeName,isGenericType);
//}

Context *const &Context::getBaseContext() const
{
	return this->baseContext;
}

void Context::setBaseContext(Context *const ctx)
{
	this->baseContext = ctx;
}

Expression* const Context::getCurrentExpression() const
{
	if (this->baseContext != nullptr) {
		return this->baseContext->getCurrentExpression();
	}
	else {
		return this->currentExpression;
	}
}

void Context::setCurrentExpression(Expression* const &expr)
{
	if (this->baseContext != nullptr) {
		this->baseContext->setCurrentExpression(expr);
	}
	else {
		this->currentExpression = expr;
	}
}