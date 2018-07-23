// Generated from c:\Users\Jonas\Desktop\WorkScript\WorkScript\Generated\WorkScript.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class WorkScriptLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		IDENTIFIER=1, NUMBER=2, STRING=3, POINT=4, NEWLINE=5, LEFT_PARENTHESE=6, 
		RIGHT_PARENTHESE=7, LEFT_BRACE=8, RIGHT_BRACE=9, EQUALS=10, PLUS=11, MINUS=12, 
		GREATER_THAN=13, GREATER_THAN_EQUAL=14, LESS_THAN=15, LESS_THAN_EQUAL=16, 
		WS=17;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"IDENTIFIER", "NUMBER", "STRING", "POINT", "NEWLINE", "LEFT_PARENTHESE", 
		"RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "EQUALS", "PLUS", "MINUS", 
		"GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", "LESS_THAN_EQUAL", 
		"WS"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, null, null, "'.'", null, "'('", "')'", "'{'", "'}'", "'='", 
		"'+'", "'-'", "'>'", "'>='", "'<'", "'<='"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "IDENTIFIER", "NUMBER", "STRING", "POINT", "NEWLINE", "LEFT_PARENTHESE", 
		"RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "EQUALS", "PLUS", "MINUS", 
		"GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", "LESS_THAN_EQUAL", 
		"WS"
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


	public WorkScriptLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "WorkScript.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\23q\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\3\2\7\2(\n\2\f\2\16\2+\13\2\3\3\6\3.\n\3\r\3\16\3/\3\3\3\3\6\3\64"+
		"\n\3\r\3\16\3\65\5\38\n\3\3\4\3\4\7\4<\n\4\f\4\16\4?\13\4\3\4\3\4\3\4"+
		"\7\4D\n\4\f\4\16\4G\13\4\3\4\5\4J\n\4\3\5\3\5\3\6\3\6\3\6\5\6Q\n\6\3\7"+
		"\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17"+
		"\3\17\3\17\3\20\3\20\3\21\3\21\3\21\3\22\6\22l\n\22\r\22\16\22m\3\22\3"+
		"\22\2\2\23\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33"+
		"\17\35\20\37\21!\22#\23\3\2\b\5\2C\\aac|\6\2\62;C\\aac|\3\2\62;\3\2$$"+
		"\3\2))\4\2\13\13\"\"\2y\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2"+
		"\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25"+
		"\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2"+
		"\2\2\2!\3\2\2\2\2#\3\2\2\2\3%\3\2\2\2\5-\3\2\2\2\7I\3\2\2\2\tK\3\2\2\2"+
		"\13P\3\2\2\2\rR\3\2\2\2\17T\3\2\2\2\21V\3\2\2\2\23X\3\2\2\2\25Z\3\2\2"+
		"\2\27\\\3\2\2\2\31^\3\2\2\2\33`\3\2\2\2\35b\3\2\2\2\37e\3\2\2\2!g\3\2"+
		"\2\2#k\3\2\2\2%)\t\2\2\2&(\t\3\2\2\'&\3\2\2\2(+\3\2\2\2)\'\3\2\2\2)*\3"+
		"\2\2\2*\4\3\2\2\2+)\3\2\2\2,.\t\4\2\2-,\3\2\2\2./\3\2\2\2/-\3\2\2\2/\60"+
		"\3\2\2\2\60\67\3\2\2\2\61\63\5\t\5\2\62\64\t\4\2\2\63\62\3\2\2\2\64\65"+
		"\3\2\2\2\65\63\3\2\2\2\65\66\3\2\2\2\668\3\2\2\2\67\61\3\2\2\2\678\3\2"+
		"\2\28\6\3\2\2\29=\7$\2\2:<\n\5\2\2;:\3\2\2\2<?\3\2\2\2=;\3\2\2\2=>\3\2"+
		"\2\2>@\3\2\2\2?=\3\2\2\2@J\7$\2\2AE\t\6\2\2BD\n\6\2\2CB\3\2\2\2DG\3\2"+
		"\2\2EC\3\2\2\2EF\3\2\2\2FH\3\2\2\2GE\3\2\2\2HJ\t\6\2\2I9\3\2\2\2IA\3\2"+
		"\2\2J\b\3\2\2\2KL\7\60\2\2L\n\3\2\2\2MN\7\17\2\2NQ\7\f\2\2OQ\7\f\2\2P"+
		"M\3\2\2\2PO\3\2\2\2Q\f\3\2\2\2RS\7*\2\2S\16\3\2\2\2TU\7+\2\2U\20\3\2\2"+
		"\2VW\7}\2\2W\22\3\2\2\2XY\7\177\2\2Y\24\3\2\2\2Z[\7?\2\2[\26\3\2\2\2\\"+
		"]\7-\2\2]\30\3\2\2\2^_\7/\2\2_\32\3\2\2\2`a\7@\2\2a\34\3\2\2\2bc\7@\2"+
		"\2cd\7?\2\2d\36\3\2\2\2ef\7>\2\2f \3\2\2\2gh\7>\2\2hi\7?\2\2i\"\3\2\2"+
		"\2jl\t\7\2\2kj\3\2\2\2lm\3\2\2\2mk\3\2\2\2mn\3\2\2\2no\3\2\2\2op\b\22"+
		"\2\2p$\3\2\2\2\f\2)/\65\67=EIPm\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}