#include <Locales.h>
#include "ValueDescriptor.h"
#include "ReferenceType.h"
#include "PointerType.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "GenerateContext.h"
#include "DeducedInfo.h"
#include "Expression.h"
#include "Value.h"

using namespace std;
using namespace WorkScript;

bool ValueDescriptor::convertableTo(const DebugInfo &d,const ValueDescriptor &srcVal,
                                    const ValueDescriptor &targetVal)
{
    Type *srcType = srcVal.type;
    Type *targetType = targetVal.type;
    if (srcType->equals(targetType))return true;
    switch (srcType->getClassification())
    {
        case TypeClassification::FLOAT:
        case TypeClassification::INTEGER:
        {
            switch (targetType->getClassification())
            {
                case TypeClassification::FLOAT:
                case TypeClassification::INTEGER:
                {
                    return true;
                }
                case TypeClassification::REFERENCE:{
                    auto *targetRefType = (ReferenceType*)targetType;
                    //TODO 引用目标类型是原类型的父类也行
                    return targetRefType->getTargetType()->equals(srcType);
                }
                default:
                    return false;
            }
            break;
        }
        case TypeClassification::VOID:
            return targetType->getClassification() == TypeClassification::VOID;
        case TypeClassification::POINTER:
        {
            PointerType *srcPtr = (PointerType*)srcType;
            switch (targetType->getClassification()) {
                case TypeClassification::POINTER: {
                    PointerType *targetPtr = (PointerType *) targetType;
                    if (srcPtr->getLevel() != targetPtr->getLevel()) return false;
                    if (targetPtr->getTargetType()->getClassification() == TypeClassification::VOID)
                        return true; //任何类型都可以转换为void*
                    if (srcPtr->getTargetType()->getClassification() == TypeClassification::VOID)
                        return true; //void*可以转换为任何类型
                    return ValueDescriptor::convertableTo(d, ValueDescriptor(srcPtr->getTargetType(), ValueKind::VALUE),
                                                          ValueDescriptor(targetPtr->getTargetType(),
                                                                          ValueKind::VALUE));
                }
                default:
                    return false;
            }
            break;
        }
        case TypeClassification::REFERENCE:{
            ReferenceType *srcRef = (ReferenceType*)srcType;
            switch(targetType->getClassification()){
                case TypeClassification::REFERENCE:
                {
                    auto *targetRefType = (ReferenceType*)targetType;
                    //TODO 目标引用的目标类型是原引用类型目标类型的父类也可以
                    return targetRefType->getTargetType()->equals(srcRef->getTargetType());
                }
                default:
                {
                    return srcRef->getTargetType()->equals(targetType);
                }
            }
        }
        default:
            return false;
    }
}

llvm::Value * ValueDescriptor::generateLLVMKindConvert(const WorkScript::DebugInfo &d,
                                                       WorkScript::GenerateContext *context, llvm::Value *srcLLVMVal,
                                                       ValueKind srcKind, ValueKind targetKind)
{
    auto builder = context->getIRBuilder();
    if(srcKind == targetKind){
        return srcLLVMVal;
    }else{
        if(srcKind == ValueKind::VARIABLE){ //target is right
            return builder->CreateLoad(srcLLVMVal);
        }else{  //src is right, target is left
            llvm::Type *srcLLVMType = srcLLVMVal->getType();
            llvm::Value *targetLLVMVal = builder->CreateAlloca(srcLLVMType);
            builder->CreateStore(srcLLVMVal, targetLLVMVal);
            return targetLLVMVal;
        }
    }
}


GenerateResult ValueDescriptor::generateLLVMConvert(const DebugInfo &d,
                                                    GenerateContext *context, Expression *srcVal,const ValueDescriptor &targetDesc)
{
    auto irBuilder = context->getIRBuilder();
    DeducedInfo srcDeducedInfo = srcVal->deduce(context);
    ValueDescriptor srcDesc = srcDeducedInfo.getValueDescriptor();
    Type *srcType = srcDesc.getType();
    ValueKind srcKind = srcDesc.getKind();
    ValueKind targetKind = targetDesc.getKind();
    llvm::Value *srcLLVMValue = srcVal->generateIR(context);
    const Type *targetType = targetDesc.getType();
    llvm::Type *targetLLVMType = targetType->getLLVMType(context);

    if (targetType->equals(srcType)) {
        return generateLLVMKindConvert(d, context, srcLLVMValue, srcKind, targetKind);
    }

    switch (srcType->getClassification()) {
        case TypeClassification::INTEGER: /*源类型为Integer*/ {
            IntegerType *srcIntegerType = (IntegerType *) srcType;
            switch (targetType->getClassification()) {
                case TypeClassification::INTEGER:/*目标类型为Integer*/ {
                    IntegerType *targetIntegerType = (IntegerType *) targetType;
                    //如果长度相同，仅仅有无符号不同，则不用进行转换
                    if (srcIntegerType->getLength() == targetIntegerType->getLength()){
                        return GenerateResult(generateLLVMKindConvert(d, context, srcLLVMValue, srcKind, targetKind));
                    }else{  //否则根据是否有符号进行符号扩展或零位扩展
                        llvm::Value *srcRightLLVMVal = generateLLVMKindConvert(d, context, srcLLVMValue, srcKind,
                                                                               ValueKind::VALUE);
                        llvm::Value *convertedLLVMVal = nullptr;
                        if(srcIntegerType->isSigned()){
                            convertedLLVMVal = irBuilder->CreateSExt(srcRightLLVMVal, targetLLVMType);
                        }else {
                            convertedLLVMVal = irBuilder->CreateZExt(srcRightLLVMVal, targetLLVMType);
                        }
                        return GenerateResult(generateLLVMKindConvert(d, context, convertedLLVMVal, srcKind, targetKind));
                    }
                }
                case TypeClassification::FLOAT: /*目标类型为Float*/ {
                    llvm::Value *srcRightLLVMVal = generateLLVMKindConvert(d, context, srcLLVMValue, srcKind,
                                                                           ValueKind::VALUE);
                    llvm::Value *convertedLLVMVal = nullptr;
                    if (srcIntegerType->isSigned()) convertedLLVMVal = irBuilder->CreateSIToFP(srcRightLLVMVal, targetLLVMType);
                    else convertedLLVMVal = irBuilder->CreateUIToFP(srcRightLLVMVal, targetLLVMType);
                    return generateLLVMKindConvert(d, context, convertedLLVMVal, srcKind, targetKind);
                }
                case TypeClassification::REFERENCE:{ /*目标类型为引用，判断是否为左值。如果左值，创建引用，右值则先创建左值再创建引用*/
                    ReferenceType *targetRefType = (ReferenceType*)targetType;
                    //TODO 原类型是目标类型的子类也可以
                    if(!targetRefType->getTargetType()->equals(srcType)) goto UNSUPPORTED;
                    llvm::Value *srcLeftLLVMVal = generateLLVMKindConvert(d, context, srcLLVMValue, srcKind,
                                                                          ValueKind::VARIABLE);
                    ReferenceType *refType = ReferenceType::get(srcType);
                    llvm::Value *llvmRef = irBuilder->CreateAlloca(refType->getLLVMType(context));
                    ReferenceType::setTargetPointer(context, llvmRef, srcLeftLLVMVal);
                    //TODO 设置局部堆地址 ReferenceType::setLocalheapPointer(context, llvmRef, )
                    return llvmRef;
                }
                default:
                    goto UNSUPPORTED;
            }

        }

        case TypeClassification::FLOAT: /*源类型为Float*/ {
            FloatType *srcFloatType = (FloatType *) srcType;
            switch (targetType->getClassification()) {
                case TypeClassification::INTEGER: /*目标类型为Integer*/ {
                    IntegerType *targetIntegerType = (IntegerType *) targetType;
                    llvm::Value *srcRightLLVMVal = generateLLVMKindConvert(d, context, srcLLVMValue, srcKind,
                                                                           ValueKind::VALUE);
                    llvm::Value *convertedLLVMVal = nullptr;
                    if (targetIntegerType->isSigned()) convertedLLVMVal = irBuilder->CreateFPToSI(srcRightLLVMVal, targetLLVMType);
                    else convertedLLVMVal = irBuilder->CreateFPToUI(srcRightLLVMVal, targetLLVMType);
                    return generateLLVMKindConvert(d, context, convertedLLVMVal, srcKind, targetKind);;
                }
                case TypeClassification::FLOAT: /*目标类型为Float*/ {
                    llvm::Value *srcRightLLVMVal = generateLLVMKindConvert(d, context, srcLLVMValue, srcKind,
                                                                           ValueKind::VALUE);
                    llvm::Value *convertedLLVMVal = irBuilder->CreateFPCast(srcRightLLVMVal, targetLLVMType);
                    return generateLLVMKindConvert(d, context, convertedLLVMVal, srcKind, targetKind);
                }
                default:
                    goto UNSUPPORTED;
            }
        }

        case TypeClassification::VOID: {
            switch (targetType->getClassification()) {
                case TypeClassification::VOID: {
                    return srcLLVMValue;
                }
                default:
                    goto UNSUPPORTED;
            }
        }

        case TypeClassification::POINTER: //Pointer类型不存在字面常量
            switch (targetType->getClassification()) {
                case TypeClassification::POINTER: {
                    return irBuilder->CreateBitCast(srcLLVMValue, targetLLVMType);
                }
                default:
                    goto UNSUPPORTED;
            }

        case TypeClassification::REFERENCE: {
            auto *srcRefType = (ReferenceType*)srcType;
            switch(targetType->getClassification()) {
                //引用转换成指针，如果指针类型和引用类型相同，直接取出裸指针
                case TypeClassification::POINTER: {
                    auto *targetPtrType = (PointerType *) targetType;
                    if (targetPtrType->getTargetType()->equals(srcRefType->getTargetType())) {
                        return ReferenceType::getTargetPointer(context, srcLLVMValue);
                    } else {
                        goto DEFAULT;
                    }
                }
                DEFAULT:
                default: {
                    //TODO 目标引用目标类型是原引用目标类型的父类也可以
                    if (!srcRefType->getTargetType()->equals(targetType)) goto UNSUPPORTED;
                    llvm::Value *srcRightLLVMVal = generateLLVMKindConvert(d, context, srcLLVMValue, srcKind,
                                                                           ValueKind::VALUE);
                    llvm::Value *targetLLVMPtr = ReferenceType::getTargetPointer(context, srcRightLLVMVal);
                    targetLLVMPtr = irBuilder->CreateBitCast(targetLLVMPtr, llvm::PointerType::get(targetLLVMType, 0U));
                    return generateLLVMKindConvert(d, context, targetLLVMPtr, ValueKind::VARIABLE, targetKind);
                }
            }
            break;
        }
        default:
            goto UNSUPPORTED;
    }

    UNSUPPORTED:
    d.getReport()->error(IncompatibleTypeError(d, L"不支持的类型转换：" + srcType->getName() + L" 到 " + targetType->getName()),
                         ErrorBehavior::CANCEL_EXPRESSION);
}

bool ValueDescriptor::equals(const ValueDescriptor &target) const noexcept
{
    if(this->kind != target.kind) return false;
    if(!this->type || !this->type->equals(target.type)) return false;
    return true;
}

llvm::Value* ValueDescriptor::getLLVMValue(const DebugInfo &d, GenerateContext *context) noexcept
{
    if (this->llvmValue) {
        return this->llvmValue;
    }
    else {
        if(this->kind == ValueKind::VALUE){
            if(!this->value){
                throw InternalException(L"GeneralSymbolInfo::getLLVMValue() ValueDescriptor的kind为VALUE时，必须指定value");
            }
            return this->llvmValue = this->value->generateIR(context);
        }else { //ValueKind::VARIABLE
            auto builder = context->getIRBuilder();
            return this->llvmValue = builder->CreateAlloca(this->type->getLLVMType(context), nullptr);
        }
    }
}