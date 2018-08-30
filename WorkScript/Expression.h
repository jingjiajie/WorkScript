#pragma once
#include <iostream>
#include "Defines.h"
#include "WorkScriptException.h"
#include "TypeInfo.h"
#include "CompileContext.h"

class Expression;
class TypeExpression;
class Context;
class StringExpression;

enum class StorageLevel : unsigned char {
	TEMP = 0,
	LOCAL = 1,
	TRANSFER = 2,
	LITERAL = 3,
	EXTERN = 4,
};

class Expression
{
public:
	inline Expression() {};
	virtual ~Expression();
	//需要实现的接口函数
	virtual Expression* const evaluate(Context *const& context) = 0;
	virtual TypeExpression* const getType(Context *const& context) const = 0;
	virtual StringExpression *const toString(Context *const& context) = 0;
	virtual void compile(CompileContext *const& context) = 0;
	virtual bool equals(Context *const &context, Expression* const&) const = 0;

	//已经实现的非虚函数
	inline void upgradeStorageLevel(const StorageLevel level)
	{
		if (this->storageLevel < level)this->storageLevel = level;
	}

	inline StorageLevel getStorageLevel() const
	{
		return this->storageLevel;
	}

	inline void setStorageLevel(const StorageLevel level = StorageLevel::TEMP)
	{
		this->storageLevel = level;
	}

	inline void releaseTemp()
	{
		if (this->storageLevel > StorageLevel::TEMP)return;
		this->release();
	}

	inline void releaseLocal()
	{
		if (this->storageLevel > StorageLevel::LOCAL)return;
		this->release();
	}

	inline void releaseTransfer()
	{
		if (this->storageLevel > StorageLevel::TRANSFER)return;
		this->release();
	}

	inline void releaseExtern()
	{
		if (this->storageLevel > StorageLevel::EXTERN)return;
		this->release();
	}

	inline void releaseLiteral()
	{
		if (this->storageLevel > StorageLevel::LITERAL)return;
		this->release();
	}

	inline void release(const StorageLevel level)
	{
		if (this->storageLevel > level)return;
		this->release();
	}

	////已经实现的虚函数
	//virtual const std::vector<TypeMemberExpression *> getInstantialExpressions() const;
	//virtual void addInstantialExpressions(TypeMemberExpression* const &expr);
protected:
	//std::vector<TypeMemberExpression *> instantialExpressions;
	StorageLevel storageLevel = StorageLevel::TEMP;

	virtual void release()
	{
		delete this;
	}
};