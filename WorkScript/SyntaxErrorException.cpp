#include "SyntaxErrorException.h"
#include <sstream>

using namespace std;

SyntaxErrorException::~SyntaxErrorException()
{
}

std::string SyntaxErrorException::toString() const
{
	stringstream ss;
	ss << "语法错误" << "（第" << this->line << "行, 第" << this->column << "列）：" << this->message;
	return ss.str();
}
