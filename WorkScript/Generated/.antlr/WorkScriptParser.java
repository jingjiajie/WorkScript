// Generated from c:\Users\Jonas\Desktop\WorkScript\WorkScript\Generated\WorkScript.g4 by ANTLR 4.7.1
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
		IDENTIFIER=1, NUMBER=2, STRING=3, POINT=4, NEWLINE=5, LEFT_PARENTHESE=6, 
		RIGHT_PARENTHESE=7, LEFT_BRACE=8, RIGHT_BRACE=9, EQUALS=10, PLUS=11, MINUS=12, 
		MULTIPLY=13, DIVIDE=14, GREATER_THAN=15, GREATER_THAN_EQUAL=16, LESS_THAN=17, 
		LESS_THAN_EQUAL=18, WS=19;
	public static final int
		RULE_program = 0, RULE_expression = 1, RULE_relationExpression = 2, RULE_polynomialExpression = 3, 
		RULE_termExpression = 4, RULE_parentheseExpression = 5;
	public static final String[] ruleNames = {
		"program", "expression", "relationExpression", "polynomialExpression", 
		"termExpression", "parentheseExpression"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, null, null, "'.'", null, "'('", "')'", "'{'", "'}'", "'='", 
		"'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "IDENTIFIER", "NUMBER", "STRING", "POINT", "NEWLINE", "LEFT_PARENTHESE", 
		"RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "EQUALS", "PLUS", "MINUS", 
		"MULTIPLY", "DIVIDE", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", 
		"LESS_THAN_EQUAL", "WS"
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
		public TerminalNode EOF() { return getToken(WorkScriptParser.EOF, 0); }
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			setState(20);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(16);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << NEWLINE) | (1L << LEFT_PARENTHESE))) != 0)) {
					{
					setState(14);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case IDENTIFIER:
					case NUMBER:
					case STRING:
					case LEFT_PARENTHESE:
						{
						setState(12);
						expression();
						}
						break;
					case NEWLINE:
						{
						setState(13);
						match(NEWLINE);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					setState(18);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(19);
				match(EOF);
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
		public TerminalNode NEWLINE() { return getToken(WorkScriptParser.NEWLINE, 0); }
		public TerminalNode EOF() { return getToken(WorkScriptParser.EOF, 0); }
		public PolynomialExpressionContext polynomialExpression() {
			return getRuleContext(PolynomialExpressionContext.class,0);
		}
		public RelationExpressionContext relationExpression() {
			return getRuleContext(RelationExpressionContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				{
				setState(22);
				polynomialExpression();
				}
				break;
			case 2:
				{
				setState(23);
				relationExpression();
				}
				break;
			}
			setState(26);
			_la = _input.LA(1);
			if ( !(_la==EOF || _la==NEWLINE) ) {
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

	public static class RelationExpressionContext extends ParserRuleContext {
		public List<PolynomialExpressionContext> polynomialExpression() {
			return getRuleContexts(PolynomialExpressionContext.class);
		}
		public PolynomialExpressionContext polynomialExpression(int i) {
			return getRuleContext(PolynomialExpressionContext.class,i);
		}
		public TerminalNode EQUALS() { return getToken(WorkScriptParser.EQUALS, 0); }
		public RelationExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relationExpression; }
	}

	public final RelationExpressionContext relationExpression() throws RecognitionException {
		RelationExpressionContext _localctx = new RelationExpressionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_relationExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(28);
			polynomialExpression();
			setState(29);
			match(EQUALS);
			setState(30);
			polynomialExpression();
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

	public static class PolynomialExpressionContext extends ParserRuleContext {
		public List<TermExpressionContext> termExpression() {
			return getRuleContexts(TermExpressionContext.class);
		}
		public TermExpressionContext termExpression(int i) {
			return getRuleContext(TermExpressionContext.class,i);
		}
		public PolynomialExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_polynomialExpression; }
	}

	public final PolynomialExpressionContext polynomialExpression() throws RecognitionException {
		PolynomialExpressionContext _localctx = new PolynomialExpressionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_polynomialExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(33); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(32);
				termExpression(0);
				}
				}
				setState(35); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE))) != 0) );
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

	public static class TermExpressionContext extends ParserRuleContext {
		public TermExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_termExpression; }
	 
		public TermExpressionContext() { }
		public void copyFrom(TermExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class FunctionPolynomialExpressionContext extends TermExpressionContext {
		public TermExpressionContext termExpression() {
			return getRuleContext(TermExpressionContext.class,0);
		}
		public ParentheseExpressionContext parentheseExpression() {
			return getRuleContext(ParentheseExpressionContext.class,0);
		}
		public FunctionPolynomialExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class MemberEvaluateExpressionContext extends TermExpressionContext {
		public List<TermExpressionContext> termExpression() {
			return getRuleContexts(TermExpressionContext.class);
		}
		public TermExpressionContext termExpression(int i) {
			return getRuleContext(TermExpressionContext.class,i);
		}
		public TerminalNode POINT() { return getToken(WorkScriptParser.POINT, 0); }
		public MemberEvaluateExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class MultiplyDivideExpressionContext extends TermExpressionContext {
		public List<TermExpressionContext> termExpression() {
			return getRuleContexts(TermExpressionContext.class);
		}
		public TermExpressionContext termExpression(int i) {
			return getRuleContext(TermExpressionContext.class,i);
		}
		public TerminalNode MULTIPLY() { return getToken(WorkScriptParser.MULTIPLY, 0); }
		public TerminalNode DIVIDE() { return getToken(WorkScriptParser.DIVIDE, 0); }
		public MultiplyDivideExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class StringExpressionContext extends TermExpressionContext {
		public TerminalNode STRING() { return getToken(WorkScriptParser.STRING, 0); }
		public StringExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class NumberExpressionContext extends TermExpressionContext {
		public TerminalNode NUMBER() { return getToken(WorkScriptParser.NUMBER, 0); }
		public NumberExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class IndependentParentheseExpressionContext extends TermExpressionContext {
		public ParentheseExpressionContext parentheseExpression() {
			return getRuleContext(ParentheseExpressionContext.class,0);
		}
		public IndependentParentheseExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class PlusMinusExpressionContext extends TermExpressionContext {
		public List<TermExpressionContext> termExpression() {
			return getRuleContexts(TermExpressionContext.class);
		}
		public TermExpressionContext termExpression(int i) {
			return getRuleContext(TermExpressionContext.class,i);
		}
		public TerminalNode PLUS() { return getToken(WorkScriptParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(WorkScriptParser.MINUS, 0); }
		public PlusMinusExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class IdentifierExpressionContext extends TermExpressionContext {
		public TerminalNode IDENTIFIER() { return getToken(WorkScriptParser.IDENTIFIER, 0); }
		public IdentifierExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}

	public final TermExpressionContext termExpression() throws RecognitionException {
		return termExpression(0);
	}

	private TermExpressionContext termExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermExpressionContext _localctx = new TermExpressionContext(_ctx, _parentState);
		TermExpressionContext _prevctx = _localctx;
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_termExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(42);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMBER:
				{
				_localctx = new NumberExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(38);
				match(NUMBER);
				}
				break;
			case STRING:
				{
				_localctx = new StringExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(39);
				match(STRING);
				}
				break;
			case IDENTIFIER:
				{
				_localctx = new IdentifierExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(40);
				match(IDENTIFIER);
				}
				break;
			case LEFT_PARENTHESE:
				{
				_localctx = new IndependentParentheseExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(41);
				parentheseExpression();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(57);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(55);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new MemberEvaluateExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(44);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(45);
						match(POINT);
						setState(46);
						termExpression(4);
						}
						break;
					case 2:
						{
						_localctx = new MultiplyDivideExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(47);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(48);
						_la = _input.LA(1);
						if ( !(_la==MULTIPLY || _la==DIVIDE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(49);
						termExpression(3);
						}
						break;
					case 3:
						{
						_localctx = new PlusMinusExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(50);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(51);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(52);
						termExpression(2);
						}
						break;
					case 4:
						{
						_localctx = new FunctionPolynomialExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(53);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(54);
						parentheseExpression();
						}
						break;
					}
					} 
				}
				setState(59);
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

	public static class ParentheseExpressionContext extends ParserRuleContext {
		public TerminalNode LEFT_PARENTHESE() { return getToken(WorkScriptParser.LEFT_PARENTHESE, 0); }
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public PolynomialExpressionContext polynomialExpression() {
			return getRuleContext(PolynomialExpressionContext.class,0);
		}
		public ParentheseExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parentheseExpression; }
	}

	public final ParentheseExpressionContext parentheseExpression() throws RecognitionException {
		ParentheseExpressionContext _localctx = new ParentheseExpressionContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_parentheseExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			match(LEFT_PARENTHESE);
			setState(62);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE))) != 0)) {
				{
				setState(61);
				polynomialExpression();
				}
			}

			setState(64);
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 4:
			return termExpression_sempred((TermExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean termExpression_sempred(TermExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 3);
		case 1:
			return precpred(_ctx, 2);
		case 2:
			return precpred(_ctx, 1);
		case 3:
			return precpred(_ctx, 5);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\25E\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\3\2\3\2\7\2\21\n\2\f\2\16\2\24\13\2"+
		"\3\2\5\2\27\n\2\3\3\3\3\5\3\33\n\3\3\3\3\3\3\4\3\4\3\4\3\4\3\5\6\5$\n"+
		"\5\r\5\16\5%\3\6\3\6\3\6\3\6\3\6\5\6-\n\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6"+
		"\3\6\3\6\3\6\3\6\7\6:\n\6\f\6\16\6=\13\6\3\7\3\7\5\7A\n\7\3\7\3\7\3\7"+
		"\2\3\n\b\2\4\6\b\n\f\2\5\3\3\7\7\3\2\17\20\3\2\r\16\2K\2\26\3\2\2\2\4"+
		"\32\3\2\2\2\6\36\3\2\2\2\b#\3\2\2\2\n,\3\2\2\2\f>\3\2\2\2\16\21\5\4\3"+
		"\2\17\21\7\7\2\2\20\16\3\2\2\2\20\17\3\2\2\2\21\24\3\2\2\2\22\20\3\2\2"+
		"\2\22\23\3\2\2\2\23\27\3\2\2\2\24\22\3\2\2\2\25\27\7\2\2\3\26\22\3\2\2"+
		"\2\26\25\3\2\2\2\27\3\3\2\2\2\30\33\5\b\5\2\31\33\5\6\4\2\32\30\3\2\2"+
		"\2\32\31\3\2\2\2\33\34\3\2\2\2\34\35\t\2\2\2\35\5\3\2\2\2\36\37\5\b\5"+
		"\2\37 \7\f\2\2 !\5\b\5\2!\7\3\2\2\2\"$\5\n\6\2#\"\3\2\2\2$%\3\2\2\2%#"+
		"\3\2\2\2%&\3\2\2\2&\t\3\2\2\2\'(\b\6\1\2(-\7\4\2\2)-\7\5\2\2*-\7\3\2\2"+
		"+-\5\f\7\2,\'\3\2\2\2,)\3\2\2\2,*\3\2\2\2,+\3\2\2\2-;\3\2\2\2./\f\5\2"+
		"\2/\60\7\6\2\2\60:\5\n\6\6\61\62\f\4\2\2\62\63\t\3\2\2\63:\5\n\6\5\64"+
		"\65\f\3\2\2\65\66\t\4\2\2\66:\5\n\6\4\678\f\7\2\28:\5\f\7\29.\3\2\2\2"+
		"9\61\3\2\2\29\64\3\2\2\29\67\3\2\2\2:=\3\2\2\2;9\3\2\2\2;<\3\2\2\2<\13"+
		"\3\2\2\2=;\3\2\2\2>@\7\b\2\2?A\5\b\5\2@?\3\2\2\2@A\3\2\2\2AB\3\2\2\2B"+
		"C\7\t\2\2C\r\3\2\2\2\13\20\22\26\32%,9;@";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}