#include "DuplicateDeclarationException.h"



DuplicateDeclarationException::DuplicateDeclarationException(std::string message)
	:WorkScriptException(message)
{
}


DuplicateDeclarationException::~DuplicateDeclarationException()
{
}
