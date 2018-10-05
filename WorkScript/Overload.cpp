#include "stdafx.h"
#include "Overload.h"
#include "Function.h"

using namespace std;
using namespace WorkScript;

WorkScript::Overload::~Overload()
{
	for (Parameter *p : this->parameters)delete p;
}

std::wstring WorkScript::Overload::getMangledFunctionName() const
{
	wstringstream ss;
	ss << this->function->getName();
	for (auto param : this->parameters) {
		ss << L"@" << param->getType()->getName();
	}
	return ss.str();
}

llvm::Function * WorkScript::Overload::getLLVMFunction(GenerateContext * context)
{
	if (!this->llvmFunction)
	{
		vector<llvm::Type*> llvmTypes;
		llvmTypes.reserve(this->parameters.size() + 1);
		for (size_t i = 0; i < this->parameters.size(); ++i)
		{
			llvmTypes[i] = this->parameters[i]->getType()->getLLVMType();
		}

		auto thisParam = this->getThisParameter(); //this
		llvmTypes[llvmTypes.size() - 1] = thisParam->getType()->getLLVMType();
		llvm::FunctionType *funcType = llvm::FunctionType::get(this->returnType->getLLVMType(), llvmTypes, false);
		llvm::Function *func = llvm::Function::Create(funcType,
			llvm::Function::ExternalLinkage,
			boost::locale::conv::from_utf(this->getMangledFunctionName(), "UTF-8"),
			context->getLLVMModule()
		);
		context->setCurrentFunction(func);
		this->llvmFunction = func;
	}
	return this->llvmFunction;
}

bool WorkScript::Overload::matchByParameters(const std::vector<Type*> &paramTypes)
{
	size_t paramCount = paramTypes.size();

	if (paramCount != this->parameters.size())return false;
	for (size_t i = 0; i < paramCount; ++i)
	{
		if (!this->parameters[i]->getType()->equals(paramTypes[i]))return false;
	}
	return true;
}

Parameter * Overload::getThisParameter()
{
	return this->function->getThisParameter();
}