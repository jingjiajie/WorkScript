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
		ACCESS_LEVEL=1, INCLUDE=2, WHEN=3, BOOLEAN=4, IDENTIFIER=5, DOUBLE=6, 
		INTEGER=7, STRING=8, POINT=9, COMMA=10, LEFT_PARENTHESE=11, RIGHT_PARENTHESE=12, 
		LEFT_BRACE=13, RIGHT_BRACE=14, LEFT_BRACKET=15, RIGHT_BRACKET=16, DOUBLE_EQUAL=17, 
		EQUALS=18, RIGHT_ARROW=19, ASSIGN=20, COLON=21, PLUS=22, MINUS=23, MULTIPLY=24, 
		DIVIDE=25, MODULUS=26, HASH=27, GREATER_THAN=28, GREATER_THAN_EQUAL=29, 
		LESS_THAN=30, LESS_THAN_EQUAL=31, SINGLE_LINE_COMMENT=32, MULTILINE_COMMENT=33, 
		APOSTROPHE=34, NEWLINE=35, WS=36;
	public static final int
		RULE_program = 0, RULE_includeCommand = 1, RULE_expression = 2, RULE_callExpression = 3, 
		RULE_multiValueExpression = 4, RULE_numberExpression = 5, RULE_stringExpression = 6, 
		RULE_variableExpression = 7, RULE_functionExpression = 8, RULE_functionDeclarationExpression = 9, 
		RULE_typeName = 10, RULE_functionName = 11, RULE_formalParameterExpression = 12, 
		RULE_formalParameterItem = 13, RULE_functionImplementationExpression = 14, 
		RULE_functionConstraintExpression = 15, RULE_blockExpression = 16, RULE_booleanExpression = 17, 
		RULE_varargsExpression = 18, RULE_identifier = 19;
	public static final String[] ruleNames = {
		"program", "includeCommand", "expression", "callExpression", "multiValueExpression", 
		"numberExpression", "stringExpression", "variableExpression", "functionExpression", 
		"functionDeclarationExpression", "typeName", "functionName", "formalParameterExpression", 
		"formalParameterItem", "functionImplementationExpression", "functionConstraintExpression", 
		"blockExpression", "booleanExpression", "varargsExpression", "identifier"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, "'include'", "'when'", null, null, null, null, null, "'.'", 
		"','", "'('", "')'", "'{'", "'}'", "'['", "']'", "'=='", "'='", "'=>'", 
		"':='", "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'#'", "'>'", "'>='", 
		"'<'", "'<='", null, null, "'...'", "'\n'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "ACCESS_LEVEL", "INCLUDE", "WHEN", "BOOLEAN", "IDENTIFIER", "DOUBLE", 
		"INTEGER", "STRING", "POINT", "COMMA", "LEFT_PARENTHESE", "RIGHT_PARENTHESE", 
		"LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "DOUBLE_EQUAL", 
		"EQUALS", "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", "MULTIPLY", 
		"DIVIDE", "MODULUS", "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", 
		"LESS_THAN_EQUAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "APOSTROPHE", 
		"NEWLINE", "WS"
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
		public List<IncludeCommandContext> includeCommand() {
			return getRuleContexts(IncludeCommandContext.class);
		}
		public IncludeCommandContext includeCommand(int i) {
			return getRuleContext(IncludeCommandContext.class,i);
		}
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
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterProgram(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitProgram(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(47);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					setState(45);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case HASH:
						{
						setState(40);
						includeCommand();
						setState(42);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
						case 1:
							{
							setState(41);
							match(NEWLINE);
							}
							break;
						}
						}
						break;
					case NEWLINE:
						{
						setState(44);
						match(NEWLINE);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					} 
				}
				setState(49);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			setState(57);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS) | (1L << NEWLINE))) != 0)) {
				{
				setState(55);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case ACCESS_LEVEL:
				case INCLUDE:
				case WHEN:
				case BOOLEAN:
				case IDENTIFIER:
				case DOUBLE:
				case INTEGER:
				case STRING:
				case LEFT_PARENTHESE:
				case PLUS:
				case MINUS:
					{
					setState(50);
					expression(0);
					setState(52);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						setState(51);
						match(NEWLINE);
						}
						break;
					}
					}
					break;
				case NEWLINE:
					{
					setState(54);
					match(NEWLINE);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(59);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(60);
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

	public static class IncludeCommandContext extends ParserRuleContext {
		public TerminalNode HASH() { return getToken(WorkScriptParser.HASH, 0); }
		public TerminalNode INCLUDE() { return getToken(WorkScriptParser.INCLUDE, 0); }
		public TerminalNode STRING() { return getToken(WorkScriptParser.STRING, 0); }
		public IncludeCommandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_includeCommand; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterIncludeCommand(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitIncludeCommand(this);
		}
	}

	public final IncludeCommandContext includeCommand() throws RecognitionException {
		IncludeCommandContext _localctx = new IncludeCommandContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_includeCommand);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			match(HASH);
			setState(63);
			match(INCLUDE);
			setState(64);
			match(STRING);
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
	public static class AccessLevelExpressionContext extends ExpressionContext {
		public TerminalNode ACCESS_LEVEL() { return getToken(WorkScriptParser.ACCESS_LEVEL, 0); }
		public TerminalNode COLON() { return getToken(WorkScriptParser.COLON, 0); }
		public AccessLevelExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterAccessLevelExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitAccessLevelExpression(this);
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
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterParentheseExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitParentheseExpression(this);
		}
	}
	public static class CallExpression_Context extends ExpressionContext {
		public CallExpressionContext callExpression() {
			return getRuleContext(CallExpressionContext.class,0);
		}
		public CallExpression_Context(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterCallExpression_(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitCallExpression_(this);
		}
	}
	public static class StringExpression_Context extends ExpressionContext {
		public StringExpressionContext stringExpression() {
			return getRuleContext(StringExpressionContext.class,0);
		}
		public StringExpression_Context(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterStringExpression_(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitStringExpression_(this);
		}
	}
	public static class MultiplyDivideModulusExpressionContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode MULTIPLY() { return getToken(WorkScriptParser.MULTIPLY, 0); }
		public TerminalNode DIVIDE() { return getToken(WorkScriptParser.DIVIDE, 0); }
		public TerminalNode MODULUS() { return getToken(WorkScriptParser.MODULUS, 0); }
		public MultiplyDivideModulusExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterMultiplyDivideModulusExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitMultiplyDivideModulusExpression(this);
		}
	}
	public static class VariableExpression_Context extends ExpressionContext {
		public VariableExpressionContext variableExpression() {
			return getRuleContext(VariableExpressionContext.class,0);
		}
		public VariableExpression_Context(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterVariableExpression_(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitVariableExpression_(this);
		}
	}
	public static class BinaryCompareExpressionContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode DOUBLE_EQUAL() { return getToken(WorkScriptParser.DOUBLE_EQUAL, 0); }
		public TerminalNode GREATER_THAN() { return getToken(WorkScriptParser.GREATER_THAN, 0); }
		public TerminalNode GREATER_THAN_EQUAL() { return getToken(WorkScriptParser.GREATER_THAN_EQUAL, 0); }
		public TerminalNode LESS_THAN() { return getToken(WorkScriptParser.LESS_THAN, 0); }
		public TerminalNode LESS_THAN_EQUAL() { return getToken(WorkScriptParser.LESS_THAN_EQUAL, 0); }
		public BinaryCompareExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterBinaryCompareExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitBinaryCompareExpression(this);
		}
	}
	public static class BooleanExpression_Context extends ExpressionContext {
		public BooleanExpressionContext booleanExpression() {
			return getRuleContext(BooleanExpressionContext.class,0);
		}
		public BooleanExpression_Context(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterBooleanExpression_(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitBooleanExpression_(this);
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
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterAssignmentOrEqualsExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitAssignmentOrEqualsExpression(this);
		}
	}
	public static class NumberExpression_Context extends ExpressionContext {
		public NumberExpressionContext numberExpression() {
			return getRuleContext(NumberExpressionContext.class,0);
		}
		public NumberExpression_Context(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterNumberExpression_(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitNumberExpression_(this);
		}
	}
	public static class AssignmentExpressionContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode ASSIGN() { return getToken(WorkScriptParser.ASSIGN, 0); }
		public AssignmentExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterAssignmentExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitAssignmentExpression(this);
		}
	}
	public static class PositiveExpressionContext extends ExpressionContext {
		public TerminalNode PLUS() { return getToken(WorkScriptParser.PLUS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public PositiveExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterPositiveExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitPositiveExpression(this);
		}
	}
	public static class FunctionExpression_Context extends ExpressionContext {
		public FunctionExpressionContext functionExpression() {
			return getRuleContext(FunctionExpressionContext.class,0);
		}
		public FunctionExpression_Context(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterFunctionExpression_(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitFunctionExpression_(this);
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
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterPlusMinusExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitPlusMinusExpression(this);
		}
	}
	public static class NegativeExpressionContext extends ExpressionContext {
		public TerminalNode MINUS() { return getToken(WorkScriptParser.MINUS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public NegativeExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterNegativeExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitNegativeExpression(this);
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
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(83);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				_localctx = new AccessLevelExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(67);
				match(ACCESS_LEVEL);
				setState(68);
				match(COLON);
				}
				break;
			case 2:
				{
				_localctx = new ParentheseExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(69);
				match(LEFT_PARENTHESE);
				setState(70);
				expression(0);
				setState(71);
				match(RIGHT_PARENTHESE);
				}
				break;
			case 3:
				{
				_localctx = new FunctionExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(73);
				functionExpression();
				}
				break;
			case 4:
				{
				_localctx = new CallExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(74);
				callExpression();
				}
				break;
			case 5:
				{
				_localctx = new NumberExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(75);
				numberExpression();
				}
				break;
			case 6:
				{
				_localctx = new NegativeExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(76);
				match(MINUS);
				setState(77);
				expression(8);
				}
				break;
			case 7:
				{
				_localctx = new PositiveExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(78);
				match(PLUS);
				setState(79);
				expression(7);
				}
				break;
			case 8:
				{
				_localctx = new StringExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(80);
				stringExpression();
				}
				break;
			case 9:
				{
				_localctx = new BooleanExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(81);
				booleanExpression();
				}
				break;
			case 10:
				{
				_localctx = new VariableExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(82);
				variableExpression();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(102);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(100);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplyDivideModulusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(85);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(86);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << MULTIPLY) | (1L << DIVIDE) | (1L << MODULUS))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(87);
						expression(12);
						}
						break;
					case 2:
						{
						_localctx = new PlusMinusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(88);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(89);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(90);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new AssignmentExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(91);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(92);
						match(ASSIGN);
						setState(93);
						expression(7);
						}
						break;
					case 4:
						{
						_localctx = new AssignmentOrEqualsExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(94);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(95);
						match(EQUALS);
						setState(96);
						expression(6);
						}
						break;
					case 5:
						{
						_localctx = new BinaryCompareExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(97);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(98);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_EQUAL) | (1L << GREATER_THAN) | (1L << GREATER_THAN_EQUAL) | (1L << LESS_THAN) | (1L << LESS_THAN_EQUAL))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(99);
						expression(5);
						}
						break;
					}
					} 
				}
				setState(104);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
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

	public static class CallExpressionContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LEFT_PARENTHESE() { return getToken(WorkScriptParser.LEFT_PARENTHESE, 0); }
		public MultiValueExpressionContext multiValueExpression() {
			return getRuleContext(MultiValueExpressionContext.class,0);
		}
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public CallExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_callExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterCallExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitCallExpression(this);
		}
	}

	public final CallExpressionContext callExpression() throws RecognitionException {
		CallExpressionContext _localctx = new CallExpressionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_callExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(105);
			identifier();
			setState(106);
			match(LEFT_PARENTHESE);
			setState(107);
			multiValueExpression();
			setState(108);
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

	public static class MultiValueExpressionContext extends ParserRuleContext {
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
		public List<TerminalNode> COMMA() { return getTokens(WorkScriptParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(WorkScriptParser.COMMA, i);
		}
		public MultiValueExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiValueExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterMultiValueExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitMultiValueExpression(this);
		}
	}

	public final MultiValueExpressionContext multiValueExpression() throws RecognitionException {
		MultiValueExpressionContext _localctx = new MultiValueExpressionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_multiValueExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(136);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(113);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(110);
					match(NEWLINE);
					}
					}
					setState(115);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(116);
				expression(0);
				setState(133);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(120);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(117);
								match(NEWLINE);
								}
								} 
							}
							setState(122);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
						}
						setState(123);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(127);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(124);
							match(NEWLINE);
							}
							}
							setState(129);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(130);
						expression(0);
						}
						} 
					}
					setState(135);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				}
				}
				break;
			}
			setState(141);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(138);
					match(NEWLINE);
					}
					} 
				}
				setState(143);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			setState(145);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(144);
				match(COMMA);
				}
			}

			setState(150);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(147);
				match(NEWLINE);
				}
				}
				setState(152);
				_errHandler.sync(this);
				_la = _input.LA(1);
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

	public static class NumberExpressionContext extends ParserRuleContext {
		public TerminalNode DOUBLE() { return getToken(WorkScriptParser.DOUBLE, 0); }
		public TerminalNode INTEGER() { return getToken(WorkScriptParser.INTEGER, 0); }
		public TerminalNode PLUS() { return getToken(WorkScriptParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(WorkScriptParser.MINUS, 0); }
		public NumberExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numberExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterNumberExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitNumberExpression(this);
		}
	}

	public final NumberExpressionContext numberExpression() throws RecognitionException {
		NumberExpressionContext _localctx = new NumberExpressionContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_numberExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(154);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PLUS || _la==MINUS) {
				{
				setState(153);
				_la = _input.LA(1);
				if ( !(_la==PLUS || _la==MINUS) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(156);
			_la = _input.LA(1);
			if ( !(_la==DOUBLE || _la==INTEGER) ) {
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

	public static class StringExpressionContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(WorkScriptParser.STRING, 0); }
		public StringExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterStringExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitStringExpression(this);
		}
	}

	public final StringExpressionContext stringExpression() throws RecognitionException {
		StringExpressionContext _localctx = new StringExpressionContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_stringExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(158);
			match(STRING);
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

	public static class VariableExpressionContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public VariableExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterVariableExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitVariableExpression(this);
		}
	}

	public final VariableExpressionContext variableExpression() throws RecognitionException {
		VariableExpressionContext _localctx = new VariableExpressionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_variableExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(160);
			identifier();
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
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterFunctionExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitFunctionExpression(this);
		}
	}

	public final FunctionExpressionContext functionExpression() throws RecognitionException {
		FunctionExpressionContext _localctx = new FunctionExpressionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_functionExpression);
		int _la;
		try {
			int _alt;
			setState(212);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(169);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(162);
					functionConstraintExpression();
					setState(166);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==NEWLINE) {
						{
						{
						setState(163);
						match(NEWLINE);
						}
						}
						setState(168);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				}
				setState(171);
				functionDeclarationExpression();
				setState(175);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(172);
						match(NEWLINE);
						}
						} 
					}
					setState(177);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
				}
				setState(178);
				functionImplementationExpression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(180);
				functionDeclarationExpression();
				setState(184);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(181);
					match(NEWLINE);
					}
					}
					setState(186);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(187);
				functionConstraintExpression();
				setState(191);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(188);
						match(NEWLINE);
						}
						} 
					}
					setState(193);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
				}
				setState(194);
				functionImplementationExpression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(196);
				functionDeclarationExpression();
				setState(200);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(197);
						match(NEWLINE);
						}
						} 
					}
					setState(202);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
				}
				setState(203);
				functionImplementationExpression();
				setState(207);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(204);
					match(NEWLINE);
					}
					}
					setState(209);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(210);
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
		public FormalParameterExpressionContext formalParameterExpression() {
			return getRuleContext(FormalParameterExpressionContext.class,0);
		}
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public FunctionNameContext functionName() {
			return getRuleContext(FunctionNameContext.class,0);
		}
		public FunctionDeclarationExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDeclarationExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterFunctionDeclarationExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitFunctionDeclarationExpression(this);
		}
	}

	public final FunctionDeclarationExpressionContext functionDeclarationExpression() throws RecognitionException {
		FunctionDeclarationExpressionContext _localctx = new FunctionDeclarationExpressionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_functionDeclarationExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
			case 1:
				{
				setState(215);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
					{
					setState(214);
					functionName();
					}
				}

				}
				break;
			case 2:
				{
				setState(217);
				typeName();
				setState(218);
				functionName();
				}
				break;
			}
			setState(222);
			match(LEFT_PARENTHESE);
			setState(223);
			formalParameterExpression();
			setState(224);
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

	public static class TypeNameContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TypeNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeName; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterTypeName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitTypeName(this);
		}
	}

	public final TypeNameContext typeName() throws RecognitionException {
		TypeNameContext _localctx = new TypeNameContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_typeName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(226);
			identifier();
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

	public static class FunctionNameContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public FunctionNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionName; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterFunctionName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitFunctionName(this);
		}
	}

	public final FunctionNameContext functionName() throws RecognitionException {
		FunctionNameContext _localctx = new FunctionNameContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_functionName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(228);
			identifier();
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

	public static class FormalParameterExpressionContext extends ParserRuleContext {
		public List<FormalParameterItemContext> formalParameterItem() {
			return getRuleContexts(FormalParameterItemContext.class);
		}
		public FormalParameterItemContext formalParameterItem(int i) {
			return getRuleContext(FormalParameterItemContext.class,i);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(WorkScriptParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(WorkScriptParser.NEWLINE, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(WorkScriptParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(WorkScriptParser.COMMA, i);
		}
		public FormalParameterExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameterExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterFormalParameterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitFormalParameterExpression(this);
		}
	}

	public final FormalParameterExpressionContext formalParameterExpression() throws RecognitionException {
		FormalParameterExpressionContext _localctx = new FormalParameterExpressionContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_formalParameterExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(256);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
			case 1:
				{
				setState(233);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(230);
					match(NEWLINE);
					}
					}
					setState(235);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(236);
				formalParameterItem();
				setState(253);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(240);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(237);
								match(NEWLINE);
								}
								} 
							}
							setState(242);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
						}
						setState(243);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(247);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(244);
							match(NEWLINE);
							}
							}
							setState(249);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(250);
						formalParameterItem();
						}
						} 
					}
					setState(255);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
				}
				}
				break;
			}
			setState(261);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(258);
					match(NEWLINE);
					}
					} 
				}
				setState(263);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
			}
			setState(265);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(264);
				match(COMMA);
				}
			}

			setState(270);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(267);
				match(NEWLINE);
				}
				}
				setState(272);
				_errHandler.sync(this);
				_la = _input.LA(1);
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

	public static class FormalParameterItemContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public FormalParameterItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameterItem; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterFormalParameterItem(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitFormalParameterItem(this);
		}
	}

	public final FormalParameterItemContext formalParameterItem() throws RecognitionException {
		FormalParameterItemContext _localctx = new FormalParameterItemContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_formalParameterItem);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(274);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,36,_ctx) ) {
			case 1:
				{
				setState(273);
				typeName();
				}
				break;
			}
			setState(276);
			expression(0);
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
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode EQUALS() { return getToken(WorkScriptParser.EQUALS, 0); }
		public TerminalNode RIGHT_ARROW() { return getToken(WorkScriptParser.RIGHT_ARROW, 0); }
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
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterFunctionImplementationExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitFunctionImplementationExpression(this);
		}
	}

	public final FunctionImplementationExpressionContext functionImplementationExpression() throws RecognitionException {
		FunctionImplementationExpressionContext _localctx = new FunctionImplementationExpressionContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_functionImplementationExpression);
		int _la;
		try {
			int _alt;
			setState(296);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,40,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(278);
				_la = _input.LA(1);
				if ( !(_la==EQUALS || _la==RIGHT_ARROW) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(279);
				expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(283);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(280);
						match(NEWLINE);
						}
						} 
					}
					setState(285);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
				}
				setState(287);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==EQUALS || _la==RIGHT_ARROW) {
					{
					setState(286);
					_la = _input.LA(1);
					if ( !(_la==EQUALS || _la==RIGHT_ARROW) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				setState(292);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(289);
					match(NEWLINE);
					}
					}
					setState(294);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(295);
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
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterFunctionConstraintExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitFunctionConstraintExpression(this);
		}
	}

	public final FunctionConstraintExpressionContext functionConstraintExpression() throws RecognitionException {
		FunctionConstraintExpressionContext _localctx = new FunctionConstraintExpressionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_functionConstraintExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(298);
			match(WHEN);
			setState(302);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(299);
				match(NEWLINE);
				}
				}
				setState(304);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(307);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LEFT_BRACE:
				{
				setState(305);
				blockExpression();
				}
				break;
			case ACCESS_LEVEL:
			case INCLUDE:
			case WHEN:
			case BOOLEAN:
			case IDENTIFIER:
			case DOUBLE:
			case INTEGER:
			case STRING:
			case LEFT_PARENTHESE:
			case PLUS:
			case MINUS:
				{
				setState(306);
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
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterBlockExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitBlockExpression(this);
		}
	}

	public final BlockExpressionContext blockExpression() throws RecognitionException {
		BlockExpressionContext _localctx = new BlockExpressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_blockExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(309);
			match(LEFT_BRACE);
			setState(313);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,43,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(310);
					match(NEWLINE);
					}
					} 
				}
				setState(315);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,43,_ctx);
			}
			setState(328);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS))) != 0)) {
				{
				setState(324);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(316);
						expression(0);
						setState(318); 
						_errHandler.sync(this);
						_la = _input.LA(1);
						do {
							{
							{
							setState(317);
							match(NEWLINE);
							}
							}
							setState(320); 
							_errHandler.sync(this);
							_la = _input.LA(1);
						} while ( _la==NEWLINE );
						}
						} 
					}
					setState(326);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
				}
				setState(327);
				expression(0);
				}
			}

			setState(333);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(330);
				match(NEWLINE);
				}
				}
				setState(335);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(336);
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

	public static class BooleanExpressionContext extends ParserRuleContext {
		public TerminalNode BOOLEAN() { return getToken(WorkScriptParser.BOOLEAN, 0); }
		public BooleanExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterBooleanExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitBooleanExpression(this);
		}
	}

	public final BooleanExpressionContext booleanExpression() throws RecognitionException {
		BooleanExpressionContext _localctx = new BooleanExpressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_booleanExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(338);
			match(BOOLEAN);
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

	public static class VarargsExpressionContext extends ParserRuleContext {
		public TerminalNode APOSTROPHE() { return getToken(WorkScriptParser.APOSTROPHE, 0); }
		public VariableExpressionContext variableExpression() {
			return getRuleContext(VariableExpressionContext.class,0);
		}
		public VarargsExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varargsExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterVarargsExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitVarargsExpression(this);
		}
	}

	public final VarargsExpressionContext varargsExpression() throws RecognitionException {
		VarargsExpressionContext _localctx = new VarargsExpressionContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_varargsExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(340);
			match(APOSTROPHE);
			setState(341);
			variableExpression();
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
		public TerminalNode BOOLEAN() { return getToken(WorkScriptParser.BOOLEAN, 0); }
		public TerminalNode WHEN() { return getToken(WorkScriptParser.WHEN, 0); }
		public TerminalNode INCLUDE() { return getToken(WorkScriptParser.INCLUDE, 0); }
		public TerminalNode ACCESS_LEVEL() { return getToken(WorkScriptParser.ACCESS_LEVEL, 0); }
		public TerminalNode IDENTIFIER() { return getToken(WorkScriptParser.IDENTIFIER, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterIdentifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitIdentifier(this);
		}
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(343);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) ) {
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
		case 2:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 11);
		case 1:
			return precpred(_ctx, 10);
		case 2:
			return precpred(_ctx, 6);
		case 3:
			return precpred(_ctx, 5);
		case 4:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3&\u015c\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\3\2\3\2\5\2-\n\2\3\2\7\2\60\n\2\f\2\16"+
		"\2\63\13\2\3\2\3\2\5\2\67\n\2\3\2\7\2:\n\2\f\2\16\2=\13\2\3\2\3\2\3\3"+
		"\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\5\4V\n\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\7\4g\n\4\f\4\16\4j\13\4\3\5\3\5\3\5\3\5\3\5\3\6\7\6r\n\6\f"+
		"\6\16\6u\13\6\3\6\3\6\7\6y\n\6\f\6\16\6|\13\6\3\6\3\6\7\6\u0080\n\6\f"+
		"\6\16\6\u0083\13\6\3\6\7\6\u0086\n\6\f\6\16\6\u0089\13\6\5\6\u008b\n\6"+
		"\3\6\7\6\u008e\n\6\f\6\16\6\u0091\13\6\3\6\5\6\u0094\n\6\3\6\7\6\u0097"+
		"\n\6\f\6\16\6\u009a\13\6\3\7\5\7\u009d\n\7\3\7\3\7\3\b\3\b\3\t\3\t\3\n"+
		"\3\n\7\n\u00a7\n\n\f\n\16\n\u00aa\13\n\5\n\u00ac\n\n\3\n\3\n\7\n\u00b0"+
		"\n\n\f\n\16\n\u00b3\13\n\3\n\3\n\3\n\3\n\7\n\u00b9\n\n\f\n\16\n\u00bc"+
		"\13\n\3\n\3\n\7\n\u00c0\n\n\f\n\16\n\u00c3\13\n\3\n\3\n\3\n\3\n\7\n\u00c9"+
		"\n\n\f\n\16\n\u00cc\13\n\3\n\3\n\7\n\u00d0\n\n\f\n\16\n\u00d3\13\n\3\n"+
		"\3\n\5\n\u00d7\n\n\3\13\5\13\u00da\n\13\3\13\3\13\3\13\5\13\u00df\n\13"+
		"\3\13\3\13\3\13\3\13\3\f\3\f\3\r\3\r\3\16\7\16\u00ea\n\16\f\16\16\16\u00ed"+
		"\13\16\3\16\3\16\7\16\u00f1\n\16\f\16\16\16\u00f4\13\16\3\16\3\16\7\16"+
		"\u00f8\n\16\f\16\16\16\u00fb\13\16\3\16\7\16\u00fe\n\16\f\16\16\16\u0101"+
		"\13\16\5\16\u0103\n\16\3\16\7\16\u0106\n\16\f\16\16\16\u0109\13\16\3\16"+
		"\5\16\u010c\n\16\3\16\7\16\u010f\n\16\f\16\16\16\u0112\13\16\3\17\5\17"+
		"\u0115\n\17\3\17\3\17\3\20\3\20\3\20\7\20\u011c\n\20\f\20\16\20\u011f"+
		"\13\20\3\20\5\20\u0122\n\20\3\20\7\20\u0125\n\20\f\20\16\20\u0128\13\20"+
		"\3\20\5\20\u012b\n\20\3\21\3\21\7\21\u012f\n\21\f\21\16\21\u0132\13\21"+
		"\3\21\3\21\5\21\u0136\n\21\3\22\3\22\7\22\u013a\n\22\f\22\16\22\u013d"+
		"\13\22\3\22\3\22\6\22\u0141\n\22\r\22\16\22\u0142\7\22\u0145\n\22\f\22"+
		"\16\22\u0148\13\22\3\22\5\22\u014b\n\22\3\22\7\22\u014e\n\22\f\22\16\22"+
		"\u0151\13\22\3\22\3\22\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3\25\2\3\6\26"+
		"\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&(\2\t\3\2\32\34\3\2\30\31"+
		"\4\2\23\23\36!\4\2\f\f%%\3\2\b\t\3\2\24\25\3\2\3\7\2\u0183\2\61\3\2\2"+
		"\2\4@\3\2\2\2\6U\3\2\2\2\bk\3\2\2\2\n\u008a\3\2\2\2\f\u009c\3\2\2\2\16"+
		"\u00a0\3\2\2\2\20\u00a2\3\2\2\2\22\u00d6\3\2\2\2\24\u00de\3\2\2\2\26\u00e4"+
		"\3\2\2\2\30\u00e6\3\2\2\2\32\u0102\3\2\2\2\34\u0114\3\2\2\2\36\u012a\3"+
		"\2\2\2 \u012c\3\2\2\2\"\u0137\3\2\2\2$\u0154\3\2\2\2&\u0156\3\2\2\2(\u0159"+
		"\3\2\2\2*,\5\4\3\2+-\7%\2\2,+\3\2\2\2,-\3\2\2\2-\60\3\2\2\2.\60\7%\2\2"+
		"/*\3\2\2\2/.\3\2\2\2\60\63\3\2\2\2\61/\3\2\2\2\61\62\3\2\2\2\62;\3\2\2"+
		"\2\63\61\3\2\2\2\64\66\5\6\4\2\65\67\7%\2\2\66\65\3\2\2\2\66\67\3\2\2"+
		"\2\67:\3\2\2\28:\7%\2\29\64\3\2\2\298\3\2\2\2:=\3\2\2\2;9\3\2\2\2;<\3"+
		"\2\2\2<>\3\2\2\2=;\3\2\2\2>?\7\2\2\3?\3\3\2\2\2@A\7\35\2\2AB\7\4\2\2B"+
		"C\7\n\2\2C\5\3\2\2\2DE\b\4\1\2EF\7\3\2\2FV\7\27\2\2GH\7\r\2\2HI\5\6\4"+
		"\2IJ\7\16\2\2JV\3\2\2\2KV\5\22\n\2LV\5\b\5\2MV\5\f\7\2NO\7\31\2\2OV\5"+
		"\6\4\nPQ\7\30\2\2QV\5\6\4\tRV\5\16\b\2SV\5$\23\2TV\5\20\t\2UD\3\2\2\2"+
		"UG\3\2\2\2UK\3\2\2\2UL\3\2\2\2UM\3\2\2\2UN\3\2\2\2UP\3\2\2\2UR\3\2\2\2"+
		"US\3\2\2\2UT\3\2\2\2Vh\3\2\2\2WX\f\r\2\2XY\t\2\2\2Yg\5\6\4\16Z[\f\f\2"+
		"\2[\\\t\3\2\2\\g\5\6\4\r]^\f\b\2\2^_\7\26\2\2_g\5\6\4\t`a\f\7\2\2ab\7"+
		"\24\2\2bg\5\6\4\bcd\f\6\2\2de\t\4\2\2eg\5\6\4\7fW\3\2\2\2fZ\3\2\2\2f]"+
		"\3\2\2\2f`\3\2\2\2fc\3\2\2\2gj\3\2\2\2hf\3\2\2\2hi\3\2\2\2i\7\3\2\2\2"+
		"jh\3\2\2\2kl\5(\25\2lm\7\r\2\2mn\5\n\6\2no\7\16\2\2o\t\3\2\2\2pr\7%\2"+
		"\2qp\3\2\2\2ru\3\2\2\2sq\3\2\2\2st\3\2\2\2tv\3\2\2\2us\3\2\2\2v\u0087"+
		"\5\6\4\2wy\7%\2\2xw\3\2\2\2y|\3\2\2\2zx\3\2\2\2z{\3\2\2\2{}\3\2\2\2|z"+
		"\3\2\2\2}\u0081\t\5\2\2~\u0080\7%\2\2\177~\3\2\2\2\u0080\u0083\3\2\2\2"+
		"\u0081\177\3\2\2\2\u0081\u0082\3\2\2\2\u0082\u0084\3\2\2\2\u0083\u0081"+
		"\3\2\2\2\u0084\u0086\5\6\4\2\u0085z\3\2\2\2\u0086\u0089\3\2\2\2\u0087"+
		"\u0085\3\2\2\2\u0087\u0088\3\2\2\2\u0088\u008b\3\2\2\2\u0089\u0087\3\2"+
		"\2\2\u008as\3\2\2\2\u008a\u008b\3\2\2\2\u008b\u008f\3\2\2\2\u008c\u008e"+
		"\7%\2\2\u008d\u008c\3\2\2\2\u008e\u0091\3\2\2\2\u008f\u008d\3\2\2\2\u008f"+
		"\u0090\3\2\2\2\u0090\u0093\3\2\2\2\u0091\u008f\3\2\2\2\u0092\u0094\7\f"+
		"\2\2\u0093\u0092\3\2\2\2\u0093\u0094\3\2\2\2\u0094\u0098\3\2\2\2\u0095"+
		"\u0097\7%\2\2\u0096\u0095\3\2\2\2\u0097\u009a\3\2\2\2\u0098\u0096\3\2"+
		"\2\2\u0098\u0099\3\2\2\2\u0099\13\3\2\2\2\u009a\u0098\3\2\2\2\u009b\u009d"+
		"\t\3\2\2\u009c\u009b\3\2\2\2\u009c\u009d\3\2\2\2\u009d\u009e\3\2\2\2\u009e"+
		"\u009f\t\6\2\2\u009f\r\3\2\2\2\u00a0\u00a1\7\n\2\2\u00a1\17\3\2\2\2\u00a2"+
		"\u00a3\5(\25\2\u00a3\21\3\2\2\2\u00a4\u00a8\5 \21\2\u00a5\u00a7\7%\2\2"+
		"\u00a6\u00a5\3\2\2\2\u00a7\u00aa\3\2\2\2\u00a8\u00a6\3\2\2\2\u00a8\u00a9"+
		"\3\2\2\2\u00a9\u00ac\3\2\2\2\u00aa\u00a8\3\2\2\2\u00ab\u00a4\3\2\2\2\u00ab"+
		"\u00ac\3\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00b1\5\24\13\2\u00ae\u00b0\7"+
		"%\2\2\u00af\u00ae\3\2\2\2\u00b0\u00b3\3\2\2\2\u00b1\u00af\3\2\2\2\u00b1"+
		"\u00b2\3\2\2\2\u00b2\u00b4\3\2\2\2\u00b3\u00b1\3\2\2\2\u00b4\u00b5\5\36"+
		"\20\2\u00b5\u00d7\3\2\2\2\u00b6\u00ba\5\24\13\2\u00b7\u00b9\7%\2\2\u00b8"+
		"\u00b7\3\2\2\2\u00b9\u00bc\3\2\2\2\u00ba\u00b8\3\2\2\2\u00ba\u00bb\3\2"+
		"\2\2\u00bb\u00bd\3\2\2\2\u00bc\u00ba\3\2\2\2\u00bd\u00c1\5 \21\2\u00be"+
		"\u00c0\7%\2\2\u00bf\u00be\3\2\2\2\u00c0\u00c3\3\2\2\2\u00c1\u00bf\3\2"+
		"\2\2\u00c1\u00c2\3\2\2\2\u00c2\u00c4\3\2\2\2\u00c3\u00c1\3\2\2\2\u00c4"+
		"\u00c5\5\36\20\2\u00c5\u00d7\3\2\2\2\u00c6\u00ca\5\24\13\2\u00c7\u00c9"+
		"\7%\2\2\u00c8\u00c7\3\2\2\2\u00c9\u00cc\3\2\2\2\u00ca\u00c8\3\2\2\2\u00ca"+
		"\u00cb\3\2\2\2\u00cb\u00cd\3\2\2\2\u00cc\u00ca\3\2\2\2\u00cd\u00d1\5\36"+
		"\20\2\u00ce\u00d0\7%\2\2\u00cf\u00ce\3\2\2\2\u00d0\u00d3\3\2\2\2\u00d1"+
		"\u00cf\3\2\2\2\u00d1\u00d2\3\2\2\2\u00d2\u00d4\3\2\2\2\u00d3\u00d1\3\2"+
		"\2\2\u00d4\u00d5\5 \21\2\u00d5\u00d7\3\2\2\2\u00d6\u00ab\3\2\2\2\u00d6"+
		"\u00b6\3\2\2\2\u00d6\u00c6\3\2\2\2\u00d7\23\3\2\2\2\u00d8\u00da\5\30\r"+
		"\2\u00d9\u00d8\3\2\2\2\u00d9\u00da\3\2\2\2\u00da\u00df\3\2\2\2\u00db\u00dc"+
		"\5\26\f\2\u00dc\u00dd\5\30\r\2\u00dd\u00df\3\2\2\2\u00de\u00d9\3\2\2\2"+
		"\u00de\u00db\3\2\2\2\u00df\u00e0\3\2\2\2\u00e0\u00e1\7\r\2\2\u00e1\u00e2"+
		"\5\32\16\2\u00e2\u00e3\7\16\2\2\u00e3\25\3\2\2\2\u00e4\u00e5\5(\25\2\u00e5"+
		"\27\3\2\2\2\u00e6\u00e7\5(\25\2\u00e7\31\3\2\2\2\u00e8\u00ea\7%\2\2\u00e9"+
		"\u00e8\3\2\2\2\u00ea\u00ed\3\2\2\2\u00eb\u00e9\3\2\2\2\u00eb\u00ec\3\2"+
		"\2\2\u00ec\u00ee\3\2\2\2\u00ed\u00eb\3\2\2\2\u00ee\u00ff\5\34\17\2\u00ef"+
		"\u00f1\7%\2\2\u00f0\u00ef\3\2\2\2\u00f1\u00f4\3\2\2\2\u00f2\u00f0\3\2"+
		"\2\2\u00f2\u00f3\3\2\2\2\u00f3\u00f5\3\2\2\2\u00f4\u00f2\3\2\2\2\u00f5"+
		"\u00f9\t\5\2\2\u00f6\u00f8\7%\2\2\u00f7\u00f6\3\2\2\2\u00f8\u00fb\3\2"+
		"\2\2\u00f9\u00f7\3\2\2\2\u00f9\u00fa\3\2\2\2\u00fa\u00fc\3\2\2\2\u00fb"+
		"\u00f9\3\2\2\2\u00fc\u00fe\5\34\17\2\u00fd\u00f2\3\2\2\2\u00fe\u0101\3"+
		"\2\2\2\u00ff\u00fd\3\2\2\2\u00ff\u0100\3\2\2\2\u0100\u0103\3\2\2\2\u0101"+
		"\u00ff\3\2\2\2\u0102\u00eb\3\2\2\2\u0102\u0103\3\2\2\2\u0103\u0107\3\2"+
		"\2\2\u0104\u0106\7%\2\2\u0105\u0104\3\2\2\2\u0106\u0109\3\2\2\2\u0107"+
		"\u0105\3\2\2\2\u0107\u0108\3\2\2\2\u0108\u010b\3\2\2\2\u0109\u0107\3\2"+
		"\2\2\u010a\u010c\7\f\2\2\u010b\u010a\3\2\2\2\u010b\u010c\3\2\2\2\u010c"+
		"\u0110\3\2\2\2\u010d\u010f\7%\2\2\u010e\u010d\3\2\2\2\u010f\u0112\3\2"+
		"\2\2\u0110\u010e\3\2\2\2\u0110\u0111\3\2\2\2\u0111\33\3\2\2\2\u0112\u0110"+
		"\3\2\2\2\u0113\u0115\5\26\f\2\u0114\u0113\3\2\2\2\u0114\u0115\3\2\2\2"+
		"\u0115\u0116\3\2\2\2\u0116\u0117\5\6\4\2\u0117\35\3\2\2\2\u0118\u0119"+
		"\t\7\2\2\u0119\u012b\5\6\4\2\u011a\u011c\7%\2\2\u011b\u011a\3\2\2\2\u011c"+
		"\u011f\3\2\2\2\u011d\u011b\3\2\2\2\u011d\u011e\3\2\2\2\u011e\u0121\3\2"+
		"\2\2\u011f\u011d\3\2\2\2\u0120\u0122\t\7\2\2\u0121\u0120\3\2\2\2\u0121"+
		"\u0122\3\2\2\2\u0122\u0126\3\2\2\2\u0123\u0125\7%\2\2\u0124\u0123\3\2"+
		"\2\2\u0125\u0128\3\2\2\2\u0126\u0124\3\2\2\2\u0126\u0127\3\2\2\2\u0127"+
		"\u0129\3\2\2\2\u0128\u0126\3\2\2\2\u0129\u012b\5\"\22\2\u012a\u0118\3"+
		"\2\2\2\u012a\u011d\3\2\2\2\u012b\37\3\2\2\2\u012c\u0130\7\5\2\2\u012d"+
		"\u012f\7%\2\2\u012e\u012d\3\2\2\2\u012f\u0132\3\2\2\2\u0130\u012e\3\2"+
		"\2\2\u0130\u0131\3\2\2\2\u0131\u0135\3\2\2\2\u0132\u0130\3\2\2\2\u0133"+
		"\u0136\5\"\22\2\u0134\u0136\5\6\4\2\u0135\u0133\3\2\2\2\u0135\u0134\3"+
		"\2\2\2\u0136!\3\2\2\2\u0137\u013b\7\17\2\2\u0138\u013a\7%\2\2\u0139\u0138"+
		"\3\2\2\2\u013a\u013d\3\2\2\2\u013b\u0139\3\2\2\2\u013b\u013c\3\2\2\2\u013c"+
		"\u014a\3\2\2\2\u013d\u013b\3\2\2\2\u013e\u0140\5\6\4\2\u013f\u0141\7%"+
		"\2\2\u0140\u013f\3\2\2\2\u0141\u0142\3\2\2\2\u0142\u0140\3\2\2\2\u0142"+
		"\u0143\3\2\2\2\u0143\u0145\3\2\2\2\u0144\u013e\3\2\2\2\u0145\u0148\3\2"+
		"\2\2\u0146\u0144\3\2\2\2\u0146\u0147\3\2\2\2\u0147\u0149\3\2\2\2\u0148"+
		"\u0146\3\2\2\2\u0149\u014b\5\6\4\2\u014a\u0146\3\2\2\2\u014a\u014b\3\2"+
		"\2\2\u014b\u014f\3\2\2\2\u014c\u014e\7%\2\2\u014d\u014c\3\2\2\2\u014e"+
		"\u0151\3\2\2\2\u014f\u014d\3\2\2\2\u014f\u0150\3\2\2\2\u0150\u0152\3\2"+
		"\2\2\u0151\u014f\3\2\2\2\u0152\u0153\7\20\2\2\u0153#\3\2\2\2\u0154\u0155"+
		"\7\6\2\2\u0155%\3\2\2\2\u0156\u0157\7$\2\2\u0157\u0158\5\20\t\2\u0158"+
		"\'\3\2\2\2\u0159\u015a\t\b\2\2\u015a)\3\2\2\2\62,/\61\669;Ufhsz\u0081"+
		"\u0087\u008a\u008f\u0093\u0098\u009c\u00a8\u00ab\u00b1\u00ba\u00c1\u00ca"+
		"\u00d1\u00d6\u00d9\u00de\u00eb\u00f2\u00f9\u00ff\u0102\u0107\u010b\u0110"+
		"\u0114\u011d\u0121\u0126\u012a\u0130\u0135\u013b\u0142\u0146\u014a\u014f";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}