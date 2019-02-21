#include "Type.h"
#include "Expression.h"
#include "Program.h"
#include "Function.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "VoidType.h"
#include "Exception.h"

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
//	this->getProgram()->addFunction(func);
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


bool WorkScript::Type::convertableTo(const DebugInfo &d, Type * src, Type * target)
{
	if (src->equals(target))return true;
	switch (src->getClassification())
	{
		case TypeClassification::FLOAT:
		case TypeClassification::INTEGER:
		{
			switch (target->getClassification())
			{
				case TypeClassification::FLOAT:
				case TypeClassification::INTEGER:
				{
					return true;
				}
				default:
					return false;
			}
			break;
		}
		case TypeClassification::VOID:
			return target->getClassification() == TypeClassification::VOID;
		case TypeClassification::POINTER:
		{
			PointerType *srcPtr = (PointerType*)src;
			switch (target->getClassification())
			{
				case TypeClassification::POINTER:
				{
					PointerType *targetPtr = (PointerType*)target;
					if(srcPtr->getLevel() != targetPtr->getLevel()) return false;
					if(targetPtr->getTargetType()->getClassification() == TypeClassification::VOID) return true; //任何类型都可以转换为void*
					if(srcPtr->getTargetType()->getClassification() == TypeClassification::VOID) return true; //void*可以转换为任何类型
					return Type::convertableTo(d, srcPtr->getTargetType(),targetPtr->getTargetType());
				}
				default:
					return false;
			}
			break;
		}
		default:
			return false;
	}
}

bool WorkScript::Type::convertableTo(const DebugInfo &d, Type * target)
{
	return Type::convertableTo(d, this, target);
}

GenerateResult Type::generateLLVMTypeConvert(const DebugInfo &d, GenerateContext * context, Expression * left, Expression * right, Type *promotedType)
{
	auto builder = context->getIRBuilder();
	Type *leftType = left->getType(context);
	Type *rightType = right->getType(context);
	if (promotedType->equals(leftType)) { //类型提升到左部类型
		return GenerateResult(left->generateIR(context).getValue(), Type::generateLLVMTypeConvert(d, context, right, promotedType).getValue());
	}
	else if (promotedType->equals(rightType)) { //类型提升到右部类型
		return GenerateResult(Type::generateLLVMTypeConvert(d, context, left, promotedType).getValue(), right->generateIR(context).getValue());
	}
	else { //两边都需要提升
		return GenerateResult(
			Type::generateLLVMTypeConvert(d, context, left, promotedType).getValue(),
			Type::generateLLVMTypeConvert(d, context, right, promotedType).getValue()
		);
	}
}

GenerateResult Type::generateLLVMTypeConvert(const DebugInfo &d, GenerateContext * context, Expression * expr, Type * targetType) {
    Type *srcType = expr->getType(context);
    llvm::Value *srcValue = expr->generateIR(context).getValue();
    if (targetType->equals(srcType)) {
        return GenerateResult(srcValue);
    }
    llvm::Type *targetLLVMType = targetType->getLLVMType(context);
    auto irBuilder = context->getIRBuilder();

    switch (srcType->getClassification()) {
        case TypeClassification::INTEGER: /*源类型为Integer*/ {
            IntegerType *srcIntegerType = (IntegerType *) srcType;
            switch (targetType->getClassification()) {
                case TypeClassification::INTEGER:/*目标类型为Integer*/ {
                    IntegerType *targetIntegerType = (IntegerType *) targetType;
                    //如果长度相同，仅仅有无符号不同，则不用进行转换
                    if (srcIntegerType->getLength() == targetIntegerType->getLength())return GenerateResult(srcValue);
                    //否则根据是否有符号进行符号扩展或零位扩展
                    if (srcIntegerType->isSigned()) {
                        return irBuilder->CreateSExt(srcValue, targetLLVMType);
                    } else {
                        return irBuilder->CreateZExt(srcValue, targetLLVMType);
                    }
                }
                case TypeClassification::FLOAT: /*目标类型为Float*/ {
                    if (srcIntegerType->isSigned()) return irBuilder->CreateSIToFP(srcValue, targetLLVMType);
                    else return irBuilder->CreateUIToFP(srcValue, targetLLVMType);
                }
                default:
                    goto UNSUPPORTED;
            }

        }

        case TypeClassification::FLOAT: /*源类型为Float*/ {
            FloatType *srcFloatType = (FloatType *) srcValue;
            switch (targetType->getClassification()) {
                case TypeClassification::INTEGER: /*目标类型为Integer*/ {
                    IntegerType *targetIntegerType = (IntegerType *) targetType;
                    if (targetIntegerType->isSigned()) return irBuilder->CreateFPToSI(srcValue, targetLLVMType);
                    else return irBuilder->CreateFPToUI(srcValue, targetLLVMType);
                }
                case TypeClassification::FLOAT: /*目标类型为Float*/ {
                    return irBuilder->CreateFPCast(srcValue, targetLLVMType);
                }
                default:
                    goto UNSUPPORTED;
            }

        }

        case TypeClassification::VOID: {
            switch (targetType->getClassification()) {
                case TypeClassification::VOID: {
                    return srcValue;
                }
                default:
                    goto UNSUPPORTED;
            }
        }

        case TypeClassification::POINTER:
            switch (targetType->getClassification()) {
                case TypeClassification::POINTER: {
                    return irBuilder->CreatePointerCast(srcValue, targetLLVMType);
                }
                case TypeClassification::INTEGER: {
                    return irBuilder->CreateBitOrPointerCast(srcValue, targetLLVMType);
                }
                default:
                    goto UNSUPPORTED;
            }
        default:
            goto UNSUPPORTED;
    }

    UNSUPPORTED:
    d.getReport()->error(IncompatibleTypeError(d, L"不支持的类型转换：" + srcType->getName() + L" 到 " + targetType->getName()),
                         ErrorBehavior::CANCEL_EXPRESSION);
}

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
