#include "stdafx.h"
#include "TreeCreateVisitor.h"
#include "ExpressionWrapper.h"
#include "Type.h"
#include "VoidType.h"
#include "CallExpression.h"
#include "VariableExpression.h"
#include "AssignmentExpression.h"
#include "MultiValueExpression.h"
#include "SyntaxErrorException.h"
#include "Parameter.h"
#include "Function.h"
#include "BranchFunction.h"
#include "FunctionBranch.h"
#include "Program.h"
#include "BinaryCompareExpression.h"
#include "BinaryCalculateExpression.h"
#include "UnaryOperatorExpression.h"
#include "Locale.h"
#include "Location.h"
#include "FormalParametersResolver.h"
#include "ConstantExpression.h"
#include "FloatConstant.h"
#include "IntegerConstant.h"
#include "StringConstant.h"

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
using namespace WorkScript;

static void handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr, Location loc);

inline static Location getLocation(antlr4::ParserRuleContext *ctx) 
{
	Location l(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1);
	return l;
}

antlrcpp::Any WorkScript::TreeCreateVisitor::visitBlock(WorkScriptParser::BlockContext *ctx)
{
	vector<Expression*> exprs;
	size_t lineCount = ctx->line().size();
	exprs.reserve((size_t)(lineCount*1.5));
	for (auto c : ctx->line()) {
		vector<Expression*> curLineExprs = c->accept(this);
		exprs.insert(exprs.end(), curLineExprs.begin(), curLineExprs.end());
	}
	return exprs;
}

antlrcpp::Any WorkScript::TreeCreateVisitor::visitLine(WorkScriptParser::LineContext *ctx)
{
	vector<Expression*> exprs;
	exprs.reserve(ctx->expression().size());
	for (auto c : ctx->expression()) {
		auto ret = c->accept(this);
		if (ret.isNotNull()) {
			exprs.push_back(ret.as<ExpressionWrapper>());
		}
	}
	return exprs;
}

antlrcpp::Any TreeCreateVisitor::visitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx)
{
	if (ctx->DOUBLE()) {
		double value = 0;
		int len = sscanf(ctx->DOUBLE()->getText().c_str(), "%lf", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new ConstantExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), new FloatConstant(FloatType::getFloat64Type(), value)));
	}
	else {
		int value = 0;
		int len = sscanf(ctx->INTEGER()->getText().c_str(), "%d", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new ConstantExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), new IntegerConstant(IntegerType::getSInt32Type(), value)));
	}
}

antlrcpp::Any TreeCreateVisitor::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string text = ctx->STRING()->getText();
	text = text.substr(1, text.length() - 2);
	wstring wtext = Locale::utf8ToUnicode(text);

	wchar_t *unescapedText = new wchar_t[wtext.length() + 1];
	try {
		handleEscapeCharacters(wtext.c_str(), unescapedText, getLocation(ctx));
	}
	catch(...){
		delete[]unescapedText;
		throw;
	}
	auto lpExpr = new ConstantExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), new StringConstant(unescapedText));
	delete[]unescapedText;
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any TreeCreateVisitor::visitBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx)
{
	string boolStr = ctx->BOOLEAN()->getText();
	if (boolStr == "true" || boolStr == "yes" || boolStr == "ok" || boolStr == "good") {
		return ExpressionWrapper(new ConstantExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), new IntegerConstant(IntegerType::getUInt1Type(), 1)));
	}
	else if (boolStr == "false" || boolStr == "no" || boolStr == "bad") {
		return ExpressionWrapper(new ConstantExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), new IntegerConstant(IntegerType::getUInt1Type(), 0)));
	}
	else {
		throw std::move(SyntaxErrorException(getLocation(ctx), L"�޷�ʶ��Ĳ���ֵ��" + Locale::utf8ToUnicode(boolStr)));
	}
}

antlrcpp::Any TreeCreateVisitor::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->identifier()->getText();
	auto expr = new VariableExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), Locale::utf8ToUnicode(varName));
	expr->setDeclarable(this->declarable); //�Ⱥ���ߵı����ſ��Դ�������
	auto wrapper = ExpressionWrapper(expr);
	return wrapper;
}

antlrcpp::Any TreeCreateVisitor::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	/*====������һ��====*/
	++this->curDepth;
	AbstractContext *outerAbstractContext = this->abstractContexts.top();
	/*��ȡ������*/
	auto funcNameCtx = ctx->functionDeclarationExpression()->functionName()->identifier();
	wstring funcName;
	if (funcNameCtx != nullptr) {
		funcName = Locale::utf8ToUnicode(funcNameCtx->getText());
	}

	/*��ȡ����ֵ������*/
	auto returnTypeNameCtx = ctx->functionDeclarationExpression()->typeName();
	wstring returnTypeName;
	Type *declReturnType = nullptr;
	if (returnTypeNameCtx) {
		returnTypeName = Locale::utf8ToUnicode(returnTypeNameCtx->identifier()->getText());
		declReturnType = outerAbstractContext->getType(returnTypeName);
		if (!declReturnType) {
			throw TypeNotFoundException(getLocation(ctx), L"�޷��ҵ����ͣ�" + returnTypeName);
		}
	}

	/*��ȡ��������*/
	auto paramItemsDeclCtx = ctx->functionDeclarationExpression()->formalParameterExpression()->formalParameterItem();
	size_t paramCount = paramItemsDeclCtx.size();
	vector<Expression*> paramDeclExprs(paramCount, nullptr);
	vector<Type*> paramDeclTypes(paramCount, nullptr);
	//TODO ����ʱ��δ���
	//bool isRuntimeVarargs = ctx->functionDeclarationExpression()->formalParameterExpression()->APOSTROPHE() != nullptr;
	bool isRuntimeVarargs = false;

	for (size_t i = 0; i < paramCount; ++i)
	{
		paramDeclExprs[i] = paramItemsDeclCtx[i]->expression()->accept(this).as<ExpressionWrapper>();
		if (paramItemsDeclCtx[i]->typeName()) {
			wstring typeName = Locale::utf8ToUnicode(paramItemsDeclCtx[i]->typeName()->getText());
			Type *type = outerAbstractContext->getType(typeName);
			if (!type) {
				throw TypeNotFoundException(getLocation(ctx), L"�޷��ҵ����ͣ�" + type->getName());
			}
			size_t pointerLevel = paramItemsDeclCtx[i]->STAR().size();
			if (pointerLevel > 0) {
				type = PointerType::get(type, pointerLevel);
			}
			paramDeclTypes[i] = type;
		}
	}

	/*��ȡ��������*/
	vector<Expression*> constraintsDecl;
	auto constraintCtx = ctx->functionConstraintExpression();
	if (constraintCtx) {
		if (constraintCtx->expression())
		{
			auto expr = constraintCtx->expression()->accept(this).as<ExpressionWrapper>().getExpression();
			constraintsDecl.push_back(expr);
		}
		else {
			constraintsDecl = constraintCtx->block()->accept(this).as<decltype(constraintsDecl)>();
		}
	}
	//��������������
	InstantializeContext instCtx(this->abstractContexts.top(), this->program->getFunctionCache(), nullptr);
	auto resolveRes = FormalParametersResolver::resolve(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), &instCtx, paramDeclTypes, paramDeclExprs, constraintsDecl);
	auto paramTypes = resolveRes.getParameterTypes();
	auto params = resolveRes.getParameters();
	auto constraints = resolveRes.getConstraints();

	auto funcs = outerAbstractContext->getFunctions(funcName, paramTypes);
	if (funcs.size() == 0) {
		//��ʱ����֪������ֵ����
		auto newFunc = new BranchFunction(outerAbstractContext, funcName, paramTypes, declReturnType, declReturnType != nullptr, isRuntimeVarargs);
		funcs.push_back(newFunc);
		outerAbstractContext->addFunction(newFunc);
	}
	//Ϊ���з��������ĺ���������Ӻ�����֧
	for (size_t i = 0; i < funcs.size(); ++i) {
		BranchFunction *func = (BranchFunction*)funcs[i];
		if (func->isDeclaredReturnType() && !func->getType()->getReturnType()->equals(declReturnType)) {
			throw TypeMismatchedException(getLocation(ctx), L"����" + funcName + L"�ķ���ֵ����" + declReturnType->getName()
				+ L"��֮ǰ�����Ĳ�����" + func->getType()->getReturnType()->getName());
		}
		size_t branchID = func->getBranchCount() + 1; //blockID��1��ʼ
		auto branch = new FunctionBranch(func, branchID, getLocation(ctx));
		branch->setParameters(params);
		AbstractContext *innerAbstractCtx = branch->getContext();
		this->abstractContexts.push(innerAbstractCtx);

		/*������������ӵ���Ӧ�����ط�֧��*/
		//Ѱ�����أ�ͬʱ�ж��Ƿ�����з���ֵ������ͬ��������������½���

		/*������ʵ��*/
		ALLOW_ASSIGN;
		vector<Expression*> impls;
		if (ctx->functionImplementationExpression()->expression() != nullptr) {
			auto expr = ctx->functionImplementationExpression()->expression()->accept(this).as<ExpressionWrapper>();
			impls.push_back(expr.getExpression());
		}
		else {
			impls = ctx->functionImplementationExpression()->block()->accept(this).as<decltype(impls)>();
		}
		branch->setConstraints(constraints);
		branch->setImplements(impls);
		FORBID_ASSIGN;
		//�ָ���ǰ��֧
		this->abstractContexts.pop();
		func->addBranch(branch);
	}
	/*====�ָ���һ��====*/
	--this->curDepth;
	RESTORE_ASSIGNABLE;
	return nullptr;
}

antlrcpp::Any WorkScript::TreeCreateVisitor::visitStdFunctionDeclExpression(WorkScriptParser::StdFunctionDeclExpressionContext *ctx)
{
	AbstractContext *outerAbstractContext = this->abstractContexts.top();
	/*��ȡ������*/
	auto funcNameCtx = ctx->functionName();
	wstring funcName = Locale::utf8ToUnicode(funcNameCtx->getText());

	/*��ȡ����ֵ������*/
	auto returnTypeNameCtx = ctx->typeName();
	wstring returnTypeName = Locale::utf8ToUnicode(returnTypeNameCtx->identifier()->getText());
	int pointerLevel = ctx->STAR().size();
	Type *returnType = outerAbstractContext->getType(returnTypeName, pointerLevel);
	if (!returnType) {
		throw TypeNotFoundException(getLocation(ctx), L"�޷��ҵ����ͣ�" + returnTypeName);
	}

	auto paramItemsCtx = ctx->stdFormalParameterExpression()->stdFormalParameterItem();
	vector<Parameter*> params;
	vector<Type*> paramTypes;
	for (size_t i = 0; i < paramItemsCtx.size(); ++i) {
		wstring paramName;
		if (paramItemsCtx[i]->identifier()) {
			paramName = Locale::utf8ToUnicode(paramItemsCtx[i]->identifier()->getText());
		}
		wstring paramTypeName = Locale::utf8ToUnicode(paramItemsCtx[i]->typeName()->getText());
		size_t pointerLevel = paramItemsCtx[i]->STAR().size();
		Type *paramType = outerAbstractContext->getType(paramTypeName, pointerLevel);
		if (!paramType) {
			throw TypeNotFoundException(getLocation(ctx), L"�޷��ҵ����ͣ�" + paramTypeName);
		}
		params.push_back(new Parameter(paramName, paramType, true));
		paramTypes.push_back(paramType);
	}
	bool isRuntimeVarargs = ctx->stdFormalParameterExpression()->APOSTROPHE() != nullptr;
	Function *func = outerAbstractContext->getFirstFunction(funcName, paramTypes);
	if (!func) {
		//TODO ���غ�����������
		func = new BranchFunction(outerAbstractContext, funcName, paramTypes, returnType,true,isRuntimeVarargs);
		outerAbstractContext->addFunction(func);
	}
	return nullptr;
}

antlrcpp::Any TreeCreateVisitor::visitCallExpression(WorkScriptParser::CallExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper paramExpressionWrapper = ctx->multiValueExpression()->accept(this);
	auto funcName = Locale::utf8ToUnicode(ctx->identifier()->getText());
	auto paramExpr = (MultiValueExpression*)paramExpressionWrapper.getExpression();
	auto expr = new CallExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), funcName, paramExpr);
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(expr);
}

antlrcpp::Any TreeCreateVisitor::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	auto lines = ctx->line();
	for (auto &line : lines)
	{
		ALLOW_ASSIGN; //ÿ���µ�һ�ж�����ֵ
		line->accept(this); //����ֻ�к������������Զ����뵽program�� TODO:��ֻ�к���������������ͨ��ִ����䣡
	}
	return nullptr;
}

antlrcpp::Any TreeCreateVisitor::visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx)
{
	if (this->assignable) {
		STORE_FORBID_ASSIGN;
		this->declarable = true;
		auto left = ctx->expression()[0]->accept(this).as<ExpressionWrapper>().getExpression();
		this->declarable = false;
		auto right = ctx->expression()[1]->accept(this).as<ExpressionWrapper>().getExpression();
		RESTORE_ASSIGNABLE;
		//����ֵ����������ű�
		InstantializeContext instCtx(this->abstractContexts.top(), program->getFunctionCache());
		if (left->getExpressionType() == ExpressionType::VARIABLE_EXPRESSION) {
			auto leftVar = (VariableExpression*)left;
			this->abstractContexts.top()->setSymbol(leftVar->getName(), right->getType(&instCtx));
		}
		return ExpressionWrapper(new AssignmentExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), left, right));
	}
	else {
		STORE_FORBID_ASSIGN;
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
		auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new BinaryCompareExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), left, right, BinaryCompareExpression::CompareType::EQUAL));
	}
}

antlrcpp::Any TreeCreateVisitor::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE;
	auto expr = new AssignmentExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), left, right);
	return ExpressionWrapper(expr);
}

antlrcpp::Any TreeCreateVisitor::visitMultiValueExpression(WorkScriptParser::MultiValueExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	vector<Expression*> items;
	items.reserve(subContextCount);
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
		items.push_back(itemExpr);
	}
	auto expr = new WorkScript::MultiValueExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), items);
	RESTORE_ASSIGNABLE
	return ExpressionWrapper(expr);
}

antlrcpp::Any TreeCreateVisitor::visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE
	if (ctx->PLUS()) {
		Expression *expr = new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculateExpression::PLUS);
		return ExpressionWrapper(expr);
	}
	else { //MINUS
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculateExpression::MINUS));
	}
}

antlrcpp::Any TreeCreateVisitor::visitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE;
	if (ctx->STAR()) {
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculateExpression::MULTIPLY));
	}
	else if (ctx->SLASH()) {
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculateExpression::DIVIDE));
	}
	else { //MODULUS
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculateExpression::MODULUS));
	}
}

antlrcpp::Any TreeCreateVisitor::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto ret = ctx->expression()->accept(this);
	RESTORE_ASSIGNABLE;
	return ret;
}

antlrcpp::Any TreeCreateVisitor::visitBinaryCompareExpression(WorkScriptParser::BinaryCompareExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	ExpressionWrapper wrapperLeft = ctx->expression()[0]->accept(this);
	ExpressionWrapper wrapperRight = ctx->expression()[1]->accept(this);
	auto leftExpression = wrapperLeft.getExpression();
	auto rightExpression = wrapperRight.getExpression();
	BinaryCompareExpression::CompareType compareType;
	RESTORE_ASSIGNABLE;
	if (ctx->DOUBLE_EQUAL()) {
		compareType = BinaryCompareExpression::CompareType::EQUAL;
	}
	else if (ctx->GREATER_THAN()) {
		compareType = BinaryCompareExpression::CompareType::GREATER_THAN;
	}
	else if (ctx->GREATER_THAN_EQUAL()) {
		compareType = BinaryCompareExpression::CompareType::GREATER_THAN_EQUAL;
	}
	else if (ctx->LESS_THAN()) {
		compareType = BinaryCompareExpression::CompareType::LESS_THAN;
	}
	else {
		compareType = BinaryCompareExpression::CompareType::LESS_THAN_EQUAL;
	}
	return ExpressionWrapper(new BinaryCompareExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), leftExpression, rightExpression, compareType));
}

//antlrcpp::Any TreeCreateVisitor::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
//{
//	STORE_FORBID_ASSIGN
//	auto subContext = ctx->expression();
//	size_t subContextCount = subContext.size();
//	auto expr = new ListExpression();
//	for (size_t i = 0; i < subContextCount; ++i) {
//		ExpressionWrapper wrapper = subContext[i]->accept(this);
//		auto itemExpr = wrapper.getExpression();
//		expr->addItem(itemExpr);
//	}
//	RESTORE_ASSIGNABLE
//	return ExpressionWrapper(expr);
//}

antlrcpp::Any TreeCreateVisitor::visitNegativeExpression(WorkScriptParser::NegativeExpressionContext *ctx)
{
	ExpressionWrapper wrapper = ctx->expression()->accept(this);
	auto expr = new UnaryOperatorExpression(ExpressionInfo(program, getLocation(ctx), this->abstractContexts.top()), wrapper.getExpression(), UnaryOperatorExpression::NEGATIVE);
	return ExpressionWrapper(expr);
}

antlrcpp::Any TreeCreateVisitor::visitPositiveExpression(WorkScriptParser::PositiveExpressionContext *ctx)
{
	return ctx->expression()->accept(this);
}

antlrcpp::Any TreeCreateVisitor::visitVarargsExpression(WorkScriptParser::VarargsExpressionContext *ctx)
{
	ExpressionWrapper varWrapper = ctx->variableExpression()->accept(this);
	auto varExpr = (VariableExpression *)varWrapper.getExpression();
	varExpr->setVarargs(true);
	return varWrapper;
}

TreeCreateVisitor::TreeCreateVisitor(Program *lpProgram)
{
	this->program = lpProgram;
	this->abstractContexts.push(program->getGlobalAbstractContext());
}

TreeCreateVisitor::~TreeCreateVisitor()
{
}

static void handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr, Location loc)
{
#define SINGLE_ESCAPE_CASE(escapedChar,unescapedChar) \
		case escapedChar: \
		targetStr[targetPos] = unescapedChar; \
		++srcPos; \
		++targetPos; \
		state = NORMAL; \
		break; 

	//����״̬������ת���
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
				throw std::move(SyntaxErrorException(loc, (L"ת���δ������\"" + wstring(srcStr) + L"\"").c_str()));
			default:
				throw std::move(SyntaxErrorException(loc, (wstring(L"����ʶ���ת���\"\\") + srcStr[srcPos] + L"\"").c_str()));
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
				int octNum; //�˽��������
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
				int hexNum; //ʮ�����������
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

