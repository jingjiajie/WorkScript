#include "stdafx.h"
#include "WorkScriptVisitorImpl.h"
#include "ExpressionWrapper.h"
#include "Type.h"
#include "VoidType.h"
#include "CallExpression.h"
#include "VariableExpression.h"
#include "AssignmentExpression.h"
#include "MultiValueExpression.h"
#include "IntegerExpression.h"
#include "FloatExpression.h"
#include "StringExpression.h"
#include "SyntaxErrorException.h"
#include "Parameter.h"
#include "Function.h"
#include "FunctionTemplate.h"
#include "BranchOverloadTemplate.h"
#include "Program.h"
#include "BinaryCompareExpression.h"
#include "BinaryCalculateExpression.h"
#include "UnaryOperatorExpression.h"
#include "Locale.h"
#include "Location.h"
#include "FormalParametersTemplateResolver.h"
#include "TemplateCall.h"
#include "OverloadTemplate.h"
#include "TemplateVariable.h"
#include "OverloadTemplate.h"

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

antlrcpp::Any WorkScriptVisitorImpl::visitIncludeCommand(WorkScriptParser::IncludeCommandContext *ctx)
{
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
		return ExpressionWrapper(new FloatExpression(ExpressionInfo(program, getLocation(ctx)), program->getFloat64Type(), value));
	}
	else {
		int value = 0;
		int len = sscanf(ctx->INTEGER()->getText().c_str(), "%d", &value);
		if (ctx->MINUS()) {
			value = -value;
		}
		return ExpressionWrapper(new IntegerExpression(ExpressionInfo(program, getLocation(ctx)),program->getSInt32Type(), value));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitStringExpression(WorkScriptParser::StringExpressionContext *ctx)
{
	string text = ctx->STRING()->getText();
	text = text.substr(1, text.length() - 2);
	wstring wtext = Locale::ansiToUnicode(text);

	wchar_t *unescapedText = new wchar_t[wtext.length() + 1];
	try {
		handleEscapeCharacters(wtext.c_str(), unescapedText, getLocation(ctx));
	}
	catch(...){
		delete[]unescapedText;
		throw;
	}
	auto lpExpr = new StringExpression(ExpressionInfo(program, getLocation(ctx)), unescapedText);
	delete[]unescapedText;
	return ExpressionWrapper(lpExpr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx)
{
	string boolStr = ctx->BOOLEAN()->getText();
	if (boolStr == "true" || boolStr == "yes" || boolStr == "ok" || boolStr == "good") {
		return ExpressionWrapper(new IntegerExpression(ExpressionInfo(program, getLocation(ctx)), program->getUInt1Type(), 1));
	}
	else if (boolStr == "false" || boolStr == "no" || boolStr == "bad") {
		return ExpressionWrapper(new IntegerExpression(ExpressionInfo(program, getLocation(ctx)), program->getUInt1Type(), 0));
	}
	else {
		throw std::move(SyntaxErrorException(getLocation(ctx), L"�޷�ʶ��Ĳ���ֵ��" + Locale::ansiToUnicode(boolStr)));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx)
{
	string varName = ctx->identifier()->getText();
	SymbolTable *symbolTable = currentOverloadTemplate->getSymbolTable();
	auto expr = new TemplateVariableExpression(ExpressionInfo(program, getLocation(ctx)), Locale::ansiToUnicode(varName), symbolTable, nullptr);
	expr->setDeclarable(this->declarable); //�Ⱥ���ߵı����ſ��Դ�������
	auto wrapper = ExpressionWrapper(expr);
	return wrapper;
}

antlrcpp::Any WorkScriptVisitorImpl::visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	/*====������һ��====*/
	++this->curDepth;

	/*���ݺ������ҵ����½���Ӧ�ĺ���ģ��*/
	auto funcNameCtx = ctx->functionDeclarationExpression()->identifier();
	wstring funcName;
	if (funcNameCtx != nullptr) {
		funcName = Locale::ansiToUnicode(funcNameCtx->getText());
	}
	FunctionTemplate* funcTemplate = this->program->getFunctionTemplate(funcName);
	if (!funcTemplate) {
		funcTemplate = new FunctionTemplate(this->program, funcName);
		this->program->addFunctionTemplate(funcTemplate);
	}

	/*�������Ĳ���������*/
	//��������
	auto paramsDeclCtx = ctx->functionDeclarationExpression()->formalParameterExpression()->multiValueExpression()->expression();
	vector<Expression*> paramDeclExprs;
	paramDeclExprs.reserve(paramsDeclCtx.size());

	for (size_t i = 0; i < paramsDeclCtx.size(); ++i)
	{
		paramDeclExprs.push_back(paramsDeclCtx[i]->accept(this).as<ExpressionWrapper>().getExpression());
	}
	//��������
	vector<Expression*> constraintsDecl;
	auto constraintCtx = ctx->functionConstraintExpression();
	if (constraintCtx) {
		if (constraintCtx->expression())
		{
			auto expr = constraintCtx->expression()->accept(this).as<ExpressionWrapper>().getExpression();
			constraintsDecl.push_back(expr);
		}
		else {
			for (auto curCtx : constraintCtx->blockExpression()->expression()) {
				auto expr = curCtx->accept(this).as<Expression*>();
				constraintsDecl.push_back(expr);
			}
		}
	}
	//��������������
	auto resolveRes = FormalParametersTemplateResolver::resolve(ExpressionInfo(program, getLocation(ctx)), this->currentOverloadTemplate->getSymbolTable(), paramDeclExprs, constraintsDecl);
	auto paramTypes = resolveRes.getParameterTypes();
	auto paramTemplates = resolveRes.getParameterTemplates();
	auto constraints = resolveRes.getConstraints();


	/*������������ӵ���Ӧ�����ط�֧��*/
	//Ѱ�����أ�ͬʱ�ж��Ƿ�����з���ֵ������ͬ��������������½���
	//TODO �жϣ�������BranchOverloadTemplate������ӷ�֧�������NativeOverload���ֹ��ӷ�֧
	BranchOverloadTemplate *overloadTemplate = (BranchOverloadTemplate*)funcTemplate->getOverload(paramTypes);
	if (!overloadTemplate){
		overloadTemplate = new BranchOverloadTemplate(funcTemplate, paramTemplates, nullptr);
		funcTemplate->addOverload(overloadTemplate);
	}
	auto prevOverloadTemplate = this->currentOverloadTemplate;
	//����ǰ�������óɴ˴�����
	this->currentOverloadTemplate = overloadTemplate;

	/*������ʵ��*/
	ALLOW_ASSIGN;
	vector<Expression*> impls;
	if (ctx->functionImplementationExpression()->expression() != nullptr) {
		auto expr = ctx->functionImplementationExpression()->expression()->accept(this).as<ExpressionWrapper>();
		impls.push_back(expr.getExpression());
	}
	else {
		auto exprs = ctx->functionImplementationExpression()->blockExpression()->expression();
		impls.reserve(exprs.size());
		for (size_t i = 0; i < exprs.size(); ++i)
		{
			auto wrapper = exprs[i]->accept(this).as<ExpressionWrapper>();
			impls.push_back(wrapper.getExpression());
		}
	}
	FORBID_ASSIGN;
	//�ָ���ǰ����
	this->currentOverloadTemplate = prevOverloadTemplate;

	/*������غ͵�ǰ���ط�֧�ķ���ֵ�����Ƿ���ͬ*/
	//TODO ������ͬ������ȡ��������ֵ�����еĸ�������
	Type * returnType;
	if (impls.size() == 0) {
		returnType = this->program->getVoidType();
	}
	else {
		returnType = impls[impls.size() - 1]->getType();
	}
	Type *overloadReturnType = overloadTemplate->getReturnType();
	if (!overloadReturnType) {
		overloadTemplate->setReturnType(returnType);
	}else if (returnType && !returnType->equals(overloadReturnType)) {
		throw SyntaxErrorException(getLocation(ctx), L"����ֵ����Ϊ" + overloadReturnType->getName() + L"����");
	}
	
	//������ط�֧
	auto branch = new OverloadBranchTemplate(overloadTemplate, getLocation(ctx), constraints, impls);
	overloadTemplate->setBranches({ branch });

	/*====�ָ���һ��====*/
	--this->curDepth;
	RESTORE_ASSIGNABLE;
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitCallExpression(WorkScriptParser::CallExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	ExpressionWrapper paramExpressionWrapper = ctx->multiValueExpression()->accept(this);
	auto funcName = Locale::ansiToUnicode(ctx->identifier()->getText());
	auto paramExpr = (MultiValueExpression*)paramExpressionWrapper.getExpression();
	FunctionTemplate *functionTemplate = program->getFunctionTemplate(funcName);
	OverloadTemplate *overloadTemplate = functionTemplate->getOverload(paramExpr->getTypes());
	auto expr = new TemplateCallExpression(ExpressionInfo(program, getLocation(ctx)), funcName, overloadTemplate, paramExpr);
	RESTORE_ASSIGNABLE;
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitProgram(WorkScriptParser::ProgramContext *ctx)
{
	auto exprs = ctx->expression();
	for (auto &expr : exprs)
	{
		ALLOW_ASSIGN; //ÿ���µ�һ�ж�����ֵ
		expr->accept(this); //����ֻ�к������������Զ����뵽program��
	}
	return nullptr;
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx)
{
	if (this->assignable) {
		STORE_FORBID_ASSIGN;
		this->declarable = true;
		auto left = ctx->expression()[0]->accept(this).as<ExpressionWrapper>().getExpression();
		this->declarable = false;
		auto right = ctx->expression()[1]->accept(this).as<ExpressionWrapper>().getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new AssignmentExpression(ExpressionInfo(program, getLocation(ctx)), left, right));
	}
	else {
		STORE_FORBID_ASSIGN;
		auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
		auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
		RESTORE_ASSIGNABLE;
		return ExpressionWrapper(new BinaryCompareExpression(ExpressionInfo(program, getLocation(ctx)), left, right, BinaryCompareExpression::CompareType::EQUAL));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto left = ((ExpressionWrapper)ctx->expression()[0]->accept(this)).getExpression();
	auto right = ((ExpressionWrapper)ctx->expression()[1]->accept(this)).getExpression();
	RESTORE_ASSIGNABLE;
	auto expr = new AssignmentExpression(ExpressionInfo(program, getLocation(ctx)), left, right);
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiValueExpression(WorkScriptParser::MultiValueExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
	auto subContext = ctx->expression();
	size_t subContextCount = subContext.size();
	vector<Expression*> items;
	items.reserve(subContextCount);
	for (size_t i = 0; i < subContextCount; ++i) {
		ExpressionWrapper wrapper = subContext[i]->accept(this);
		auto itemExpr = wrapper.getExpression();
		items[i] = itemExpr;
	}
	auto expr = new WorkScript::MultiValueExpression(ExpressionInfo(program, getLocation(ctx)), items);
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
//	return ExpressionWrapper(Expression*(new MemberEvaluateExpression(this->context,objExpr,memberExpr)));
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
		Expression *expr = new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::PLUS);
		return ExpressionWrapper(expr);
	}
	else { //MINUS
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::MINUS));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN
		const ExpressionWrapper &leftExpressionWrapper = ctx->expression()[0]->accept(this);
	auto leftExpression = leftExpressionWrapper.getExpression();
	const ExpressionWrapper &rightExpressionWrapper = ctx->expression()[1]->accept(this);
	auto rightExpression = rightExpressionWrapper.getExpression();
	RESTORE_ASSIGNABLE;
	if (ctx->MULTIPLY()) {
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::MULTIPLY));
	}
	else if (ctx->DIVIDE()) {
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::DIVIDE));
	}
	else { //MODULUS
		return ExpressionWrapper(new BinaryCalculateExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, BinaryCalculateExpression::MODULUS));
	}
}

antlrcpp::Any WorkScriptVisitorImpl::visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx)
{
	STORE_FORBID_ASSIGN;
	auto ret = ctx->expression()->accept(this);
	RESTORE_ASSIGNABLE;
	return ret;
}

antlrcpp::Any WorkScriptVisitorImpl::visitBinaryCompareExpression(WorkScriptParser::BinaryCompareExpressionContext *ctx)
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
	return new BinaryCompareExpression(ExpressionInfo(program, getLocation(ctx)), leftExpression, rightExpression, compareType);
}

//antlrcpp::Any WorkScriptVisitorImpl::visitListExpression(WorkScriptParser::ListExpressionContext *ctx)
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

antlrcpp::Any WorkScriptVisitorImpl::visitNegativeExpression(WorkScriptParser::NegativeExpressionContext *ctx)
{
	ExpressionWrapper wrapper = ctx->expression()->accept(this);
	auto expr = new UnaryOperatorExpression(ExpressionInfo(program, getLocation(ctx)), wrapper.getExpression(), UnaryOperatorExpression::NEGATIVE);
	return ExpressionWrapper(expr);
}

antlrcpp::Any WorkScriptVisitorImpl::visitPositiveExpression(WorkScriptParser::PositiveExpressionContext *ctx)
{
	return ctx->expression()->accept(this);
}

antlrcpp::Any WorkScriptVisitorImpl::visitVarargsExpression(WorkScriptParser::VarargsExpressionContext *ctx)
{
	ExpressionWrapper varWrapper = ctx->variableExpression()->accept(this);
	auto varExpr = (VariableExpression *)varWrapper.getExpression();
	varExpr->setVarargs(true);
	return varWrapper;
}

WorkScriptVisitorImpl::WorkScriptVisitorImpl(Program *lpProgram)
{
	this->program = lpProgram;
}

WorkScriptVisitorImpl::~WorkScriptVisitorImpl()
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

