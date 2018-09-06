#include "Context.h"
#include <string>

using namespace std;

Context * const Context::getBaseContext(int depth)
{
	if (depth > this->depth) {
		throw WorkScriptException((wstring(L"�ڲ�����getBaseContextֻ�ܻ�ȡ���������ġ���ǰ��ȣ�") + to_wstring(this->depth) + L"Ŀ����ȣ�" + to_wstring(depth)).c_str());
	}
	auto target = this;
	for (int i = 0; i < this->depth - depth; i++) {
		target = target->baseContext;
	}
	return target;
}
