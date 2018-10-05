#pragma once
namespace WorkScript {
	class Initializer {
	public:
		inline Initializer(void(*func)())
		{
			func();
		}
	};
};