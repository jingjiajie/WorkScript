#include <unordered_map>
#include "AbstractContext.h"
#include "Function.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "PointerType.h"
#include "FunctionType.h"
#include "Value.h"
#include "FunctionFragment.h"

using namespace WorkScript;
using namespace std;

WorkScript::AbstractContext::AbstractContext(const DebugInfo &d, AbstractContext * base, size_t blockID) noexcept
	:base(base), program(base->program), blockID(blockID), blockPrefix(base?base->blockPrefix + L"." + to_wstring(blockID):L""), abstractSymbolTable(blockPrefix), debugInfo(d)
{
}

AbstractContext::AbstractContext(const DebugInfo &d, Program *p) noexcept
: base(nullptr), program(p), blockID(0), blockPrefix(L"")
{
}


WorkScript::AbstractContext::~AbstractContext() noexcept
{
	for (const auto &itFuncs : this->functions)
	{
		for (auto itFunc : itFuncs.second)
		{
			delete itFunc;
		}
	}

	for(const auto &itFragments : this->fragments){
		for(auto itFragment : itFragments.second){
			delete itFragment;
		}
	}

	for (const auto &itType : this->types)
	{
		Type *type = itType.second;
		if (type->getClassification() == TypeClassification::CLASS) {
			delete type;
		}
	}
}

void WorkScript::AbstractContext::addFunction(Function * func)
{
	wstring name = func->getName();
	this->functions[name].push_back(func);
}

Type * WorkScript::AbstractContext::getType(const std::wstring & name, size_t pointerLevel)
{
	auto type = this->getLocalType(name, pointerLevel);
	if (!type && base) {
		type = base->getType(name, pointerLevel);
	}
	return type;
}

Type * AbstractContext::getLocalType(const std::wstring & name, size_t pointerLevel)
{
	Type *returnType = nullptr;
	auto it = this->types.find(name);
	if (it == this->types.end()) returnType = nullptr;
	else returnType = it->second;

	if (pointerLevel > 0) {
		returnType = PointerType::get(returnType, pointerLevel);
	}
	return returnType;
}

void AbstractContext::addType(const std::wstring &name, Type *type)
{
	this->types[name] = type;
}

void AbstractContext::addType(Type * type)
{
	this->addType(type->getName(), type);
}

const DebugInfo &AbstractContext::getDebugInfo() const noexcept
{
    return debugInfo;
}

void AbstractContext::setDebugInfo(const DebugInfo &debugInfo) noexcept
{
    this->debugInfo = debugInfo;
}

void AbstractContext::addFunctionFragment(FunctionFragment *fragment)
{
	wstring name = fragment->getName();
	this->fragments[name].push_back(fragment);
}

Function *AbstractContext::getFunction(const DebugInfo &d, const FunctionQuery &query)
{
	//如果相应的函数已经存在，则直接返回函数

	auto itFunc = this->functions.find(query.getName());
	if (itFunc != this->functions.end())
	{
		vector<Function *> &funcs = itFunc->second;
		for (Function *f : funcs)
		{
			if (f->match(d, query)) return f;
		}
	}

	//当相应的函数不存在，则使用Fragment新建一个函数
	const vector<FunctionFragment *> &matchedFragments = this->getFunctionFragments(d, query);
	if (matchedFragments.empty())
	{
		return nullptr;
	}
	//根据fragment的链接类型，决定生成Function的链接类型
	LinkageType linkageType = matchedFragments[0]->getLinkageType();

	for (size_t i = 1; i < matchedFragments.size(); ++i)
	{
		if (!matchedFragments[i]->getLinkageType().equals(linkageType))
		{
			d.getReport()->error(TypeMismatchedError(d, L"函数" + query.toString() + L" 的链接类型不统一"),
								 ErrorBehavior::CANCEL_EXPRESSION);
		}
	}

	FunctionType *funcType = FunctionType::get(query.getParameterTypes(), nullptr, false, query.isConst());
	auto func = new Function(this, query.getName(), funcType, linkageType);
	func->addFragments(matchedFragments);
	this->functions[query.getName()].push_back(func);
	return func;
}

std::vector<FunctionFragment *> AbstractContext::getLocalFunctionFragments(const DebugInfo &d, const FunctionQuery &query) noexcept
{
	vector<FunctionFragment*> matchedFragments;
	auto it = this->fragments.find(query.getName());
	if (it == this->fragments.end())
	{
		return matchedFragments;
	}
	const vector<FunctionFragment*> &fragments = it->second;
	for(FunctionFragment *fragment : fragments)
	{
		if(fragment->match(d,query)){
			matchedFragments.push_back(fragment);
		}
	}
	return matchedFragments;
}

std::vector<FunctionFragment *> AbstractContext::getFunctionFragments(const DebugInfo &d, const FunctionQuery &query) noexcept
{
	//子级的Fragments必须放在父级之前，以保证子级的声明比父级优先。
	vector<FunctionFragment*> fragments = this->getLocalFunctionFragments(d, query);
	if(this->base){
		const vector<FunctionFragment*> &baseFragments = this->base->getFunctionFragments(d, query);
		fragments.insert(fragments.end(), baseFragments.begin(), baseFragments.end());
	}
	return fragments;
}

std::vector<Function *> AbstractContext::getFunctions(const DebugInfo &d, const std::wstring &name)
{
	vector<Function*> funcs;
	const auto &itLocalFunc = this->functions.find(name);
	if(itLocalFunc != this->functions.end()){
		funcs = itLocalFunc->second;
	}
	if(this->base){
		auto baseFuncs = this->base->getFunctions(d,name);
		funcs.insert(funcs.end(), baseFuncs.begin(), baseFuncs.end());
	}
	return funcs;
}

std::vector<FunctionFragment*> AbstractContext::getLocalFunctionFragments(const DebugInfo &d, const std::wstring &name) noexcept
{
	vector<FunctionFragment *> fragments;
	const auto &itLocalFragment = this->fragments.find(name);
	if (itLocalFragment != this->fragments.end())
	{
		fragments = itLocalFragment->second;
	}
	return fragments;
}