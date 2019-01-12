#pragma once
#include <type_traits>
#include "stdafx.h"

#define thistype typename std::decay<decltype(*this)>::type

class Finalizer final{
public:
	Finalizer(void(*f)(void)) :func(f) {}
	~Finalizer() { this->func(); }
private:
	void(*func)(void);
};