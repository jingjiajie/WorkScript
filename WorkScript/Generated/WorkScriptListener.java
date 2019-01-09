// Generated from WorkScript.g4 by ANTLR 4.7.1
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
	 * Enter a parse tree produced by {@link WorkScriptParser#includeCommand}.
	 * @param ctx the parse tree
	 */
	void enterIncludeCommand(WorkScriptParser.IncludeCommandContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#includeCommand}.
	 * @param ctx the parse tree
	 */
	void exitIncludeCommand(WorkScriptParser.IncludeCommandContext ctx);
	/**
	 * Enter a parse tree produced by the {@code AccessLevelExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAccessLevelExpression(WorkScriptParser.AccessLevelExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AccessLevelExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAccessLevelExpression(WorkScriptParser.AccessLevelExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParentheseExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterParentheseExpression(WorkScriptParser.ParentheseExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParentheseExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitParentheseExpression(WorkScriptParser.ParentheseExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code CallExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterCallExpression_(WorkScriptParser.CallExpression_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code CallExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitCallExpression_(WorkScriptParser.CallExpression_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code StringExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterStringExpression_(WorkScriptParser.StringExpression_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code StringExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitStringExpression_(WorkScriptParser.StringExpression_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code MultiplyDivideModulusExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterMultiplyDivideModulusExpression(WorkScriptParser.MultiplyDivideModulusExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MultiplyDivideModulusExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitMultiplyDivideModulusExpression(WorkScriptParser.MultiplyDivideModulusExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VariableExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterVariableExpression_(WorkScriptParser.VariableExpression_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code VariableExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitVariableExpression_(WorkScriptParser.VariableExpression_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryCompareExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBinaryCompareExpression(WorkScriptParser.BinaryCompareExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryCompareExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBinaryCompareExpression(WorkScriptParser.BinaryCompareExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BooleanExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBooleanExpression_(WorkScriptParser.BooleanExpression_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code BooleanExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBooleanExpression_(WorkScriptParser.BooleanExpression_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code AssignmentOrEqualsExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAssignmentOrEqualsExpression(WorkScriptParser.AssignmentOrEqualsExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AssignmentOrEqualsExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAssignmentOrEqualsExpression(WorkScriptParser.AssignmentOrEqualsExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code NumberExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterNumberExpression_(WorkScriptParser.NumberExpression_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code NumberExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitNumberExpression_(WorkScriptParser.NumberExpression_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code AssignmentExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAssignmentExpression(WorkScriptParser.AssignmentExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AssignmentExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAssignmentExpression(WorkScriptParser.AssignmentExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StdFunctionDeclExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterStdFunctionDeclExpression_(WorkScriptParser.StdFunctionDeclExpression_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code StdFunctionDeclExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitStdFunctionDeclExpression_(WorkScriptParser.StdFunctionDeclExpression_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code PositiveExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterPositiveExpression(WorkScriptParser.PositiveExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code PositiveExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitPositiveExpression(WorkScriptParser.PositiveExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterFunctionExpression_(WorkScriptParser.FunctionExpression_Context ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitFunctionExpression_(WorkScriptParser.FunctionExpression_Context ctx);
	/**
	 * Enter a parse tree produced by the {@code PlusMinusExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterPlusMinusExpression(WorkScriptParser.PlusMinusExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code PlusMinusExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitPlusMinusExpression(WorkScriptParser.PlusMinusExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code NegativeExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterNegativeExpression(WorkScriptParser.NegativeExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code NegativeExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitNegativeExpression(WorkScriptParser.NegativeExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#callExpression}.
	 * @param ctx the parse tree
	 */
	void enterCallExpression(WorkScriptParser.CallExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#callExpression}.
	 * @param ctx the parse tree
	 */
	void exitCallExpression(WorkScriptParser.CallExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#multiValueExpression}.
	 * @param ctx the parse tree
	 */
	void enterMultiValueExpression(WorkScriptParser.MultiValueExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#multiValueExpression}.
	 * @param ctx the parse tree
	 */
	void exitMultiValueExpression(WorkScriptParser.MultiValueExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#numberExpression}.
	 * @param ctx the parse tree
	 */
	void enterNumberExpression(WorkScriptParser.NumberExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#numberExpression}.
	 * @param ctx the parse tree
	 */
	void exitNumberExpression(WorkScriptParser.NumberExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#stringExpression}.
	 * @param ctx the parse tree
	 */
	void enterStringExpression(WorkScriptParser.StringExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#stringExpression}.
	 * @param ctx the parse tree
	 */
	void exitStringExpression(WorkScriptParser.StringExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#variableExpression}.
	 * @param ctx the parse tree
	 */
	void enterVariableExpression(WorkScriptParser.VariableExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#variableExpression}.
	 * @param ctx the parse tree
	 */
	void exitVariableExpression(WorkScriptParser.VariableExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#stdFunctionDeclExpression}.
	 * @param ctx the parse tree
	 */
	void enterStdFunctionDeclExpression(WorkScriptParser.StdFunctionDeclExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#stdFunctionDeclExpression}.
	 * @param ctx the parse tree
	 */
	void exitStdFunctionDeclExpression(WorkScriptParser.StdFunctionDeclExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#stdFormalParameterExpression}.
	 * @param ctx the parse tree
	 */
	void enterStdFormalParameterExpression(WorkScriptParser.StdFormalParameterExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#stdFormalParameterExpression}.
	 * @param ctx the parse tree
	 */
	void exitStdFormalParameterExpression(WorkScriptParser.StdFormalParameterExpressionContext ctx);
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
	 * Enter a parse tree produced by {@link WorkScriptParser#functionExpression}.
	 * @param ctx the parse tree
	 */
	void enterFunctionExpression(WorkScriptParser.FunctionExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionExpression}.
	 * @param ctx the parse tree
	 */
	void exitFunctionExpression(WorkScriptParser.FunctionExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#functionDeclarationExpression}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDeclarationExpression(WorkScriptParser.FunctionDeclarationExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionDeclarationExpression}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDeclarationExpression(WorkScriptParser.FunctionDeclarationExpressionContext ctx);
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
	 * Enter a parse tree produced by {@link WorkScriptParser#formalParameterExpression}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameterExpression(WorkScriptParser.FormalParameterExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#formalParameterExpression}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameterExpression(WorkScriptParser.FormalParameterExpressionContext ctx);
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
	 * Enter a parse tree produced by {@link WorkScriptParser#functionImplementationExpression}.
	 * @param ctx the parse tree
	 */
	void enterFunctionImplementationExpression(WorkScriptParser.FunctionImplementationExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionImplementationExpression}.
	 * @param ctx the parse tree
	 */
	void exitFunctionImplementationExpression(WorkScriptParser.FunctionImplementationExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#functionConstraintExpression}.
	 * @param ctx the parse tree
	 */
	void enterFunctionConstraintExpression(WorkScriptParser.FunctionConstraintExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#functionConstraintExpression}.
	 * @param ctx the parse tree
	 */
	void exitFunctionConstraintExpression(WorkScriptParser.FunctionConstraintExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#blockExpression}.
	 * @param ctx the parse tree
	 */
	void enterBlockExpression(WorkScriptParser.BlockExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#blockExpression}.
	 * @param ctx the parse tree
	 */
	void exitBlockExpression(WorkScriptParser.BlockExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#booleanExpression}.
	 * @param ctx the parse tree
	 */
	void enterBooleanExpression(WorkScriptParser.BooleanExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#booleanExpression}.
	 * @param ctx the parse tree
	 */
	void exitBooleanExpression(WorkScriptParser.BooleanExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WorkScriptParser#varargsExpression}.
	 * @param ctx the parse tree
	 */
	void enterVarargsExpression(WorkScriptParser.VarargsExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WorkScriptParser#varargsExpression}.
	 * @param ctx the parse tree
	 */
	void exitVarargsExpression(WorkScriptParser.VarargsExpressionContext ctx);
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