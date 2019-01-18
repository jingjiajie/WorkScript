
// Generated from WorkScript.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "WorkScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by WorkScriptParser.
 */
class  WorkScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by WorkScriptParser.
   */
    virtual antlrcpp::Any visitProgram(WorkScriptParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitLine(WorkScriptParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitStdFunctionDecl_(WorkScriptParser::StdFunctionDecl_Context *context) = 0;

    virtual antlrcpp::Any visitFunctionDefine_(WorkScriptParser::FunctionDefine_Context *context) = 0;

    virtual antlrcpp::Any visitBinaryCompare(WorkScriptParser::BinaryCompareContext *context) = 0;

    virtual antlrcpp::Any visitVariable(WorkScriptParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitMultiplyDivideModulus(WorkScriptParser::MultiplyDivideModulusContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOrEquals(WorkScriptParser::AssignmentOrEqualsContext *context) = 0;

    virtual antlrcpp::Any visitString(WorkScriptParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitAccessLevel(WorkScriptParser::AccessLevelContext *context) = 0;

    virtual antlrcpp::Any visitPlusMinus(WorkScriptParser::PlusMinusContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(WorkScriptParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitNumber(WorkScriptParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitNegative(WorkScriptParser::NegativeContext *context) = 0;

    virtual antlrcpp::Any visitPositive(WorkScriptParser::PositiveContext *context) = 0;

    virtual antlrcpp::Any visitParenthese(WorkScriptParser::ParentheseContext *context) = 0;

    virtual antlrcpp::Any visitCall_(WorkScriptParser::Call_Context *context) = 0;

    virtual antlrcpp::Any visitBoolean(WorkScriptParser::BooleanContext *context) = 0;

    virtual antlrcpp::Any visitCall(WorkScriptParser::CallContext *context) = 0;

    virtual antlrcpp::Any visitMultiValue(WorkScriptParser::MultiValueContext *context) = 0;

    virtual antlrcpp::Any visitStdFunctionDecl(WorkScriptParser::StdFunctionDeclContext *context) = 0;

    virtual antlrcpp::Any visitStdFormalParameter(WorkScriptParser::StdFormalParameterContext *context) = 0;

    virtual antlrcpp::Any visitStdFormalParameterItem(WorkScriptParser::StdFormalParameterItemContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefine(WorkScriptParser::FunctionDefineContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(WorkScriptParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(WorkScriptParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitFunctionName(WorkScriptParser::FunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameter(WorkScriptParser::FormalParameterContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameterItem(WorkScriptParser::FormalParameterItemContext *context) = 0;

    virtual antlrcpp::Any visitFunctionImplementation(WorkScriptParser::FunctionImplementationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionConstraint(WorkScriptParser::FunctionConstraintContext *context) = 0;

    virtual antlrcpp::Any visitBlock(WorkScriptParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStaticVarargs(WorkScriptParser::StaticVarargsContext *context) = 0;

    virtual antlrcpp::Any visitNewlineOrComma(WorkScriptParser::NewlineOrCommaContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(WorkScriptParser::IdentifierContext *context) = 0;


};

