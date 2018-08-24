// Generated from WorkScript.g4 by ANTLR 4.7.1
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
	 * Visit a parse tree produced by the {@code ParentheseExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParentheseExpression(WorkScriptParser.ParentheseExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ListExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitListExpression(WorkScriptParser.ListExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code FunctionInvocationExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionInvocationExpression(WorkScriptParser.FunctionInvocationExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code NumberExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumberExpression(WorkScriptParser.NumberExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code VariableExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableExpression(WorkScriptParser.VariableExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code CompareExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCompareExpression(WorkScriptParser.CompareExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code MethodInvocationExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMethodInvocationExpression(WorkScriptParser.MethodInvocationExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code AssignmentOrEqualsExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignmentOrEqualsExpression(WorkScriptParser.AssignmentOrEqualsExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code MultiplyDivideExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiplyDivideExpression(WorkScriptParser.MultiplyDivideExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code MemberEvaluateExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMemberEvaluateExpression(WorkScriptParser.MemberEvaluateExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code StringExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStringExpression(WorkScriptParser.StringExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code FunctionExpression_}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionExpression_(WorkScriptParser.FunctionExpression_Context ctx);
	/**
	 * Visit a parse tree produced by the {@code PlusMinusExpression}
	 * labeled alternative in {@link WorkScriptParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlusMinusExpression(WorkScriptParser.PlusMinusExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#parameterExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterExpression(WorkScriptParser.ParameterExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionExpression(WorkScriptParser.FunctionExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionDeclarationExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionDeclarationExpression(WorkScriptParser.FunctionDeclarationExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionImplementationExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionImplementationExpression(WorkScriptParser.FunctionImplementationExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#functionConstraintExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionConstraintExpression(WorkScriptParser.FunctionConstraintExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#blockExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlockExpression(WorkScriptParser.BlockExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link WorkScriptParser#identifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifier(WorkScriptParser.IdentifierContext ctx);
}