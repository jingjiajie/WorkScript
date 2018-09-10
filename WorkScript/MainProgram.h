#pragma once
#include "Program.h"
class MainProgram :
	public Program
{
public:
	MainProgram();
	virtual ~MainProgram();

	void initConstants();
	void initPrintExpression();
};

