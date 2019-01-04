#pragma once
#include "Location.h"

namespace WorkScript {
	class AbstractContext;
	class Program;

	class ExpressionInfo {
	public:
		ExpressionInfo(Program *p, Location loc, AbstractContext *abstractContext) 
			:program(p), location(loc), abstractContext(abstractContext) {}
		inline Program * getProgram() const { return this->program; }
		inline Location getLocation() const { return this->location; }
		inline AbstractContext * getAbstractContext()const { return this->abstractContext; }
	protected:
		AbstractContext * abstractContext = nullptr;
		Program * program;
		Location location;
	};
}