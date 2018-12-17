#pragma once
#include <vector>
#include "OverloadTemplate.h"

namespace WorkScript {
	class FunctionTemplate {
	public:
		inline FunctionTemplate(Program *program, const std::wstring &name)
			:program(program), name(name) {}

		inline ~FunctionTemplate()
		{
			for (OverloadTemplate *overload : this->overloads)delete overload;
			if (this->thisParam) delete this->thisParam;
		}

		Function * createFunction();

		OverloadTemplate * getOverload(const std::vector<Type*> &paramTypes)
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

		void addOverload(OverloadTemplate *overload)
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

		inline ParameterTemplate * getThisParameter()
		{
			return this->thisParam;
		}

		inline void setThisParameter(ParameterTemplate *thisParam)
		{
			this->thisParam = thisParam;
		}

		inline Program * getProgram()
		{
			return this->program;
		}

		inline void setProgram(Program * program)
		{
			this->program = program;
		}
	private:
		std::wstring name;
		std::vector<WorkScript::OverloadTemplate*> overloads;
		ParameterTemplate *thisParam = nullptr;
		Program *program;
	};
}