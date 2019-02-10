#pragma once
#include <type_traits>

#define thistype typename std::decay<decltype(*this)>::type

class Finalizer final{
public:
	explicit Finalizer(void(*f)()) noexcept :func(f) {}
	~Finalizer() noexcept { this->func(); }
private:
	void(*func)();
};