#pragma once
#include <string>
#include <unordered_map>
#include "FunctionQuery.h"
#include "SymbolTable.h"

namespace WorkScript {
	class FunctionType;
	class PointerType;
	class FunctionFragment;
	class Function;
	class LinkageType;

	class AbstractContext {
	public:
		AbstractContext(const DebugInfo &d, AbstractContext *base, size_t blockID) noexcept;
		AbstractContext(const DebugInfo &d, Program *p) noexcept;
		~AbstractContext() noexcept;
		inline AbstractContext * getBaseContext() const noexcept{return this->base;}
		inline size_t getBlockID() const noexcept{ return this->blockID; }
		inline const std::wstring &getBlockPrefix() const noexcept {return this->blockPrefix;}
		inline const SymbolInfo * getSymbolInfo(const std::wstring &name) const noexcept { return this->abstractSymbolTable.getSymbolInfo(name); }
		inline SymbolInfo * getSymbolInfo(const std::wstring &name) noexcept { return this->abstractSymbolTable.getSymbolInfo(name);}
		inline SymbolInfo * setSymbol (const SymbolInfo &info) noexcept { return this->abstractSymbolTable.setSymbol(info); }
		inline SymbolTable * getSymbolTable() noexcept { return &this->abstractSymbolTable; }

		Function *getFunction(const DebugInfo &d, const FunctionQuery &query);
		std::vector<Function*> getFunctions(const DebugInfo &d, const std::wstring &name);
        void addFunction(Function *func);

		void addFunctionFragment(FunctionFragment *fragment);
		std::vector<FunctionFragment*> getLocalFunctionFragments(const DebugInfo &d, const FunctionQuery &query) noexcept;
		std::vector<FunctionFragment*> getLocalFunctionFragments(const DebugInfo &d, const std::wstring &name) noexcept;
		std::vector<FunctionFragment*> getFunctionFragments(const DebugInfo &d, const FunctionQuery &query) noexcept;
		size_t getFunctionFragmentCount() const{return this->fragments.size();}

		const DebugInfo &getDebugInfo() const noexcept;
		void setDebugInfo(const DebugInfo &debugInfo) noexcept;
		inline Program *getProgram() const noexcept{return this->program;}
		Type * getType(const std::wstring &name, size_t pointerLevel = 0);
		Type * getLocalType(const std::wstring &name, size_t pointerLevel = 0);
		void addType(const std::wstring &name, Type *type);
		void addType(Type *type);

	protected:
		AbstractContext * base;
		Program *program = nullptr;
		size_t blockID = 0;
		std::wstring blockPrefix;
		SymbolTable abstractSymbolTable;
		std::unordered_map<std::wstring, std::vector<Function*>> functions;
		std::unordered_map<std::wstring, std::vector<FunctionFragment*>> fragments;
		std::unordered_map<std::wstring, Type*> types;
		DebugInfo debugInfo;
	};
}