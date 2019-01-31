#pragma once
#include <string>
#include <unordered_map>
#include "SymbolTable.h"

namespace WorkScript {
	class FunctionType;
	class PointerType;

	class AbstractContext {
	public:
		AbstractContext(const DebugInfo &d, AbstractContext *base, size_t blockID);
		~AbstractContext();
		inline size_t getBlockID() const { return this->blockID; }
		inline SymbolInfo * getSymbolInfo(const std::wstring &name) { return this->abstractSymbolTable.getSymbolInfo(name); }
		inline SymbolInfo * setSymbol(const DebugInfo &d, const std::wstring &name, Type *type, LinkageType lt) { return this->abstractSymbolTable.setSymbol(d, name, type, lt); }
		inline SymbolTable * getSymbolTable() { return &this->abstractSymbolTable; }

		void addFunction(Function *func);
		Function* getFirstFunction(const std::wstring &name, std::vector<Type*> paramTypes);
		std::vector<Function*> getLocalFunctions(const std::wstring &name, std::vector<Type*> paramTypes, bool compromise = false);
		std::vector<Function*> getLocalFunctions(const std::wstring &name);
		std::vector<Function*> getFunctions(const std::wstring &name, std::vector<Type*> paramTypes, bool compromise = false);
		std::vector<Function*> getFunctions(const std::wstring &name);

		const DebugInfo &getDebugInfo() const;
		void setDebugInfo(const DebugInfo &debugInfo);
		Type * getType(const std::wstring &name, size_t pointerLevel = 0);
		Type * getLocalType(const std::wstring &name, size_t pointerLevel = 0);
		void addType(const std::wstring &name, Type *type);
		void addType(Type *type);

	protected:
		AbstractContext * base;
		size_t blockID = 0;
		std::wstring prefix;
		SymbolTable abstractSymbolTable;
		std::unordered_map<std::wstring, std::vector<Function*>> functions;
		std::unordered_map<std::wstring, Type*> types;
		DebugInfo debugInfo;
	};
}