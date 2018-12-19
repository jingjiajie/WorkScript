#include "stdafx.h"
#include "Expression.h"
#include "WorkScriptException.h"

using namespace WorkScript;

Expression * WorkScript::Expression::instantialize(InstantializeContext * context)
{
	throw WorkScriptException(L"非模板表达式不能实例化");
}
