#pragma once
namespace WorkScript {
	enum class TypeClassification : unsigned char {
		VOID,
		INTEGER,
		INTEGER_POINTER,
		FLOAT,
		FLOAT_POINTER,
		STRING,
		CLASS
	};
}