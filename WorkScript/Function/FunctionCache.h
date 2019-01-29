#pragma once
#include <unordered_map>
#include <vector>
#include "DebugInfo.h"

namespace WorkScript {
	class Function;
	class Type;

	class FunctionCache {
	public:
		void setFunctionTypeCache(const DebugInfo &d, Function *branch, const std::vector<Type*> &paramTypes, bool isRuntimeVarargs, bool isStaticVarargs, Type *cacheReturnType);
		bool getFunctionTypeCache(const DebugInfo &d, Function *branch, const std::vector<Type*> &paramTypes, bool isRuntimeVarargs, bool isStaticVarargs, Type **outReturnType);
	
	protected:
		class ParameterTypesAndReturnType
		{
		public:
			inline ParameterTypesAndReturnType(const std::vector<Type*> &paramTypes, Type *returnType)
				:parameterTypes(paramTypes), returnType(returnType) {}
			bool matchByParameters(const DebugInfo &d, const std::vector<Type*> &paramTypes, bool isRuntimeVarargs, bool isStaticVarargs);
			std::vector<Type*> getParameterTypes() { return this->parameterTypes; }
			Type *getReturnType() { return this->returnType; }
			void setReturnType(Type *t) { this->returnType = t; }
		protected:
			std::vector<Type*> parameterTypes;
			Type *returnType = nullptr;
		};

		std::unordered_map<Function*, std::vector<ParameterTypesAndReturnType>> functionBranchTypeCache;
	};
}