#include "ErrorManager.h"

using namespace WorkScript;
using namespace std;

vector<WorkScriptError> ErrorManager::errors;
vector<WorkScriptWarning> ErrorManager::warnings;

ErrorStatus ErrorManager::warning(const WorkScriptWarning &w)
{
    ErrorManager::warnings.push_back(w);
    return ErrorStatus::CONTINUE;
}

ErrorStatus ErrorManager::error(const WorkScriptError &e)
{
    ErrorManager::errors.push_back(e);
    if(ErrorManager::errors.size() >= ErrorManager::MAX_ERROR_COUNT){
        return ErrorStatus::STOP;
    }else{
        return ErrorStatus::CONTINUE;
    }
}


