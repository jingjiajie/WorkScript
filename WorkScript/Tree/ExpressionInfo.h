#pragma once
#include "DebugInfo.h"

namespace WorkScript {
	class AbstractContext;
	class Program;

	class ExpressionInfo {
	public:
		ExpressionInfo(Program *p, const DebugInfo &d, AbstractContext *abstractContext)
			:abstractContext(abstractContext), program(p), debugInfo(d) {}
		inline Program * getProgram() const { return this->program; }
		inline DebugInfo getDebugInfo() const { return this->debugInfo; }
		inline AbstractContext * getAbstractContext()const { return this->abstractContext; }
	protected:
		AbstractContext * abstractContext = nullptr;
		Program * program;
		DebugInfo debugInfo;
	};
}