#pragma once
#include "Location.h"

namespace WorkScript {
	class Program;

	class ExpressionInfo {
	public:
		ExpressionInfo(Program *p, Location loc) :program(p), location(loc) {}
		inline Program * getProgram() const { return this->program; }
		inline Location getLocation() const { return this->location; }
	protected:
		Program * program;
		Location location;
	};
}