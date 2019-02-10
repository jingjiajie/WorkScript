#pragma once
namespace WorkScript {
	enum class TypeClassification : unsigned char {
		VOID,
		INTEGER,
		FLOAT,
		POINTER,
		STRING,
		FUNCTION,
		ARRAY,
		MULTI_VALUE,
		CLASS
	};
}