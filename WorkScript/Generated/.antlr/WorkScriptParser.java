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
		RULE_termExpression = 4;
	public static final String[] ruleNames = {
		"program", "expression", "relationExpression", "polynomialExpression", 
		"termExpression"
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
			setState(18);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(14);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << NEWLINE) | (1L << LEFT_PARENTHESE))) != 0)) {
					{
					setState(12);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case IDENTIFIER:
					case NUMBER:
					case STRING:
					case LEFT_PARENTHESE:
						{
						setState(10);
						expression();
						}
						break;
					case NEWLINE:
						{
						setState(11);
						match(NEWLINE);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					setState(16);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(17);
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
			setState(22);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				{
				setState(20);
				polynomialExpression();
				}
				break;
			case 2:
				{
				setState(21);
				relationExpression();
				}
				break;
			}
			setState(24);
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
			setState(26);
			polynomialExpression();
			setState(27);
			match(EQUALS);
			setState(28);
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
			setState(31); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(30);
				termExpression(0);
				}
				}
				setState(33); 
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
	public static class EvaluatedFunctionExpressionContext extends TermExpressionContext {
		public List<TerminalNode> LEFT_PARENTHESE() { return getTokens(WorkScriptParser.LEFT_PARENTHESE); }
		public TerminalNode LEFT_PARENTHESE(int i) {
			return getToken(WorkScriptParser.LEFT_PARENTHESE, i);
		}
		public List<TerminalNode> RIGHT_PARENTHESE() { return getTokens(WorkScriptParser.RIGHT_PARENTHESE); }
		public TerminalNode RIGHT_PARENTHESE(int i) {
			return getToken(WorkScriptParser.RIGHT_PARENTHESE, i);
		}
		public List<PolynomialExpressionContext> polynomialExpression() {
			return getRuleContexts(PolynomialExpressionContext.class);
		}
		public PolynomialExpressionContext polynomialExpression(int i) {
			return getRuleContext(PolynomialExpressionContext.class,i);
		}
		public EvaluatedFunctionExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class NumberExpressionContext extends TermExpressionContext {
		public TerminalNode NUMBER() { return getToken(WorkScriptParser.NUMBER, 0); }
		public NumberExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class IndependentParentheseExpressionContext extends TermExpressionContext {
		public TerminalNode LEFT_PARENTHESE() { return getToken(WorkScriptParser.LEFT_PARENTHESE, 0); }
		public TerminalNode RIGHT_PARENTHESE() { return getToken(WorkScriptParser.RIGHT_PARENTHESE, 0); }
		public PolynomialExpressionContext polynomialExpression() {
			return getRuleContext(PolynomialExpressionContext.class,0);
		}
		public IndependentParentheseExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class CompareExpressionContext extends TermExpressionContext {
		public List<TermExpressionContext> termExpression() {
			return getRuleContexts(TermExpressionContext.class);
		}
		public TermExpressionContext termExpression(int i) {
			return getRuleContext(TermExpressionContext.class,i);
		}
		public TerminalNode GREATER_THAN() { return getToken(WorkScriptParser.GREATER_THAN, 0); }
		public TerminalNode GREATER_THAN_EQUAL() { return getToken(WorkScriptParser.GREATER_THAN_EQUAL, 0); }
		public TerminalNode LESS_THAN() { return getToken(WorkScriptParser.LESS_THAN, 0); }
		public TerminalNode LESS_THAN_EQUAL() { return getToken(WorkScriptParser.LESS_THAN_EQUAL, 0); }
		public CompareExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class DirectFunctionExpressionContext extends TermExpressionContext {
		public TermExpressionContext termExpression() {
			return getRuleContext(TermExpressionContext.class,0);
		}
		public List<TerminalNode> LEFT_PARENTHESE() { return getTokens(WorkScriptParser.LEFT_PARENTHESE); }
		public TerminalNode LEFT_PARENTHESE(int i) {
			return getToken(WorkScriptParser.LEFT_PARENTHESE, i);
		}
		public List<TerminalNode> RIGHT_PARENTHESE() { return getTokens(WorkScriptParser.RIGHT_PARENTHESE); }
		public TerminalNode RIGHT_PARENTHESE(int i) {
			return getToken(WorkScriptParser.RIGHT_PARENTHESE, i);
		}
		public List<PolynomialExpressionContext> polynomialExpression() {
			return getRuleContexts(PolynomialExpressionContext.class);
		}
		public PolynomialExpressionContext polynomialExpression(int i) {
			return getRuleContext(PolynomialExpressionContext.class,i);
		}
		public DirectFunctionExpressionContext(TermExpressionContext ctx) { copyFrom(ctx); }
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
			setState(58);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				{
				_localctx = new NumberExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(36);
				match(NUMBER);
				}
				break;
			case 2:
				{
				_localctx = new StringExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(37);
				match(STRING);
				}
				break;
			case 3:
				{
				_localctx = new IdentifierExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(38);
				match(IDENTIFIER);
				}
				break;
			case 4:
				{
				_localctx = new EvaluatedFunctionExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(39);
				match(LEFT_PARENTHESE);
				setState(41);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE))) != 0)) {
					{
					setState(40);
					polynomialExpression();
					}
				}

				setState(43);
				match(RIGHT_PARENTHESE);
				setState(49); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(44);
						match(LEFT_PARENTHESE);
						setState(46);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE))) != 0)) {
							{
							setState(45);
							polynomialExpression();
							}
						}

						setState(48);
						match(RIGHT_PARENTHESE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(51); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 5:
				{
				_localctx = new IndependentParentheseExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(53);
				match(LEFT_PARENTHESE);
				setState(55);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE))) != 0)) {
					{
					setState(54);
					polynomialExpression();
					}
				}

				setState(57);
				match(RIGHT_PARENTHESE);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(84);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(82);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
					case 1:
						{
						_localctx = new MemberEvaluateExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(60);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(61);
						match(POINT);
						setState(62);
						termExpression(5);
						}
						break;
					case 2:
						{
						_localctx = new MultiplyDivideExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(63);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(64);
						_la = _input.LA(1);
						if ( !(_la==MULTIPLY || _la==DIVIDE) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(65);
						termExpression(4);
						}
						break;
					case 3:
						{
						_localctx = new PlusMinusExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(66);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(67);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(68);
						termExpression(3);
						}
						break;
					case 4:
						{
						_localctx = new CompareExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(69);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(70);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << GREATER_THAN) | (1L << GREATER_THAN_EQUAL) | (1L << LESS_THAN) | (1L << LESS_THAN_EQUAL))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(71);
						termExpression(2);
						}
						break;
					case 5:
						{
						_localctx = new DirectFunctionExpressionContext(new TermExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_termExpression);
						setState(72);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(78); 
						_errHandler.sync(this);
						_alt = 1;
						do {
							switch (_alt) {
							case 1:
								{
								{
								setState(73);
								match(LEFT_PARENTHESE);
								setState(75);
								_errHandler.sync(this);
								_la = _input.LA(1);
								if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << NUMBER) | (1L << STRING) | (1L << LEFT_PARENTHESE))) != 0)) {
									{
									setState(74);
									polynomialExpression();
									}
								}

								setState(77);
								match(RIGHT_PARENTHESE);
								}
								}
								break;
							default:
								throw new NoViableAltException(this);
							}
							setState(80); 
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
						} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
						}
						break;
					}
					} 
				}
				setState(86);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
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
			return precpred(_ctx, 4);
		case 1:
			return precpred(_ctx, 3);
		case 2:
			return precpred(_ctx, 2);
		case 3:
			return precpred(_ctx, 1);
		case 4:
			return precpred(_ctx, 6);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\25Z\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\3\2\3\2\7\2\17\n\2\f\2\16\2\22\13\2\3\2\5\2"+
		"\25\n\2\3\3\3\3\5\3\31\n\3\3\3\3\3\3\4\3\4\3\4\3\4\3\5\6\5\"\n\5\r\5\16"+
		"\5#\3\6\3\6\3\6\3\6\3\6\3\6\5\6,\n\6\3\6\3\6\3\6\5\6\61\n\6\3\6\6\6\64"+
		"\n\6\r\6\16\6\65\3\6\3\6\5\6:\n\6\3\6\5\6=\n\6\3\6\3\6\3\6\3\6\3\6\3\6"+
		"\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6N\n\6\3\6\6\6Q\n\6\r\6\16\6R\7"+
		"\6U\n\6\f\6\16\6X\13\6\3\6\2\3\n\7\2\4\6\b\n\2\6\3\3\7\7\3\2\17\20\3\2"+
		"\r\16\3\2\21\24\2h\2\24\3\2\2\2\4\30\3\2\2\2\6\34\3\2\2\2\b!\3\2\2\2\n"+
		"<\3\2\2\2\f\17\5\4\3\2\r\17\7\7\2\2\16\f\3\2\2\2\16\r\3\2\2\2\17\22\3"+
		"\2\2\2\20\16\3\2\2\2\20\21\3\2\2\2\21\25\3\2\2\2\22\20\3\2\2\2\23\25\7"+
		"\2\2\3\24\20\3\2\2\2\24\23\3\2\2\2\25\3\3\2\2\2\26\31\5\b\5\2\27\31\5"+
		"\6\4\2\30\26\3\2\2\2\30\27\3\2\2\2\31\32\3\2\2\2\32\33\t\2\2\2\33\5\3"+
		"\2\2\2\34\35\5\b\5\2\35\36\7\f\2\2\36\37\5\b\5\2\37\7\3\2\2\2 \"\5\n\6"+
		"\2! \3\2\2\2\"#\3\2\2\2#!\3\2\2\2#$\3\2\2\2$\t\3\2\2\2%&\b\6\1\2&=\7\4"+
		"\2\2\'=\7\5\2\2(=\7\3\2\2)+\7\b\2\2*,\5\b\5\2+*\3\2\2\2+,\3\2\2\2,-\3"+
		"\2\2\2-\63\7\t\2\2.\60\7\b\2\2/\61\5\b\5\2\60/\3\2\2\2\60\61\3\2\2\2\61"+
		"\62\3\2\2\2\62\64\7\t\2\2\63.\3\2\2\2\64\65\3\2\2\2\65\63\3\2\2\2\65\66"+
		"\3\2\2\2\66=\3\2\2\2\679\7\b\2\28:\5\b\5\298\3\2\2\29:\3\2\2\2:;\3\2\2"+
		"\2;=\7\t\2\2<%\3\2\2\2<\'\3\2\2\2<(\3\2\2\2<)\3\2\2\2<\67\3\2\2\2=V\3"+
		"\2\2\2>?\f\6\2\2?@\7\6\2\2@U\5\n\6\7AB\f\5\2\2BC\t\3\2\2CU\5\n\6\6DE\f"+
		"\4\2\2EF\t\4\2\2FU\5\n\6\5GH\f\3\2\2HI\t\5\2\2IU\5\n\6\4JP\f\b\2\2KM\7"+
		"\b\2\2LN\5\b\5\2ML\3\2\2\2MN\3\2\2\2NO\3\2\2\2OQ\7\t\2\2PK\3\2\2\2QR\3"+
		"\2\2\2RP\3\2\2\2RS\3\2\2\2SU\3\2\2\2T>\3\2\2\2TA\3\2\2\2TD\3\2\2\2TG\3"+
		"\2\2\2TJ\3\2\2\2UX\3\2\2\2VT\3\2\2\2VW\3\2\2\2W\13\3\2\2\2XV\3\2\2\2\20"+
		"\16\20\24\30#+\60\659<MRTV";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}