// Generated from WorkScript.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link WorkScriptParser}.
 */
public interface WorkScriptListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(WorkScriptParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(WorkScriptParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#line}.
	 * @param ctx the parse tree
	 */
	void enterLine(WorkScriptParser.LineContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#line}.
	 * @param ctx the parse tree
	 */
	void exitLine(WorkScriptParser.LineContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StdFunctionDecl_}
	 * labeled alternative in {@link WorkScriptParser#function}.
	 * @param ctx the parse tree
	 */
	void enterStdFunctionDecl_(WorkScriptParser.StdFunctionDecl_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code StdFunctionDecl_}
	 * labeled alternative in {@link WorkScriptParser#function}.
	 * @param ctx the parse tree
	 */
	void exitStdFunctionDecl_(WorkScriptParser.StdFunctionDecl_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionDefine_}
	 * labeled alternative in {@link WorkScriptParser#function}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDefine_(WorkScriptParser.FunctionDefine_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionDefine_}
	 * labeled alternative in {@link WorkScriptParser#function}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDefine_(WorkScriptParser.FunctionDefine_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryCompare}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBinaryCompare(WorkScriptParser.BinaryCompareContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryCompare}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBinaryCompare(WorkScriptParser.BinaryCompareContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterVariable(WorkScriptParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitVariable(WorkScriptParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MultiplyDivideModulus}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterMultiplyDivideModulus(WorkScriptParser.MultiplyDivideModulusContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MultiplyDivideModulus}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitMultiplyDivideModulus(WorkScriptParser.MultiplyDivideModulusContext ctx);
	/**
	 * Enter a parse tree produced by the {@code AssignmentOrEquals}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAssignmentOrEquals(WorkScriptParser.AssignmentOrEqualsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AssignmentOrEquals}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAssignmentOrEquals(WorkScriptParser.AssignmentOrEqualsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code String}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterString(WorkScriptParser.StringContext ctx);
	/**
	 * Exit a parse tree produced by the {@code String}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitString(WorkScriptParser.StringContext ctx);
	/**
	 * Enter a parse tree produced by the {@code AccessLevel}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAccessLevel(WorkScriptParser.AccessLevelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AccessLevel}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAccessLevel(WorkScriptParser.AccessLevelContext ctx);
	/**
	 * Enter a parse tree produced by the {@code PlusMinus}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterPlusMinus(WorkScriptParser.PlusMinusContext ctx);
	/**
	 * Exit a parse tree produced by the {@code PlusMinus}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitPlusMinus(WorkScriptParser.PlusMinusContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Assignment}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(WorkScriptParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Assignment}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(WorkScriptParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Number}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterNumber(WorkScriptParser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Number}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitNumber(WorkScriptParser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Negative}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterNegative(WorkScriptParser.NegativeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Negative}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitNegative(WorkScriptParser.NegativeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Positive}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterPositive(WorkScriptParser.PositiveContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Positive}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitPositive(WorkScriptParser.PositiveContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parenthese}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterParenthese(WorkScriptParser.ParentheseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parenthese}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitParenthese(WorkScriptParser.ParentheseContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Call_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterCall_(WorkScriptParser.Call_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code Call_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitCall_(WorkScriptParser.Call_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code Boolean}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBoolean(WorkScriptParser.BooleanContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Boolean}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBoolean(WorkScriptParser.BooleanContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#call}.
	 * @param ctx the parse tree
	 */
	void enterCall(WorkScriptParser.CallContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#call}.
	 * @param ctx the parse tree
	 */
	void exitCall(WorkScriptParser.CallContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#multiValue}.
	 * @param ctx the parse tree
	 */
	void enterMultiValue(WorkScriptParser.MultiValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#multiValue}.
	 * @param ctx the parse tree
	 */
	void exitMultiValue(WorkScriptParser.MultiValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#stdFunctionDecl}.
	 * @param ctx the parse tree
	 */
	void enterStdFunctionDecl(WorkScriptParser.StdFunctionDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#stdFunctionDecl}.
	 * @param ctx the parse tree
	 */
	void exitStdFunctionDecl(WorkScriptParser.StdFunctionDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#stdFormalParameter}.
	 * @param ctx the parse tree
	 */
	void enterStdFormalParameter(WorkScriptParser.StdFormalParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#stdFormalParameter}.
	 * @param ctx the parse tree
	 */
	void exitStdFormalParameter(WorkScriptParser.StdFormalParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#stdFormalParameterItem}.
	 * @param ctx the parse tree
	 */
	void enterStdFormalParameterItem(WorkScriptParser.StdFormalParameterItemContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#stdFormalParameterItem}.
	 * @param ctx the parse tree
	 */
	void exitStdFormalParameterItem(WorkScriptParser.StdFormalParameterItemContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#functionDefine}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDefine(WorkScriptParser.FunctionDefineContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionDefine}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDefine(WorkScriptParser.FunctionDefineContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#functionDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDeclaration(WorkScriptParser.FunctionDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDeclaration(WorkScriptParser.FunctionDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#typeName}.
	 * @param ctx the parse tree
	 */
	void enterTypeName(WorkScriptParser.TypeNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#typeName}.
	 * @param ctx the parse tree
	 */
	void exitTypeName(WorkScriptParser.TypeNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#functionName}.
	 * @param ctx the parse tree
	 */
	void enterFunctionName(WorkScriptParser.FunctionNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionName}.
	 * @param ctx the parse tree
	 */
	void exitFunctionName(WorkScriptParser.FunctionNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#formalParameter}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameter(WorkScriptParser.FormalParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#formalParameter}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameter(WorkScriptParser.FormalParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#formalParameterItem}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameterItem(WorkScriptParser.FormalParameterItemContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#formalParameterItem}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameterItem(WorkScriptParser.FormalParameterItemContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#functionImplementation}.
	 * @param ctx the parse tree
	 */
	void enterFunctionImplementation(WorkScriptParser.FunctionImplementationContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionImplementation}.
	 * @param ctx the parse tree
	 */
	void exitFunctionImplementation(WorkScriptParser.FunctionImplementationContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#functionConstraint}.
	 * @param ctx the parse tree
	 */
	void enterFunctionConstraint(WorkScriptParser.FunctionConstraintContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionConstraint}.
	 * @param ctx the parse tree
	 */
	void exitFunctionConstraint(WorkScriptParser.FunctionConstraintContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(WorkScriptParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(WorkScriptParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#staticVarargs}.
	 * @param ctx the parse tree
	 */
	void enterStaticVarargs(WorkScriptParser.StaticVarargsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#staticVarargs}.
	 * @param ctx the parse tree
	 */
	void exitStaticVarargs(WorkScriptParser.StaticVarargsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#newlineOrComma}.
	 * @param ctx the parse tree
	 */
	void enterNewlineOrComma(WorkScriptParser.NewlineOrCommaContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#newlineOrComma}.
	 * @param ctx the parse tree
	 */
	void exitNewlineOrComma(WorkScriptParser.NewlineOrCommaContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#identifier}.
	 * @param ctx the parse tree
	 */
	void enterIdentifier(WorkScriptParser.IdentifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#identifier}.
	 * @param ctx the parse tree
	 */
	void exitIdentifier(WorkScriptParser.IdentifierContext ctx);
}