#include "stdafx.h"

#include "Defines.h"
#include "WorkScriptEngine.h"

using namespace std;

void printUsages()
{
	printf("欢迎使用WorkScript解释器！您可以使用以下参数来启动解释器：\n");
	printf("-v 或 -version：\t显示版本号\n");
	printf("-h 或 -help：\t显示此帮助信息\n");
	printf("(文件名)：\t运行指定目录的WorkScript脚本文件\n");
}

void printVersion()
{
	printf("WorkScript解释器 1.0 alpha 1版本 2018-8-24\n荆佳颉 932166095@qq.com\n");
}

int main(int argc, const char* argv[]) {
	setlocale(LC_CTYPE,"");
	if (argc <= 1) {
		printUsages();
	}
	else if (argc > 2) {
		printUsages();
	}
	else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "-version") == 0) {
		printVersion();
	}
	else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-h") == 0) {
		printUsages();
	}
	else {
		auto fileName = argv[1];
		WorkScriptEngine engine;
		engine.run(boost::locale::conv::to_utf<wchar_t>(fileName, LOCAL_BOOST_ENCODING).c_str());
	}
	getchar();
}