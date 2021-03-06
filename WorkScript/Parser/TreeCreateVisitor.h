#pragma once
#include <memory>
#include <vector>
#include <stack>
#include "Generated/WorkScriptBaseVisitor.h"
#include "Variable.h"

namespace WorkScript {
	class Module;
	class FunctionFragment;

	class TreeCreateVisitor :
		public WorkScriptBaseVisitor
	{
	public:
		antlrcpp::Any visitBlock(WorkScriptParser::BlockContext*)override;
		antlrcpp::Any visitLine(WorkScriptParser::LineContext*)override;
		antlrcpp::Any visitNumber(WorkScriptParser::NumberContext*) override;
		antlrcpp::Any visitString(WorkScriptParser::StringContext*) override;
		antlrcpp::Any visitBoolean(WorkScriptParser::BooleanContext*)override;
		antlrcpp::Any visitVariable(WorkScriptParser::VariableContext*) override;
		antlrcpp::Any visitFunctionDefine(WorkScriptParser::FunctionDefineContext*) override;
		antlrcpp::Any visitStdFunctionDecl(WorkScriptParser::StdFunctionDeclContext*) override;
		antlrcpp::Any visitCall(WorkScriptParser::CallContext*) override;
		antlrcpp::Any visitModule(WorkScriptParser::ModuleContext*) override;
		antlrcpp::Any visitAssignmentOrEquals(WorkScriptParser::AssignmentOrEqualsContext*)override;
		antlrcpp::Any visitAssignment(WorkScriptParser::AssignmentContext*)override;
		antlrcpp::Any visitMultiValue(WorkScriptParser::MultiValueContext*) override;
		//antlrcpp::Any visitMemberEvaluate(WorkScriptParser::MemberEvaluateContext*) override;
		antlrcpp::Any visitPlusMinus(WorkScriptParser::PlusMinusContext*) override;
		antlrcpp::Any visitMultiplyDivideModulus(WorkScriptParser::MultiplyDivideModulusContext*) override;
		antlrcpp::Any visitParenthese(WorkScriptParser::ParentheseContext*)override;
		antlrcpp::Any visitBinaryCompare(WorkScriptParser::BinaryCompareContext*)override;
		//antlrcpp::Any visitList(WorkScriptParser::ListContext*)override;
		antlrcpp::Any visitNegative(WorkScriptParser::NegativeContext*)override;
		antlrcpp::Any visitPositive(WorkScriptParser::PositiveContext*)override;
		antlrcpp::Any visitType(WorkScriptParser::TypeContext*) override;
		//antlrcpp::Any visitAccessLevel(WorkScriptParser::AccessLevelContext*)override;
		TreeCreateVisitor(Module* module, const std::wstring &fileName);
		virtual ~TreeCreateVisitor();

		inline Module *getModule() const {return this->module;}
		inline const std::wstring &getFileName() const {return this->fileName;}
	private:
		Module * module = nullptr;
		bool assignable = true;
		bool declarable = false;
		size_t curDepth = 0;
		std::wstring fileName;
		std::stack<AbstractContext*> abstractContexts;
	};
}