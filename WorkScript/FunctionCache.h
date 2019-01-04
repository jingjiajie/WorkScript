#pragma once
#include <unordered_map>

namespace WorkScript {
	class Function;
	class Type;

	class FunctionCache {
	public:
		void setFunctionTypeCache(Function *branch, const std::vector<Type*> &paramTypes, Type *cacheReturnType);
		bool getFunctionTypeCache(Function *branch, const std::vector<Type*> &paramTypes, Type **outReturnType);
	
	protected:
		class ParameterTypesAndReturnType
		{
		public:
			inline ParameterTypesAndReturnType(const std::vector<Type*> &paramTypes, Type *returnType)
				:parameterTypes(paramTypes), returnType(returnType) {}
			bool matchByParameters(const std::vector<Type*> &paramTypes);
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