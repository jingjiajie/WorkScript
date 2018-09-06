#include "Context.h"
#include <string>

using namespace std;

Context * const Context::getBaseContext(int depth)
{
	if (depth > this->depth) {
		throw WorkScriptException((wstring(L"内部错误：getBaseContext只能获取父级上下文。当前深度：") + to_wstring(this->depth) + L"目标深度：" + to_wstring(depth)).c_str());
	}
	auto target = this;
	for (int i = 0; i < this->depth - depth; i++) {
		target = target->baseContext;
	}
	return target;
}
