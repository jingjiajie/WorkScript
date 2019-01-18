// Generated from WorkScript.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link WorkScriptParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface WorkScriptVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(WorkScriptParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#line}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLine(WorkScriptParser.LineContext ctx);
	/**
	 * Visit a parse tree produced by the {@code StdFunctionDecl_}
	 * labeled alternative in {@link WorkScriptParser#function}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStdFunctionDecl_(WorkScriptParser.StdFunctionDecl_Context ctx);
	/**
	 * Visit a parse tree produced by the {@code FunctionDefine_}
	 * labeled alternative in {@link WorkScriptParser#function}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionDefine_(WorkScriptParser.FunctionDefine_Context ctx);
	/**
	 * Visit a parse tree produced by the {@code BinaryCompare}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBinaryCompare(WorkScriptParser.BinaryCompareContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariable(WorkScriptParser.VariableContext ctx);
	/**
	 * Visit a parse tree produced by the {@code MultiplyDivideModulus}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiplyDivideModulus(WorkScriptParser.MultiplyDivideModulusContext ctx);
	/**
	 * Visit a parse tree produced by the {@code AssignmentOrEquals}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignmentOrEquals(WorkScriptParser.AssignmentOrEqualsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code String}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitString(WorkScriptParser.StringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code AccessLevel}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAccessLevel(WorkScriptParser.AccessLevelContext ctx);
	/**
	 * Visit a parse tree produced by the {@code PlusMinus}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlusMinus(WorkScriptParser.PlusMinusContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Assignment}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignment(WorkScriptParser.AssignmentContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Number}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumber(WorkScriptParser.NumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Negative}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNegative(WorkScriptParser.NegativeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Positive}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPositive(WorkScriptParser.PositiveContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Parenthese}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParenthese(WorkScriptParser.ParentheseContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Call_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_(WorkScriptParser.Call_Context ctx);
	/**
	 * Visit a parse tree produced by the {@code Boolean}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBoolean(WorkScriptParser.BooleanContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#call}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall(WorkScriptParser.CallContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#multiValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiValue(WorkScriptParser.MultiValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#stdFunctionDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStdFunctionDecl(WorkScriptParser.StdFunctionDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#stdFormalParameter}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStdFormalParameter(WorkScriptParser.StdFormalParameterContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#stdFormalParameterItem}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStdFormalParameterItem(WorkScriptParser.StdFormalParameterItemContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionDefine}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionDefine(WorkScriptParser.FunctionDefineContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionDeclaration(WorkScriptParser.FunctionDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#typeName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeName(WorkScriptParser.TypeNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionName(WorkScriptParser.FunctionNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#formalParameter}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFormalParameter(WorkScriptParser.FormalParameterContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#formalParameterItem}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFormalParameterItem(WorkScriptParser.FormalParameterItemContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionImplementation}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionImplementation(WorkScriptParser.FunctionImplementationContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionConstraint}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionConstraint(WorkScriptParser.FunctionConstraintContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock(WorkScriptParser.BlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#staticVarargs}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStaticVarargs(WorkScriptParser.StaticVarargsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#newlineOrComma}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNewlineOrComma(WorkScriptParser.NewlineOrCommaContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#identifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifier(WorkScriptParser.IdentifierContext ctx);
}