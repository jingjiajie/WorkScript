// Generated from WorkScript.g4 by ANTLR 4.7.1
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
		ACCESS_LEVEL=1, INCLUDE=2, WHEN=3, BOOLEAN=4, IDENTIFIER=5, DOUBLE=6, 
		INTEGER=7, STRING=8, POINT=9, COMMA=10, LEFT_PARENTHESE=11, RIGHT_PARENTHESE=12, 
		LEFT_BRACE=13, RIGHT_BRACE=14, LEFT_BRACKET=15, RIGHT_BRACKET=16, DOUBLE_EQUAL=17, 
		EQUALS=18, RIGHT_ARROW=19, ASSIGN=20, COLON=21, PLUS=22, MINUS=23, MULTIPLY=24, 
		DIVIDE=25, MODULUS=26, HASH=27, GREATER_THAN=28, GREATER_THAN_EQUAL=29, 
		LESS_THAN=30, LESS_THAN_EQUAL=31, SINGLE_LINE_COMMENT=32, MULTILINE_COMMENT=33, 
		APOSTROPHE=34, NEWLINE=35, WS=36;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"ACCESS_LEVEL", "INCLUDE", "WHEN", "BOOLEAN", "IDENTIFIER", "DOUBLE", 
		"INTEGER", "STRING", "POINT", "COMMA", "LEFT_PARENTHESE", "RIGHT_PARENTHESE", 
		"LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "DOUBLE_EQUAL", 
		"EQUALS", "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", "MULTIPLY", 
		"DIVIDE", "MODULUS", "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", 
		"LESS_THAN_EQUAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "APOSTROPHE", 
		"NEWLINE", "WS"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2&\u0109\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\5\2Y\n\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4"+
		"\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5\177\n\5\3\6\3\6\3\6\5\6\u0084\n\6\3\6\3"+
		"\6\7\6\u0088\n\6\f\6\16\6\u008b\13\6\5\6\u008d\n\6\3\7\6\7\u0090\n\7\r"+
		"\7\16\7\u0091\3\7\3\7\6\7\u0096\n\7\r\7\16\7\u0097\3\b\6\b\u009b\n\b\r"+
		"\b\16\b\u009c\3\t\3\t\7\t\u00a1\n\t\f\t\16\t\u00a4\13\t\3\t\3\t\3\t\7"+
		"\t\u00a9\n\t\f\t\16\t\u00ac\13\t\3\t\5\t\u00af\n\t\3\n\3\n\3\13\3\13\3"+
		"\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22\3\22"+
		"\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3\25\3\26\3\26\3\27\3\27\3\30\3\30"+
		"\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\35\3\35\3\36\3\36\3\36\3\37"+
		"\3\37\3 \3 \3 \3!\3!\3!\3!\7!\u00e8\n!\f!\16!\u00eb\13!\3!\3!\3\"\3\""+
		"\3\"\3\"\7\"\u00f3\n\"\f\"\16\"\u00f6\13\"\3\"\3\"\3\"\3\"\3\"\3#\3#\3"+
		"#\3#\3$\3$\3%\6%\u0104\n%\r%\16%\u0105\3%\3%\3\u00f4\2&\3\3\5\4\7\5\t"+
		"\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23"+
		"%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G"+
		"%I&\3\2\n\5\2C\\aac|\3\2\2\u0101\6\2\62;C\\aac|\3\2\62;\3\2$$\3\2))\3"+
		"\2\f\f\5\2\13\13\17\17\"\"\2\u011c\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2"+
		"\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3"+
		"\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2"+
		"\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2"+
		"\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2"+
		"\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2"+
		"\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\3X\3\2\2\2\5Z\3\2\2\2\7"+
		"b\3\2\2\2\t~\3\2\2\2\13\u008c\3\2\2\2\r\u008f\3\2\2\2\17\u009a\3\2\2\2"+
		"\21\u00ae\3\2\2\2\23\u00b0\3\2\2\2\25\u00b2\3\2\2\2\27\u00b4\3\2\2\2\31"+
		"\u00b6\3\2\2\2\33\u00b8\3\2\2\2\35\u00ba\3\2\2\2\37\u00bc\3\2\2\2!\u00be"+
		"\3\2\2\2#\u00c0\3\2\2\2%\u00c3\3\2\2\2\'\u00c5\3\2\2\2)\u00c8\3\2\2\2"+
		"+\u00cb\3\2\2\2-\u00cd\3\2\2\2/\u00cf\3\2\2\2\61\u00d1\3\2\2\2\63\u00d3"+
		"\3\2\2\2\65\u00d5\3\2\2\2\67\u00d7\3\2\2\29\u00d9\3\2\2\2;\u00db\3\2\2"+
		"\2=\u00de\3\2\2\2?\u00e0\3\2\2\2A\u00e3\3\2\2\2C\u00ee\3\2\2\2E\u00fc"+
		"\3\2\2\2G\u0100\3\2\2\2I\u0103\3\2\2\2KL\7r\2\2LM\7w\2\2MN\7d\2\2NO\7"+
		"n\2\2OP\7k\2\2PY\7e\2\2QR\7r\2\2RS\7t\2\2ST\7k\2\2TU\7x\2\2UV\7c\2\2V"+
		"W\7v\2\2WY\7g\2\2XK\3\2\2\2XQ\3\2\2\2Y\4\3\2\2\2Z[\7k\2\2[\\\7p\2\2\\"+
		"]\7e\2\2]^\7n\2\2^_\7w\2\2_`\7f\2\2`a\7g\2\2a\6\3\2\2\2bc\7y\2\2cd\7j"+
		"\2\2de\7g\2\2ef\7p\2\2f\b\3\2\2\2gh\7v\2\2hi\7t\2\2ij\7w\2\2j\177\7g\2"+
		"\2kl\7{\2\2lm\7g\2\2m\177\7u\2\2no\7q\2\2o\177\7m\2\2pq\7i\2\2qr\7q\2"+
		"\2rs\7q\2\2s\177\7f\2\2tu\7h\2\2uv\7c\2\2vw\7n\2\2wx\7u\2\2x\177\7g\2"+
		"\2yz\7p\2\2z\177\7q\2\2{|\7d\2\2|}\7c\2\2}\177\7f\2\2~g\3\2\2\2~k\3\2"+
		"\2\2~n\3\2\2\2~p\3\2\2\2~t\3\2\2\2~y\3\2\2\2~{\3\2\2\2\177\n\3\2\2\2\u0080"+
		"\u008d\5\7\4\2\u0081\u0084\t\2\2\2\u0082\u0084\n\3\2\2\u0083\u0081\3\2"+
		"\2\2\u0083\u0082\3\2\2\2\u0084\u0089\3\2\2\2\u0085\u0088\t\4\2\2\u0086"+
		"\u0088\n\3\2\2\u0087\u0085\3\2\2\2\u0087\u0086\3\2\2\2\u0088\u008b\3\2"+
		"\2\2\u0089\u0087\3\2\2\2\u0089\u008a\3\2\2\2\u008a\u008d\3\2\2\2\u008b"+
		"\u0089\3\2\2\2\u008c\u0080\3\2\2\2\u008c\u0083\3\2\2\2\u008d\f\3\2\2\2"+
		"\u008e\u0090\t\5\2\2\u008f\u008e\3\2\2\2\u0090\u0091\3\2\2\2\u0091\u008f"+
		"\3\2\2\2\u0091\u0092\3\2\2\2\u0092\u0093\3\2\2\2\u0093\u0095\5\23\n\2"+
		"\u0094\u0096\t\5\2\2\u0095\u0094\3\2\2\2\u0096\u0097\3\2\2\2\u0097\u0095"+
		"\3\2\2\2\u0097\u0098\3\2\2\2\u0098\16\3\2\2\2\u0099\u009b\t\5\2\2\u009a"+
		"\u0099\3\2\2\2\u009b\u009c\3\2\2\2\u009c\u009a\3\2\2\2\u009c\u009d\3\2"+
		"\2\2\u009d\20\3\2\2\2\u009e\u00a2\7$\2\2\u009f\u00a1\n\6\2\2\u00a0\u009f"+
		"\3\2\2\2\u00a1\u00a4\3\2\2\2\u00a2\u00a0\3\2\2\2\u00a2\u00a3\3\2\2\2\u00a3"+
		"\u00a5\3\2\2\2\u00a4\u00a2\3\2\2\2\u00a5\u00af\7$\2\2\u00a6\u00aa\t\7"+
		"\2\2\u00a7\u00a9\n\7\2\2\u00a8\u00a7\3\2\2\2\u00a9\u00ac\3\2\2\2\u00aa"+
		"\u00a8\3\2\2\2\u00aa\u00ab\3\2\2\2\u00ab\u00ad\3\2\2\2\u00ac\u00aa\3\2"+
		"\2\2\u00ad\u00af\t\7\2\2\u00ae\u009e\3\2\2\2\u00ae\u00a6\3\2\2\2\u00af"+
		"\22\3\2\2\2\u00b0\u00b1\7\60\2\2\u00b1\24\3\2\2\2\u00b2\u00b3\7.\2\2\u00b3"+
		"\26\3\2\2\2\u00b4\u00b5\7*\2\2\u00b5\30\3\2\2\2\u00b6\u00b7\7+\2\2\u00b7"+
		"\32\3\2\2\2\u00b8\u00b9\7}\2\2\u00b9\34\3\2\2\2\u00ba\u00bb\7\177\2\2"+
		"\u00bb\36\3\2\2\2\u00bc\u00bd\7]\2\2\u00bd \3\2\2\2\u00be\u00bf\7_\2\2"+
		"\u00bf\"\3\2\2\2\u00c0\u00c1\7?\2\2\u00c1\u00c2\7?\2\2\u00c2$\3\2\2\2"+
		"\u00c3\u00c4\7?\2\2\u00c4&\3\2\2\2\u00c5\u00c6\7?\2\2\u00c6\u00c7\7@\2"+
		"\2\u00c7(\3\2\2\2\u00c8\u00c9\7<\2\2\u00c9\u00ca\7?\2\2\u00ca*\3\2\2\2"+
		"\u00cb\u00cc\7<\2\2\u00cc,\3\2\2\2\u00cd\u00ce\7-\2\2\u00ce.\3\2\2\2\u00cf"+
		"\u00d0\7/\2\2\u00d0\60\3\2\2\2\u00d1\u00d2\7,\2\2\u00d2\62\3\2\2\2\u00d3"+
		"\u00d4\7\61\2\2\u00d4\64\3\2\2\2\u00d5\u00d6\7\'\2\2\u00d6\66\3\2\2\2"+
		"\u00d7\u00d8\7%\2\2\u00d88\3\2\2\2\u00d9\u00da\7@\2\2\u00da:\3\2\2\2\u00db"+
		"\u00dc\7@\2\2\u00dc\u00dd\7?\2\2\u00dd<\3\2\2\2\u00de\u00df\7>\2\2\u00df"+
		">\3\2\2\2\u00e0\u00e1\7>\2\2\u00e1\u00e2\7?\2\2\u00e2@\3\2\2\2\u00e3\u00e4"+
		"\7\61\2\2\u00e4\u00e5\7\61\2\2\u00e5\u00e9\3\2\2\2\u00e6\u00e8\n\b\2\2"+
		"\u00e7\u00e6\3\2\2\2\u00e8\u00eb\3\2\2\2\u00e9\u00e7\3\2\2\2\u00e9\u00ea"+
		"\3\2\2\2\u00ea\u00ec\3\2\2\2\u00eb\u00e9\3\2\2\2\u00ec\u00ed\b!\2\2\u00ed"+
		"B\3\2\2\2\u00ee\u00ef\7\61\2\2\u00ef\u00f0\7,\2\2\u00f0\u00f4\3\2\2\2"+
		"\u00f1\u00f3\13\2\2\2\u00f2\u00f1\3\2\2\2\u00f3\u00f6\3\2\2\2\u00f4\u00f5"+
		"\3\2\2\2\u00f4\u00f2\3\2\2\2\u00f5\u00f7\3\2\2\2\u00f6\u00f4\3\2\2\2\u00f7"+
		"\u00f8\7,\2\2\u00f8\u00f9\7\61\2\2\u00f9\u00fa\3\2\2\2\u00fa\u00fb\b\""+
		"\2\2\u00fbD\3\2\2\2\u00fc\u00fd\7\60\2\2\u00fd\u00fe\7\60\2\2\u00fe\u00ff"+
		"\7\60\2\2\u00ffF\3\2\2\2\u0100\u0101\7\f\2\2\u0101H\3\2\2\2\u0102\u0104"+
		"\t\t\2\2\u0103\u0102\3\2\2\2\u0104\u0105\3\2\2\2\u0105\u0103\3\2\2\2\u0105"+
		"\u0106\3\2\2\2\u0106\u0107\3\2\2\2\u0107\u0108\b%\2\2\u0108J\3\2\2\2\22"+
		"\2X~\u0083\u0087\u0089\u008c\u0091\u0097\u009c\u00a2\u00aa\u00ae\u00e9"+
		"\u00f4\u0105\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}