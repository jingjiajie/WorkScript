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
		RULE_formalParameterExpression = 10, RULE_functionImplementationExpression = 11, 
		RULE_functionConstraintExpression = 12, RULE_blockExpression = 13, RULE_booleanExpression = 14, 
		RULE_varargsExpression = 15, RULE_identifier = 16;
	public static final String[] ruleNames = {
		"program", "includeCommand", "expression", "callExpression", "multiValueExpression", 
		"numberExpression", "stringExpression", "variableExpression", "functionExpression", 
		"functionDeclarationExpression", "formalParameterExpression", "functionImplementationExpression", 
		"functionConstraintExpression", "blockExpression", "booleanExpression", 
		"varargsExpression", "identifier"
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
			setState(41);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					setState(39);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case HASH:
						{
						setState(34);
						includeCommand();
						setState(36);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
						case 1:
							{
							setState(35);
							match(NEWLINE);
							}
							break;
						}
						}
						break;
					case NEWLINE:
						{
						setState(38);
						match(NEWLINE);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					} 
				}
				setState(43);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			setState(51);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS) | (1L << NEWLINE))) != 0)) {
				{
				setState(49);
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
					setState(44);
					expression(0);
					setState(46);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						setState(45);
						match(NEWLINE);
						}
						break;
					}
					}
					break;
				case NEWLINE:
					{
					setState(48);
					match(NEWLINE);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(53);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(54);
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
			setState(56);
			match(HASH);
			setState(57);
			match(INCLUDE);
			setState(58);
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
			setState(77);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				_localctx = new AccessLevelExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(61);
				match(ACCESS_LEVEL);
				setState(62);
				match(COLON);
				}
				break;
			case 2:
				{
				_localctx = new ParentheseExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(63);
				match(LEFT_PARENTHESE);
				setState(64);
				expression(0);
				setState(65);
				match(RIGHT_PARENTHESE);
				}
				break;
			case 3:
				{
				_localctx = new FunctionExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(67);
				functionExpression();
				}
				break;
			case 4:
				{
				_localctx = new CallExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(68);
				callExpression();
				}
				break;
			case 5:
				{
				_localctx = new NumberExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(69);
				numberExpression();
				}
				break;
			case 6:
				{
				_localctx = new NegativeExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(70);
				match(MINUS);
				setState(71);
				expression(8);
				}
				break;
			case 7:
				{
				_localctx = new PositiveExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(72);
				match(PLUS);
				setState(73);
				expression(7);
				}
				break;
			case 8:
				{
				_localctx = new StringExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(74);
				stringExpression();
				}
				break;
			case 9:
				{
				_localctx = new BooleanExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(75);
				booleanExpression();
				}
				break;
			case 10:
				{
				_localctx = new VariableExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(76);
				variableExpression();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(96);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(94);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplyDivideModulusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(79);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(80);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << MULTIPLY) | (1L << DIVIDE) | (1L << MODULUS))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(81);
						expression(12);
						}
						break;
					case 2:
						{
						_localctx = new PlusMinusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(82);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(83);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(84);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new AssignmentExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(85);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(86);
						match(ASSIGN);
						setState(87);
						expression(7);
						}
						break;
					case 4:
						{
						_localctx = new AssignmentOrEqualsExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(88);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(89);
						match(EQUALS);
						setState(90);
						expression(6);
						}
						break;
					case 5:
						{
						_localctx = new BinaryCompareExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(91);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(92);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_EQUAL) | (1L << GREATER_THAN) | (1L << GREATER_THAN_EQUAL) | (1L << LESS_THAN) | (1L << LESS_THAN_EQUAL))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(93);
						expression(5);
						}
						break;
					}
					} 
				}
				setState(98);
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
			setState(99);
			identifier();
			setState(100);
			match(LEFT_PARENTHESE);
			setState(101);
			multiValueExpression();
			setState(102);
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
			setState(130);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(107);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(104);
					match(NEWLINE);
					}
					}
					setState(109);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(110);
				expression(0);
				setState(127);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(114);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(111);
								match(NEWLINE);
								}
								} 
							}
							setState(116);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
						}
						setState(117);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(121);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(118);
							match(NEWLINE);
							}
							}
							setState(123);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(124);
						expression(0);
						}
						} 
					}
					setState(129);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				}
				}
				break;
			}
			setState(135);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(132);
					match(NEWLINE);
					}
					} 
				}
				setState(137);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			setState(139);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(138);
				match(COMMA);
				}
			}

			setState(144);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(141);
				match(NEWLINE);
				}
				}
				setState(146);
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
			setState(148);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PLUS || _la==MINUS) {
				{
				setState(147);
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

			setState(150);
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
			setState(152);
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
			setState(154);
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
			setState(206);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(163);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(156);
					functionConstraintExpression();
					setState(160);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==NEWLINE) {
						{
						{
						setState(157);
						match(NEWLINE);
						}
						}
						setState(162);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				}
				setState(165);
				functionDeclarationExpression();
				setState(169);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(166);
						match(NEWLINE);
						}
						} 
					}
					setState(171);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
				}
				setState(172);
				functionImplementationExpression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(174);
				functionDeclarationExpression();
				setState(178);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(175);
					match(NEWLINE);
					}
					}
					setState(180);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(181);
				functionConstraintExpression();
				setState(185);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(182);
						match(NEWLINE);
						}
						} 
					}
					setState(187);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
				}
				setState(188);
				functionImplementationExpression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(190);
				functionDeclarationExpression();
				setState(194);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(191);
						match(NEWLINE);
						}
						} 
					}
					setState(196);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
				}
				setState(197);
				functionImplementationExpression();
				setState(201);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(198);
					match(NEWLINE);
					}
					}
					setState(203);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(204);
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
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
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
			setState(209);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
				{
				setState(208);
				identifier();
				}
			}

			setState(211);
			match(LEFT_PARENTHESE);
			setState(212);
			formalParameterExpression();
			setState(213);
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

	public static class FormalParameterExpressionContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
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
		enterRule(_localctx, 20, RULE_formalParameterExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(215);
				identifier();
				setState(216);
				match(COMMA);
				}
				}
				setState(222);
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
		enterRule(_localctx, 22, RULE_functionImplementationExpression);
		int _la;
		try {
			int _alt;
			setState(241);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,31,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(223);
				_la = _input.LA(1);
				if ( !(_la==EQUALS || _la==RIGHT_ARROW) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(224);
				expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(228);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(225);
						match(NEWLINE);
						}
						} 
					}
					setState(230);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				}
				setState(232);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==EQUALS || _la==RIGHT_ARROW) {
					{
					setState(231);
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

				setState(237);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(234);
					match(NEWLINE);
					}
					}
					setState(239);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(240);
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
		enterRule(_localctx, 24, RULE_functionConstraintExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(243);
			match(WHEN);
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
			setState(252);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LEFT_BRACE:
				{
				setState(250);
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
				setState(251);
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
		enterRule(_localctx, 26, RULE_blockExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(254);
			match(LEFT_BRACE);
			setState(258);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(255);
					match(NEWLINE);
					}
					} 
				}
				setState(260);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
			}
			setState(273);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS))) != 0)) {
				{
				setState(269);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(261);
						expression(0);
						setState(263); 
						_errHandler.sync(this);
						_la = _input.LA(1);
						do {
							{
							{
							setState(262);
							match(NEWLINE);
							}
							}
							setState(265); 
							_errHandler.sync(this);
							_la = _input.LA(1);
						} while ( _la==NEWLINE );
						}
						} 
					}
					setState(271);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
				}
				setState(272);
				expression(0);
				}
			}

			setState(278);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(275);
				match(NEWLINE);
				}
				}
				setState(280);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(281);
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
		enterRule(_localctx, 28, RULE_booleanExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(283);
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
		enterRule(_localctx, 30, RULE_varargsExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(285);
			match(APOSTROPHE);
			setState(286);
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
		enterRule(_localctx, 32, RULE_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(288);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3&\u0125\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\3\2\5\2\'\n\2\3\2\7\2*\n\2\f\2\16\2-\13\2\3\2\3\2\5\2\61\n\2\3\2"+
		"\7\2\64\n\2\f\2\16\2\67\13\2\3\2\3\2\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4P\n\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4a\n\4\f\4\16\4d"+
		"\13\4\3\5\3\5\3\5\3\5\3\5\3\6\7\6l\n\6\f\6\16\6o\13\6\3\6\3\6\7\6s\n\6"+
		"\f\6\16\6v\13\6\3\6\3\6\7\6z\n\6\f\6\16\6}\13\6\3\6\7\6\u0080\n\6\f\6"+
		"\16\6\u0083\13\6\5\6\u0085\n\6\3\6\7\6\u0088\n\6\f\6\16\6\u008b\13\6\3"+
		"\6\5\6\u008e\n\6\3\6\7\6\u0091\n\6\f\6\16\6\u0094\13\6\3\7\5\7\u0097\n"+
		"\7\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\7\n\u00a1\n\n\f\n\16\n\u00a4\13\n\5"+
		"\n\u00a6\n\n\3\n\3\n\7\n\u00aa\n\n\f\n\16\n\u00ad\13\n\3\n\3\n\3\n\3\n"+
		"\7\n\u00b3\n\n\f\n\16\n\u00b6\13\n\3\n\3\n\7\n\u00ba\n\n\f\n\16\n\u00bd"+
		"\13\n\3\n\3\n\3\n\3\n\7\n\u00c3\n\n\f\n\16\n\u00c6\13\n\3\n\3\n\7\n\u00ca"+
		"\n\n\f\n\16\n\u00cd\13\n\3\n\3\n\5\n\u00d1\n\n\3\13\5\13\u00d4\n\13\3"+
		"\13\3\13\3\13\3\13\3\f\3\f\3\f\7\f\u00dd\n\f\f\f\16\f\u00e0\13\f\3\r\3"+
		"\r\3\r\7\r\u00e5\n\r\f\r\16\r\u00e8\13\r\3\r\5\r\u00eb\n\r\3\r\7\r\u00ee"+
		"\n\r\f\r\16\r\u00f1\13\r\3\r\5\r\u00f4\n\r\3\16\3\16\7\16\u00f8\n\16\f"+
		"\16\16\16\u00fb\13\16\3\16\3\16\5\16\u00ff\n\16\3\17\3\17\7\17\u0103\n"+
		"\17\f\17\16\17\u0106\13\17\3\17\3\17\6\17\u010a\n\17\r\17\16\17\u010b"+
		"\7\17\u010e\n\17\f\17\16\17\u0111\13\17\3\17\5\17\u0114\n\17\3\17\7\17"+
		"\u0117\n\17\f\17\16\17\u011a\13\17\3\17\3\17\3\20\3\20\3\21\3\21\3\21"+
		"\3\22\3\22\3\22\2\3\6\23\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"\2\t"+
		"\3\2\32\34\3\2\30\31\4\2\23\23\36!\4\2\f\f%%\3\2\b\t\3\2\24\25\3\2\3\7"+
		"\2\u0146\2+\3\2\2\2\4:\3\2\2\2\6O\3\2\2\2\be\3\2\2\2\n\u0084\3\2\2\2\f"+
		"\u0096\3\2\2\2\16\u009a\3\2\2\2\20\u009c\3\2\2\2\22\u00d0\3\2\2\2\24\u00d3"+
		"\3\2\2\2\26\u00de\3\2\2\2\30\u00f3\3\2\2\2\32\u00f5\3\2\2\2\34\u0100\3"+
		"\2\2\2\36\u011d\3\2\2\2 \u011f\3\2\2\2\"\u0122\3\2\2\2$&\5\4\3\2%\'\7"+
		"%\2\2&%\3\2\2\2&\'\3\2\2\2\'*\3\2\2\2(*\7%\2\2)$\3\2\2\2)(\3\2\2\2*-\3"+
		"\2\2\2+)\3\2\2\2+,\3\2\2\2,\65\3\2\2\2-+\3\2\2\2.\60\5\6\4\2/\61\7%\2"+
		"\2\60/\3\2\2\2\60\61\3\2\2\2\61\64\3\2\2\2\62\64\7%\2\2\63.\3\2\2\2\63"+
		"\62\3\2\2\2\64\67\3\2\2\2\65\63\3\2\2\2\65\66\3\2\2\2\668\3\2\2\2\67\65"+
		"\3\2\2\289\7\2\2\39\3\3\2\2\2:;\7\35\2\2;<\7\4\2\2<=\7\n\2\2=\5\3\2\2"+
		"\2>?\b\4\1\2?@\7\3\2\2@P\7\27\2\2AB\7\r\2\2BC\5\6\4\2CD\7\16\2\2DP\3\2"+
		"\2\2EP\5\22\n\2FP\5\b\5\2GP\5\f\7\2HI\7\31\2\2IP\5\6\4\nJK\7\30\2\2KP"+
		"\5\6\4\tLP\5\16\b\2MP\5\36\20\2NP\5\20\t\2O>\3\2\2\2OA\3\2\2\2OE\3\2\2"+
		"\2OF\3\2\2\2OG\3\2\2\2OH\3\2\2\2OJ\3\2\2\2OL\3\2\2\2OM\3\2\2\2ON\3\2\2"+
		"\2Pb\3\2\2\2QR\f\r\2\2RS\t\2\2\2Sa\5\6\4\16TU\f\f\2\2UV\t\3\2\2Va\5\6"+
		"\4\rWX\f\b\2\2XY\7\26\2\2Ya\5\6\4\tZ[\f\7\2\2[\\\7\24\2\2\\a\5\6\4\b]"+
		"^\f\6\2\2^_\t\4\2\2_a\5\6\4\7`Q\3\2\2\2`T\3\2\2\2`W\3\2\2\2`Z\3\2\2\2"+
		"`]\3\2\2\2ad\3\2\2\2b`\3\2\2\2bc\3\2\2\2c\7\3\2\2\2db\3\2\2\2ef\5\"\22"+
		"\2fg\7\r\2\2gh\5\n\6\2hi\7\16\2\2i\t\3\2\2\2jl\7%\2\2kj\3\2\2\2lo\3\2"+
		"\2\2mk\3\2\2\2mn\3\2\2\2np\3\2\2\2om\3\2\2\2p\u0081\5\6\4\2qs\7%\2\2r"+
		"q\3\2\2\2sv\3\2\2\2tr\3\2\2\2tu\3\2\2\2uw\3\2\2\2vt\3\2\2\2w{\t\5\2\2"+
		"xz\7%\2\2yx\3\2\2\2z}\3\2\2\2{y\3\2\2\2{|\3\2\2\2|~\3\2\2\2}{\3\2\2\2"+
		"~\u0080\5\6\4\2\177t\3\2\2\2\u0080\u0083\3\2\2\2\u0081\177\3\2\2\2\u0081"+
		"\u0082\3\2\2\2\u0082\u0085\3\2\2\2\u0083\u0081\3\2\2\2\u0084m\3\2\2\2"+
		"\u0084\u0085\3\2\2\2\u0085\u0089\3\2\2\2\u0086\u0088\7%\2\2\u0087\u0086"+
		"\3\2\2\2\u0088\u008b\3\2\2\2\u0089\u0087\3\2\2\2\u0089\u008a\3\2\2\2\u008a"+
		"\u008d\3\2\2\2\u008b\u0089\3\2\2\2\u008c\u008e\7\f\2\2\u008d\u008c\3\2"+
		"\2\2\u008d\u008e\3\2\2\2\u008e\u0092\3\2\2\2\u008f\u0091\7%\2\2\u0090"+
		"\u008f\3\2\2\2\u0091\u0094\3\2\2\2\u0092\u0090\3\2\2\2\u0092\u0093\3\2"+
		"\2\2\u0093\13\3\2\2\2\u0094\u0092\3\2\2\2\u0095\u0097\t\3\2\2\u0096\u0095"+
		"\3\2\2\2\u0096\u0097\3\2\2\2\u0097\u0098\3\2\2\2\u0098\u0099\t\6\2\2\u0099"+
		"\r\3\2\2\2\u009a\u009b\7\n\2\2\u009b\17\3\2\2\2\u009c\u009d\5\"\22\2\u009d"+
		"\21\3\2\2\2\u009e\u00a2\5\32\16\2\u009f\u00a1\7%\2\2\u00a0\u009f\3\2\2"+
		"\2\u00a1\u00a4\3\2\2\2\u00a2\u00a0\3\2\2\2\u00a2\u00a3\3\2\2\2\u00a3\u00a6"+
		"\3\2\2\2\u00a4\u00a2\3\2\2\2\u00a5\u009e\3\2\2\2\u00a5\u00a6\3\2\2\2\u00a6"+
		"\u00a7\3\2\2\2\u00a7\u00ab\5\24\13\2\u00a8\u00aa\7%\2\2\u00a9\u00a8\3"+
		"\2\2\2\u00aa\u00ad\3\2\2\2\u00ab\u00a9\3\2\2\2\u00ab\u00ac\3\2\2\2\u00ac"+
		"\u00ae\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ae\u00af\5\30\r\2\u00af\u00d1\3"+
		"\2\2\2\u00b0\u00b4\5\24\13\2\u00b1\u00b3\7%\2\2\u00b2\u00b1\3\2\2\2\u00b3"+
		"\u00b6\3\2\2\2\u00b4\u00b2\3\2\2\2\u00b4\u00b5\3\2\2\2\u00b5\u00b7\3\2"+
		"\2\2\u00b6\u00b4\3\2\2\2\u00b7\u00bb\5\32\16\2\u00b8\u00ba\7%\2\2\u00b9"+
		"\u00b8\3\2\2\2\u00ba\u00bd\3\2\2\2\u00bb\u00b9\3\2\2\2\u00bb\u00bc\3\2"+
		"\2\2\u00bc\u00be\3\2\2\2\u00bd\u00bb\3\2\2\2\u00be\u00bf\5\30\r\2\u00bf"+
		"\u00d1\3\2\2\2\u00c0\u00c4\5\24\13\2\u00c1\u00c3\7%\2\2\u00c2\u00c1\3"+
		"\2\2\2\u00c3\u00c6\3\2\2\2\u00c4\u00c2\3\2\2\2\u00c4\u00c5\3\2\2\2\u00c5"+
		"\u00c7\3\2\2\2\u00c6\u00c4\3\2\2\2\u00c7\u00cb\5\30\r\2\u00c8\u00ca\7"+
		"%\2\2\u00c9\u00c8\3\2\2\2\u00ca\u00cd\3\2\2\2\u00cb\u00c9\3\2\2\2\u00cb"+
		"\u00cc\3\2\2\2\u00cc\u00ce\3\2\2\2\u00cd\u00cb\3\2\2\2\u00ce\u00cf\5\32"+
		"\16\2\u00cf\u00d1\3\2\2\2\u00d0\u00a5\3\2\2\2\u00d0\u00b0\3\2\2\2\u00d0"+
		"\u00c0\3\2\2\2\u00d1\23\3\2\2\2\u00d2\u00d4\5\"\22\2\u00d3\u00d2\3\2\2"+
		"\2\u00d3\u00d4\3\2\2\2\u00d4\u00d5\3\2\2\2\u00d5\u00d6\7\r\2\2\u00d6\u00d7"+
		"\5\26\f\2\u00d7\u00d8\7\16\2\2\u00d8\25\3\2\2\2\u00d9\u00da\5\"\22\2\u00da"+
		"\u00db\7\f\2\2\u00db\u00dd\3\2\2\2\u00dc\u00d9\3\2\2\2\u00dd\u00e0\3\2"+
		"\2\2\u00de\u00dc\3\2\2\2\u00de\u00df\3\2\2\2\u00df\27\3\2\2\2\u00e0\u00de"+
		"\3\2\2\2\u00e1\u00e2\t\7\2\2\u00e2\u00f4\5\6\4\2\u00e3\u00e5\7%\2\2\u00e4"+
		"\u00e3\3\2\2\2\u00e5\u00e8\3\2\2\2\u00e6\u00e4\3\2\2\2\u00e6\u00e7\3\2"+
		"\2\2\u00e7\u00ea\3\2\2\2\u00e8\u00e6\3\2\2\2\u00e9\u00eb\t\7\2\2\u00ea"+
		"\u00e9\3\2\2\2\u00ea\u00eb\3\2\2\2\u00eb\u00ef\3\2\2\2\u00ec\u00ee\7%"+
		"\2\2\u00ed\u00ec\3\2\2\2\u00ee\u00f1\3\2\2\2\u00ef\u00ed\3\2\2\2\u00ef"+
		"\u00f0\3\2\2\2\u00f0\u00f2\3\2\2\2\u00f1\u00ef\3\2\2\2\u00f2\u00f4\5\34"+
		"\17\2\u00f3\u00e1\3\2\2\2\u00f3\u00e6\3\2\2\2\u00f4\31\3\2\2\2\u00f5\u00f9"+
		"\7\5\2\2\u00f6\u00f8\7%\2\2\u00f7\u00f6\3\2\2\2\u00f8\u00fb\3\2\2\2\u00f9"+
		"\u00f7\3\2\2\2\u00f9\u00fa\3\2\2\2\u00fa\u00fe\3\2\2\2\u00fb\u00f9\3\2"+
		"\2\2\u00fc\u00ff\5\34\17\2\u00fd\u00ff\5\6\4\2\u00fe\u00fc\3\2\2\2\u00fe"+
		"\u00fd\3\2\2\2\u00ff\33\3\2\2\2\u0100\u0104\7\17\2\2\u0101\u0103\7%\2"+
		"\2\u0102\u0101\3\2\2\2\u0103\u0106\3\2\2\2\u0104\u0102\3\2\2\2\u0104\u0105"+
		"\3\2\2\2\u0105\u0113\3\2\2\2\u0106\u0104\3\2\2\2\u0107\u0109\5\6\4\2\u0108"+
		"\u010a\7%\2\2\u0109\u0108\3\2\2\2\u010a\u010b\3\2\2\2\u010b\u0109\3\2"+
		"\2\2\u010b\u010c\3\2\2\2\u010c\u010e\3\2\2\2\u010d\u0107\3\2\2\2\u010e"+
		"\u0111\3\2\2\2\u010f\u010d\3\2\2\2\u010f\u0110\3\2\2\2\u0110\u0112\3\2"+
		"\2\2\u0111\u010f\3\2\2\2\u0112\u0114\5\6\4\2\u0113\u010f\3\2\2\2\u0113"+
		"\u0114\3\2\2\2\u0114\u0118\3\2\2\2\u0115\u0117\7%\2\2\u0116\u0115\3\2"+
		"\2\2\u0117\u011a\3\2\2\2\u0118\u0116\3\2\2\2\u0118\u0119\3\2\2\2\u0119"+
		"\u011b\3\2\2\2\u011a\u0118\3\2\2\2\u011b\u011c\7\20\2\2\u011c\35\3\2\2"+
		"\2\u011d\u011e\7\6\2\2\u011e\37\3\2\2\2\u011f\u0120\7$\2\2\u0120\u0121"+
		"\5\20\t\2\u0121!\3\2\2\2\u0122\u0123\t\b\2\2\u0123#\3\2\2\2)&)+\60\63"+
		"\65O`bmt{\u0081\u0084\u0089\u008d\u0092\u0096\u00a2\u00a5\u00ab\u00b4"+
		"\u00bb\u00c4\u00cb\u00d0\u00d3\u00de\u00e6\u00ea\u00ef\u00f3\u00f9\u00fe"+
		"\u0104\u010b\u010f\u0113\u0118";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}