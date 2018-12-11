#pragma once
#include <type_traits>
#include "stdafx.h"

#define thistype typename std::decay<decltype(*this)>::type
