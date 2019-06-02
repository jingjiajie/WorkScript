#include "LLVMGenerator.h"
#include "Module.h"
#include "Function.h"
#include "StringCache.h"

using namespace std;
using namespace WorkScript;

void LLVMGenerator::visit(const Module *module, VisitResult *res)
{
    StringCache stringCache;
    //LLVMGenerateResult res(this->llvmContext, this->llvmModule, nullptr, module->getGlobalAbstractContext(), &this->functionCache, &stringCache);
    //TODO DebugInfo
    Function *funcMain = module->getGlobalAbstractContext()->getFunction(DebugInfo(), FunctionQuery(L"main", {}, false), &this->functionCache);
    try {
        funcMain->accept(this, res);
    }
    catch (const CancelException &) {
        return;
    }
}