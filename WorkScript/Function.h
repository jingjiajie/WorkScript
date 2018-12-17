#pragma once
#include <vector>
#include "Overload.h"

namespace WorkScript {
	class Function {
	public:
		inline Function(Program *program, const std::wstring &name)
			:program(program), name(name) {}

		inline ~Function()
		{
			for (Overload *overload : this->overloads)delete overload;
		}

		virtual void bindSymbols();
		virtual GenerateResult generateLLVMIR(GenerateContext *context);

		Overload * getOverload(const std::vector<Type*> paramTypes)
		{
			for (size_t i = 0; i < this->overloads.size(); ++i)
			{
				if (this->overloads[i]->matchByParameters(paramTypes))
				{
					return this->overloads[i];
				}
			}
			return nullptr;
		}

		void addOverload(Overload *overload)
		{
			this->overloads.push_back(overload);
		}

		inline const std::wstring & getName()const
		{
			return name;
		}

		inline void setName(const std::wstring &funcName)
		{
			this->name = funcName;
		}

	private:
		std::wstring name;
		std::vector<WorkScript::Overload*> overloads;
		Program *program;
	};
}