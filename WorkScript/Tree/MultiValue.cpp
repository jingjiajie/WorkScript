#include <sstream>
#include "MultiValue.h"
#include "Type.h"
#include "Assignment.h"
#include "Utils.h"
#include "Exception.h"
#include "InstantialContext.h"
#include "Variable.h"

using namespace WorkScript;
using namespace std;

MultiValue::~MultiValue() noexcept
{
	for (Expression *expr : this->items)
	{
		delete expr;
	}
}

DeducedInfo MultiValue::deduce(InstantialContext *context) const
{
    vector<ValueDescriptor> descs;
    descs.reserve(items.size());
    for (size_t i = 0; i < items.size(); ++i)
    {
        DeducedInfo curInfo = this->items[i]->deduce(context);
        //如果遇到MultiValue的项，则展平
        if (!curInfo.isSingle())
        {
            vector<ValueDescriptor> curDescs = curInfo.getValueDescriptors();
            descs.insert(descs.end(), curDescs.begin(), curDescs.end());
        } else
        {
            descs.push_back(curInfo.getValueDescriptor());
        }
    }
    return DeducedInfo(descs);
}

std::wstring MultiValue::toString() const
{
	size_t itemCount = this->items.size();
	//如果有0项，直接返回空字符串就行了
	if (itemCount == 0) {
		return L"";
	}
	wstringstream ss;
	//否则返回逗号分隔的各项
	for (size_t i = 0; i < itemCount; ++i)
	{
		ss << this->items[i]->toString();
		if (i != itemCount - 1) ss << L", ";
	}
	return ss.str();
}

MultiValue * MultiValue::clone() const
{
	vector<Expression*> newItems;
	newItems.reserve(this->items.size());
	for (size_t i = 0; i < this->items.size(); ++i)
	{
		newItems[i] = this->items[i]->clone();
	}
	auto newInstance = new thistype(expressionInfo, newItems);
	return newInstance;
}

ExpressionType WorkScript::MultiValue::getExpressionType() const
{
	return ExpressionType::MULTI_VALUE;
}

GenerateResult WorkScript::MultiValue::generateIR(GenerateContext * context)
{
	throw InternalException(L"请调用getLLVMArgs()");
}

std::vector<llvm::Value*> MultiValue::getLLVMValues(GenerateContext *context, const vector<ValueDescriptor> &expectedDescs)
{
	std::vector<llvm::Value*> llvmValues;
	size_t expectedDescCount = expectedDescs.size();
	llvmValues.reserve(this->items.size());
	size_t curTotalLLVMValues = 0;
	for (Expression *item : this->items)
	{
		if(curTotalLLVMValues > expectedDescCount){
			throw InternalException(L"期待类型数量"+to_wstring(expectedDescCount)+L" 少于实际类型数量");
		}
		DeducedInfo curInfo = item->deduce(context);
		ValueDescriptor curDesc = curInfo;
		Type *curItemType = curDesc.getType();
		if (!curItemType)
		{
			this->expressionInfo.getDebugInfo().getReport()->error(
					UninferableTypeError(this->expressionInfo.getDebugInfo(), L"无法推导参数类型！"),
					ErrorBehavior::CANCEL_EXPRESSION);
		}else if(!curInfo.isSingle()){ //如果子项为MultiValue，则单独处理
			MultiValue *multiValueItem = nullptr;
			if(item->getExpressionType() == ExpressionType::MULTI_VALUE){
				multiValueItem = (MultiValue*)item;
			}else if(item->getExpressionType() == ExpressionType::VARIABLE){
				auto variable = (Variable*)item;
				multiValueItem = (MultiValue*)variable->getValue(context);
			}else{
				throw InternalException(L"未知的表达式生成了MultiValue类型的值");
			}
			const auto &itemLLVMValues = multiValueItem->getLLVMValues(context, vector<ValueDescriptor>(
					expectedDescs.begin() + llvmValues.size(), expectedDescs.end()));
			llvmValues.insert(llvmValues.end(),itemLLVMValues.begin(), itemLLVMValues.end());
			curTotalLLVMValues+=itemLLVMValues.size();
		}
		else if (curDesc.equals(expectedDescs[curTotalLLVMValues]))
		{
			llvm::Value *curLLVMParam = item->generateIR(context).getValue();
			llvmValues.push_back(curLLVMParam);
			++curTotalLLVMValues;
		} else {
			llvm::Value *convertedLLVMParam = ValueDescriptor::generateLLVMConvert(this->getDebugInfo(), context, item,
																				   expectedDescs[curTotalLLVMValues]).getValue();
			llvmValues.push_back(convertedLLVMParam);
			++curTotalLLVMValues;
		}
	}
	return llvmValues;
}

bool MultiValue::isNested(WorkScript::InstantialContext *context) const
{
	//如果是嵌套，只可能是变量被赋值为MultiValue，不可能直接写出来嵌套的MultiValue，在构造的时候就被展平了
	for(Expression *item : this->items){
		if(item->deduce(context).getValueDescriptor().getType()->getClassification() == TypeClassification::MULTI_VALUE){
			return true;
		}
	}
	return false;
}

//bool MultiValue::equals(Context * const & context, Expression *target) const
//{
//	if (!target->getType(context)->equals(context, this->getAbstractType(context))) {
//		return false;
//	}
//	auto targetListExpr = (const Pointer<MultiValue>)(target);
//	if (this->count != targetListExpr->count) return false;
//	for (size_t i = 0; i < this->count; ++i) {
//		if (!this->items[i]->equals(context, targetListExpr->items[i]))return false;
//	}
//	return true;
//}
//
//void MultiValue::flat()
//{
//	size_t flatLength = this->count;
//	for (size_t i = 0; i < this->count; ++i)
//	{
//		if (this->items[i]->getExpressionType() != ExpressionType::PARAMETER_EXPRESSION)continue;
//		flatLength += ((MultiValue*)this->items[i])->getCount() - 1;
//	}
//	//如果参数列表不包含参数列表，则不用展平，直接返回
//	if (flatLength == this->count)return;
//	auto oldItems = this->items;
//	size_t oldCount = this->count;
//	this->count = flatLength;
//	this->items.reserve(this->count);
//	size_t newPos = 0;
//	for (size_t oldPos = 0; oldPos < oldCount; ++oldPos) {
//		auto curOldItem = oldItems[oldPos];
//		if (curOldItem->getExpressionType() != ExpressionType::PARAMETER_EXPRESSION) {
//			this->items[newPos++] = curOldItem;
//		}
//		else {
//			for (size_t curOldItemPos = 0; curOldItemPos < ((MultiValue*)curOldItem)->getCount(); ++curOldItemPos)
//			{
//				this->items[newPos++] = ((MultiValue*)curOldItem)->items[curOldItemPos];
//			}
//		}
//	}
//}
