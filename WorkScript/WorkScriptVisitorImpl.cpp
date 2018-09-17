#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <boost/locale.hpp>
#include <math.h>
#include <limits.h>
#include "WorkScriptVisitorImpl.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "ExpressionWrapper.h"
#include "TypeExpression.h"
#include "PlusExpression.h"
#include "MinusExpression.h"
#include "MemberEvaluateExpression.h"
#include "MultiplyExpression.h"
#include "DivideExpression.h"
#include "FunctionInvocationExpression.h"
#include "FunctionExpression.h"
#include "GreaterThanExpression.h"
#include "ListExpression.h"
#include "VariableExpression.h"
#include "EqualsExpression.h"
#include "AssignmentExpression.h"
#include "ParameterExpression.h"
#include "GreaterThanEqualExpression.h"
#include "LessThanEqualExpression.h"
#include "LessThanExpression.h"
#include "NegativeExpression.h"
#include "IntegerExpression.h"
#include "ModulusExpression.h"
#include "ByteExpression.h"
#include "Pointer.h"
#include "SyntaxErrorException.h"

#define FORBID_ASSIGN \
this->assignable = false; 

#define ALLOW_ASSIGN \
this->assignable = true; 

#define STORE_FORBID_ASSIGN \
bool oriAssignable = this->assignable; \
FORBID_ASSIGN 

#define STORE_ALLOW_ASSIGN \
bool oriAssignable = this->assignable; \
ALLOW_ASSIGN 

#define RESTORE_ASSIGNABLE \
this->assignable = oriAssignable; 

using namespace std;

antlrcpp::Any WorkScriptVisitorImpl::visitIncludeCommand(WorkScriptParser::IncludeCommandContext *ctx)
{
	string utf8FileName = ctx->STRING()->getText();
	utf8FileName = utf8FileName.substr(1, utf8FileName.size() - 2);
	wstring wFileName = boost::locale::conv::to_utf<wchar_t>(utf8FileName, "UTF-8");
	this->program->addIncludeFile(wFileName.c_str());
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx)
{
	if (ctx->DOUBLE()) {
		double value = 0;
		int len = sscanf(ctx->DOUBLE()->getText().c_str(), "%lf", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(DoubleExpression::newInstance(value));
	}
	else {
		int value = 0;
		int len = sscanf(ctx->INTEGER()->getText().c_str(), "%d", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(IntegerExpression::newInstance(value));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string text = ctx->STRING()->getText();
	text = text.substr(1, text.length() - 2);
	wstring wtext = boost::locale::conv::to_utf<wchar_t>(text, "UTF-8");

	wchar_t *unescapedText = new wchar_t[wtext.length() + 1];
	try {
		this->handleEscapeCharacters(wtext.c_str(), unescapedText, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1);
	}
	catch(...){
		delete[]unescapedText;
		throw;
	}
	auto lpExpr = StringExpression::newInstance(unescapedText);
	delete[]unescapedText;
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx)
{
	string boolStr = ctx->BOOLEAN()->getText();
	if (boolStr == "true") {
		return ExpressionWrapper(BooleanExpression::VAL_TRUE);
	}
	else if (boolStr == "yes") {
		return ExpressionWrapper(BooleanExpression::VAL_YES);
	}
	else if (boolStr == "ok") {
		return ExpressionWrapper(BooleanExpression::VAL_OK);
	}
	else if (boolStr == "good") {
		return ExpressionWrapper(BooleanExpression::VAL_GOOD);
	}
	else if (boolStr == "false") {
		return ExpressionWrapper(BooleanExpression::VAL_FALSE);
	}
	else if (boolStr == "no") {
		return ExpressionWrapper(BooleanExpression::VAL_NO);
	}
	else if (boolStr == "bad") {
		return ExpressionWrapper(BooleanExpression::VAL_BAD);
	}
	else {
		throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, (L"无法识别的布尔值：" + boost::locale::conv::to_utf<wchar_t>(boolStr, "UTF-8")).c_str()));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->identifier()->getText();
	auto expr = new VariableExpression(boost::locale::conv::to_utf<wchar_t>(varName, "UTF-8").c_str());
	expr->setDomain(this->domain);
	expr->setDomainAccess(this->getDomainAccess(this->curDepth));
	expr->setDeclarable(this->declarable); //等号左边的变量才可以创建声明
	auto wrapper = ExpressionWrapper(expr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ALLOW_ASSIGN;
	/*====深入下一层====*/
	++this->curDepth;
	//函数的实现
	Pointer<Expression>*impls;
	size_t implCount;
	if (ctx->functionImplementationExpression()->expression() != nullptr) {
		auto expr = (ExpressionWrapper)ctx->functionImplementationExpression()->expression()->accept(this);
		if (expr.getLifeCycle() == ExpressionLifeCycle::ALL) {
			implCount = 1;
			impls = new Pointer<Expression>[1];
			impls[0] = (expr).getExpression();
		}
		else {
			implCount = 0;
			impls = nullptr;
		}
	}
	else {
		auto exprs = ctx->functionImplementationExpression()->blockExpression()->expression();
		size_t maxImplCount = exprs.size();
		impls = new Pointer<Expression>[maxImplCount];
		implCount = 0;
		for (size_t i = 0; i < maxImplCount; ++i)
		{
			auto wrapper = (ExpressionWrapper)exprs[i]->accept(this);
			if (wrapper.getLifeCycle() == ExpressionLifeCycle::ALL) {
				impls[implCount] = wrapper.getExpression();
				++implCount;
			}
		}
	}
	FORBID_ASSIGN

	//函数的参数和限制
	ExpressionWrapper paramsWrapper = ctx->functionDeclarationExpression()->parameterExpression()->accept(this);
	auto paramExpr = (const Pointer<ParameterExpression> &)(paramsWrapper.getExpression());
	size_t paramCount = paramExpr->getCount();
	ParameterInfo *paramInfos = new ParameterInfo[paramCount]();
	vector<Pointer<Expression>> vecConstraints; //函数的限制，由字面声明和语法糖编译两部分组成
	//首先是语法糖编译，包括约束和默认值
	for (size_t i = 0; i < paramCount; ++i) {
		if (paramExpr->getItem(i)->getType(nullptr)->equals(nullptr, TypeExpression::VARIABLE_EXPRESSION)) {
			Pointer<VariableExpression> varExpr = paramExpr->getItem(i);
			paramInfos[i].setParameterName(varExpr->getName());
			paramInfos[i].setVarargs(varExpr->isVarargs());
		}
		else if (paramExpr->getItem(i)->getType(nullptr)->isSubTypeOf(nullptr, TypeExpression::BINARY_COMPARE_EXPRESSION)) {
			Pointer<VariableExpression>leftVar = ((Pointer<BinaryCompareExpression>)paramExpr->getItem(i))->getLeftVariable();
			if (leftVar == nullptr) {
				throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, L"函数参数约束左部必须为变量！"));
			}
			vecConstraints.push_back(paramExpr->getItem(i));
			paramInfos[i].setParameterName(leftVar->getName());
		}
		else if (paramExpr->getItem(i)->getType(nullptr)->isSubTypeOf(nullptr, TypeExpression::ASSIGNMENT_EXPRESSION)) {
			Pointer<AssignmentExpression>assignmentExpr = (Pointer<AssignmentExpression>)paramExpr->getItem(i);
			auto leftExpr = assignmentExpr->getLeftExpression();
			if (!leftExpr->getType(nullptr)->equals(nullptr, TypeExpression::VARIABLE_EXPRESSION)){
				throw std::move(SyntaxErrorException(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1, L"参数默认值左部必须为参数名！"));
			}
			auto leftVar = (Pointer<VariableExpression>)leftExpr;
			paramInfos[i].setParameterName(leftVar->getName());
			paramInfos[i].setDefaultValue(assignmentExpr->getRightExpression());
		}else{
			wstring tmpVarName = L"_" + to_wstring(i);
			paramInfos[i].setParameterName(tmpVarName.c_str());
			const Pointer<EqualsExpression>constraint = new EqualsExpression();
			Pointer<VariableExpression> paramVar = new VariableExpression(tmpVarName.c_str());
			paramVar->setDomain(this->domain);
			paramVar->setDomainAccess(DomainAccess::PUBLIC);
			constraint->setLeftExpression(paramVar);
			constraint->setRightExpression(paramExpr->getItem(i));
			vecConstraints.push_back(constraint);
		}
	}
	//然后是字面声明
	if (ctx->functionConstraintExpression() != nullptr) {
		if (ctx->functionConstraintExpression()->expression() != nullptr) {
			auto expr = ((ExpressionWrapper)ctx->functionConstraintExpression()->expression()->accept(this)).getExpression();
			vecConstraints.push_back(expr);
		}
		else {
			for (auto &subCtx : ctx->functionConstraintExpression()->blockExpression()->expression()) {
				vecConstraints.push_back(((ExpressionWrapper)subCtx->accept(this)).getExpression());
			}
		}
	}

	/*====恢复上一层====*/
	--this->curDepth;

	Pointer<FunctionExpression> funcExpr = new FunctionExpression();
	auto funcNameCtx = ctx->functionDeclarationExpression()->identifier();
	if (funcNameCtx == nullptr) {
		funcExpr->setName(nullptr);
	}
	else {
		string funcName = funcNameCtx->getText();
		funcExpr->setName(boost::locale::conv::to_utf<wchar_t>(funcName, "UTF-8").c_str());
	}

	Pointer<Expression> *constraints = new Pointer<Expression>[vecConstraints.size()];
	for (size_t i = 0; i < vecConstraints.size(); ++i) {
		constraints[i] = vecConstraints[i];
	}

	auto overload = new Overload;
	overload->setParameterInfos(paramInfos,paramCount);
	overload->setConstraints(constraints, vecConstraints.size());
	overload->setImplements(impls, implCount);
	funcExpr->addOverload(overload);

	RESTORE_ASSIGNABLE;
	funcExpr->setDomain(this->domain);
	auto funcName = funcExpr->getName();
	auto access = this->getDomainAccess(this->curDepth);
	funcExpr->setDomainAccess(this->getDomainAccess(this->curDepth));
	return ExpressionWrapper(funcExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper expressionWrapper = ctx->expression()->accept(this);
	ExpressionWrapper paramExpressionWrapper = ctx->parameterExpression()->accept(this);
	auto termExpr = (const Pointer<Expression> &)(expressionWrapper.getExpression());
	auto paramExpr = (const Pointer<ParameterExpression> &)(paramExpressionWrapper.getExpression());
	auto expr = new FunctionInvocationExpression();
	expr->setLeftExpression(termExpr);
	expr->setParameters(paramExpr);
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	auto includeCommands = ctx->includeCommand();
	for (auto &command : includeCommands) {
		command->accept(this);
	}

	auto exprs = ctx->expression();
	for (auto &expr : exprs)
	{
		ALLOW_ASSIGN; //每次新的一行都允许赋值
		ExpressionWrapper ret = expr->accept(this);
		if (ret.getLifeCycle() == ExpressionLifeCycle::ALL) {
			this->program->pushExpression(ret.getExpression());
		}
	}
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx)
{
	if (this->assignable) {
		STORE_FORBID_ASSIGN;
		this->declarable = true;
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
		this->declarable = false;
		auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new AssignmentExpression(left, right));
	}
	else {
		STORE_FORBID_ASSIGN;
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
		auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new EqualsExpression(left, right));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE
		return ExpressionWrapper(new AssignmentExpression(left, right));
}

antlrcpp::Any WorkScriptVisitorImpl::visitEqualsExpression(WorkScriptParser::EqualsExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(new EqualsExpression(left, right));
}

antlrcpp::Any WorkScriptVisitorImpl::visitParameterExpression(WorkScriptParser::ParameterExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->parameterExpressionItem();
	size_t subContextCount = subContext.size();
	auto items = new Pointer<Expression>[subContextCount];
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		Pointer<Expression> itemExpr = wrapper.getExpression();
		items[i] = itemExpr;
	}
	auto expr = new ParameterExpression(items, subContextCount);
	RESTORE_ASSIGNABLE
	return ExpressionWrapper(expr);
}

//antlrcpp::Any WorkScriptVisitorImpl::visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext *ctx)
//{
//	auto objExprCtx = ctx->expression()[0];
//	ExpressionWrapper objExprWrapper = objExprCtx->accept(this);
//	auto objExpr = objExprWrapper.getExpression();
//	auto memberExprCtx = ctx->expression()[1];
//	ExpressionWrapper memberExprWrapper = memberExprCtx->accept(this);
//	auto memberExpr = memberExprWrapper.getExpression();
//	return ExpressionWrapper(Pointer<Expression>(new MemberEvaluateExpression(this->context,objExpr,memberExpr)));
//}

antlrcpp::Any WorkScriptVisitorImpl::visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE
	if (ctx->PLUS()) {
		return ExpressionWrapper(new PlusExpression(leftExpression, rightExpression));
	}
	else { //MINUS
		return ExpressionWrapper(new MinusExpression(leftExpression, rightExpression));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE
		if (ctx->DIVIDE()) { //DIVIDE
			return ExpressionWrapper(new DivideExpression(leftExpression, rightExpression));
		}
		else if (ctx->MODULUS()) {
			return ExpressionWrapper(new ModulusExpression(leftExpression,rightExpression));
		}//乘号可以省略
		else{
			return ExpressionWrapper(new MultiplyExpression(leftExpression, rightExpression));
		}
}

antlrcpp::Any WorkScriptVisitorImpl::visitNonSignMultiplyExpression(WorkScriptParser::NonSignMultiplyExpressionContext *ctx)
{
	ExpressionWrapper leftWrapper = ctx->numberExpression()->accept(this);
	ExpressionWrapper rightWrapper = ctx->variableExpression()->accept(this);
	auto expr = new MultiplyExpression(leftWrapper.getExpression(), rightWrapper.getExpression());
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		auto ret = ctx->expression()->accept(this);
	RESTORE_ASSIGNABLE
		return ret;
}

antlrcpp::Any WorkScriptVisitorImpl::visitCompareExpression(WorkScriptParser::CompareExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	ExpressionWrapper wrapperLeft = ctx->expression()[0]->accept(this);
	ExpressionWrapper wrapperRight = ctx->expression()[1]->accept(this);
	auto leftExpression = wrapperLeft.getExpression();
	auto rightExpression = wrapperRight.getExpression();
	RESTORE_ASSIGNABLE
	if (ctx->GREATER_THAN()) {
		return ExpressionWrapper(new GreaterThanExpression(leftExpression, rightExpression));
	}
	else if (ctx->GREATER_THAN_EQUAL()) {
		return ExpressionWrapper(new GreaterThanEqualExpression(leftExpression, rightExpression));
	}
	else if (ctx->LESS_THAN()) {
		return ExpressionWrapper(new LessThanExpression(leftExpression, rightExpression));
	}
	else {
		return ExpressionWrapper(new LessThanEqualExpression(leftExpression, rightExpression));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	auto expr = new ListExpression();
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
		expr->addItem(itemExpr);
	}
	RESTORE_ASSIGNABLE
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitNegativeExpression(WorkScriptParser::NegativeExpressionContext *ctx)
{
	ExpressionWrapper wrapper = ctx->expression()->accept(this);
	auto expr = new NegativeExpression(wrapper.getExpression());
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitPositiveExpression(WorkScriptParser::PositiveExpressionContext *ctx)
{
	return ctx->expression()->accept(this);
}

antlrcpp::Any WorkScriptVisitorImpl::visitVarargsExpression(WorkScriptParser::VarargsExpressionContext *ctx)
{
	ExpressionWrapper varWrapper = ctx->variableExpression()->accept(this);
	Pointer<VariableExpression> varExpr = varWrapper.getExpression();
	varExpr->setVarargs(true);
	return varWrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitParameterExpressionItem(WorkScriptParser::ParameterExpressionItemContext *ctx)
{
	if (ctx->expression()) {
		return ctx->expression()->accept(this);
	}
	else {
		return ctx->varargsExpression()->accept(this);
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitAccessLevelExpression(WorkScriptParser::AccessLevelExpressionContext *ctx)
{
	string level = ctx->ACCESS_LEVEL()->getText();
	if (level == "public") {
		this->setDomainAccess(this->curDepth, DomainAccess::PUBLIC);
	}
	else if (level == "private") {
		this->setDomainAccess(this->curDepth, DomainAccess::PRIVATE);
	}
	ExpressionWrapper ret;
	ret.setLifeCycle(ExpressionLifeCycle::COMPILE);
	return ret;
}

WorkScriptVisitorImpl::WorkScriptVisitorImpl(Program *lpProgram, DOMAIN_ID domain)
{
	this->program = lpProgram;
	this->setDomain(domain);
}

WorkScriptVisitorImpl::~WorkScriptVisitorImpl()
{
}

void WorkScriptVisitorImpl::handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr, size_t line, size_t column)const
{
#define SINGLE_ESCAPE_CASE(escapedChar,unescapedChar) \
		case escapedChar: \
		targetStr[targetPos] = unescapedChar; \
		++srcPos; \
		++targetPos; \
		state = NORMAL; \
		break; 

	//有限状态机解析转义符
	enum State {
		NORMAL, FINISH, ESCAPE_START, ESCAPE_OCT, ESCAPE_HEX
	};
	size_t escapeStartPos = 0;
	State state = NORMAL;
	size_t srcPos = 0, targetPos = 0;
	while (state != FINISH)
	{
		switch (state)
		{
		case NORMAL:{
			switch (srcStr[srcPos])
			{
			case L'\\':
				state = ESCAPE_START;
				++srcPos;
				break;
			case L'\0':
				state = FINISH;
				break;
			default:
				targetStr[targetPos] = srcStr[srcPos];
				++srcPos;
				++targetPos;
				break;
			}
			break;
		}
		case ESCAPE_START: {
			switch (srcStr[srcPos])
			{
				SINGLE_ESCAPE_CASE(L'n', L'\n');
				SINGLE_ESCAPE_CASE(L't', L'\t');
				SINGLE_ESCAPE_CASE(L'r', L'\r');
				SINGLE_ESCAPE_CASE(L'0', L'\0');
				SINGLE_ESCAPE_CASE(L'v', L'\v');
				SINGLE_ESCAPE_CASE(L'a', L'\a');
				SINGLE_ESCAPE_CASE(L'b', L'\b');
				SINGLE_ESCAPE_CASE(L'f', L'\f');
				SINGLE_ESCAPE_CASE(L'\'', L'\'');
				SINGLE_ESCAPE_CASE(L'\"', L'\"');
				SINGLE_ESCAPE_CASE(L'\\', L'\\');
			case 'x':
				state = ESCAPE_HEX;
				escapeStartPos = srcPos;
				++srcPos;
				break;
			case L'1':case L'2':case L'3':case L'4':case L'5':case L'6':case L'7':case L'8':case L'9':
				state = ESCAPE_OCT;
				escapeStartPos = srcPos;
				++srcPos;
				break;
			case L'\0':
				throw std::move(SyntaxErrorException(line, column, (L"转义符未结束：\"" + wstring(srcStr) + L"\"").c_str()));
			default:
				throw std::move(SyntaxErrorException(line, column, (wstring(L"不能识别的转义符\"\\") + srcStr[srcPos] + L"\"").c_str()));
			}
			break;
		}
		case ESCAPE_OCT: {
			switch (srcStr[srcPos])
			{
			case L'0': case L'1':case L'2':case L'3':case L'4':case L'5':case L'6':case L'7':case L'8':case L'9':
				++srcPos;
				break;
			default:
				size_t octLen = srcPos - escapeStartPos;
				wchar_t *dstr = new wchar_t[octLen + 1];
				for (int i = 0; i < octLen; i++) {
					dstr[i] = srcStr[escapeStartPos + i];
				}
				dstr[octLen] = L'\0';
				int octNum; //八进制数结果
				swscanf(dstr, L"%o", &octNum);
				delete[]dstr;
				targetStr[targetPos] = (wchar_t)octNum;
				++targetPos;
				state = NORMAL;
				break;
			}
		}
		case ESCAPE_HEX: {
			switch (srcStr[srcPos])
			{
			case L'0': case L'1':case L'2':case L'3':case L'4':case L'5':
			case L'6':case L'7':case L'8':case L'9':case L'a':case L'b':
			case L'c':case L'd':case L'e':case L'f':case L'A':case L'B':
			case L'C':case L'D':case L'E':case L'F':
				++srcPos;
				break;
			default:
				size_t hexLen = srcPos - escapeStartPos - 1;
				wchar_t *dstr = new wchar_t[hexLen + 1];
				for (int i = 0; i < hexLen; i++) {
					dstr[i] = srcStr[escapeStartPos + 1 + i];
				}
				dstr[hexLen] = L'\0';
				int hexNum; //十六进制数结果
				swscanf(dstr, L"%x", &hexNum);
				delete[]dstr;
				targetStr[targetPos] = (wchar_t)hexNum;
				++targetPos;
				state = NORMAL;
				break;
			}
		}
		}
	}
	targetStr[targetPos] = L'\0';
}

DomainAccess WorkScriptVisitorImpl::getDomainAccess(size_t depth) const
{
	auto it = this->domainAccesses.find(depth);
	if (it == this->domainAccesses.end())return DomainAccess::PUBLIC;
	else return it->second;
}

void WorkScriptVisitorImpl::setDomainAccess(size_t depth, DomainAccess level)
{
	this->domainAccesses[depth] = level;
}

DOMAIN_ID WorkScriptVisitorImpl::getDomain() const
{
	return this->domain;
}

void WorkScriptVisitorImpl::setDomain(DOMAIN_ID domain)
{
	this->domain = domain;
}
