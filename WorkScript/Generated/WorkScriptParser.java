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
		EQUALS=18, RIGHT_ARROW=19, ASSIGN=20, COLON=21, PLUS=22, MINUS=23, STAR=24, 
		SLASH=25, PERCENT=26, HASH=27, GREATER_THAN=28, GREATER_THAN_EQUAL=29, 
		LESS_THAN=30, LESS_THAN_EQUAL=31, SINGLE_LINE_COMMENT=32, MULTILINE_COMMENT=33, 
		APOSTROPHE=34, NEWLINE=35, WS=36;
	public static final int
		RULE_program = 0, RULE_includeCommand = 1, RULE_expression = 2, RULE_callExpression = 3, 
		RULE_multiValueExpression = 4, RULE_numberExpression = 5, RULE_stringExpression = 6, 
		RULE_variableExpression = 7, RULE_stdFunctionDeclExpression = 8, RULE_stdFormalParameterExpression = 9, 
		RULE_stdFormalParameterItem = 10, RULE_functionExpression = 11, RULE_functionDeclarationExpression = 12, 
		RULE_typeName = 13, RULE_functionName = 14, RULE_formalParameterExpression = 15, 
		RULE_formalParameterItem = 16, RULE_functionImplementationExpression = 17, 
		RULE_functionConstraintExpression = 18, RULE_blockExpression = 19, RULE_booleanExpression = 20, 
		RULE_varargsExpression = 21, RULE_identifier = 22;
	public static final String[] ruleNames = {
		"program", "includeCommand", "expression", "callExpression", "multiValueExpression", 
		"numberExpression", "stringExpression", "variableExpression", "stdFunctionDeclExpression", 
		"stdFormalParameterExpression", "stdFormalParameterItem", "functionExpression", 
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
		"EQUALS", "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", "STAR", "SLASH", 
		"PERCENT", "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", 
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
			setState(53);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					setState(51);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case HASH:
						{
						setState(46);
						includeCommand();
						setState(48);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
						case 1:
							{
							setState(47);
							match(NEWLINE);
							}
							break;
						}
						}
						break;
					case NEWLINE:
						{
						setState(50);
						match(NEWLINE);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					} 
				}
				setState(55);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			setState(63);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS) | (1L << NEWLINE))) != 0)) {
				{
				setState(61);
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
					setState(56);
					expression(0);
					setState(58);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						setState(57);
						match(NEWLINE);
						}
						break;
					}
					}
					break;
				case NEWLINE:
					{
					setState(60);
					match(NEWLINE);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(65);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(66);
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
			setState(68);
			match(HASH);
			setState(69);
			match(INCLUDE);
			setState(70);
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
			setState(90);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				_localctx = new AccessLevelExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(73);
				match(ACCESS_LEVEL);
				setState(74);
				match(COLON);
				}
				break;
			case 2:
				{
				_localctx = new ParentheseExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(75);
				match(LEFT_PARENTHESE);
				setState(76);
				expression(0);
				setState(77);
				match(RIGHT_PARENTHESE);
				}
				break;
			case 3:
				{
				_localctx = new StdFunctionDeclExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(79);
				stdFunctionDeclExpression();
				}
				break;
			case 4:
				{
				_localctx = new FunctionExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(80);
				functionExpression();
				}
				break;
			case 5:
				{
				_localctx = new CallExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(81);
				callExpression();
				}
				break;
			case 6:
				{
				_localctx = new NumberExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(82);
				numberExpression();
				}
				break;
			case 7:
				{
				_localctx = new NegativeExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(83);
				match(MINUS);
				setState(84);
				expression(8);
				}
				break;
			case 8:
				{
				_localctx = new PositiveExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(85);
				match(PLUS);
				setState(86);
				expression(7);
				}
				break;
			case 9:
				{
				_localctx = new StringExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(87);
				stringExpression();
				}
				break;
			case 10:
				{
				_localctx = new BooleanExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(88);
				booleanExpression();
				}
				break;
			case 11:
				{
				_localctx = new VariableExpression_Context(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(89);
				variableExpression();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(109);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(107);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplyDivideModulusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(92);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(93);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STAR) | (1L << SLASH) | (1L << PERCENT))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(94);
						expression(12);
						}
						break;
					case 2:
						{
						_localctx = new PlusMinusExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(95);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(96);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(97);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new AssignmentExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(98);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(99);
						match(ASSIGN);
						setState(100);
						expression(7);
						}
						break;
					case 4:
						{
						_localctx = new AssignmentOrEqualsExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(101);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(102);
						match(EQUALS);
						setState(103);
						expression(6);
						}
						break;
					case 5:
						{
						_localctx = new BinaryCompareExpressionContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(104);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(105);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_EQUAL) | (1L << GREATER_THAN) | (1L << GREATER_THAN_EQUAL) | (1L << LESS_THAN) | (1L << LESS_THAN_EQUAL))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(106);
						expression(5);
						}
						break;
					}
					} 
				}
				setState(111);
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
			setState(112);
			identifier();
			setState(113);
			match(LEFT_PARENTHESE);
			setState(114);
			multiValueExpression();
			setState(115);
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
			setState(143);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
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
				expression(0);
				setState(140);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(127);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
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
							_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
						}
						setState(130);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(134);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(131);
							match(NEWLINE);
							}
							}
							setState(136);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(137);
						expression(0);
						}
						} 
					}
					setState(142);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				}
				}
				break;
			}
			setState(148);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(145);
					match(NEWLINE);
					}
					} 
				}
				setState(150);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			setState(152);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(151);
				match(COMMA);
				}
			}

			setState(157);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(154);
				match(NEWLINE);
				}
				}
				setState(159);
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
			setState(161);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PLUS || _la==MINUS) {
				{
				setState(160);
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

			setState(163);
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
			setState(165);
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
			setState(167);
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
			setState(169);
			typeName();
			setState(173);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==STAR) {
				{
				{
				setState(170);
				match(STAR);
				}
				}
				setState(175);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(176);
			functionName();
			setState(177);
			match(LEFT_PARENTHESE);
			setState(178);
			stdFormalParameterExpression();
			setState(179);
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
			setState(184);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(181);
					match(NEWLINE);
					}
					} 
				}
				setState(186);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			setState(207);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
				{
				setState(187);
				stdFormalParameterItem();
				setState(204);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(191);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
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
							_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
						}
						setState(194);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(198);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(195);
							match(NEWLINE);
							}
							}
							setState(200);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(201);
						stdFormalParameterItem();
						}
						} 
					}
					setState(206);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
				}
				}
			}

			setState(223);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				{
				setState(212);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(209);
						match(NEWLINE);
						}
						} 
					}
					setState(214);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
				}
				setState(215);
				_la = _input.LA(1);
				if ( !(_la==COMMA || _la==NEWLINE) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(219);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(216);
					match(NEWLINE);
					}
					}
					setState(221);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(222);
				match(APOSTROPHE);
				}
				break;
			}
			setState(228);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
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
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			}
			setState(232);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(231);
				match(COMMA);
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
			setState(240);
			typeName();
			setState(244);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==STAR) {
				{
				{
				setState(241);
				match(STAR);
				}
				}
				setState(246);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(247);
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
			setState(299);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,38,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(256);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
				case 1:
					{
					setState(249);
					functionConstraintExpression();
					setState(253);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==NEWLINE) {
						{
						{
						setState(250);
						match(NEWLINE);
						}
						}
						setState(255);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				}
				setState(258);
				functionDeclarationExpression();
				setState(262);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(259);
						match(NEWLINE);
						}
						} 
					}
					setState(264);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
				}
				setState(265);
				functionImplementationExpression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(267);
				functionDeclarationExpression();
				setState(271);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(268);
					match(NEWLINE);
					}
					}
					setState(273);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(274);
				functionConstraintExpression();
				setState(278);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(275);
						match(NEWLINE);
						}
						} 
					}
					setState(280);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
				}
				setState(281);
				functionImplementationExpression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(283);
				functionDeclarationExpression();
				setState(287);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(284);
						match(NEWLINE);
						}
						} 
					}
					setState(289);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
				}
				setState(290);
				functionImplementationExpression();
				setState(294);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(291);
					match(NEWLINE);
					}
					}
					setState(296);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(297);
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
			setState(313);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,41,_ctx) ) {
			case 1:
				{
				setState(302);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
					{
					setState(301);
					functionName();
					}
				}

				}
				break;
			case 2:
				{
				setState(304);
				typeName();
				setState(308);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==STAR) {
					{
					{
					setState(305);
					match(STAR);
					}
					}
					setState(310);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(311);
				functionName();
				}
				break;
			}
			setState(315);
			match(LEFT_PARENTHESE);
			setState(316);
			formalParameterExpression();
			setState(317);
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
			setState(319);
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
			setState(321);
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
			setState(326);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,42,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(323);
					match(NEWLINE);
					}
					} 
				}
				setState(328);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,42,_ctx);
			}
			setState(349);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS))) != 0)) {
				{
				setState(329);
				formalParameterItem();
				setState(346);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(333);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,43,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(330);
								match(NEWLINE);
								}
								} 
							}
							setState(335);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,43,_ctx);
						}
						setState(336);
						_la = _input.LA(1);
						if ( !(_la==COMMA || _la==NEWLINE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(340);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(337);
							match(NEWLINE);
							}
							}
							setState(342);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(343);
						formalParameterItem();
						}
						} 
					}
					setState(348);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
				}
				}
			}

			setState(354);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,47,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(351);
					match(NEWLINE);
					}
					} 
				}
				setState(356);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,47,_ctx);
			}
			setState(358);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(357);
				match(COMMA);
				}
			}

			setState(363);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(360);
				match(NEWLINE);
				}
				}
				setState(365);
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
			setState(373);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,51,_ctx) ) {
			case 1:
				{
				setState(366);
				typeName();
				setState(370);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==STAR) {
					{
					{
					setState(367);
					match(STAR);
					}
					}
					setState(372);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			}
			setState(375);
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
		enterRule(_localctx, 34, RULE_functionImplementationExpression);
		int _la;
		try {
			int _alt;
			setState(395);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,55,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(377);
				_la = _input.LA(1);
				if ( !(_la==EQUALS || _la==RIGHT_ARROW) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(378);
				expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(382);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,52,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(379);
						match(NEWLINE);
						}
						} 
					}
					setState(384);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,52,_ctx);
				}
				setState(386);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==EQUALS || _la==RIGHT_ARROW) {
					{
					setState(385);
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

				setState(391);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(388);
					match(NEWLINE);
					}
					}
					setState(393);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(394);
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
		enterRule(_localctx, 36, RULE_functionConstraintExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(397);
			match(WHEN);
			setState(401);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(398);
				match(NEWLINE);
				}
				}
				setState(403);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(406);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LEFT_BRACE:
				{
				setState(404);
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
				setState(405);
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
		enterRule(_localctx, 38, RULE_blockExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(408);
			match(LEFT_BRACE);
			setState(412);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,58,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(409);
					match(NEWLINE);
					}
					} 
				}
				setState(414);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,58,_ctx);
			}
			setState(427);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ACCESS_LEVEL) | (1L << INCLUDE) | (1L << WHEN) | (1L << BOOLEAN) | (1L << IDENTIFIER) | (1L << DOUBLE) | (1L << INTEGER) | (1L << STRING) | (1L << LEFT_PARENTHESE) | (1L << PLUS) | (1L << MINUS))) != 0)) {
				{
				setState(423);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,60,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(415);
						expression(0);
						setState(417); 
						_errHandler.sync(this);
						_la = _input.LA(1);
						do {
							{
							{
							setState(416);
							match(NEWLINE);
							}
							}
							setState(419); 
							_errHandler.sync(this);
							_la = _input.LA(1);
						} while ( _la==NEWLINE );
						}
						} 
					}
					setState(425);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,60,_ctx);
				}
				setState(426);
				expression(0);
				}
			}

			setState(432);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(429);
				match(NEWLINE);
				}
				}
				setState(434);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(435);
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
			setState(437);
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
			setState(439);
			match(APOSTROPHE);
			setState(440);
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
			setState(442);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3&\u01bf\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\3\2\3\2\5"+
		"\2\63\n\2\3\2\7\2\66\n\2\f\2\16\29\13\2\3\2\3\2\5\2=\n\2\3\2\7\2@\n\2"+
		"\f\2\16\2C\13\2\3\2\3\2\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4]\n\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4n\n\4\f\4\16\4q\13\4\3\5"+
		"\3\5\3\5\3\5\3\5\3\6\7\6y\n\6\f\6\16\6|\13\6\3\6\3\6\7\6\u0080\n\6\f\6"+
		"\16\6\u0083\13\6\3\6\3\6\7\6\u0087\n\6\f\6\16\6\u008a\13\6\3\6\7\6\u008d"+
		"\n\6\f\6\16\6\u0090\13\6\5\6\u0092\n\6\3\6\7\6\u0095\n\6\f\6\16\6\u0098"+
		"\13\6\3\6\5\6\u009b\n\6\3\6\7\6\u009e\n\6\f\6\16\6\u00a1\13\6\3\7\5\7"+
		"\u00a4\n\7\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\7\n\u00ae\n\n\f\n\16\n\u00b1"+
		"\13\n\3\n\3\n\3\n\3\n\3\n\3\13\7\13\u00b9\n\13\f\13\16\13\u00bc\13\13"+
		"\3\13\3\13\7\13\u00c0\n\13\f\13\16\13\u00c3\13\13\3\13\3\13\7\13\u00c7"+
		"\n\13\f\13\16\13\u00ca\13\13\3\13\7\13\u00cd\n\13\f\13\16\13\u00d0\13"+
		"\13\5\13\u00d2\n\13\3\13\7\13\u00d5\n\13\f\13\16\13\u00d8\13\13\3\13\3"+
		"\13\7\13\u00dc\n\13\f\13\16\13\u00df\13\13\3\13\5\13\u00e2\n\13\3\13\7"+
		"\13\u00e5\n\13\f\13\16\13\u00e8\13\13\3\13\5\13\u00eb\n\13\3\13\7\13\u00ee"+
		"\n\13\f\13\16\13\u00f1\13\13\3\f\3\f\7\f\u00f5\n\f\f\f\16\f\u00f8\13\f"+
		"\3\f\3\f\3\r\3\r\7\r\u00fe\n\r\f\r\16\r\u0101\13\r\5\r\u0103\n\r\3\r\3"+
		"\r\7\r\u0107\n\r\f\r\16\r\u010a\13\r\3\r\3\r\3\r\3\r\7\r\u0110\n\r\f\r"+
		"\16\r\u0113\13\r\3\r\3\r\7\r\u0117\n\r\f\r\16\r\u011a\13\r\3\r\3\r\3\r"+
		"\3\r\7\r\u0120\n\r\f\r\16\r\u0123\13\r\3\r\3\r\7\r\u0127\n\r\f\r\16\r"+
		"\u012a\13\r\3\r\3\r\5\r\u012e\n\r\3\16\5\16\u0131\n\16\3\16\3\16\7\16"+
		"\u0135\n\16\f\16\16\16\u0138\13\16\3\16\3\16\5\16\u013c\n\16\3\16\3\16"+
		"\3\16\3\16\3\17\3\17\3\20\3\20\3\21\7\21\u0147\n\21\f\21\16\21\u014a\13"+
		"\21\3\21\3\21\7\21\u014e\n\21\f\21\16\21\u0151\13\21\3\21\3\21\7\21\u0155"+
		"\n\21\f\21\16\21\u0158\13\21\3\21\7\21\u015b\n\21\f\21\16\21\u015e\13"+
		"\21\5\21\u0160\n\21\3\21\7\21\u0163\n\21\f\21\16\21\u0166\13\21\3\21\5"+
		"\21\u0169\n\21\3\21\7\21\u016c\n\21\f\21\16\21\u016f\13\21\3\22\3\22\7"+
		"\22\u0173\n\22\f\22\16\22\u0176\13\22\5\22\u0178\n\22\3\22\3\22\3\23\3"+
		"\23\3\23\7\23\u017f\n\23\f\23\16\23\u0182\13\23\3\23\5\23\u0185\n\23\3"+
		"\23\7\23\u0188\n\23\f\23\16\23\u018b\13\23\3\23\5\23\u018e\n\23\3\24\3"+
		"\24\7\24\u0192\n\24\f\24\16\24\u0195\13\24\3\24\3\24\5\24\u0199\n\24\3"+
		"\25\3\25\7\25\u019d\n\25\f\25\16\25\u01a0\13\25\3\25\3\25\6\25\u01a4\n"+
		"\25\r\25\16\25\u01a5\7\25\u01a8\n\25\f\25\16\25\u01ab\13\25\3\25\5\25"+
		"\u01ae\n\25\3\25\7\25\u01b1\n\25\f\25\16\25\u01b4\13\25\3\25\3\25\3\26"+
		"\3\26\3\27\3\27\3\27\3\30\3\30\3\30\2\3\6\31\2\4\6\b\n\f\16\20\22\24\26"+
		"\30\32\34\36 \"$&(*,.\2\t\3\2\32\34\3\2\30\31\4\2\23\23\36!\4\2\f\f%%"+
		"\3\2\b\t\3\2\24\25\3\2\3\7\2\u01f3\2\67\3\2\2\2\4F\3\2\2\2\6\\\3\2\2\2"+
		"\br\3\2\2\2\n\u0091\3\2\2\2\f\u00a3\3\2\2\2\16\u00a7\3\2\2\2\20\u00a9"+
		"\3\2\2\2\22\u00ab\3\2\2\2\24\u00ba\3\2\2\2\26\u00f2\3\2\2\2\30\u012d\3"+
		"\2\2\2\32\u013b\3\2\2\2\34\u0141\3\2\2\2\36\u0143\3\2\2\2 \u0148\3\2\2"+
		"\2\"\u0177\3\2\2\2$\u018d\3\2\2\2&\u018f\3\2\2\2(\u019a\3\2\2\2*\u01b7"+
		"\3\2\2\2,\u01b9\3\2\2\2.\u01bc\3\2\2\2\60\62\5\4\3\2\61\63\7%\2\2\62\61"+
		"\3\2\2\2\62\63\3\2\2\2\63\66\3\2\2\2\64\66\7%\2\2\65\60\3\2\2\2\65\64"+
		"\3\2\2\2\669\3\2\2\2\67\65\3\2\2\2\678\3\2\2\28A\3\2\2\29\67\3\2\2\2:"+
		"<\5\6\4\2;=\7%\2\2<;\3\2\2\2<=\3\2\2\2=@\3\2\2\2>@\7%\2\2?:\3\2\2\2?>"+
		"\3\2\2\2@C\3\2\2\2A?\3\2\2\2AB\3\2\2\2BD\3\2\2\2CA\3\2\2\2DE\7\2\2\3E"+
		"\3\3\2\2\2FG\7\35\2\2GH\7\4\2\2HI\7\n\2\2I\5\3\2\2\2JK\b\4\1\2KL\7\3\2"+
		"\2L]\7\27\2\2MN\7\r\2\2NO\5\6\4\2OP\7\16\2\2P]\3\2\2\2Q]\5\22\n\2R]\5"+
		"\30\r\2S]\5\b\5\2T]\5\f\7\2UV\7\31\2\2V]\5\6\4\nWX\7\30\2\2X]\5\6\4\t"+
		"Y]\5\16\b\2Z]\5*\26\2[]\5\20\t\2\\J\3\2\2\2\\M\3\2\2\2\\Q\3\2\2\2\\R\3"+
		"\2\2\2\\S\3\2\2\2\\T\3\2\2\2\\U\3\2\2\2\\W\3\2\2\2\\Y\3\2\2\2\\Z\3\2\2"+
		"\2\\[\3\2\2\2]o\3\2\2\2^_\f\r\2\2_`\t\2\2\2`n\5\6\4\16ab\f\f\2\2bc\t\3"+
		"\2\2cn\5\6\4\rde\f\b\2\2ef\7\26\2\2fn\5\6\4\tgh\f\7\2\2hi\7\24\2\2in\5"+
		"\6\4\bjk\f\6\2\2kl\t\4\2\2ln\5\6\4\7m^\3\2\2\2ma\3\2\2\2md\3\2\2\2mg\3"+
		"\2\2\2mj\3\2\2\2nq\3\2\2\2om\3\2\2\2op\3\2\2\2p\7\3\2\2\2qo\3\2\2\2rs"+
		"\5.\30\2st\7\r\2\2tu\5\n\6\2uv\7\16\2\2v\t\3\2\2\2wy\7%\2\2xw\3\2\2\2"+
		"y|\3\2\2\2zx\3\2\2\2z{\3\2\2\2{}\3\2\2\2|z\3\2\2\2}\u008e\5\6\4\2~\u0080"+
		"\7%\2\2\177~\3\2\2\2\u0080\u0083\3\2\2\2\u0081\177\3\2\2\2\u0081\u0082"+
		"\3\2\2\2\u0082\u0084\3\2\2\2\u0083\u0081\3\2\2\2\u0084\u0088\t\5\2\2\u0085"+
		"\u0087\7%\2\2\u0086\u0085\3\2\2\2\u0087\u008a\3\2\2\2\u0088\u0086\3\2"+
		"\2\2\u0088\u0089\3\2\2\2\u0089\u008b\3\2\2\2\u008a\u0088\3\2\2\2\u008b"+
		"\u008d\5\6\4\2\u008c\u0081\3\2\2\2\u008d\u0090\3\2\2\2\u008e\u008c\3\2"+
		"\2\2\u008e\u008f\3\2\2\2\u008f\u0092\3\2\2\2\u0090\u008e\3\2\2\2\u0091"+
		"z\3\2\2\2\u0091\u0092\3\2\2\2\u0092\u0096\3\2\2\2\u0093\u0095\7%\2\2\u0094"+
		"\u0093\3\2\2\2\u0095\u0098\3\2\2\2\u0096\u0094\3\2\2\2\u0096\u0097\3\2"+
		"\2\2\u0097\u009a\3\2\2\2\u0098\u0096\3\2\2\2\u0099\u009b\7\f\2\2\u009a"+
		"\u0099\3\2\2\2\u009a\u009b\3\2\2\2\u009b\u009f\3\2\2\2\u009c\u009e\7%"+
		"\2\2\u009d\u009c\3\2\2\2\u009e\u00a1\3\2\2\2\u009f\u009d\3\2\2\2\u009f"+
		"\u00a0\3\2\2\2\u00a0\13\3\2\2\2\u00a1\u009f\3\2\2\2\u00a2\u00a4\t\3\2"+
		"\2\u00a3\u00a2\3\2\2\2\u00a3\u00a4\3\2\2\2\u00a4\u00a5\3\2\2\2\u00a5\u00a6"+
		"\t\6\2\2\u00a6\r\3\2\2\2\u00a7\u00a8\7\n\2\2\u00a8\17\3\2\2\2\u00a9\u00aa"+
		"\5.\30\2\u00aa\21\3\2\2\2\u00ab\u00af\5\34\17\2\u00ac\u00ae\7\32\2\2\u00ad"+
		"\u00ac\3\2\2\2\u00ae\u00b1\3\2\2\2\u00af\u00ad\3\2\2\2\u00af\u00b0\3\2"+
		"\2\2\u00b0\u00b2\3\2\2\2\u00b1\u00af\3\2\2\2\u00b2\u00b3\5\36\20\2\u00b3"+
		"\u00b4\7\r\2\2\u00b4\u00b5\5\24\13\2\u00b5\u00b6\7\16\2\2\u00b6\23\3\2"+
		"\2\2\u00b7\u00b9\7%\2\2\u00b8\u00b7\3\2\2\2\u00b9\u00bc\3\2\2\2\u00ba"+
		"\u00b8\3\2\2\2\u00ba\u00bb\3\2\2\2\u00bb\u00d1\3\2\2\2\u00bc\u00ba\3\2"+
		"\2\2\u00bd\u00ce\5\26\f\2\u00be\u00c0\7%\2\2\u00bf\u00be\3\2\2\2\u00c0"+
		"\u00c3\3\2\2\2\u00c1\u00bf\3\2\2\2\u00c1\u00c2\3\2\2\2\u00c2\u00c4\3\2"+
		"\2\2\u00c3\u00c1\3\2\2\2\u00c4\u00c8\t\5\2\2\u00c5\u00c7\7%\2\2\u00c6"+
		"\u00c5\3\2\2\2\u00c7\u00ca\3\2\2\2\u00c8\u00c6\3\2\2\2\u00c8\u00c9\3\2"+
		"\2\2\u00c9\u00cb\3\2\2\2\u00ca\u00c8\3\2\2\2\u00cb\u00cd\5\26\f\2\u00cc"+
		"\u00c1\3\2\2\2\u00cd\u00d0\3\2\2\2\u00ce\u00cc\3\2\2\2\u00ce\u00cf\3\2"+
		"\2\2\u00cf\u00d2\3\2\2\2\u00d0\u00ce\3\2\2\2\u00d1\u00bd\3\2\2\2\u00d1"+
		"\u00d2\3\2\2\2\u00d2\u00e1\3\2\2\2\u00d3\u00d5\7%\2\2\u00d4\u00d3\3\2"+
		"\2\2\u00d5\u00d8\3\2\2\2\u00d6\u00d4\3\2\2\2\u00d6\u00d7\3\2\2\2\u00d7"+
		"\u00d9\3\2\2\2\u00d8\u00d6\3\2\2\2\u00d9\u00dd\t\5\2\2\u00da\u00dc\7%"+
		"\2\2\u00db\u00da\3\2\2\2\u00dc\u00df\3\2\2\2\u00dd\u00db\3\2\2\2\u00dd"+
		"\u00de\3\2\2\2\u00de\u00e0\3\2\2\2\u00df\u00dd\3\2\2\2\u00e0\u00e2\7$"+
		"\2\2\u00e1\u00d6\3\2\2\2\u00e1\u00e2\3\2\2\2\u00e2\u00e6\3\2\2\2\u00e3"+
		"\u00e5\7%\2\2\u00e4\u00e3\3\2\2\2\u00e5\u00e8\3\2\2\2\u00e6\u00e4\3\2"+
		"\2\2\u00e6\u00e7\3\2\2\2\u00e7\u00ea\3\2\2\2\u00e8\u00e6\3\2\2\2\u00e9"+
		"\u00eb\7\f\2\2\u00ea\u00e9\3\2\2\2\u00ea\u00eb\3\2\2\2\u00eb\u00ef\3\2"+
		"\2\2\u00ec\u00ee\7%\2\2\u00ed\u00ec\3\2\2\2\u00ee\u00f1\3\2\2\2\u00ef"+
		"\u00ed\3\2\2\2\u00ef\u00f0\3\2\2\2\u00f0\25\3\2\2\2\u00f1\u00ef\3\2\2"+
		"\2\u00f2\u00f6\5\34\17\2\u00f3\u00f5\7\32\2\2\u00f4\u00f3\3\2\2\2\u00f5"+
		"\u00f8\3\2\2\2\u00f6\u00f4\3\2\2\2\u00f6\u00f7\3\2\2\2\u00f7\u00f9\3\2"+
		"\2\2\u00f8\u00f6\3\2\2\2\u00f9\u00fa\5.\30\2\u00fa\27\3\2\2\2\u00fb\u00ff"+
		"\5&\24\2\u00fc\u00fe\7%\2\2\u00fd\u00fc\3\2\2\2\u00fe\u0101\3\2\2\2\u00ff"+
		"\u00fd\3\2\2\2\u00ff\u0100\3\2\2\2\u0100\u0103\3\2\2\2\u0101\u00ff\3\2"+
		"\2\2\u0102\u00fb\3\2\2\2\u0102\u0103\3\2\2\2\u0103\u0104\3\2\2\2\u0104"+
		"\u0108\5\32\16\2\u0105\u0107\7%\2\2\u0106\u0105\3\2\2\2\u0107\u010a\3"+
		"\2\2\2\u0108\u0106\3\2\2\2\u0108\u0109\3\2\2\2\u0109\u010b\3\2\2\2\u010a"+
		"\u0108\3\2\2\2\u010b\u010c\5$\23\2\u010c\u012e\3\2\2\2\u010d\u0111\5\32"+
		"\16\2\u010e\u0110\7%\2\2\u010f\u010e\3\2\2\2\u0110\u0113\3\2\2\2\u0111"+
		"\u010f\3\2\2\2\u0111\u0112\3\2\2\2\u0112\u0114\3\2\2\2\u0113\u0111\3\2"+
		"\2\2\u0114\u0118\5&\24\2\u0115\u0117\7%\2\2\u0116\u0115\3\2\2\2\u0117"+
		"\u011a\3\2\2\2\u0118\u0116\3\2\2\2\u0118\u0119\3\2\2\2\u0119\u011b\3\2"+
		"\2\2\u011a\u0118\3\2\2\2\u011b\u011c\5$\23\2\u011c\u012e\3\2\2\2\u011d"+
		"\u0121\5\32\16\2\u011e\u0120\7%\2\2\u011f\u011e\3\2\2\2\u0120\u0123\3"+
		"\2\2\2\u0121\u011f\3\2\2\2\u0121\u0122\3\2\2\2\u0122\u0124\3\2\2\2\u0123"+
		"\u0121\3\2\2\2\u0124\u0128\5$\23\2\u0125\u0127\7%\2\2\u0126\u0125\3\2"+
		"\2\2\u0127\u012a\3\2\2\2\u0128\u0126\3\2\2\2\u0128\u0129\3\2\2\2\u0129"+
		"\u012b\3\2\2\2\u012a\u0128\3\2\2\2\u012b\u012c\5&\24\2\u012c\u012e\3\2"+
		"\2\2\u012d\u0102\3\2\2\2\u012d\u010d\3\2\2\2\u012d\u011d\3\2\2\2\u012e"+
		"\31\3\2\2\2\u012f\u0131\5\36\20\2\u0130\u012f\3\2\2\2\u0130\u0131\3\2"+
		"\2\2\u0131\u013c\3\2\2\2\u0132\u0136\5\34\17\2\u0133\u0135\7\32\2\2\u0134"+
		"\u0133\3\2\2\2\u0135\u0138\3\2\2\2\u0136\u0134\3\2\2\2\u0136\u0137\3\2"+
		"\2\2\u0137\u0139\3\2\2\2\u0138\u0136\3\2\2\2\u0139\u013a\5\36\20\2\u013a"+
		"\u013c\3\2\2\2\u013b\u0130\3\2\2\2\u013b\u0132\3\2\2\2\u013c\u013d\3\2"+
		"\2\2\u013d\u013e\7\r\2\2\u013e\u013f\5 \21\2\u013f\u0140\7\16\2\2\u0140"+
		"\33\3\2\2\2\u0141\u0142\5.\30\2\u0142\35\3\2\2\2\u0143\u0144\5.\30\2\u0144"+
		"\37\3\2\2\2\u0145\u0147\7%\2\2\u0146\u0145\3\2\2\2\u0147\u014a\3\2\2\2"+
		"\u0148\u0146\3\2\2\2\u0148\u0149\3\2\2\2\u0149\u015f\3\2\2\2\u014a\u0148"+
		"\3\2\2\2\u014b\u015c\5\"\22\2\u014c\u014e\7%\2\2\u014d\u014c\3\2\2\2\u014e"+
		"\u0151\3\2\2\2\u014f\u014d\3\2\2\2\u014f\u0150\3\2\2\2\u0150\u0152\3\2"+
		"\2\2\u0151\u014f\3\2\2\2\u0152\u0156\t\5\2\2\u0153\u0155\7%\2\2\u0154"+
		"\u0153\3\2\2\2\u0155\u0158\3\2\2\2\u0156\u0154\3\2\2\2\u0156\u0157\3\2"+
		"\2\2\u0157\u0159\3\2\2\2\u0158\u0156\3\2\2\2\u0159\u015b\5\"\22\2\u015a"+
		"\u014f\3\2\2\2\u015b\u015e\3\2\2\2\u015c\u015a\3\2\2\2\u015c\u015d\3\2"+
		"\2\2\u015d\u0160\3\2\2\2\u015e\u015c\3\2\2\2\u015f\u014b\3\2\2\2\u015f"+
		"\u0160\3\2\2\2\u0160\u0164\3\2\2\2\u0161\u0163\7%\2\2\u0162\u0161\3\2"+
		"\2\2\u0163\u0166\3\2\2\2\u0164\u0162\3\2\2\2\u0164\u0165\3\2\2\2\u0165"+
		"\u0168\3\2\2\2\u0166\u0164\3\2\2\2\u0167\u0169\7\f\2\2\u0168\u0167\3\2"+
		"\2\2\u0168\u0169\3\2\2\2\u0169\u016d\3\2\2\2\u016a\u016c\7%\2\2\u016b"+
		"\u016a\3\2\2\2\u016c\u016f\3\2\2\2\u016d\u016b\3\2\2\2\u016d\u016e\3\2"+
		"\2\2\u016e!\3\2\2\2\u016f\u016d\3\2\2\2\u0170\u0174\5\34\17\2\u0171\u0173"+
		"\7\32\2\2\u0172\u0171\3\2\2\2\u0173\u0176\3\2\2\2\u0174\u0172\3\2\2\2"+
		"\u0174\u0175\3\2\2\2\u0175\u0178\3\2\2\2\u0176\u0174\3\2\2\2\u0177\u0170"+
		"\3\2\2\2\u0177\u0178\3\2\2\2\u0178\u0179\3\2\2\2\u0179\u017a\5\6\4\2\u017a"+
		"#\3\2\2\2\u017b\u017c\t\7\2\2\u017c\u018e\5\6\4\2\u017d\u017f\7%\2\2\u017e"+
		"\u017d\3\2\2\2\u017f\u0182\3\2\2\2\u0180\u017e\3\2\2\2\u0180\u0181\3\2"+
		"\2\2\u0181\u0184\3\2\2\2\u0182\u0180\3\2\2\2\u0183\u0185\t\7\2\2\u0184"+
		"\u0183\3\2\2\2\u0184\u0185\3\2\2\2\u0185\u0189\3\2\2\2\u0186\u0188\7%"+
		"\2\2\u0187\u0186\3\2\2\2\u0188\u018b\3\2\2\2\u0189\u0187\3\2\2\2\u0189"+
		"\u018a\3\2\2\2\u018a\u018c\3\2\2\2\u018b\u0189\3\2\2\2\u018c\u018e\5("+
		"\25\2\u018d\u017b\3\2\2\2\u018d\u0180\3\2\2\2\u018e%\3\2\2\2\u018f\u0193"+
		"\7\5\2\2\u0190\u0192\7%\2\2\u0191\u0190\3\2\2\2\u0192\u0195\3\2\2\2\u0193"+
		"\u0191\3\2\2\2\u0193\u0194\3\2\2\2\u0194\u0198\3\2\2\2\u0195\u0193\3\2"+
		"\2\2\u0196\u0199\5(\25\2\u0197\u0199\5\6\4\2\u0198\u0196\3\2\2\2\u0198"+
		"\u0197\3\2\2\2\u0199\'\3\2\2\2\u019a\u019e\7\17\2\2\u019b\u019d\7%\2\2"+
		"\u019c\u019b\3\2\2\2\u019d\u01a0\3\2\2\2\u019e\u019c\3\2\2\2\u019e\u019f"+
		"\3\2\2\2\u019f\u01ad\3\2\2\2\u01a0\u019e\3\2\2\2\u01a1\u01a3\5\6\4\2\u01a2"+
		"\u01a4\7%\2\2\u01a3\u01a2\3\2\2\2\u01a4\u01a5\3\2\2\2\u01a5\u01a3\3\2"+
		"\2\2\u01a5\u01a6\3\2\2\2\u01a6\u01a8\3\2\2\2\u01a7\u01a1\3\2\2\2\u01a8"+
		"\u01ab\3\2\2\2\u01a9\u01a7\3\2\2\2\u01a9\u01aa\3\2\2\2\u01aa\u01ac\3\2"+
		"\2\2\u01ab\u01a9\3\2\2\2\u01ac\u01ae\5\6\4\2\u01ad\u01a9\3\2\2\2\u01ad"+
		"\u01ae\3\2\2\2\u01ae\u01b2\3\2\2\2\u01af\u01b1\7%\2\2\u01b0\u01af\3\2"+
		"\2\2\u01b1\u01b4\3\2\2\2\u01b2\u01b0\3\2\2\2\u01b2\u01b3\3\2\2\2\u01b3"+
		"\u01b5\3\2\2\2\u01b4\u01b2\3\2\2\2\u01b5\u01b6\7\20\2\2\u01b6)\3\2\2\2"+
		"\u01b7\u01b8\7\6\2\2\u01b8+\3\2\2\2\u01b9\u01ba\7$\2\2\u01ba\u01bb\5\20"+
		"\t\2\u01bb-\3\2\2\2\u01bc\u01bd\t\b\2\2\u01bd/\3\2\2\2A\62\65\67<?A\\"+
		"moz\u0081\u0088\u008e\u0091\u0096\u009a\u009f\u00a3\u00af\u00ba\u00c1"+
		"\u00c8\u00ce\u00d1\u00d6\u00dd\u00e1\u00e6\u00ea\u00ef\u00f6\u00ff\u0102"+
		"\u0108\u0111\u0118\u0121\u0128\u012d\u0130\u0136\u013b\u0148\u014f\u0156"+
		"\u015c\u015f\u0164\u0168\u016d\u0174\u0177\u0180\u0184\u0189\u018d\u0193"+
		"\u0198\u019e\u01a5\u01a9\u01ad\u01b2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}