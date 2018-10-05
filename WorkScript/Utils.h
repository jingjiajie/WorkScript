#pragma once
#include <type_traits>

#define thistype typename std::decay<decltype(*this)>::type

