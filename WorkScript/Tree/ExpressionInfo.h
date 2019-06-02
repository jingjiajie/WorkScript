#pragma once
#include "DebugInfo.h"

namespace WorkScript {
	class AbstractContext;
	class Module;

	class ExpressionInfo {
	public:
		ExpressionInfo(Module *p, const DebugInfo &d, AbstractContext *abstractContext)
			:abstractContext(abstractContext), module(p), debugInfo(d) {}
		inline Module * getModule() const { return this->module; }
		inline const DebugInfo & getDebugInfo() const { return this->debugInfo; }
		inline AbstractContext * getAbstractContext()const { return this->abstractContext; }
	protected:
		AbstractContext * abstractContext = nullptr;
		Module * module;
		DebugInfo debugInfo;
	};
}