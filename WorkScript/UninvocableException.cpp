#include "UninvocableException.h"



UninvocableException::UninvocableException(std::string message)
	:WorkScriptException(message)
{
}


UninvocableException::~UninvocableException()
{
}
