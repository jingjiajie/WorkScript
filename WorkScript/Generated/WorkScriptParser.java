// Generated from WorkScript.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class WorkScriptParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		WHEN=1, IDENTIFIER=2, NUMBER=3, STRING=4, POINT=5, COMMA=6, NEWLINE=7, 
		LEFT_PARENTHESE=8, RIGHT_PARENTHESE=9, LEFT_BRACE=10, RIGHT_BRACE=11, 
		LEFT_BRACKET=12, RIGHT_BRACKET=13, EQUALS=14, PLUS=15, MINUS=16, MULTIPLY=17, 
		DIVIDE=18, GREATER_THAN=19, GREATER_THAN_EQUAL=20, LESS_THAN=21, LESS_THAN_EQUAL=22, 
		WS=23;
	public static final int
		RULE_program = 0, RULE_expression = 1, RULE_parameterExpression = 2, RULE_functionExpression = 3, 
		RULE_functionDeclarationExpression = 4, RULE_functionImplementationExpression = 5, 
		RULE_functionConstraintExpression = 6, RULE_blockExpression = 7, RULE_identifier = 8;
	public static final String[] ruleNames = {
		"program", "expression", "parameterExpression", "functionExpression", 
		"functionDeclarationExpression", "functionImplementationExpression", "functionConstraintExpression", 
		"blockExpression", "identifier"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'when'", null, null, null, "'.'", "','", null, "'('", "')'", "'{'", 
		"'}'", "'['", "']'", "'='", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", 
		"'<'", "'<='"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "WHEN", "IDENTIFIER", "NUMBER", "STRING", "POINT", "COMMA", "NEWLINE", 
		"LEFT_PARENTHESE", "RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", 
		"RIGHT_BRACKET", "EQUALS", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "GREATER_THAN", 
		"GREATER_THAN_EQUAL", "LESS_THAN", "LESS_THAN_EQUAL", "WS"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "WorkScript.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public WorkScriptParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(WorkScriptParser.EOF, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(WorkScriptParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(WorkScriptParser.NEWLINE, i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitProgram(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << WHEN) | (1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << NEWLINE) | (1L << LEFT_PARENTHESE) | (1L << LEFT_BRACKET))) != 0)) {
				{
				setState(22);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case WHEN:
				case IDENTIFIER:
				case NUMBER:
				case STRING:
				case LEFT_PARENTHESE:
				case LEFT_BRACKET:
					{
					setState(18);
					expression(0);
					setState(19);
					match(NEWLINE);
					}
					break;
				case NEWLINE:
					{
					setState(21);
					match(NEWLINE);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(26);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(27);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ParentheseExpressionContext extends ExpressionContext {
		public TerminalNode LEFT_PARENTHESE() { return getToken(WorkScriptParser.LEFT_PARENTHESE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public ParentheseExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitParentheseExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class ListExpressionContext extends ExpressionContext {
		public TerminalNode LEFT_BRACKET() { return getToken(WorkScriptParser.LEFT_BRACKET, 0); }
		public TerminalNode RIGHT_BRACKET() { return getToken(WorkScriptParser.RIGHT_BRACKET, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(WorkScriptParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(WorkScriptParser.COMMA, i);
		}
		public ListExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitListExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class FunctionInvocationExpressionContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode LEFT_PARENTHESE() { return getToken(WorkScriptParser.LEFT_PARENTHESE, 0); }
		public ParameterExpressionContext parameterExpression() {
			return getRuleContext(ParameterExpressionContext.class,0);
		}
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public FunctionInvocationExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitFunctionInvocationExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class NumberExpressionContext extends ExpressionContext {
		public TerminalNode NUMBER() { return getToken(WorkScriptParser.NUMBER, 0); }
		public NumberExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitNumberExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class VariableExpressionContext extends ExpressionContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public VariableExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitVariableExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class CompareExpressionContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode GREATER_THAN() { return getToken(WorkScriptParser.GREATER_THAN, 0); }
		public TerminalNode GREATER_THAN_EQUAL() { return getToken(WorkScriptParser.GREATER_THAN_EQUAL, 0); }
		public TerminalNode LESS_THAN() { return getToken(WorkScriptParser.LESS_THAN, 0); }
		public TerminalNode LESS_THAN_EQUAL() { return getToken(WorkScriptParser.LESS_THAN_EQUAL, 0); }
		public CompareExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitCompareExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MethodInvocationExpressionContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode POINT() { return getToken(WorkScriptParser.POINT, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LEFT_PARENTHESE() { return getToken(WorkScriptParser.LEFT_PARENTHESE, 0); }
		public ParameterExpressionContext parameterExpression() {
			return getRuleContext(ParameterExpressionContext.class,0);
		}
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public MethodInvocationExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitMethodInvocationExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AssignmentOrEqualsExpressionContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode EQUALS() { return getToken(WorkScriptParser.EQUALS, 0); }
		public AssignmentOrEqualsExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitAssignmentOrEqualsExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MultiplyDivideExpressionContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode MULTIPLY() { return getToken(WorkScriptParser.MULTIPLY, 0); }
		public TerminalNode DIVIDE() { return getToken(WorkScriptParser.DIVIDE, 0); }
		public MultiplyDivideExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitMultiplyDivideExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MemberEvaluateExpressionContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode POINT() { return getToken(WorkScriptParser.POINT, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public MemberEvaluateExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitMemberEvaluateExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class StringExpressionContext extends ExpressionContext {
		public TerminalNode STRING() { return getToken(WorkScriptParser.STRING, 0); }
		public StringExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitStringExpression(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class FunctionExpression_Context extends ExpressionContext {
		public FunctionExpressionContext functionExpression() {
			return getRuleContext(FunctionExpressionContext.class,0);
		}
		public FunctionExpression_Context(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitFunctionExpression_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PlusMinusExpressionContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode PLUS() { return getToken(WorkScriptParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(WorkScriptParser.MINUS, 0); }
		public PlusMinusExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitPlusMinusExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(52);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				{
				_localctx = new ParentheseExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(30);
				match(LEFT_PARENTHESE);
				setState(31);
				expression(0);
				setState(32);
				match(RIGHT_PARENTHESE);
				}
				break;
			case 2:
				{
				_localctx = new ListExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(34);
				match(LEFT_BRACKET);
				setState(45);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << WHEN) | (1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << LEFT_BRACKET))) != 0)) {
					{
					setState(35);
					expression(0);
					setState(42);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << WHEN) | (1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << COMMA) | (1L << LEFT_PARENTHESE) | (1L << LEFT_BRACKET))) != 0)) {
						{
						{
						setState(37);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(36);
							match(COMMA);
							}
						}

						setState(39);
						expression(0);
						}
						}
						setState(44);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				setState(47);
				match(RIGHT_BRACKET);
				}
				break;
			case 3:
				{
				_localctx = new FunctionExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(48);
				functionExpression();
				}
				break;
			case 4:
				{
				_localctx = new NumberExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(49);
				match(NUMBER);
				}
				break;
			case 5:
				{
				_localctx = new StringExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(50);
				match(STRING);
				}
				break;
			case 6:
				{
				_localctx = new VariableExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(51);
				identifier();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(83);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(81);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplyDivideExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(54);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(55);
						_la = _input.LA(1);
						if ( !(_la==MULTIPLY || _la==DIVIDE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(56);
						expression(8);
						}
						break;
					case 2:
						{
						_localctx = new PlusMinusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(57);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(58);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(59);
						expression(7);
						}
						break;
					case 3:
						{
						_localctx = new AssignmentOrEqualsExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(60);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(61);
						match(EQUALS);
						setState(62);
						expression(6);
						}
						break;
					case 4:
						{
						_localctx = new CompareExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(63);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(64);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << GREATER_THAN) | (1L << GREATER_THAN_EQUAL) | (1L << LESS_THAN) | (1L << LESS_THAN_EQUAL))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(65);
						expression(5);
						}
						break;
					case 5:
						{
						_localctx = new FunctionInvocationExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(66);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(67);
						match(LEFT_PARENTHESE);
						setState(68);
						parameterExpression();
						setState(69);
						match(RIGHT_PARENTHESE);
						}
						break;
					case 6:
						{
						_localctx = new MethodInvocationExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(71);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(72);
						match(POINT);
						setState(73);
						identifier();
						setState(74);
						match(LEFT_PARENTHESE);
						setState(75);
						parameterExpression();
						setState(76);
						match(RIGHT_PARENTHESE);
						}
						break;
					case 7:
						{
						_localctx = new MemberEvaluateExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(78);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(79);
						match(POINT);
						setState(80);
						identifier();
						}
						break;
					}
					} 
				}
				setState(85);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ParameterExpressionContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(WorkScriptParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(WorkScriptParser.COMMA, i);
		}
		public ParameterExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterExpression; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitParameterExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ParameterExpressionContext parameterExpression() throws RecognitionException {
		ParameterExpressionContext _localctx = new ParameterExpressionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_parameterExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(96);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << WHEN) | (1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << LEFT_BRACKET))) != 0)) {
				{
				setState(86);
				expression(0);
				setState(93);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << WHEN) | (1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << COMMA) | (1L << LEFT_PARENTHESE) | (1L << LEFT_BRACKET))) != 0)) {
					{
					{
					setState(88);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==COMMA) {
						{
						setState(87);
						match(COMMA);
						}
					}

					setState(90);
					expression(0);
					}
					}
					setState(95);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionExpressionContext extends ParserRuleContext {
		public FunctionDeclarationExpressionContext functionDeclarationExpression() {
			return getRuleContext(FunctionDeclarationExpressionContext.class,0);
		}
		public FunctionImplementationExpressionContext functionImplementationExpression() {
			return getRuleContext(FunctionImplementationExpressionContext.class,0);
		}
		public FunctionConstraintExpressionContext functionConstraintExpression() {
			return getRuleContext(FunctionConstraintExpressionContext.class,0);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(WorkScriptParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(WorkScriptParser.NEWLINE, i);
		}
		public FunctionExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionExpression; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitFunctionExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FunctionExpressionContext functionExpression() throws RecognitionException {
		FunctionExpressionContext _localctx = new FunctionExpressionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_functionExpression);
		int _la;
		try {
			int _alt;
			setState(148);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(105);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
				case 1:
					{
					setState(98);
					functionConstraintExpression();
					setState(102);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==NEWLINE) {
						{
						{
						setState(99);
						match(NEWLINE);
						}
						}
						setState(104);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				}
				setState(107);
				functionDeclarationExpression();
				setState(111);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(108);
						match(NEWLINE);
						}
						} 
					}
					setState(113);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				}
				setState(114);
				functionImplementationExpression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(116);
				functionDeclarationExpression();
				setState(120);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(117);
					match(NEWLINE);
					}
					}
					setState(122);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(123);
				functionConstraintExpression();
				setState(127);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(124);
						match(NEWLINE);
						}
						} 
					}
					setState(129);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
				}
				setState(130);
				functionImplementationExpression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(132);
				functionDeclarationExpression();
				setState(136);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(133);
						match(NEWLINE);
						}
						} 
					}
					setState(138);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
				}
				setState(139);
				functionImplementationExpression();
				setState(143);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(140);
					match(NEWLINE);
					}
					}
					setState(145);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(146);
				functionConstraintExpression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionDeclarationExpressionContext extends ParserRuleContext {
		public TerminalNode LEFT_PARENTHESE() { return getToken(WorkScriptParser.LEFT_PARENTHESE, 0); }
		public ParameterExpressionContext parameterExpression() {
			return getRuleContext(ParameterExpressionContext.class,0);
		}
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public FunctionDeclarationExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDeclarationExpression; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitFunctionDeclarationExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FunctionDeclarationExpressionContext functionDeclarationExpression() throws RecognitionException {
		FunctionDeclarationExpressionContext _localctx = new FunctionDeclarationExpressionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_functionDeclarationExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(151);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHEN || _la==IDENTIFIER) {
				{
				setState(150);
				identifier();
				}
			}

			setState(153);
			match(LEFT_PARENTHESE);
			setState(154);
			parameterExpression();
			setState(155);
			match(RIGHT_PARENTHESE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionImplementationExpressionContext extends ParserRuleContext {
		public TerminalNode EQUALS() { return getToken(WorkScriptParser.EQUALS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public BlockExpressionContext blockExpression() {
			return getRuleContext(BlockExpressionContext.class,0);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(WorkScriptParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(WorkScriptParser.NEWLINE, i);
		}
		public FunctionImplementationExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionImplementationExpression; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitFunctionImplementationExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FunctionImplementationExpressionContext functionImplementationExpression() throws RecognitionException {
		FunctionImplementationExpressionContext _localctx = new FunctionImplementationExpressionContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_functionImplementationExpression);
		int _la;
		try {
			int _alt;
			setState(175);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(157);
				match(EQUALS);
				setState(158);
				expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(162);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(159);
						match(NEWLINE);
						}
						} 
					}
					setState(164);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
				}
				setState(166);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==EQUALS) {
					{
					setState(165);
					match(EQUALS);
					}
				}

				setState(171);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(168);
					match(NEWLINE);
					}
					}
					setState(173);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(174);
				blockExpression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionConstraintExpressionContext extends ParserRuleContext {
		public TerminalNode WHEN() { return getToken(WorkScriptParser.WHEN, 0); }
		public BlockExpressionContext blockExpression() {
			return getRuleContext(BlockExpressionContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(WorkScriptParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(WorkScriptParser.NEWLINE, i);
		}
		public FunctionConstraintExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionConstraintExpression; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitFunctionConstraintExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FunctionConstraintExpressionContext functionConstraintExpression() throws RecognitionException {
		FunctionConstraintExpressionContext _localctx = new FunctionConstraintExpressionContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_functionConstraintExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(177);
			match(WHEN);
			setState(181);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(178);
				match(NEWLINE);
				}
				}
				setState(183);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(186);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LEFT_BRACE:
				{
				setState(184);
				blockExpression();
				}
				break;
			case WHEN:
			case IDENTIFIER:
			case NUMBER:
			case STRING:
			case LEFT_PARENTHESE:
			case LEFT_BRACKET:
				{
				setState(185);
				expression(0);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockExpressionContext extends ParserRuleContext {
		public TerminalNode LEFT_BRACE() { return getToken(WorkScriptParser.LEFT_BRACE, 0); }
		public TerminalNode RIGHT_BRACE() { return getToken(WorkScriptParser.RIGHT_BRACE, 0); }
		public List<TerminalNode> NEWLINE() { return getTokens(WorkScriptParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(WorkScriptParser.NEWLINE, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public BlockExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockExpression; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitBlockExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final BlockExpressionContext blockExpression() throws RecognitionException {
		BlockExpressionContext _localctx = new BlockExpressionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_blockExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(188);
			match(LEFT_BRACE);
			setState(192);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(189);
					match(NEWLINE);
					}
					} 
				}
				setState(194);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			}
			setState(207);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << WHEN) | (1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << LEFT_BRACKET))) != 0)) {
				{
				setState(203);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(195);
						expression(0);
						setState(197); 
						_errHandler.sync(this);
						_la = _input.LA(1);
						do {
							{
							{
							setState(196);
							match(NEWLINE);
							}
							}
							setState(199); 
							_errHandler.sync(this);
							_la = _input.LA(1);
						} while ( _la==NEWLINE );
						}
						} 
					}
					setState(205);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				}
				setState(206);
				expression(0);
				}
			}

			setState(212);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(209);
				match(NEWLINE);
				}
				}
				setState(214);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(215);
			match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierContext extends ParserRuleContext {
		public TerminalNode WHEN() { return getToken(WorkScriptParser.WHEN, 0); }
		public TerminalNode IDENTIFIER() { return getToken(WorkScriptParser.IDENTIFIER, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof WorkScriptVisitor ) return ((WorkScriptVisitor<? extends T>)visitor).visitIdentifier(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(217);
			_la = _input.LA(1);
			if ( !(_la==WHEN || _la==IDENTIFIER) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 11);
		case 5:
			return precpred(_ctx, 10);
		case 6:
			return precpred(_ctx, 9);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\31\u00de\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\3"+
		"\2\3\2\3\2\7\2\31\n\2\f\2\16\2\34\13\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\5\3(\n\3\3\3\7\3+\n\3\f\3\16\3.\13\3\5\3\60\n\3\3\3\3\3\3\3\3"+
		"\3\3\3\5\3\67\n\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\7\3T\n\3\f\3"+
		"\16\3W\13\3\3\4\3\4\5\4[\n\4\3\4\7\4^\n\4\f\4\16\4a\13\4\5\4c\n\4\3\5"+
		"\3\5\7\5g\n\5\f\5\16\5j\13\5\5\5l\n\5\3\5\3\5\7\5p\n\5\f\5\16\5s\13\5"+
		"\3\5\3\5\3\5\3\5\7\5y\n\5\f\5\16\5|\13\5\3\5\3\5\7\5\u0080\n\5\f\5\16"+
		"\5\u0083\13\5\3\5\3\5\3\5\3\5\7\5\u0089\n\5\f\5\16\5\u008c\13\5\3\5\3"+
		"\5\7\5\u0090\n\5\f\5\16\5\u0093\13\5\3\5\3\5\5\5\u0097\n\5\3\6\5\6\u009a"+
		"\n\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\7\7\u00a3\n\7\f\7\16\7\u00a6\13\7\3\7"+
		"\5\7\u00a9\n\7\3\7\7\7\u00ac\n\7\f\7\16\7\u00af\13\7\3\7\5\7\u00b2\n\7"+
		"\3\b\3\b\7\b\u00b6\n\b\f\b\16\b\u00b9\13\b\3\b\3\b\5\b\u00bd\n\b\3\t\3"+
		"\t\7\t\u00c1\n\t\f\t\16\t\u00c4\13\t\3\t\3\t\6\t\u00c8\n\t\r\t\16\t\u00c9"+
		"\7\t\u00cc\n\t\f\t\16\t\u00cf\13\t\3\t\5\t\u00d2\n\t\3\t\7\t\u00d5\n\t"+
		"\f\t\16\t\u00d8\13\t\3\t\3\t\3\n\3\n\3\n\2\3\4\13\2\4\6\b\n\f\16\20\22"+
		"\2\6\3\2\23\24\3\2\21\22\3\2\25\30\3\2\3\4\2\u00fd\2\32\3\2\2\2\4\66\3"+
		"\2\2\2\6b\3\2\2\2\b\u0096\3\2\2\2\n\u0099\3\2\2\2\f\u00b1\3\2\2\2\16\u00b3"+
		"\3\2\2\2\20\u00be\3\2\2\2\22\u00db\3\2\2\2\24\25\5\4\3\2\25\26\7\t\2\2"+
		"\26\31\3\2\2\2\27\31\7\t\2\2\30\24\3\2\2\2\30\27\3\2\2\2\31\34\3\2\2\2"+
		"\32\30\3\2\2\2\32\33\3\2\2\2\33\35\3\2\2\2\34\32\3\2\2\2\35\36\7\2\2\3"+
		"\36\3\3\2\2\2\37 \b\3\1\2 !\7\n\2\2!\"\5\4\3\2\"#\7\13\2\2#\67\3\2\2\2"+
		"$/\7\16\2\2%,\5\4\3\2&(\7\b\2\2\'&\3\2\2\2\'(\3\2\2\2()\3\2\2\2)+\5\4"+
		"\3\2*\'\3\2\2\2+.\3\2\2\2,*\3\2\2\2,-\3\2\2\2-\60\3\2\2\2.,\3\2\2\2/%"+
		"\3\2\2\2/\60\3\2\2\2\60\61\3\2\2\2\61\67\7\17\2\2\62\67\5\b\5\2\63\67"+
		"\7\5\2\2\64\67\7\6\2\2\65\67\5\22\n\2\66\37\3\2\2\2\66$\3\2\2\2\66\62"+
		"\3\2\2\2\66\63\3\2\2\2\66\64\3\2\2\2\66\65\3\2\2\2\67U\3\2\2\289\f\t\2"+
		"\29:\t\2\2\2:T\5\4\3\n;<\f\b\2\2<=\t\3\2\2=T\5\4\3\t>?\f\7\2\2?@\7\20"+
		"\2\2@T\5\4\3\bAB\f\6\2\2BC\t\4\2\2CT\5\4\3\7DE\f\r\2\2EF\7\n\2\2FG\5\6"+
		"\4\2GH\7\13\2\2HT\3\2\2\2IJ\f\f\2\2JK\7\7\2\2KL\5\22\n\2LM\7\n\2\2MN\5"+
		"\6\4\2NO\7\13\2\2OT\3\2\2\2PQ\f\13\2\2QR\7\7\2\2RT\5\22\n\2S8\3\2\2\2"+
		"S;\3\2\2\2S>\3\2\2\2SA\3\2\2\2SD\3\2\2\2SI\3\2\2\2SP\3\2\2\2TW\3\2\2\2"+
		"US\3\2\2\2UV\3\2\2\2V\5\3\2\2\2WU\3\2\2\2X_\5\4\3\2Y[\7\b\2\2ZY\3\2\2"+
		"\2Z[\3\2\2\2[\\\3\2\2\2\\^\5\4\3\2]Z\3\2\2\2^a\3\2\2\2_]\3\2\2\2_`\3\2"+
		"\2\2`c\3\2\2\2a_\3\2\2\2bX\3\2\2\2bc\3\2\2\2c\7\3\2\2\2dh\5\16\b\2eg\7"+
		"\t\2\2fe\3\2\2\2gj\3\2\2\2hf\3\2\2\2hi\3\2\2\2il\3\2\2\2jh\3\2\2\2kd\3"+
		"\2\2\2kl\3\2\2\2lm\3\2\2\2mq\5\n\6\2np\7\t\2\2on\3\2\2\2ps\3\2\2\2qo\3"+
		"\2\2\2qr\3\2\2\2rt\3\2\2\2sq\3\2\2\2tu\5\f\7\2u\u0097\3\2\2\2vz\5\n\6"+
		"\2wy\7\t\2\2xw\3\2\2\2y|\3\2\2\2zx\3\2\2\2z{\3\2\2\2{}\3\2\2\2|z\3\2\2"+
		"\2}\u0081\5\16\b\2~\u0080\7\t\2\2\177~\3\2\2\2\u0080\u0083\3\2\2\2\u0081"+
		"\177\3\2\2\2\u0081\u0082\3\2\2\2\u0082\u0084\3\2\2\2\u0083\u0081\3\2\2"+
		"\2\u0084\u0085\5\f\7\2\u0085\u0097\3\2\2\2\u0086\u008a\5\n\6\2\u0087\u0089"+
		"\7\t\2\2\u0088\u0087\3\2\2\2\u0089\u008c\3\2\2\2\u008a\u0088\3\2\2\2\u008a"+
		"\u008b\3\2\2\2\u008b\u008d\3\2\2\2\u008c\u008a\3\2\2\2\u008d\u0091\5\f"+
		"\7\2\u008e\u0090\7\t\2\2\u008f\u008e\3\2\2\2\u0090\u0093\3\2\2\2\u0091"+
		"\u008f\3\2\2\2\u0091\u0092\3\2\2\2\u0092\u0094\3\2\2\2\u0093\u0091\3\2"+
		"\2\2\u0094\u0095\5\16\b\2\u0095\u0097\3\2\2\2\u0096k\3\2\2\2\u0096v\3"+
		"\2\2\2\u0096\u0086\3\2\2\2\u0097\t\3\2\2\2\u0098\u009a\5\22\n\2\u0099"+
		"\u0098\3\2\2\2\u0099\u009a\3\2\2\2\u009a\u009b\3\2\2\2\u009b\u009c\7\n"+
		"\2\2\u009c\u009d\5\6\4\2\u009d\u009e\7\13\2\2\u009e\13\3\2\2\2\u009f\u00a0"+
		"\7\20\2\2\u00a0\u00b2\5\4\3\2\u00a1\u00a3\7\t\2\2\u00a2\u00a1\3\2\2\2"+
		"\u00a3\u00a6\3\2\2\2\u00a4\u00a2\3\2\2\2\u00a4\u00a5\3\2\2\2\u00a5\u00a8"+
		"\3\2\2\2\u00a6\u00a4\3\2\2\2\u00a7\u00a9\7\20\2\2\u00a8\u00a7\3\2\2\2"+
		"\u00a8\u00a9\3\2\2\2\u00a9\u00ad\3\2\2\2\u00aa\u00ac\7\t\2\2\u00ab\u00aa"+
		"\3\2\2\2\u00ac\u00af\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae"+
		"\u00b0\3\2\2\2\u00af\u00ad\3\2\2\2\u00b0\u00b2\5\20\t\2\u00b1\u009f\3"+
		"\2\2\2\u00b1\u00a4\3\2\2\2\u00b2\r\3\2\2\2\u00b3\u00b7\7\3\2\2\u00b4\u00b6"+
		"\7\t\2\2\u00b5\u00b4\3\2\2\2\u00b6\u00b9\3\2\2\2\u00b7\u00b5\3\2\2\2\u00b7"+
		"\u00b8\3\2\2\2\u00b8\u00bc\3\2\2\2\u00b9\u00b7\3\2\2\2\u00ba\u00bd\5\20"+
		"\t\2\u00bb\u00bd\5\4\3\2\u00bc\u00ba\3\2\2\2\u00bc\u00bb\3\2\2\2\u00bd"+
		"\17\3\2\2\2\u00be\u00c2\7\f\2\2\u00bf\u00c1\7\t\2\2\u00c0\u00bf\3\2\2"+
		"\2\u00c1\u00c4\3\2\2\2\u00c2\u00c0\3\2\2\2\u00c2\u00c3\3\2\2\2\u00c3\u00d1"+
		"\3\2\2\2\u00c4\u00c2\3\2\2\2\u00c5\u00c7\5\4\3\2\u00c6\u00c8\7\t\2\2\u00c7"+
		"\u00c6\3\2\2\2\u00c8\u00c9\3\2\2\2\u00c9\u00c7\3\2\2\2\u00c9\u00ca\3\2"+
		"\2\2\u00ca\u00cc\3\2\2\2\u00cb\u00c5\3\2\2\2\u00cc\u00cf\3\2\2\2\u00cd"+
		"\u00cb\3\2\2\2\u00cd\u00ce\3\2\2\2\u00ce\u00d0\3\2\2\2\u00cf\u00cd\3\2"+
		"\2\2\u00d0\u00d2\5\4\3\2\u00d1\u00cd\3\2\2\2\u00d1\u00d2\3\2\2\2\u00d2"+
		"\u00d6\3\2\2\2\u00d3\u00d5\7\t\2\2\u00d4\u00d3\3\2\2\2\u00d5\u00d8\3\2"+
		"\2\2\u00d6\u00d4\3\2\2\2\u00d6\u00d7\3\2\2\2\u00d7\u00d9\3\2\2\2\u00d8"+
		"\u00d6\3\2\2\2\u00d9\u00da\7\r\2\2\u00da\21\3\2\2\2\u00db\u00dc\t\5\2"+
		"\2\u00dc\23\3\2\2\2!\30\32\',/\66SUZ_bhkqz\u0081\u008a\u0091\u0096\u0099"+
		"\u00a4\u00a8\u00ad\u00b1\u00b7\u00bc\u00c2\u00c9\u00cd\u00d1\u00d6";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}