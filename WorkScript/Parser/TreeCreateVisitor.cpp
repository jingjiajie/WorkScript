#include <optional>
#include "InstantialContext.h"
#include "TreeCreateVisitor.h"
#include "ExpressionWrapper.h"
#include "TypeWrapper.h"
#include "Type.h"
#include "VoidType.h"
#include "Call.h"
#include "Variable.h"
#include "Assignment.h"
#include "MultiValue.h"
#include "Report.h"
#include "Exception.h"
#include "Parameter.h"
#include "Function.h"
#include "FunctionFragment.h"
#include "Program.h"
#include "BinaryCompare.h"
#include "BinaryCalculate.h"
#include "UnaryOperator.h"
#include "Locales.h"
#include "DebugInfo.h"
#include "FormalParametersResolver.h"
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

static void handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr,const DebugInfo &d);

inline static DebugInfo getDebugInfo(const TreeCreateVisitor *visitor, antlr4::ParserRuleContext *ctx)
{
	return DebugInfo(
			Location(visitor->getFileName(), ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine() + 1),
			visitor->getProgram()->getReport());
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
    /*遍历函数*/
    for(auto c : ctx->function()){
        c->accept(this);
    }

	/*遍历表达式*/
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

antlrcpp::Any TreeCreateVisitor::visitNumber(WorkScriptParser::NumberContext *ctx)
{
	if (ctx->DOUBLE()) {
		long double value = strtold(ctx->DOUBLE()->getText().c_str(), nullptr);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new FloatConstant(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), FloatType::get(64), value));
	}
	else {
		long long int value = strtoll(ctx->INTEGER()->getText().c_str(), nullptr, 10);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new IntegerConstant(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), IntegerType::get(32,true), value));
	}
}

antlrcpp::Any TreeCreateVisitor::visitString(WorkScriptParser::StringContext *ctx)
{
	string text = ctx->STRING()->getText();
	text = text.substr(1, text.length() - 2);
	wstring wtext = Locales::toWideChar(Encoding::UTF_8, text);

	wchar_t *unescapedText = new wchar_t[wtext.length() + 1];
	try {
		handleEscapeCharacters(wtext.c_str(), unescapedText, getDebugInfo(this, ctx));
	}
	catch(...){
		delete[]unescapedText;
		throw;
	}
	auto lpExpr = new StringConstant(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), unescapedText);
	delete[]unescapedText;
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any TreeCreateVisitor::visitBoolean(WorkScriptParser::BooleanContext *ctx)
{
	string boolStr = ctx->BOOLEAN()->getText();
	if (boolStr == "true" || boolStr == "yes" || boolStr == "ok" || boolStr == "good") {
		return ExpressionWrapper(new IntegerConstant(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), IntegerType::get(1,false), 1));
	}
	else if (boolStr == "false" || boolStr == "no" || boolStr == "bad") {
		return ExpressionWrapper(new IntegerConstant(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), IntegerType::get(1,false), 0));
	}
	else {
		throw std::move(SyntaxError(getDebugInfo(this, ctx), L"无法识别的布尔值：" + Locales::toWideChar(Encoding::UTF_8, boolStr)));
	}
}

antlrcpp::Any TreeCreateVisitor::visitVariable(WorkScriptParser::VariableContext *ctx)
{
	string varName = ctx->identifier()->getText();
	auto expr = new Variable(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), Locales::toWideChar(Encoding::UTF_8, varName));
	expr->setDeclarable(this->declarable); //等号左边的变量才可以创建声明
	auto wrapper = ExpressionWrapper(expr);
	return wrapper;
}

antlrcpp::Any TreeCreateVisitor::visitFunctionDefine(WorkScriptParser::FunctionDefineContext *ctx)
{
    STORE_FORBID_ASSIGN;
    /*====深入下一层====*/
    ++this->curDepth;
    AbstractContext *outerAbstractContext = this->abstractContexts.top();
    /*读取函数名*/
    auto funcNameCtx = ctx->functionDeclaration()->functionName()->identifier();
    wstring funcName;
    if (funcNameCtx != nullptr)
    {
        funcName = Locales::toWideChar(Encoding::UTF_8, funcNameCtx->getText());
    }

    /*读取返回值类型名*/
    auto returnTypeCtx = ctx->functionDeclaration()->type();
    Type *declReturnType = nullptr;
    LinkageType linkageType = LinkageType::EXTERNAL;
    if (returnTypeCtx)
    {
        TypeWrapper returnTypeWrapper = returnTypeCtx->accept(this).as<TypeWrapper>();
        if (returnTypeWrapper.getLinkageType().has_value() &&
            returnTypeWrapper.getLinkageType().value().equals(LinkageType::INTERNAL))
        {
            linkageType = LinkageType::INTERNAL;
        }
        declReturnType = returnTypeWrapper.getType();
        size_t pointerLevel = ctx->functionDeclaration()->STAR().size();
        if (pointerLevel > 0) declReturnType = PointerType::get(declReturnType, pointerLevel);
    }

    /*读取参数声明*/
    auto paramItemsDeclCtx = ctx->functionDeclaration()->formalParameter()->formalParameterItem();
    size_t paramCount = paramItemsDeclCtx.size();
    vector<Expression *> paramDeclExprs(paramCount, nullptr);
    vector<Type *> paramDeclTypes(paramCount, nullptr);
    bool isRuntimeVarargs = ctx->functionDeclaration()->formalParameter()->runtimeVarargs() != nullptr;
    auto staticVarargsCtx = ctx->functionDeclaration()->formalParameter()->staticVarargs();
    optional<wstring> staticVarargsName = nullopt;
    if(staticVarargsCtx != nullptr)
	{
		staticVarargsName = Locales::toWideChar(Encoding::UTF_8, staticVarargsCtx->identifier()->getText());
	}

    for (size_t i = 0; i < paramCount; ++i)
    {
        paramDeclExprs[i] = paramItemsDeclCtx[i]->expression()->accept(this).as<ExpressionWrapper>();
        if (paramItemsDeclCtx[i]->type())
        {
            Type *type = paramItemsDeclCtx[i]->type()->accept(this).as<TypeWrapper>().getType();
            size_t pointerLevel = paramItemsDeclCtx[i]->STAR().size();
            if (pointerLevel > 0) type = PointerType::get(type, pointerLevel);
            paramDeclTypes[i] = type;
        }
    }

    /*读取限制声明*/
    vector<Expression *> constraintsDecl;
    auto constraintCtx = ctx->functionConstraint();
    if (constraintCtx)
    {
        if (constraintCtx->expression())
        {
            auto expr = constraintCtx->expression()->accept(this).as<ExpressionWrapper>().getExpression();
            constraintsDecl.push_back(expr);
        } else
        {
            constraintsDecl = constraintCtx->block()->accept(this).as<decltype(constraintsDecl)>();
        }
    }
    //解析参数和限制
    InstantialContext instCtx(this->abstractContexts.top(), this->program->getFunctionCache());
    auto resolveRes = FormalParametersResolver::resolve(
            ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), &instCtx, paramDeclTypes,
            paramDeclExprs, constraintsDecl);
    auto paramTypes = resolveRes.getParameterTypes();
    auto params = resolveRes.getParameters();
    auto constraints = resolveRes.getConstraints();

    /*将函数声明添加到相应的重载分支中*/
    //寻找重载，同时判断是否和已有返回值类型相同，如果不存在则新建。

    /*函数的实现*/
    ALLOW_ASSIGN;
    vector<Expression *> impls;
    if (ctx->functionImplementation()->expression() != nullptr)
    {
        auto expr = ctx->functionImplementation()->expression()->accept(this).as<ExpressionWrapper>();
        impls.push_back(expr.getExpression());
    } else
    {
        impls = ctx->functionImplementation()->block()->accept(this).as<decltype(impls)>();
    }

    //将Fragment加入到外层的AbstractContext中
    //TODO 函数的const修饰符
    auto fragment = new FunctionFragment(getDebugInfo(this, ctx), outerAbstractContext, funcName, params, false, isRuntimeVarargs, staticVarargsName, linkageType,constraints,impls);
    outerAbstractContext->addFunctionFragment(fragment);
	AbstractContext *innerAbstractCtx = fragment->getContext();
	this->abstractContexts.push(innerAbstractCtx);

    FORBID_ASSIGN;
    //恢复当前分支
    this->abstractContexts.pop();

    /*====恢复上一层====*/
    --this->curDepth;
    RESTORE_ASSIGNABLE;
    return nullptr;
}

antlrcpp::Any WorkScript::TreeCreateVisitor::visitStdFunctionDecl(WorkScriptParser::StdFunctionDeclContext *ctx)
{
	AbstractContext *outerAbstractContext = this->abstractContexts.top();
	/*读取函数名*/
	auto funcNameCtx = ctx->functionName();
	wstring funcName = Locales::toWideChar(Encoding::UTF_8, funcNameCtx->getText());

	/*读取返回值类型名*/
	auto returnTypeCtx = ctx->type();
	TypeWrapper returnTypeWrapper = returnTypeCtx->accept(this).as<TypeWrapper>();
	Type *returnType = returnTypeWrapper.getType();
	size_t pointerLevel = ctx->STAR().size();
	if (pointerLevel > 0) returnType = PointerType::get(returnType, pointerLevel);
	LinkageType linkageType = returnTypeWrapper.getLinkageType().value_or(LinkageType::EXTERNAL);

	/*处理参数声明*/
	auto paramItemsCtx = ctx->stdFormalParameter()->stdFormalParameterItem();
	vector<Parameter *> params;
	vector<Type *> paramTypes;
	for (size_t i = 0; i < paramItemsCtx.size(); ++i)
	{
		wstring paramName;
		if (paramItemsCtx[i]->identifier())
		{
			paramName = Locales::toWideChar(Encoding::UTF_8, paramItemsCtx[i]->identifier()->getText());
		}
		Type *paramType = paramItemsCtx[i]->type()->accept(this).as<TypeWrapper>().getType();
		size_t pointerLevel = paramItemsCtx[i]->STAR().size();
		if (pointerLevel > 0) paramType = PointerType::get(paramType, pointerLevel);
		params.push_back(new Parameter(paramName, paramType, true));
		paramTypes.push_back(paramType);
	}
	bool isRuntimeVarargs = ctx->stdFormalParameter()->runtimeVarargs() != nullptr;
	//TODO FunctionQuery的isConst参数未处理
	Function *func = outerAbstractContext->getFunction(getDebugInfo(this,ctx),FunctionQuery(funcName, paramTypes, false));
	if (!func)
	{
		//TODO 函数的const修饰符
		FunctionType *funcType = FunctionType::get(paramTypes, returnType, isRuntimeVarargs, false);
		func = new Function(outerAbstractContext, funcName, funcType, linkageType);
		outerAbstractContext->addFunction(func);
	}
	return nullptr;
}

antlrcpp::Any TreeCreateVisitor::visitCall(WorkScriptParser::CallContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper paramExpressionWrapper = ctx->multiValue()->accept(this);
	auto funcName = Locales::toWideChar(Encoding::UTF_8, ctx->identifier()->getText());
	auto paramExpr = (MultiValue*)paramExpressionWrapper.getExpression();
	auto expr = new Call(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), funcName, paramExpr);
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(expr);
}

antlrcpp::Any TreeCreateVisitor::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	auto lines = ctx->line();
	for (auto &line : lines)
	{
	    string lineStr = line->toString();
		ALLOW_ASSIGN; //每次新的一行都允许赋值
		line->accept(this); //假设只有函数声明，会自动加入到program里 TODO:不只有函数声明，还有普通的执行语句！
	}
	return nullptr;
}

antlrcpp::Any TreeCreateVisitor::visitAssignmentOrEquals(WorkScriptParser::AssignmentOrEqualsContext *ctx)
{
	if (this->assignable) {
		STORE_FORBID_ASSIGN;
		this->declarable = true;
		auto left = ctx->expression()[0]->accept(this).as<ExpressionWrapper>().getExpression();
		this->declarable = false;
		auto right = ctx->expression()[1]->accept(this).as<ExpressionWrapper>().getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new Assignment(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), left, right));
	}
	else {
		STORE_FORBID_ASSIGN;
		auto left = (ctx->expression()[0]->accept(this).as<ExpressionWrapper>()).getExpression();
		auto right = (ctx->expression()[1]->accept(this).as<ExpressionWrapper>()).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new BinaryCompare(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), left, right, BinaryCompare::CompareType::EQUAL));
	}
}

antlrcpp::Any TreeCreateVisitor::visitAssignment(WorkScriptParser::AssignmentContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = (ctx->expression()[0]->accept(this).as<ExpressionWrapper>()).getExpression();
	auto right = (ctx->expression()[1]->accept(this).as<ExpressionWrapper>()).getExpression();
	RESTORE_ASSIGNABLE;
	auto expr = new Assignment(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), left, right);
	return ExpressionWrapper(expr);
}

antlrcpp::Any TreeCreateVisitor::visitMultiValue(WorkScriptParser::MultiValueContext *ctx)
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
	auto expr = new WorkScript::MultiValue(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), items);
	RESTORE_ASSIGNABLE
	return ExpressionWrapper(expr);
}

antlrcpp::Any TreeCreateVisitor::visitPlusMinus(WorkScriptParser::PlusMinusContext *ctx)
{
	STORE_FORBID_ASSIGN
	const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE
	if (ctx->PLUS()) {
		Expression *expr = new BinaryCalculate(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculate::PLUS);
		return ExpressionWrapper(expr);
	}
	else { //MINUS
		return ExpressionWrapper(new BinaryCalculate(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculate::MINUS));
	}
}

antlrcpp::Any TreeCreateVisitor::visitMultiplyDivideModulus(WorkScriptParser::MultiplyDivideModulusContext *ctx)
{
	STORE_FORBID_ASSIGN
		const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE;
	if (ctx->STAR()) {
		return ExpressionWrapper(new BinaryCalculate(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculate::MULTIPLY));
	}
	else if (ctx->SLASH()) {
		return ExpressionWrapper(new BinaryCalculate(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculate::DIVIDE));
	}
	else { //MODULUS
		return ExpressionWrapper(new BinaryCalculate(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), leftExpression, rightExpression, BinaryCalculate::MODULUS));
	}
}

antlrcpp::Any TreeCreateVisitor::visitParenthese(WorkScriptParser::ParentheseContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto ret = ctx->expression()->accept(this);
	RESTORE_ASSIGNABLE;
	return ret;
}

antlrcpp::Any TreeCreateVisitor::visitBinaryCompare(WorkScriptParser::BinaryCompareContext *ctx)
{
	STORE_FORBID_ASSIGN
	ExpressionWrapper wrapperLeft = ctx->expression()[0]->accept(this);
	ExpressionWrapper wrapperRight = ctx->expression()[1]->accept(this);
	auto leftExpression = wrapperLeft.getExpression();
	auto rightExpression = wrapperRight.getExpression();
	BinaryCompare::CompareType compareType;
	RESTORE_ASSIGNABLE;
	if (ctx->DOUBLE_EQUAL()) {
		compareType = BinaryCompare::CompareType::EQUAL;
	}
	else if (ctx->GREATER_THAN()) {
		compareType = BinaryCompare::CompareType::GREATER_THAN;
	}
	else if (ctx->GREATER_THAN_EQUAL()) {
		compareType = BinaryCompare::CompareType::GREATER_THAN_EQUAL;
	}
	else if (ctx->LESS_THAN()) {
		compareType = BinaryCompare::CompareType::LESS_THAN;
	}
	else {
		compareType = BinaryCompare::CompareType::LESS_THAN_EQUAL;
	}
	return ExpressionWrapper(new BinaryCompare(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), leftExpression, rightExpression, compareType));
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

antlrcpp::Any TreeCreateVisitor::visitNegative(WorkScriptParser::NegativeContext *ctx)
{
	ExpressionWrapper wrapper = ctx->expression()->accept(this);
	auto expr = new UnaryOperator(ExpressionInfo(program, getDebugInfo(this, ctx), this->abstractContexts.top()), wrapper.getExpression(), UnaryOperator::NEGATIVE);
	return ExpressionWrapper(expr);
}

antlrcpp::Any TreeCreateVisitor::visitPositive(WorkScriptParser::PositiveContext *ctx)
{
	return ctx->expression()->accept(this);
}

TreeCreateVisitor::TreeCreateVisitor(Program *lpProgram, const std::wstring &fileName)
:program(lpProgram),fileName(fileName)
{
    this->abstractContexts.push(program->getGlobalAbstractContext());
}

TreeCreateVisitor::~TreeCreateVisitor() = default;

antlrcpp::Any TreeCreateVisitor::visitType(WorkScriptParser::TypeContext *ctx)
{
	auto qualifiers = ctx->typeQualifier();
	auto specifiers = ctx->typeSpecifier();
	auto storageClassSpecifiers = ctx->storageClassSpecifier();
	bool isConst = false, isVolatile = false;
	bool isShort = false, isLong = false, isUnsigned = false;
	optional<LinkageType> linkageType = nullopt;
	wstring typeName;
	Type *type = nullptr;
	for (auto qualifierCtx : qualifiers)
	{
		string qualifier = qualifierCtx->getText();
		if (qualifier == "const") isConst = true;
		else if (qualifier == "volatile") isVolatile = true;
	}

    for (auto storageCtx : storageClassSpecifiers)
    {
        string specifier = storageCtx->getText();
        if (specifier == "static") {
            linkageType = LinkageType::INTERNAL;
        }
        else if (specifier == "extern"){
            linkageType = LinkageType::EXTERNAL;
        }
    }

	for (auto specifierCtx : specifiers)
	{
		string specifier = specifierCtx->getText();
		if (specifier == "short") isShort = true;
		else if (specifier == "long") isLong = true;
		else if (specifier == "signed") isUnsigned = false;
		else if (specifier == "unsigned") isUnsigned = true;
		else
		{
			typeName = Locales::toWideChar(Encoding::UTF_8, specifier);
		}
	}

	if (typeName.empty())
	{
		if(isShort || isLong || isUnsigned){
			typeName = L"int";
		}
	}

	if (typeName == L"int")
	{
		unsigned char len = 32;
		if (isShort) len = 16;
		else if (isLong) len = 64;
		type = IntegerType::get(len, !isUnsigned, isConst, isVolatile);
	} else if (typeName == L"char")
	{
		type = IntegerType::get(8, !isUnsigned, isConst, isVolatile);
	} else if (typeName == L"bool")
	{
		type = IntegerType::get(1, !isUnsigned, isConst, isVolatile);
	} else if (typeName == L"float")
	{
		type = FloatType::get(32, isConst, isVolatile);
	} else if (typeName == L"void")
	{
		type = VoidType::get();
	} else
	{
		this->program->getReport()->error(UnimplementedError(getDebugInfo(this, ctx), L"尚未实现自定义类型"), ErrorBehavior::CANCEL_EXPRESSION);
	}

	return TypeWrapper(type, linkageType);
}

static void handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr,const DebugInfo &d)
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
		case FINISH: break;
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
				throw std::move(SyntaxError(d, L"转义符未结束：\"" + wstring(srcStr) + L"\""));
			default:
				throw std::move(SyntaxError(d, wstring(L"不能识别的转义符\"\\") + srcStr[srcPos] + L"\""));
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
				auto *dstr = new wchar_t[octLen + 1];
				for (size_t i = 0; i < octLen; i++) {
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
			case L'0':case L'1':case L'2':case L'3':case L'4':case L'5':
			case L'6':case L'7':case L'8':case L'9':case L'a':case L'b':
			case L'c':case L'd':case L'e':case L'f':case L'A':case L'B':
			case L'C':case L'D':case L'E':case L'F':
				++srcPos;
				break;
			default:
				size_t hexLen = srcPos - escapeStartPos - 1;
				auto *dstr = new wchar_t[hexLen + 1];
				for (size_t i = 0; i < hexLen; i++) {
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
