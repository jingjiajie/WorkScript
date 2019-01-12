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
		INTEGER=7, STRING=8, SEMICOLON=9, POINT=10, COMMA=11, LEFT_PARENTHESE=12, 
		RIGHT_PARENTHESE=13, LEFT_BRACE=14, RIGHT_BRACE=15, LEFT_BRACKET=16, RIGHT_BRACKET=17, 
		DOUBLE_EQUAL=18, EQUALS=19, RIGHT_ARROW=20, ASSIGN=21, COLON=22, PLUS=23, 
		MINUS=24, STAR=25, SLASH=26, PERCENT=27, HASH=28, GREATER_THAN=29, GREATER_THAN_EQUAL=30, 
		LESS_THAN=31, LESS_THAN_EQUAL=32, SINGLE_LINE_COMMENT=33, MULTILINE_COMMENT=34, 
		APOSTROPHE=35, NEWLINE=36, WS=37;
	public static final int
		RULE_program = 0, RULE_line = 1, RULE_expression = 2, RULE_callExpression = 3, 
		RULE_multiValueExpression = 4, RULE_numberExpression = 5, RULE_stringExpression = 6, 
		RULE_variableExpression = 7, RULE_stdFunctionDeclExpression = 8, RULE_stdFormalParameterExpression = 9, 
		RULE_stdFormalParameterItem = 10, RULE_functionExpression = 11, RULE_functionDeclarationExpression = 12, 
		RULE_typeName = 13, RULE_functionName = 14, RULE_formalParameterExpression = 15, 
		RULE_formalParameterItem = 16, RULE_functionImplementationExpression = 17, 
		RULE_functionConstraintExpression = 18, RULE_block = 19, RULE_booleanExpression = 20, 
		RULE_varargsExpression = 21, RULE_identifier = 22;
	public static final String[] ruleNames = {
		"program", "line", "expression", "callExpression", "multiValueExpression", 
		"numberExpression", "stringExpression", "variableExpression", "stdFunctionDeclExpression", 
		"stdFormalParameterExpression", "stdFormalParameterItem", "functionExpression", 
		"functionDeclarationExpression", "typeName", "functionName", "formalParameterExpression", 
		"formalParameterItem", "functionImplementationExpression", "functionConstraintExpression", 
		"block", "booleanExpression", "varargsExpression", "identifier"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, "'include'", "'when'", null, null, null, null, null, "';'", 
		"'.'", "','", "'('", "')'", "'{'", "'}'", "'['", "']'", "'=='", "'='", 
		"'=>'", "':='", "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'#'", "'>'", 
		"'>='", "'<'", "'<='", null, null, "'...'", "'\n'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "ACCESS_LEVEL", "INCLUDE", "WHEN", "BOOLEAN", "IDENTIFIER", "DOUBLE", 
		"INTEGER", "STRING", "SEMICOLON", "POINT", "COMMA", "LEFT_PARENTHESE", 
		"RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", 
		"DOUBLE_EQUAL", "EQUALS", "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", 
		"STAR", "SLASH", "PERCENT", "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", 
		"LESS_THAN", "LESS_THAN_EQUAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", 
		"APOSTROPHE", "NEWLINE", "WS"
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
		public List<LineContext> line() {
			return getRuleContexts(LineContext.class);
		}
		public LineContext line(int i) {
			return getRuleContext(LineContext.class,i);
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
			enterOuterAlt(_localctx, 1);
			{
			setState(49);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << SEMICOLON) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS) | (1L << NEWLINE))) != 0)) {
				{
				{
				setState(46);
				line();
				}
				}
				setState(51);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(52);
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

	public static class LineContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NEWLINE() { return getToken(WorkScriptParser.NEWLINE, 0); }
		public List<TerminalNode> SEMICOLON() { return getTokens(WorkScriptParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(WorkScriptParser.SEMICOLON, i);
		}
		public LineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_line; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterLine(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitLine(this);
		}
	}

	public final LineContext line() throws RecognitionException {
		LineContext _localctx = new LineContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_line);
		int _la;
		try {
			int _alt;
			setState(83);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(67); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(57);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==SEMICOLON) {
							{
							{
							setState(54);
							match(SEMICOLON);
							}
							}
							setState(59);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(60);
						expression(0);
						setState(64);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(61);
								match(SEMICOLON);
								}
								} 
							}
							setState(66);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
						}
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(69); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(72);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
				case 1:
					{
					setState(71);
					match(NEWLINE);
					}
					break;
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(75); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(74);
						match(SEMICOLON);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(77); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(80);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
				case 1:
					{
					setState(79);
					match(NEWLINE);
					}
					break;
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(82);
				match(NEWLINE);
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
		public TerminalNode STAR() { return getToken(WorkScriptParser.STAR, 0); }
		public TerminalNode SLASH() { return getToken(WorkScriptParser.SLASH, 0); }
		public TerminalNode PERCENT() { return getToken(WorkScriptParser.PERCENT, 0); }
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
	public static class StdFunctionDeclExpression_Context extends ExpressionContext {
		public StdFunctionDeclExpressionContext stdFunctionDeclExpression() {
			return getRuleContext(StdFunctionDeclExpressionContext.class,0);
		}
		public StdFunctionDeclExpression_Context(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterStdFunctionDeclExpression_(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitStdFunctionDeclExpression_(this);
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
			setState(103);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				{
				_localctx = new AccessLevelExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(86);
				match(ACCESS_LEVEL);
				setState(87);
				match(COLON);
				}
				break;
			case 2:
				{
				_localctx = new ParentheseExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(88);
				match(LEFT_PARENTHESE);
				setState(89);
				expression(0);
				setState(90);
				match(RIGHT_PARENTHESE);
				}
				break;
			case 3:
				{
				_localctx = new StdFunctionDeclExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(92);
				stdFunctionDeclExpression();
				}
				break;
			case 4:
				{
				_localctx = new FunctionExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(93);
				functionExpression();
				}
				break;
			case 5:
				{
				_localctx = new CallExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(94);
				callExpression();
				}
				break;
			case 6:
				{
				_localctx = new NumberExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(95);
				numberExpression();
				}
				break;
			case 7:
				{
				_localctx = new NegativeExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(96);
				match(MINUS);
				setState(97);
				expression(8);
				}
				break;
			case 8:
				{
				_localctx = new PositiveExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(98);
				match(PLUS);
				setState(99);
				expression(7);
				}
				break;
			case 9:
				{
				_localctx = new StringExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(100);
				stringExpression();
				}
				break;
			case 10:
				{
				_localctx = new BooleanExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(101);
				booleanExpression();
				}
				break;
			case 11:
				{
				_localctx = new VariableExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(102);
				variableExpression();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(122);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(120);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplyDivideModulusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(105);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(106);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STAR) | (1L << SLASH) | (1L << PERCENT))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(107);
						expression(12);
						}
						break;
					case 2:
						{
						_localctx = new PlusMinusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(108);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(109);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(110);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new AssignmentExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(111);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(112);
						match(ASSIGN);
						setState(113);
						expression(7);
						}
						break;
					case 4:
						{
						_localctx = new AssignmentOrEqualsExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(114);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(115);
						match(EQUALS);
						setState(116);
						expression(6);
						}
						break;
					case 5:
						{
						_localctx = new BinaryCompareExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(117);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(118);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_EQUAL) | (1L << GREATER_THAN) | (1L << GREATER_THAN_EQUAL) | (1L << LESS_THAN) | (1L << LESS_THAN_EQUAL))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(119);
						expression(5);
						}
						break;
					}
					} 
				}
				setState(124);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
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
			setState(125);
			identifier();
			setState(126);
			match(LEFT_PARENTHESE);
			setState(127);
			multiValueExpression();
			setState(128);
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
			setState(156);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				{
				setState(133);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(130);
					match(NEWLINE);
					}
					}
					setState(135);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(136);
				expression(0);
				setState(153);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(140);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(137);
								match(NEWLINE);
								}
								} 
							}
							setState(142);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
						}
						setState(143);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(147);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(144);
							match(NEWLINE);
							}
							}
							setState(149);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(150);
						expression(0);
						}
						} 
					}
					setState(155);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
				}
				}
				break;
			}
			setState(161);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(158);
					match(NEWLINE);
					}
					} 
				}
				setState(163);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			}
			setState(165);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(164);
				match(COMMA);
				}
			}

			setState(170);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(167);
				match(NEWLINE);
				}
				}
				setState(172);
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
			setState(174);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PLUS || _la==MINUS) {
				{
				setState(173);
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

			setState(176);
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
			setState(178);
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
			setState(180);
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

	public static class StdFunctionDeclExpressionContext extends ParserRuleContext {
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public FunctionNameContext functionName() {
			return getRuleContext(FunctionNameContext.class,0);
		}
		public TerminalNode LEFT_PARENTHESE() { return getToken(WorkScriptParser.LEFT_PARENTHESE, 0); }
		public StdFormalParameterExpressionContext stdFormalParameterExpression() {
			return getRuleContext(StdFormalParameterExpressionContext.class,0);
		}
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public List<TerminalNode> STAR() { return getTokens(WorkScriptParser.STAR); }
		public TerminalNode STAR(int i) {
			return getToken(WorkScriptParser.STAR, i);
		}
		public StdFunctionDeclExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stdFunctionDeclExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterStdFunctionDeclExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitStdFunctionDeclExpression(this);
		}
	}

	public final StdFunctionDeclExpressionContext stdFunctionDeclExpression() throws RecognitionException {
		StdFunctionDeclExpressionContext _localctx = new StdFunctionDeclExpressionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_stdFunctionDeclExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(182);
			typeName();
			setState(186);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==STAR) {
				{
				{
				setState(183);
				match(STAR);
				}
				}
				setState(188);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(189);
			functionName();
			setState(190);
			match(LEFT_PARENTHESE);
			setState(191);
			stdFormalParameterExpression();
			setState(192);
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

	public static class StdFormalParameterExpressionContext extends ParserRuleContext {
		public List<TerminalNode> NEWLINE() { return getTokens(WorkScriptParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(WorkScriptParser.NEWLINE, i);
		}
		public List<StdFormalParameterItemContext> stdFormalParameterItem() {
			return getRuleContexts(StdFormalParameterItemContext.class);
		}
		public StdFormalParameterItemContext stdFormalParameterItem(int i) {
			return getRuleContext(StdFormalParameterItemContext.class,i);
		}
		public TerminalNode APOSTROPHE() { return getToken(WorkScriptParser.APOSTROPHE, 0); }
		public List<TerminalNode> COMMA() { return getTokens(WorkScriptParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(WorkScriptParser.COMMA, i);
		}
		public StdFormalParameterExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stdFormalParameterExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterStdFormalParameterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitStdFormalParameterExpression(this);
		}
	}

	public final StdFormalParameterExpressionContext stdFormalParameterExpression() throws RecognitionException {
		StdFormalParameterExpressionContext _localctx = new StdFormalParameterExpressionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_stdFormalParameterExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(197);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(194);
					match(NEWLINE);
					}
					} 
				}
				setState(199);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			setState(220);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
				{
				setState(200);
				stdFormalParameterItem();
				setState(217);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(204);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(201);
								match(NEWLINE);
								}
								} 
							}
							setState(206);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
						}
						setState(207);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(211);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(208);
							match(NEWLINE);
							}
							}
							setState(213);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(214);
						stdFormalParameterItem();
						}
						} 
					}
					setState(219);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
				}
				}
			}

			setState(236);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
			case 1:
				{
				setState(225);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(222);
						match(NEWLINE);
						}
						} 
					}
					setState(227);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
				}
				setState(228);
				_la = _input.LA(1);
				if ( !(_la==COMMA || _la==NEWLINE) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(232);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(229);
					match(NEWLINE);
					}
					}
					setState(234);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(235);
				match(APOSTROPHE);
				}
				break;
			}
			setState(241);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(238);
					match(NEWLINE);
					}
					} 
				}
				setState(243);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			}
			setState(245);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(244);
				match(COMMA);
				}
			}

			setState(250);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(247);
				match(NEWLINE);
				}
				}
				setState(252);
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

	public static class StdFormalParameterItemContext extends ParserRuleContext {
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public List<TerminalNode> STAR() { return getTokens(WorkScriptParser.STAR); }
		public TerminalNode STAR(int i) {
			return getToken(WorkScriptParser.STAR, i);
		}
		public StdFormalParameterItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stdFormalParameterItem; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterStdFormalParameterItem(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitStdFormalParameterItem(this);
		}
	}

	public final StdFormalParameterItemContext stdFormalParameterItem() throws RecognitionException {
		StdFormalParameterItemContext _localctx = new StdFormalParameterItemContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_stdFormalParameterItem);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(253);
			typeName();
			setState(257);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==STAR) {
				{
				{
				setState(254);
				match(STAR);
				}
				}
				setState(259);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(260);
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
		enterRule(_localctx, 22, RULE_functionExpression);
		int _la;
		try {
			int _alt;
			setState(312);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,40,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(269);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,34,_ctx) ) {
				case 1:
					{
					setState(262);
					functionConstraintExpression();
					setState(266);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==NEWLINE) {
						{
						{
						setState(263);
						match(NEWLINE);
						}
						}
						setState(268);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				}
				setState(271);
				functionDeclarationExpression();
				setState(275);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(272);
						match(NEWLINE);
						}
						} 
					}
					setState(277);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
				}
				setState(278);
				functionImplementationExpression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(280);
				functionDeclarationExpression();
				setState(284);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(281);
					match(NEWLINE);
					}
					}
					setState(286);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(287);
				functionConstraintExpression();
				setState(291);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(288);
						match(NEWLINE);
						}
						} 
					}
					setState(293);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
				}
				setState(294);
				functionImplementationExpression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(296);
				functionDeclarationExpression();
				setState(300);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(297);
						match(NEWLINE);
						}
						} 
					}
					setState(302);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
				}
				setState(303);
				functionImplementationExpression();
				setState(307);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(304);
					match(NEWLINE);
					}
					}
					setState(309);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(310);
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
		public List<TerminalNode> STAR() { return getTokens(WorkScriptParser.STAR); }
		public TerminalNode STAR(int i) {
			return getToken(WorkScriptParser.STAR, i);
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
		enterRule(_localctx, 24, RULE_functionDeclarationExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(326);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,43,_ctx) ) {
			case 1:
				{
				setState(315);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
					{
					setState(314);
					functionName();
					}
				}

				}
				break;
			case 2:
				{
				setState(317);
				typeName();
				setState(321);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==STAR) {
					{
					{
					setState(318);
					match(STAR);
					}
					}
					setState(323);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(324);
				functionName();
				}
				break;
			}
			setState(328);
			match(LEFT_PARENTHESE);
			setState(329);
			formalParameterExpression();
			setState(330);
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
		enterRule(_localctx, 26, RULE_typeName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(332);
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
		enterRule(_localctx, 28, RULE_functionName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(334);
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
		public List<TerminalNode> NEWLINE() { return getTokens(WorkScriptParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(WorkScriptParser.NEWLINE, i);
		}
		public List<FormalParameterItemContext> formalParameterItem() {
			return getRuleContexts(FormalParameterItemContext.class);
		}
		public FormalParameterItemContext formalParameterItem(int i) {
			return getRuleContext(FormalParameterItemContext.class,i);
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
		enterRule(_localctx, 30, RULE_formalParameterExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(339);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,44,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(336);
					match(NEWLINE);
					}
					} 
				}
				setState(341);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,44,_ctx);
			}
			setState(362);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS))) != 0)) {
				{
				setState(342);
				formalParameterItem();
				setState(359);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,47,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(346);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(343);
								match(NEWLINE);
								}
								} 
							}
							setState(348);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
						}
						setState(349);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(353);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(350);
							match(NEWLINE);
							}
							}
							setState(355);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(356);
						formalParameterItem();
						}
						} 
					}
					setState(361);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,47,_ctx);
				}
				}
			}

			setState(367);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,49,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(364);
					match(NEWLINE);
					}
					} 
				}
				setState(369);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,49,_ctx);
			}
			setState(371);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(370);
				match(COMMA);
				}
			}

			setState(376);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(373);
				match(NEWLINE);
				}
				}
				setState(378);
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
		public List<TerminalNode> STAR() { return getTokens(WorkScriptParser.STAR); }
		public TerminalNode STAR(int i) {
			return getToken(WorkScriptParser.STAR, i);
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
		enterRule(_localctx, 32, RULE_formalParameterItem);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(386);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,53,_ctx) ) {
			case 1:
				{
				setState(379);
				typeName();
				setState(383);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==STAR) {
					{
					{
					setState(380);
					match(STAR);
					}
					}
					setState(385);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			}
			setState(388);
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
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
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
		enterRule(_localctx, 34, RULE_functionImplementationExpression);
		int _la;
		try {
			int _alt;
			setState(408);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,57,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(390);
				_la = _input.LA(1);
				if ( !(_la==EQUALS || _la==RIGHT_ARROW) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(391);
				expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(395);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,54,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(392);
						match(NEWLINE);
						}
						} 
					}
					setState(397);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,54,_ctx);
				}
				setState(399);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==EQUALS || _la==RIGHT_ARROW) {
					{
					setState(398);
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

				setState(404);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(401);
					match(NEWLINE);
					}
					}
					setState(406);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(407);
				block();
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
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
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
		enterRule(_localctx, 36, RULE_functionConstraintExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(410);
			match(WHEN);
			setState(414);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(411);
				match(NEWLINE);
				}
				}
				setState(416);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(419);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LEFT_BRACE:
				{
				setState(417);
				block();
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
				setState(418);
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

	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LEFT_BRACE() { return getToken(WorkScriptParser.LEFT_BRACE, 0); }
		public TerminalNode RIGHT_BRACE() { return getToken(WorkScriptParser.RIGHT_BRACE, 0); }
		public List<LineContext> line() {
			return getRuleContexts(LineContext.class);
		}
		public LineContext line(int i) {
			return getRuleContext(LineContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof WorkScriptListener ) ((WorkScriptListener)listener).exitBlock(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(421);
			match(LEFT_BRACE);
			setState(425);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << SEMICOLON) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS) | (1L << NEWLINE))) != 0)) {
				{
				{
				setState(422);
				line();
				}
				}
				setState(427);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(428);
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
		enterRule(_localctx, 40, RULE_booleanExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(430);
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
		enterRule(_localctx, 42, RULE_varargsExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(432);
			match(APOSTROPHE);
			setState(433);
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
		enterRule(_localctx, 44, RULE_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(435);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\'\u01b8\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\3\2\7\2\62"+
		"\n\2\f\2\16\2\65\13\2\3\2\3\2\3\3\7\3:\n\3\f\3\16\3=\13\3\3\3\3\3\7\3"+
		"A\n\3\f\3\16\3D\13\3\6\3F\n\3\r\3\16\3G\3\3\5\3K\n\3\3\3\6\3N\n\3\r\3"+
		"\16\3O\3\3\5\3S\n\3\3\3\5\3V\n\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4j\n\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4{\n\4\f\4\16\4~\13\4\3\5\3\5\3\5"+
		"\3\5\3\5\3\6\7\6\u0086\n\6\f\6\16\6\u0089\13\6\3\6\3\6\7\6\u008d\n\6\f"+
		"\6\16\6\u0090\13\6\3\6\3\6\7\6\u0094\n\6\f\6\16\6\u0097\13\6\3\6\7\6\u009a"+
		"\n\6\f\6\16\6\u009d\13\6\5\6\u009f\n\6\3\6\7\6\u00a2\n\6\f\6\16\6\u00a5"+
		"\13\6\3\6\5\6\u00a8\n\6\3\6\7\6\u00ab\n\6\f\6\16\6\u00ae\13\6\3\7\5\7"+
		"\u00b1\n\7\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\7\n\u00bb\n\n\f\n\16\n\u00be"+
		"\13\n\3\n\3\n\3\n\3\n\3\n\3\13\7\13\u00c6\n\13\f\13\16\13\u00c9\13\13"+
		"\3\13\3\13\7\13\u00cd\n\13\f\13\16\13\u00d0\13\13\3\13\3\13\7\13\u00d4"+
		"\n\13\f\13\16\13\u00d7\13\13\3\13\7\13\u00da\n\13\f\13\16\13\u00dd\13"+
		"\13\5\13\u00df\n\13\3\13\7\13\u00e2\n\13\f\13\16\13\u00e5\13\13\3\13\3"+
		"\13\7\13\u00e9\n\13\f\13\16\13\u00ec\13\13\3\13\5\13\u00ef\n\13\3\13\7"+
		"\13\u00f2\n\13\f\13\16\13\u00f5\13\13\3\13\5\13\u00f8\n\13\3\13\7\13\u00fb"+
		"\n\13\f\13\16\13\u00fe\13\13\3\f\3\f\7\f\u0102\n\f\f\f\16\f\u0105\13\f"+
		"\3\f\3\f\3\r\3\r\7\r\u010b\n\r\f\r\16\r\u010e\13\r\5\r\u0110\n\r\3\r\3"+
		"\r\7\r\u0114\n\r\f\r\16\r\u0117\13\r\3\r\3\r\3\r\3\r\7\r\u011d\n\r\f\r"+
		"\16\r\u0120\13\r\3\r\3\r\7\r\u0124\n\r\f\r\16\r\u0127\13\r\3\r\3\r\3\r"+
		"\3\r\7\r\u012d\n\r\f\r\16\r\u0130\13\r\3\r\3\r\7\r\u0134\n\r\f\r\16\r"+
		"\u0137\13\r\3\r\3\r\5\r\u013b\n\r\3\16\5\16\u013e\n\16\3\16\3\16\7\16"+
		"\u0142\n\16\f\16\16\16\u0145\13\16\3\16\3\16\5\16\u0149\n\16\3\16\3\16"+
		"\3\16\3\16\3\17\3\17\3\20\3\20\3\21\7\21\u0154\n\21\f\21\16\21\u0157\13"+
		"\21\3\21\3\21\7\21\u015b\n\21\f\21\16\21\u015e\13\21\3\21\3\21\7\21\u0162"+
		"\n\21\f\21\16\21\u0165\13\21\3\21\7\21\u0168\n\21\f\21\16\21\u016b\13"+
		"\21\5\21\u016d\n\21\3\21\7\21\u0170\n\21\f\21\16\21\u0173\13\21\3\21\5"+
		"\21\u0176\n\21\3\21\7\21\u0179\n\21\f\21\16\21\u017c\13\21\3\22\3\22\7"+
		"\22\u0180\n\22\f\22\16\22\u0183\13\22\5\22\u0185\n\22\3\22\3\22\3\23\3"+
		"\23\3\23\7\23\u018c\n\23\f\23\16\23\u018f\13\23\3\23\5\23\u0192\n\23\3"+
		"\23\7\23\u0195\n\23\f\23\16\23\u0198\13\23\3\23\5\23\u019b\n\23\3\24\3"+
		"\24\7\24\u019f\n\24\f\24\16\24\u01a2\13\24\3\24\3\24\5\24\u01a6\n\24\3"+
		"\25\3\25\7\25\u01aa\n\25\f\25\16\25\u01ad\13\25\3\25\3\25\3\26\3\26\3"+
		"\27\3\27\3\27\3\30\3\30\3\30\2\3\6\31\2\4\6\b\n\f\16\20\22\24\26\30\32"+
		"\34\36 \"$&(*,.\2\t\3\2\33\35\3\2\31\32\4\2\24\24\37\"\4\2\r\r&&\3\2\b"+
		"\t\3\2\25\26\3\2\3\7\2\u01eb\2\63\3\2\2\2\4U\3\2\2\2\6i\3\2\2\2\b\177"+
		"\3\2\2\2\n\u009e\3\2\2\2\f\u00b0\3\2\2\2\16\u00b4\3\2\2\2\20\u00b6\3\2"+
		"\2\2\22\u00b8\3\2\2\2\24\u00c7\3\2\2\2\26\u00ff\3\2\2\2\30\u013a\3\2\2"+
		"\2\32\u0148\3\2\2\2\34\u014e\3\2\2\2\36\u0150\3\2\2\2 \u0155\3\2\2\2\""+
		"\u0184\3\2\2\2$\u019a\3\2\2\2&\u019c\3\2\2\2(\u01a7\3\2\2\2*\u01b0\3\2"+
		"\2\2,\u01b2\3\2\2\2.\u01b5\3\2\2\2\60\62\5\4\3\2\61\60\3\2\2\2\62\65\3"+
		"\2\2\2\63\61\3\2\2\2\63\64\3\2\2\2\64\66\3\2\2\2\65\63\3\2\2\2\66\67\7"+
		"\2\2\3\67\3\3\2\2\28:\7\13\2\298\3\2\2\2:=\3\2\2\2;9\3\2\2\2;<\3\2\2\2"+
		"<>\3\2\2\2=;\3\2\2\2>B\5\6\4\2?A\7\13\2\2@?\3\2\2\2AD\3\2\2\2B@\3\2\2"+
		"\2BC\3\2\2\2CF\3\2\2\2DB\3\2\2\2E;\3\2\2\2FG\3\2\2\2GE\3\2\2\2GH\3\2\2"+
		"\2HJ\3\2\2\2IK\7&\2\2JI\3\2\2\2JK\3\2\2\2KV\3\2\2\2LN\7\13\2\2ML\3\2\2"+
		"\2NO\3\2\2\2OM\3\2\2\2OP\3\2\2\2PR\3\2\2\2QS\7&\2\2RQ\3\2\2\2RS\3\2\2"+
		"\2SV\3\2\2\2TV\7&\2\2UE\3\2\2\2UM\3\2\2\2UT\3\2\2\2V\5\3\2\2\2WX\b\4\1"+
		"\2XY\7\3\2\2Yj\7\30\2\2Z[\7\16\2\2[\\\5\6\4\2\\]\7\17\2\2]j\3\2\2\2^j"+
		"\5\22\n\2_j\5\30\r\2`j\5\b\5\2aj\5\f\7\2bc\7\32\2\2cj\5\6\4\nde\7\31\2"+
		"\2ej\5\6\4\tfj\5\16\b\2gj\5*\26\2hj\5\20\t\2iW\3\2\2\2iZ\3\2\2\2i^\3\2"+
		"\2\2i_\3\2\2\2i`\3\2\2\2ia\3\2\2\2ib\3\2\2\2id\3\2\2\2if\3\2\2\2ig\3\2"+
		"\2\2ih\3\2\2\2j|\3\2\2\2kl\f\r\2\2lm\t\2\2\2m{\5\6\4\16no\f\f\2\2op\t"+
		"\3\2\2p{\5\6\4\rqr\f\b\2\2rs\7\27\2\2s{\5\6\4\ttu\f\7\2\2uv\7\25\2\2v"+
		"{\5\6\4\bwx\f\6\2\2xy\t\4\2\2y{\5\6\4\7zk\3\2\2\2zn\3\2\2\2zq\3\2\2\2"+
		"zt\3\2\2\2zw\3\2\2\2{~\3\2\2\2|z\3\2\2\2|}\3\2\2\2}\7\3\2\2\2~|\3\2\2"+
		"\2\177\u0080\5.\30\2\u0080\u0081\7\16\2\2\u0081\u0082\5\n\6\2\u0082\u0083"+
		"\7\17\2\2\u0083\t\3\2\2\2\u0084\u0086\7&\2\2\u0085\u0084\3\2\2\2\u0086"+
		"\u0089\3\2\2\2\u0087\u0085\3\2\2\2\u0087\u0088\3\2\2\2\u0088\u008a\3\2"+
		"\2\2\u0089\u0087\3\2\2\2\u008a\u009b\5\6\4\2\u008b\u008d\7&\2\2\u008c"+
		"\u008b\3\2\2\2\u008d\u0090\3\2\2\2\u008e\u008c\3\2\2\2\u008e\u008f\3\2"+
		"\2\2\u008f\u0091\3\2\2\2\u0090\u008e\3\2\2\2\u0091\u0095\t\5\2\2\u0092"+
		"\u0094\7&\2\2\u0093\u0092\3\2\2\2\u0094\u0097\3\2\2\2\u0095\u0093\3\2"+
		"\2\2\u0095\u0096\3\2\2\2\u0096\u0098\3\2\2\2\u0097\u0095\3\2\2\2\u0098"+
		"\u009a\5\6\4\2\u0099\u008e\3\2\2\2\u009a\u009d\3\2\2\2\u009b\u0099\3\2"+
		"\2\2\u009b\u009c\3\2\2\2\u009c\u009f\3\2\2\2\u009d\u009b\3\2\2\2\u009e"+
		"\u0087\3\2\2\2\u009e\u009f\3\2\2\2\u009f\u00a3\3\2\2\2\u00a0\u00a2\7&"+
		"\2\2\u00a1\u00a0\3\2\2\2\u00a2\u00a5\3\2\2\2\u00a3\u00a1\3\2\2\2\u00a3"+
		"\u00a4\3\2\2\2\u00a4\u00a7\3\2\2\2\u00a5\u00a3\3\2\2\2\u00a6\u00a8\7\r"+
		"\2\2\u00a7\u00a6\3\2\2\2\u00a7\u00a8\3\2\2\2\u00a8\u00ac\3\2\2\2\u00a9"+
		"\u00ab\7&\2\2\u00aa\u00a9\3\2\2\2\u00ab\u00ae\3\2\2\2\u00ac\u00aa\3\2"+
		"\2\2\u00ac\u00ad\3\2\2\2\u00ad\13\3\2\2\2\u00ae\u00ac\3\2\2\2\u00af\u00b1"+
		"\t\3\2\2\u00b0\u00af\3\2\2\2\u00b0\u00b1\3\2\2\2\u00b1\u00b2\3\2\2\2\u00b2"+
		"\u00b3\t\6\2\2\u00b3\r\3\2\2\2\u00b4\u00b5\7\n\2\2\u00b5\17\3\2\2\2\u00b6"+
		"\u00b7\5.\30\2\u00b7\21\3\2\2\2\u00b8\u00bc\5\34\17\2\u00b9\u00bb\7\33"+
		"\2\2\u00ba\u00b9\3\2\2\2\u00bb\u00be\3\2\2\2\u00bc\u00ba\3\2\2\2\u00bc"+
		"\u00bd\3\2\2\2\u00bd\u00bf\3\2\2\2\u00be\u00bc\3\2\2\2\u00bf\u00c0\5\36"+
		"\20\2\u00c0\u00c1\7\16\2\2\u00c1\u00c2\5\24\13\2\u00c2\u00c3\7\17\2\2"+
		"\u00c3\23\3\2\2\2\u00c4\u00c6\7&\2\2\u00c5\u00c4\3\2\2\2\u00c6\u00c9\3"+
		"\2\2\2\u00c7\u00c5\3\2\2\2\u00c7\u00c8\3\2\2\2\u00c8\u00de\3\2\2\2\u00c9"+
		"\u00c7\3\2\2\2\u00ca\u00db\5\26\f\2\u00cb\u00cd\7&\2\2\u00cc\u00cb\3\2"+
		"\2\2\u00cd\u00d0\3\2\2\2\u00ce\u00cc\3\2\2\2\u00ce\u00cf\3\2\2\2\u00cf"+
		"\u00d1\3\2\2\2\u00d0\u00ce\3\2\2\2\u00d1\u00d5\t\5\2\2\u00d2\u00d4\7&"+
		"\2\2\u00d3\u00d2\3\2\2\2\u00d4\u00d7\3\2\2\2\u00d5\u00d3\3\2\2\2\u00d5"+
		"\u00d6\3\2\2\2\u00d6\u00d8\3\2\2\2\u00d7\u00d5\3\2\2\2\u00d8\u00da\5\26"+
		"\f\2\u00d9\u00ce\3\2\2\2\u00da\u00dd\3\2\2\2\u00db\u00d9\3\2\2\2\u00db"+
		"\u00dc\3\2\2\2\u00dc\u00df\3\2\2\2\u00dd\u00db\3\2\2\2\u00de\u00ca\3\2"+
		"\2\2\u00de\u00df\3\2\2\2\u00df\u00ee\3\2\2\2\u00e0\u00e2\7&\2\2\u00e1"+
		"\u00e0\3\2\2\2\u00e2\u00e5\3\2\2\2\u00e3\u00e1\3\2\2\2\u00e3\u00e4\3\2"+
		"\2\2\u00e4\u00e6\3\2\2\2\u00e5\u00e3\3\2\2\2\u00e6\u00ea\t\5\2\2\u00e7"+
		"\u00e9\7&\2\2\u00e8\u00e7\3\2\2\2\u00e9\u00ec\3\2\2\2\u00ea\u00e8\3\2"+
		"\2\2\u00ea\u00eb\3\2\2\2\u00eb\u00ed\3\2\2\2\u00ec\u00ea\3\2\2\2\u00ed"+
		"\u00ef\7%\2\2\u00ee\u00e3\3\2\2\2\u00ee\u00ef\3\2\2\2\u00ef\u00f3\3\2"+
		"\2\2\u00f0\u00f2\7&\2\2\u00f1\u00f0\3\2\2\2\u00f2\u00f5\3\2\2\2\u00f3"+
		"\u00f1\3\2\2\2\u00f3\u00f4\3\2\2\2\u00f4\u00f7\3\2\2\2\u00f5\u00f3\3\2"+
		"\2\2\u00f6\u00f8\7\r\2\2\u00f7\u00f6\3\2\2\2\u00f7\u00f8\3\2\2\2\u00f8"+
		"\u00fc\3\2\2\2\u00f9\u00fb\7&\2\2\u00fa\u00f9\3\2\2\2\u00fb\u00fe\3\2"+
		"\2\2\u00fc\u00fa\3\2\2\2\u00fc\u00fd\3\2\2\2\u00fd\25\3\2\2\2\u00fe\u00fc"+
		"\3\2\2\2\u00ff\u0103\5\34\17\2\u0100\u0102\7\33\2\2\u0101\u0100\3\2\2"+
		"\2\u0102\u0105\3\2\2\2\u0103\u0101\3\2\2\2\u0103\u0104\3\2\2\2\u0104\u0106"+
		"\3\2\2\2\u0105\u0103\3\2\2\2\u0106\u0107\5.\30\2\u0107\27\3\2\2\2\u0108"+
		"\u010c\5&\24\2\u0109\u010b\7&\2\2\u010a\u0109\3\2\2\2\u010b\u010e\3\2"+
		"\2\2\u010c\u010a\3\2\2\2\u010c\u010d\3\2\2\2\u010d\u0110\3\2\2\2\u010e"+
		"\u010c\3\2\2\2\u010f\u0108\3\2\2\2\u010f\u0110\3\2\2\2\u0110\u0111\3\2"+
		"\2\2\u0111\u0115\5\32\16\2\u0112\u0114\7&\2\2\u0113\u0112\3\2\2\2\u0114"+
		"\u0117\3\2\2\2\u0115\u0113\3\2\2\2\u0115\u0116\3\2\2\2\u0116\u0118\3\2"+
		"\2\2\u0117\u0115\3\2\2\2\u0118\u0119\5$\23\2\u0119\u013b\3\2\2\2\u011a"+
		"\u011e\5\32\16\2\u011b\u011d\7&\2\2\u011c\u011b\3\2\2\2\u011d\u0120\3"+
		"\2\2\2\u011e\u011c\3\2\2\2\u011e\u011f\3\2\2\2\u011f\u0121\3\2\2\2\u0120"+
		"\u011e\3\2\2\2\u0121\u0125\5&\24\2\u0122\u0124\7&\2\2\u0123\u0122\3\2"+
		"\2\2\u0124\u0127\3\2\2\2\u0125\u0123\3\2\2\2\u0125\u0126\3\2\2\2\u0126"+
		"\u0128\3\2\2\2\u0127\u0125\3\2\2\2\u0128\u0129\5$\23\2\u0129\u013b\3\2"+
		"\2\2\u012a\u012e\5\32\16\2\u012b\u012d\7&\2\2\u012c\u012b\3\2\2\2\u012d"+
		"\u0130\3\2\2\2\u012e\u012c\3\2\2\2\u012e\u012f\3\2\2\2\u012f\u0131\3\2"+
		"\2\2\u0130\u012e\3\2\2\2\u0131\u0135\5$\23\2\u0132\u0134\7&\2\2\u0133"+
		"\u0132\3\2\2\2\u0134\u0137\3\2\2\2\u0135\u0133\3\2\2\2\u0135\u0136\3\2"+
		"\2\2\u0136\u0138\3\2\2\2\u0137\u0135\3\2\2\2\u0138\u0139\5&\24\2\u0139"+
		"\u013b\3\2\2\2\u013a\u010f\3\2\2\2\u013a\u011a\3\2\2\2\u013a\u012a\3\2"+
		"\2\2\u013b\31\3\2\2\2\u013c\u013e\5\36\20\2\u013d\u013c\3\2\2\2\u013d"+
		"\u013e\3\2\2\2\u013e\u0149\3\2\2\2\u013f\u0143\5\34\17\2\u0140\u0142\7"+
		"\33\2\2\u0141\u0140\3\2\2\2\u0142\u0145\3\2\2\2\u0143\u0141\3\2\2\2\u0143"+
		"\u0144\3\2\2\2\u0144\u0146\3\2\2\2\u0145\u0143\3\2\2\2\u0146\u0147\5\36"+
		"\20\2\u0147\u0149\3\2\2\2\u0148\u013d\3\2\2\2\u0148\u013f\3\2\2\2\u0149"+
		"\u014a\3\2\2\2\u014a\u014b\7\16\2\2\u014b\u014c\5 \21\2\u014c\u014d\7"+
		"\17\2\2\u014d\33\3\2\2\2\u014e\u014f\5.\30\2\u014f\35\3\2\2\2\u0150\u0151"+
		"\5.\30\2\u0151\37\3\2\2\2\u0152\u0154\7&\2\2\u0153\u0152\3\2\2\2\u0154"+
		"\u0157\3\2\2\2\u0155\u0153\3\2\2\2\u0155\u0156\3\2\2\2\u0156\u016c\3\2"+
		"\2\2\u0157\u0155\3\2\2\2\u0158\u0169\5\"\22\2\u0159\u015b\7&\2\2\u015a"+
		"\u0159\3\2\2\2\u015b\u015e\3\2\2\2\u015c\u015a\3\2\2\2\u015c\u015d\3\2"+
		"\2\2\u015d\u015f\3\2\2\2\u015e\u015c\3\2\2\2\u015f\u0163\t\5\2\2\u0160"+
		"\u0162\7&\2\2\u0161\u0160\3\2\2\2\u0162\u0165\3\2\2\2\u0163\u0161\3\2"+
		"\2\2\u0163\u0164\3\2\2\2\u0164\u0166\3\2\2\2\u0165\u0163\3\2\2\2\u0166"+
		"\u0168\5\"\22\2\u0167\u015c\3\2\2\2\u0168\u016b\3\2\2\2\u0169\u0167\3"+
		"\2\2\2\u0169\u016a\3\2\2\2\u016a\u016d\3\2\2\2\u016b\u0169\3\2\2\2\u016c"+
		"\u0158\3\2\2\2\u016c\u016d\3\2\2\2\u016d\u0171\3\2\2\2\u016e\u0170\7&"+
		"\2\2\u016f\u016e\3\2\2\2\u0170\u0173\3\2\2\2\u0171\u016f\3\2\2\2\u0171"+
		"\u0172\3\2\2\2\u0172\u0175\3\2\2\2\u0173\u0171\3\2\2\2\u0174\u0176\7\r"+
		"\2\2\u0175\u0174\3\2\2\2\u0175\u0176\3\2\2\2\u0176\u017a\3\2\2\2\u0177"+
		"\u0179\7&\2\2\u0178\u0177\3\2\2\2\u0179\u017c\3\2\2\2\u017a\u0178\3\2"+
		"\2\2\u017a\u017b\3\2\2\2\u017b!\3\2\2\2\u017c\u017a\3\2\2\2\u017d\u0181"+
		"\5\34\17\2\u017e\u0180\7\33\2\2\u017f\u017e\3\2\2\2\u0180\u0183\3\2\2"+
		"\2\u0181\u017f\3\2\2\2\u0181\u0182\3\2\2\2\u0182\u0185\3\2\2\2\u0183\u0181"+
		"\3\2\2\2\u0184\u017d\3\2\2\2\u0184\u0185\3\2\2\2\u0185\u0186\3\2\2\2\u0186"+
		"\u0187\5\6\4\2\u0187#\3\2\2\2\u0188\u0189\t\7\2\2\u0189\u019b\5\6\4\2"+
		"\u018a\u018c\7&\2\2\u018b\u018a\3\2\2\2\u018c\u018f\3\2\2\2\u018d\u018b"+
		"\3\2\2\2\u018d\u018e\3\2\2\2\u018e\u0191\3\2\2\2\u018f\u018d\3\2\2\2\u0190"+
		"\u0192\t\7\2\2\u0191\u0190\3\2\2\2\u0191\u0192\3\2\2\2\u0192\u0196\3\2"+
		"\2\2\u0193\u0195\7&\2\2\u0194\u0193\3\2\2\2\u0195\u0198\3\2\2\2\u0196"+
		"\u0194\3\2\2\2\u0196\u0197\3\2\2\2\u0197\u0199\3\2\2\2\u0198\u0196\3\2"+
		"\2\2\u0199\u019b\5(\25\2\u019a\u0188\3\2\2\2\u019a\u018d\3\2\2\2\u019b"+
		"%\3\2\2\2\u019c\u01a0\7\5\2\2\u019d\u019f\7&\2\2\u019e\u019d\3\2\2\2\u019f"+
		"\u01a2\3\2\2\2\u01a0\u019e\3\2\2\2\u01a0\u01a1\3\2\2\2\u01a1\u01a5\3\2"+
		"\2\2\u01a2\u01a0\3\2\2\2\u01a3\u01a6\5(\25\2\u01a4\u01a6\5\6\4\2\u01a5"+
		"\u01a3\3\2\2\2\u01a5\u01a4\3\2\2\2\u01a6\'\3\2\2\2\u01a7\u01ab\7\20\2"+
		"\2\u01a8\u01aa\5\4\3\2\u01a9\u01a8\3\2\2\2\u01aa\u01ad\3\2\2\2\u01ab\u01a9"+
		"\3\2\2\2\u01ab\u01ac\3\2\2\2\u01ac\u01ae\3\2\2\2\u01ad\u01ab\3\2\2\2\u01ae"+
		"\u01af\7\21\2\2\u01af)\3\2\2\2\u01b0\u01b1\7\6\2\2\u01b1+\3\2\2\2\u01b2"+
		"\u01b3\7%\2\2\u01b3\u01b4\5\20\t\2\u01b4-\3\2\2\2\u01b5\u01b6\t\b\2\2"+
		"\u01b6/\3\2\2\2?\63;BGJORUiz|\u0087\u008e\u0095\u009b\u009e\u00a3\u00a7"+
		"\u00ac\u00b0\u00bc\u00c7\u00ce\u00d5\u00db\u00de\u00e3\u00ea\u00ee\u00f3"+
		"\u00f7\u00fc\u0103\u010c\u010f\u0115\u011e\u0125\u012e\u0135\u013a\u013d"+
		"\u0143\u0148\u0155\u015c\u0163\u0169\u016c\u0171\u0175\u017a\u0181\u0184"+
		"\u018d\u0191\u0196\u019a\u01a0\u01a5\u01ab";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}