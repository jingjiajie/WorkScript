#include <llvm/IR/IRBuilder.h>
#include "LLVMGenerateResult.h"
#include "Visitor/Visitor.h"
#include "FunctionCache.h"

namespace WorkScript
{
    class LLVMGenerator : public Visitor
    {
    public:
        void visit(const class Module *, VisitResult *) override;

        void visit(const class Function *, LLVMGenerateResult *) override;

        void visit(const class FunctionFragment *, LLVMGenerateResult *) override;

        void visit(const class UnaryOperator *, LLVMGenerateResult *) override;

        void visit(const class BinaryOperator *, LLVMGenerateResult *) override;

        void visit(const class Call *, LLVMGenerateResult *) override;

        void visit(const class Value *, LLVMGenerateResult *) override;

        void visit(const class Variable *, LLVMGenerateResult *) override;

    protected:
        llvm::LLVMContext *llvmContext = nullptr;
        llvm::Module *llvmModule = nullptr;
        llvm::IRBuilder<> *irBuilder = nullptr;
        FunctionCache functionCache;
    };
}