#pragma once
#include "stdafx.h"

namespace WorkScript {
	class Function;
	class FunctionTemplate;
	class Type;

	struct pair_hash {
		template <class T1, class T2>
		std::size_t operator()(const std::pair<T1, T2> &p)
		{
			auto h1 = std::hash<T1>{}(p.first);
			auto h2 = std::hash<T2>{}(p.second);
			return h1 ^ h2;
		}
	};

	class Program final
	{
	public:
		Program();
		~Program();

		Overload * getFunctionOverload(const std::wstring &funcName,const std::vector<Type*> &paramTypes, Type *type = nullptr) const;
		void addFunction(Function *func, Type *type = nullptr);
		FunctionTemplate * getFunctionTemplate(const std::wstring & funcName, Type *type = nullptr) const;
		void addFunctionTemplate(FunctionTemplate *funcTemplate, Type *type = nullptr);
		Type * getType(const std::wstring &name) const;
		void addType(Type *type);
	protected:
		std::unordered_map<std::pair<Type*,std::wstring>, Function*, pair_hash> functions;
		std::unordered_map<std::pair<Type*, std::wstring>, FunctionTemplate*, pair_hash> functionTemplates;
		std::unordered_map<std::wstring, Type*> types;
	};
}
