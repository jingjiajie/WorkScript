#include "stdafx.h"
#include "Type.h"
#include "Expression.h"
#include "UnimplementedException.h"
#include "Program.h"
#include "Function.h"
#include "StringExpression.h"

using namespace WorkScript;
using namespace std;

Type * WorkScript::Type::inferReturnType(const std::wstring & funcName, const std::vector<Type*>& params)
{
	//TODO
}

bool Type::isSubTypeOf(const Type *type) const
{
	const Type *curType = this;
	while (curType) {
		if (curType->equals(type)) {
			return true;
		}
		if (curType->baseType != nullptr && curType->baseType != curType) {
			curType = curType->baseType;
		}
		else {
			return false;
		}
	}
	return false;
}

void WorkScript::Type::addMemberFunction(Function * func)
{
	this->program->addFunction(func);
	this->memberFunctions[func->getName()] = func;
}
