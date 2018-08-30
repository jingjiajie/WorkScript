#include "SyntaxErrorException.h"
#include <sstream>

using namespace std;

SyntaxErrorException::~SyntaxErrorException()
{
}

std::string SyntaxErrorException::toString() const
{
	stringstream ss;
	ss << "�﷨����" << "����" << this->line << "��, ��" << this->column << "�У���" << this->message;
	return ss.str();
}
