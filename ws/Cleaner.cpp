#include "Cleaner.h"
#include "Locales.h"
#include <stdio.h>

using namespace std;
using namespace WorkScript;

void Cleaner::clean()
{
    for(size_t i=0; i<this->files.size(); ++i){
        string file = Locales::fromWideChar(Encoding::ANSI, this->files[i]);
        remove(file.c_str());
    }
}
