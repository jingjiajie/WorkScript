#ifdef __linux__
#include <iconv.h>
#include <wchar.h>
#include <stdlib.h>
#include "Locales.h"
#include "WorkScriptException.h"


using namespace std;
using namespace WorkScript;

//static const char * toIconvEncoding(Encoding encoding){
//    static char * localEncoding = nullptr;
//
//    if(!localEncoding){
//        localEncoding = getenv("LANG");
//        auto pointPos = strchr(localEncoding,'.');
//        if(pointPos) localEncoding = pointPos + 1;
//    }
//
//    switch(encoding){
//        case Encoding ::ANSI:
//            return localEncoding;
//        case Encoding ::UTF_8:
//            return "UTF-8";
//    }
//    return nullptr;
//}

static const char * getLang(Encoding encoding){
    static char * localLang = nullptr;

    if(!localLang) localLang = getenv("LANG");
    switch(encoding){
        case Encoding ::ANSI:
            return localLang;
        case Encoding::UTF_8:
            return "en_US.UTF-8";
    }
    return nullptr;
}

std::wstring Locales::toWideChar(Encoding fromEncoding, const std::string &str)
{
    const char *lang = getLang(fromEncoding);
    const char *oriLang =  getenv("LANG");
    setlocale(LC_CTYPE,lang);
    size_t len = mbstowcs(nullptr,str.c_str(),0) + 1;
    wchar_t *buff = new wchar_t[len];
    mbstowcs(buff, str.c_str(), len-1);
    buff[len-1] = '\0';
    wstring result = buff;
    delete []buff;
    setlocale(LC_CTYPE, oriLang);
    return result;
}

std::string Locales::fromWideChar(Encoding toEncoding, const std::wstring &str){
    const char *lang = getLang(toEncoding);
    const char *oriLang =  getenv("LANG");
    setlocale(LC_CTYPE,lang);
    size_t len = wcstombs(nullptr,str.c_str(),0) + 1;
    char *buff = new char[len];
    wcstombs(buff, str.c_str(), len-1);
    buff[len-1] = '\0';
    string result = buff;
    delete []buff;
    setlocale(LC_CTYPE, oriLang);
    return result;
}

std::string Locales::convert(Encoding fromEncoding, Encoding toEncoding, const std::string &str){
    wstring unicodeStr = Locales::toWideChar(fromEncoding,str);
    string targetStr = Locales::fromWideChar(toEncoding,unicodeStr);
    return targetStr;
}

#endif