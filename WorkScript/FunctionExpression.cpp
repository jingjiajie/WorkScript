#include "stdafx.h"
#include "FunctionExpression.h"
#include "FunctionInvocationExpression.h"
#include "BooleanExpression.h"
#include "DuplicateDeclarationException.h"
#include "StringExpression.h"
#include "ParameterExpression.h"
#include "Context.h"
#include "CallStack.h"
#include "StackFrame.h"
#include "WorkScriptException.h"
#include "UninvocableException.h"
#include "Program.h"

using namespace std;

FunctionExpression::~FunctionExpression()
{
	for (size_t i = 0; i < this->overloads->size();++i) {
		delete (*this->overloads)[i];
	}
	delete this->overloads;
	if (this->name)delete[]this->name;
}

const Pointer<TypeExpression> FunctionExpression::getType(Context *const& context) const
{
	return TypeExpression::FUNCTION_EXPRESSION;
}

const Pointer<Expression> FunctionExpression::evaluate(Context *const &context)
{
	this->declareStackFrame = context->getStackFrame();
	this->declareStack = context->getCallStack();
	StackFrame *targetFrame = this->declareStackFrame->getBaseStackFrame(this->targetBlock);
	if (this->name != nullptr) {
		auto varExpr = targetFrame->getLocalVariable(this->offset);
		if (varExpr == nullptr) { //����������û���������������Ƿ���ڸ����ĺ��������������Ƿ���ڸ������������кϲ�
			targetFrame->setLocalVariable(this->offset, (const Pointer<Expression>&)this);
			return this;
		}
		else { //��������ҵ���ͬ����������ϲ�����
			if (!varExpr->getType(nullptr)->equals(nullptr, TypeExpression::FUNCTION_EXPRESSION)) {
				throw std::move(DuplicateDeclarationException((wstring(this->name) + L"�Ѿ����������������ظ�������").c_str()));
			}
			auto funcExpr = (const Pointer<FunctionExpression>&)varExpr;
			for (auto &overload : *this->overloads) {
				funcExpr->addOverload(overload);
			}
			this->overloads->clear();
			return funcExpr;
		}
	}
	else {
		return this;
	}
}

bool FunctionExpression::equals(Context *const &context, const Pointer<Expression>& targetExpression) const
{
	return targetExpression == this;
}

const Pointer<StringExpression> FunctionExpression::toString(Context *const &context)
{
	return StringExpression::newInstance((wstring(L"FunctionDeclaration(") + this->name + L")").c_str());
	//stringstream ss;
	//ss << this->functionName;
	//for (size_t i = 0; i < this->parameters.size(); ++i) {
	//	ss << "(" << this->parameters[i]->toString() << ")";
	//	if (i != subExpressionCount - 1) {
	//		ss << " ";
	//	}
	//}
	//return ss.str();
}

void FunctionExpression::link(LinkContext *const &context)
{
	auto symbolTable = context->getSymbolTable();
	if (context->getLinkTask() == LinkTask::SYMBOL_COLLECTING) {
		this->targetBlock = context->getBlock();
		if (this->name != nullptr) {
			symbolTable->setSymbolInfo(this->targetBlock, this->domain, this->domainAccess, this->name, true);
		}
		//���أ�������Լ����ʵ�֣�����������������
		for (auto &overload : *this->overloads) {
			BLOCK_ID subBlockID = symbolTable->newBlock(this->targetBlock);
			LinkContext subContext(context, subBlockID);
			overload->link(&subContext);
		}
	}
	else { //SYMBOL_BINDING
		if (this->name != nullptr) {
			//�����������ڵ�ǰ��������
			symbolTable->getLocalSymbolOffset(this->targetBlock, this->domain, this->name, &this->targetBlock, &this->offset);
			this->hasBaseFunction = symbolTable->getBaseSymbolOffset(this->targetBlock, this->domain, this->name, &this->baseFunctionBlock, &this->baseOffset);
		}
		//���أ�������Լ����ʵ�֣�����������������
		for (auto &overload : *this->overloads) {
			LinkContext subContext(context, 0); //���Ű󶨽׶β����½���block
			overload->link(&subContext);
		}
	}
}

Overload *const FunctionExpression::getMatchedOverload(const Pointer<ParameterExpression>& params, Context *const context) const
{
	StackFrame *frame = context->getStackFrame();
	for (auto &overload : *this->overloads) {
		if (overload->match(params, context)) {
			return overload;
		}
	}
	return nullptr;
}

const Pointer<Expression> FunctionExpression::invoke(const Pointer<ParameterExpression> &params) const
{
	StackFrame *newFrame = this->declareStack->newStackFrame(this->declareStackFrame, 0, 0);
	Context subContext(this->declareStack, newFrame);
	Overload *matchedOverload = this->getMatchedOverload(params, &subContext);
	if (matchedOverload != nullptr) {
		auto ret = matchedOverload->invoke(&subContext);
		this->declareStack->popStackFrame();
		return ret;
	}
	else {
		this->declareStack->popStackFrame();
		if (this->hasBaseFunction) {
			StackFrame *targetFrame = this->declareStackFrame->getBaseStackFrame(this->baseFunctionBlock);
			auto expr = targetFrame->getLocalVariable(this->baseOffset);
			if (!expr->getType(nullptr)->equals(nullptr, TypeExpression::FUNCTION_EXPRESSION)) {
				throw DuplicateDeclarationException((wstring(this->name) + L"�Ѿ��������������ظ�������").c_str());
			}
			auto funcExpr = (const Pointer<FunctionExpression>&)expr;
			return funcExpr->invoke(params);
		}
		else {
			return nullptr;
		}
	}
}

bool Overload::match(const Pointer<ParameterExpression> &params,Context *const &context) const
{
	size_t targetParamCount = params->getCount();
	size_t myParamCount = this->parameterCount;
	StackFrame *frame = context->getStackFrame();

	//������Ǳ�κ�������ʵ�ζ����βΣ���ֱ��ƥ��ʧ��
	if (targetParamCount > myParamCount && this->parameters[myParamCount - 1].isVarargs() == false) {
		return false;
	}

	//�����ȳ�ʼ��ջ֡
	frame->setBlockID(this->block);
	frame->resetLocalVariableCount(this->localVariableCount);

	//���ƥ��������������ͬ�����������һ��ͬ�����������֮ǰ��ֵ��ȣ�����ƥ��ʧ��
	//���Ŀ���������������������û���趨Ĭ��ֵ
	for (size_t i = 0; i < myParamCount; ++i) {
		//�����ǰ�β��Ѿ�����ʵ�θ��������ж��Ƿ���Ĭ��ֵ
		if (i + 1 > targetParamCount) { //ע�⣬����ֻ��i+1�������ұ�-1����Ϊsize_t�޷���
			Pointer<Expression>defaultValue = this->parameters[i].getDefaultValue();
			if (!defaultValue)return false;
			frame->setLocalVariable(this->parameters[i].getOffset(), defaultValue->evaluate(context));
		}
		//��������һ������������ǰ���Ѿ��жϹ�������ʵ�θ���һ�����ڵ����βθ�����
		//���ʵ�ζ����βΣ���ƥ���κ�����������ͨ����
		else if (i == myParamCount - 1 
			&& i < targetParamCount - 1
			&& this->parameters[i].isVarargs()) {
			size_t restParamCount = targetParamCount - myParamCount + 1;
			Pointer<Expression> *restParamItems = new Pointer<Expression>[restParamCount];
			for (size_t i = 0; i < restParamCount; ++i)
			{
				restParamItems[i] = params->getItem(myParamCount - 1 + i);
			}
			auto restParamList = new ParameterExpression(restParamItems,restParamCount);
			frame->setLocalVariable(this->parameters[i].getOffset(), restParamList);
			Pointer<Expression> prev = nullptr;
			if ((prev = frame->getLocalVariable(this->parameters[i].getOffset())) != nullptr) {
				if (!prev->equals(context, restParamList))return false;
			}
		}
		else {
			Pointer<Expression> prev = nullptr;
			if ((prev = frame->getLocalVariable(this->parameters[i].getOffset())) != nullptr) {
				if (!prev->equals(context, params->getItems()[i]))return false;
			}
			frame->setLocalVariable(this->parameters[i].getOffset(), params->getItems()[i]);
		}
	}
	//��֤Լ���Ƿ���ϣ����в�������ƥ��ʧ��
	try {
		for (size_t i = 0; i < this->constraintCount; ++i) {
			Pointer<Expression> res =  this->constraints[i]->evaluate(context);
			if (!res->equals(context, BooleanExpression::VAL_YES))
			{
				return false;
			}
		}
	}
	catch (const WorkScriptException&) {
		return false;
	}
	return true;
}

const Pointer<Expression> Overload::invoke(Context *context) const
{
	INVOKE_START:
	for (size_t i = 0; i < this->implementCount-1; ++i)
	{
		this->implements[i]->evaluate(context);
	}
	//���һ�����Ľ����Ϊ����ֵ
	Pointer<Expression> lastImpl = this->implements[implementCount - 1];
	if (lastImpl->getType(nullptr)->equals(nullptr, TypeExpression::FUNCTION_INVOCATION_EXPRESSION)) {
		auto invocation = ((Pointer<FunctionInvocationExpression>)lastImpl);
		auto func = invocation->getFunctionExpression(context); //Ŀ�꺯��
		auto params = invocation->getEvaluatedParameters(context); //ʵ��
		//getMatchedOverload()�Ѿ���ƥ���ʵ��д�뵽context�С�
		if (func->getDeclareStackFrame() == context->getStackFrame()) {
			StackFrame *newFrame = context->getCallStack()->newStackFrame(context->getStackFrame(),this->block, 0);
			context->setStackFrame(newFrame);
		}
		else {
			context->getStackFrame()->setBaseStackFrame(func->getDeclareStackFrame());
		}
		Overload *matchedOverload = func->getMatchedOverload(params, context);
		if (matchedOverload == nullptr) {
			throw std::move(UninvocableException((L"δ�ҵ�ƥ���" + wstring(func->getName()) + L"������").c_str()));
		}
		else if (matchedOverload == this) {	//β�ݹ��Ż�
			goto INVOKE_START;
		}
		else {
			auto ret = matchedOverload->invoke(context);
			//if (createdNewFrame) targetContext->getCallStack()->popStackFrame();
			return ret;
		}
	}
	else {
		return lastImpl->evaluate(context);
	}
}

void Overload::link(LinkContext *const &context)
{
	SymbolTable *symbolTable = context->getSymbolTable();
	if (context->getLinkTask() == LinkTask::SYMBOL_COLLECTING) {
		this->block = context->getBlock();
		//�����б�
		for (size_t i = 0; i < this->parameterCount; ++i) {
			auto curVarName = this->parameters[i].getParameterName();
			symbolTable->setSymbolInfo(this->block, this->functionExpression->getDomain(), DomainAccess::PUBLIC, curVarName, true);
		}
	}
	else { //SYMBOL_BINDING
		//�����б��ƫ��
		for (size_t i = 0; i < this->parameterCount; ++i) {
			auto curVarName = this->parameters[i].getParameterName();
			BLOCK_ID targetBlock; //�϶�Ϊ��block��������������block
			size_t targetOffset; //����������ƫ��
			symbolTable->getLocalSymbolOffset(this->block, this->functionExpression->getDomain(), curVarName, &targetBlock, &targetOffset);
			this->parameters[i].setOffset(targetOffset);
		}
		//��ȡ�ֲ���������
		this->localVariableCount = symbolTable->getTotalSymbolCount(this->block);
	}

	//Լ���б�
	for (size_t i = 0; i < this->constraintCount; ++i) {
		this->constraints[i]->link(context);
	}
	//ʵ��
	for (size_t i = 0; i < this->implementCount; ++i) {
		this->implements[i]->link(context);
	}
}