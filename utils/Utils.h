#pragma once
#include <type_traits>
#include <string>

#define thistype typename std::decay<decltype(*this)>::type

namespace WorkScript
{
	class Finalizer final
	{
	public:
		explicit Finalizer(void(*f)()) noexcept : func(f)
		{}

		~Finalizer() noexcept
		{ this->func(); }

	private:
		void (*func)();
	};
}