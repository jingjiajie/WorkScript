#pragma once
#include <type_traits>
#include <math.h>

template<typename T1, typename T2>
inline auto PLUS_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 + v2;
}

template<typename T1, typename T2>
inline auto MINUS_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 - v2;
}

template<typename T1, typename T2>
inline auto MULTIPLY_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 * v2;
}

template<typename T1, typename T2>
inline auto DIVIDE_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 / v2;
}

template<typename T1, typename T2>
inline auto MODULUS_WRAPPER(const T1 &v1, const T2 &v2) -> decltype(v1 % v2)
{
	return v1 % v2;
}

template<typename T1, typename T2>
inline auto MODULUS_WRAPPER(const T1 &v1, const T2 &v2) 
-> typename std::enable_if<std::is_same<T1,double>::value || std::is_same<T2,double>::value,double>::type
{
	return fmod(v1, v2);
}

template<typename T1, typename T2>
inline bool GREATER_THAN_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 > v2;
}

template<typename T1, typename T2>
inline bool GREATER_THAN_EQUALS_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 >= v2;
}

template<typename T1, typename T2>
inline bool LESS_THAN_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 < v2;
}

template<typename T1, typename T2>
inline bool LESS_THAN_EQUALS_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 <= v2;
}

template<typename T1, typename T2>
inline bool EQUALS_WRAPPER(const T1 &v1, const T2 &v2)
{
	return v1 == v2;
}