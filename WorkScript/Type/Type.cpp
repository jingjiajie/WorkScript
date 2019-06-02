#include <Tree/Constant.h>
#include "Type.h"
#include "Expression.h"
#include "Module.h"
#include "Function.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "VoidType.h"
#include "Exception.h"
#include "ReferenceType.h"

using namespace WorkScript;
using namespace std;

const LinkageType LinkageType::INTERNAL(LinkageType::Classification::INTERNAL);
const LinkageType LinkageType::EXTERNAL(LinkageType::Classification::EXTERNAL);

//bool Type::isSubTypeOf(const Type *abstractType) const
//{
//	const Type *curType = this;
//	while (curType) {
//		if (curType->equals(abstractType)) {
//			return true;
//		}
//		if (curType->baseType != nullptr && curType->baseType != curType) {
//			curType = curType->baseType;
//		}
//		else {
//			return false;
//		}
//	}
//	return false;
//}
//
//void WorkScript::Type::addMemberFunction(Function * func)
//{
//	this->getModule()->addFunction(func);
//	this->memberFunctions[func->getName()] = func;
//}

Type * Type::getPromotedType(const DebugInfo &d, Type * left, Type * right)
{
    if (!left)return right;
    if (!right)return left;
    switch (left->getClassification())
    {
        case TypeClassification::INTEGER:
        {
            IntegerType *leftIntegerType = (IntegerType *) left;
            switch (right->getClassification())
            {
                case TypeClassification::INTEGER:
                {
                    IntegerType *rightIntegerType = (IntegerType *) right;
                    auto leftLen = leftIntegerType->getLength();
                    auto rightLen = rightIntegerType->getLength();
                    if (leftLen > rightLen) return left;
                    else if (leftLen < rightLen) return right;
                    else if (leftIntegerType->isSigned() && !rightIntegerType->isSigned()) return right;
                    else if (!leftIntegerType->isSigned() && rightIntegerType->isSigned()) return left;
                    else return left;
                }
                case TypeClassification::FLOAT:
                {
                    return right;
                }
                default:
                    goto UNSUPPORTED;
            }
        }

        case TypeClassification::FLOAT:
        {
            FloatType *leftFloatType = (FloatType *) left;
            switch (right->getClassification())
            {
                case TypeClassification::INTEGER:
                {
                    return left;
                }
                case TypeClassification::FLOAT:
                {
                    FloatType *rightFloatType = (FloatType *) right;
                    if (leftFloatType->getLength() > rightFloatType->getLength()) return left;
                    else return right;
                }
                default:
                    goto UNSUPPORTED;
            }
        }
        case TypeClassification::POINTER:
        {
            auto leftPtr = (PointerType *) left;
            switch (right->getClassification())
            {
                case TypeClassification::POINTER:
                {
                    auto rightPtr = (PointerType *) right;
                    if (leftPtr->getLevel() != rightPtr->getLevel()) goto UNSUPPORTED;
                    bool isConst = false, isVolatile = false;
                    //if (left->isConst() || right->isConst()) isConst = true;
                    //if (left->isVolatile() || right->isVolatile()) isVolatile = true;
                    //TODO 指针类型的const和volatile，由于有pointerlevel，故应该支持各级的cv
                    try
                    {
                        return PointerType::get(getPromotedType(d, leftPtr->getTargetType(), rightPtr->getTargetType()),
                                                leftPtr->getLevel(),
                                                false, false);
                    } catch (const IncompatibleTypeError &)
                    {
                        goto UNSUPPORTED;
                    }
                }
                default:
                    goto UNSUPPORTED;
            }
        }
        case TypeClassification::REFERENCE:{
            auto leftRef = (ReferenceType*)left;
            switch(right->getClassification()){
                case TypeClassification::REFERENCE:{
                    auto rightRef = (ReferenceType*)right;
                    try {
                        return ReferenceType::get(
                                getPromotedType(d, leftRef->getTargetType(), rightRef->getTargetType()));
                    }catch (const IncompatibleTypeError &){
                        goto UNSUPPORTED;
                    }
                }
                default: goto UNSUPPORTED;
            }
        }
        case TypeClassification::VOID:
            if (right->getClassification() == TypeClassification::VOID)
            {
                return left;
            } else
            {
                goto UNSUPPORTED;
            }
        default:
            goto UNSUPPORTED;
    }

    UNSUPPORTED:
	d.getReport()->error(IncompatibleTypeError(d, L"不支持的类型转换" + left->getName() + L" 和 " + right->getName()), ErrorBehavior::CANCEL_EXPRESSION);
}

//GenerateResult Type::generateLLVMTypeConvert(const DebugInfo &d, GenerateContext * context, Expression * left, Expression * right, Type *promotedType)
//{
//	auto builder = context->getIRBuilder();
//	Type *leftType = left->getType(context);
//	Type *rightType = right->getType(context);
//	if (promotedType->equals(leftType)) { //类型提升到左部类型
//		return GenerateResult(left->generateIR(context).getValue(), Type::generateLLVMTypeConvert(d, context, right, promotedType).getValue());
//	}
//	else if (promotedType->equals(rightType)) { //类型提升到右部类型
//		return GenerateResult(Type::generateLLVMTypeConvert(d, context, left, promotedType).getValue(), right->generateIR(context).getValue());
//	}
//	else { //两边都需要提升
//		return GenerateResult(
//			Type::generateLLVMTypeConvert(d, context, left, promotedType).getValue(),
//			Type::generateLLVMTypeConvert(d, context, right, promotedType).getValue()
//		);
//	}
//}


const std::wstring &LinkageType::toString() const noexcept
{
    static std::wstring internal = L"internal", external = L"external";
    switch (this->classification)
    {
        case Classification::INTERNAL:
            return internal;
        default: //EXTERNAL
            return external;
    }
}

std::wstring Type::toString() const noexcept
{
    return this->getName();
}
