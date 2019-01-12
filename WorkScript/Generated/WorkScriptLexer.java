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
		INTEGER=7, STRING=8, SEMICOLON=9, POINT=10, COMMA=11, LEFT_PARENTHESE=12, 
		RIGHT_PARENTHESE=13, LEFT_BRACE=14, RIGHT_BRACE=15, LEFT_BRACKET=16, RIGHT_BRACKET=17, 
		DOUBLE_EQUAL=18, EQUALS=19, RIGHT_ARROW=20, ASSIGN=21, COLON=22, PLUS=23, 
		MINUS=24, STAR=25, SLASH=26, PERCENT=27, HASH=28, GREATER_THAN=29, GREATER_THAN_EQUAL=30, 
		LESS_THAN=31, LESS_THAN_EQUAL=32, SINGLE_LINE_COMMENT=33, MULTILINE_COMMENT=34, 
		APOSTROPHE=35, NEWLINE=36, WS=37;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"ACCESS_LEVEL", "INCLUDE", "WHEN", "BOOLEAN", "IDENTIFIER", "DOUBLE", 
		"INTEGER", "STRING", "SEMICOLON", "POINT", "COMMA", "LEFT_PARENTHESE", 
		"RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", 
		"DOUBLE_EQUAL", "EQUALS", "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", 
		"STAR", "SLASH", "PERCENT", "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", 
		"LESS_THAN", "LESS_THAN_EQUAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", 
		"APOSTROPHE", "NEWLINE", "WS"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\'\u010d\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\5\2[\n\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3"+
		"\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5\u0081\n\5\3\6\3\6\3\6\5\6\u0086\n"+
		"\6\3\6\3\6\7\6\u008a\n\6\f\6\16\6\u008d\13\6\5\6\u008f\n\6\3\7\6\7\u0092"+
		"\n\7\r\7\16\7\u0093\3\7\3\7\6\7\u0098\n\7\r\7\16\7\u0099\3\b\6\b\u009d"+
		"\n\b\r\b\16\b\u009e\3\t\3\t\7\t\u00a3\n\t\f\t\16\t\u00a6\13\t\3\t\3\t"+
		"\3\t\7\t\u00ab\n\t\f\t\16\t\u00ae\13\t\3\t\5\t\u00b1\n\t\3\n\3\n\3\13"+
		"\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22"+
		"\3\23\3\23\3\23\3\24\3\24\3\25\3\25\3\25\3\26\3\26\3\26\3\27\3\27\3\30"+
		"\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\35\3\35\3\36\3\36\3\37"+
		"\3\37\3\37\3 \3 \3!\3!\3!\3\"\3\"\3\"\3\"\7\"\u00ec\n\"\f\"\16\"\u00ef"+
		"\13\"\3\"\3\"\3#\3#\3#\3#\7#\u00f7\n#\f#\16#\u00fa\13#\3#\3#\3#\3#\3#"+
		"\3$\3$\3$\3$\3%\3%\3&\6&\u0108\n&\r&\16&\u0109\3&\3&\3\u00f8\2\'\3\3\5"+
		"\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21"+
		"!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!"+
		"A\"C#E$G%I&K\'\3\2\n\5\2C\\aac|\3\2\2\u0101\6\2\62;C\\aac|\3\2\62;\3\2"+
		"$$\3\2))\3\2\f\f\5\2\13\13\17\17\"\"\2\u0120\2\3\3\2\2\2\2\5\3\2\2\2\2"+
		"\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2"+
		"\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2"+
		"\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2"+
		"\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2"+
		"\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2"+
		"\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\3"+
		"Z\3\2\2\2\5\\\3\2\2\2\7d\3\2\2\2\t\u0080\3\2\2\2\13\u008e\3\2\2\2\r\u0091"+
		"\3\2\2\2\17\u009c\3\2\2\2\21\u00b0\3\2\2\2\23\u00b2\3\2\2\2\25\u00b4\3"+
		"\2\2\2\27\u00b6\3\2\2\2\31\u00b8\3\2\2\2\33\u00ba\3\2\2\2\35\u00bc\3\2"+
		"\2\2\37\u00be\3\2\2\2!\u00c0\3\2\2\2#\u00c2\3\2\2\2%\u00c4\3\2\2\2\'\u00c7"+
		"\3\2\2\2)\u00c9\3\2\2\2+\u00cc\3\2\2\2-\u00cf\3\2\2\2/\u00d1\3\2\2\2\61"+
		"\u00d3\3\2\2\2\63\u00d5\3\2\2\2\65\u00d7\3\2\2\2\67\u00d9\3\2\2\29\u00db"+
		"\3\2\2\2;\u00dd\3\2\2\2=\u00df\3\2\2\2?\u00e2\3\2\2\2A\u00e4\3\2\2\2C"+
		"\u00e7\3\2\2\2E\u00f2\3\2\2\2G\u0100\3\2\2\2I\u0104\3\2\2\2K\u0107\3\2"+
		"\2\2MN\7r\2\2NO\7w\2\2OP\7d\2\2PQ\7n\2\2QR\7k\2\2R[\7e\2\2ST\7r\2\2TU"+
		"\7t\2\2UV\7k\2\2VW\7x\2\2WX\7c\2\2XY\7v\2\2Y[\7g\2\2ZM\3\2\2\2ZS\3\2\2"+
		"\2[\4\3\2\2\2\\]\7k\2\2]^\7p\2\2^_\7e\2\2_`\7n\2\2`a\7w\2\2ab\7f\2\2b"+
		"c\7g\2\2c\6\3\2\2\2de\7y\2\2ef\7j\2\2fg\7g\2\2gh\7p\2\2h\b\3\2\2\2ij\7"+
		"v\2\2jk\7t\2\2kl\7w\2\2l\u0081\7g\2\2mn\7{\2\2no\7g\2\2o\u0081\7u\2\2"+
		"pq\7q\2\2q\u0081\7m\2\2rs\7i\2\2st\7q\2\2tu\7q\2\2u\u0081\7f\2\2vw\7h"+
		"\2\2wx\7c\2\2xy\7n\2\2yz\7u\2\2z\u0081\7g\2\2{|\7p\2\2|\u0081\7q\2\2}"+
		"~\7d\2\2~\177\7c\2\2\177\u0081\7f\2\2\u0080i\3\2\2\2\u0080m\3\2\2\2\u0080"+
		"p\3\2\2\2\u0080r\3\2\2\2\u0080v\3\2\2\2\u0080{\3\2\2\2\u0080}\3\2\2\2"+
		"\u0081\n\3\2\2\2\u0082\u008f\5\7\4\2\u0083\u0086\t\2\2\2\u0084\u0086\n"+
		"\3\2\2\u0085\u0083\3\2\2\2\u0085\u0084\3\2\2\2\u0086\u008b\3\2\2\2\u0087"+
		"\u008a\t\4\2\2\u0088\u008a\n\3\2\2\u0089\u0087\3\2\2\2\u0089\u0088\3\2"+
		"\2\2\u008a\u008d\3\2\2\2\u008b\u0089\3\2\2\2\u008b\u008c\3\2\2\2\u008c"+
		"\u008f\3\2\2\2\u008d\u008b\3\2\2\2\u008e\u0082\3\2\2\2\u008e\u0085\3\2"+
		"\2\2\u008f\f\3\2\2\2\u0090\u0092\t\5\2\2\u0091\u0090\3\2\2\2\u0092\u0093"+
		"\3\2\2\2\u0093\u0091\3\2\2\2\u0093\u0094\3\2\2\2\u0094\u0095\3\2\2\2\u0095"+
		"\u0097\5\25\13\2\u0096\u0098\t\5\2\2\u0097\u0096\3\2\2\2\u0098\u0099\3"+
		"\2\2\2\u0099\u0097\3\2\2\2\u0099\u009a\3\2\2\2\u009a\16\3\2\2\2\u009b"+
		"\u009d\t\5\2\2\u009c\u009b\3\2\2\2\u009d\u009e\3\2\2\2\u009e\u009c\3\2"+
		"\2\2\u009e\u009f\3\2\2\2\u009f\20\3\2\2\2\u00a0\u00a4\7$\2\2\u00a1\u00a3"+
		"\n\6\2\2\u00a2\u00a1\3\2\2\2\u00a3\u00a6\3\2\2\2\u00a4\u00a2\3\2\2\2\u00a4"+
		"\u00a5\3\2\2\2\u00a5\u00a7\3\2\2\2\u00a6\u00a4\3\2\2\2\u00a7\u00b1\7$"+
		"\2\2\u00a8\u00ac\t\7\2\2\u00a9\u00ab\n\7\2\2\u00aa\u00a9\3\2\2\2\u00ab"+
		"\u00ae\3\2\2\2\u00ac\u00aa\3\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00af\3\2"+
		"\2\2\u00ae\u00ac\3\2\2\2\u00af\u00b1\t\7\2\2\u00b0\u00a0\3\2\2\2\u00b0"+
		"\u00a8\3\2\2\2\u00b1\22\3\2\2\2\u00b2\u00b3\7=\2\2\u00b3\24\3\2\2\2\u00b4"+
		"\u00b5\7\60\2\2\u00b5\26\3\2\2\2\u00b6\u00b7\7.\2\2\u00b7\30\3\2\2\2\u00b8"+
		"\u00b9\7*\2\2\u00b9\32\3\2\2\2\u00ba\u00bb\7+\2\2\u00bb\34\3\2\2\2\u00bc"+
		"\u00bd\7}\2\2\u00bd\36\3\2\2\2\u00be\u00bf\7\177\2\2\u00bf \3\2\2\2\u00c0"+
		"\u00c1\7]\2\2\u00c1\"\3\2\2\2\u00c2\u00c3\7_\2\2\u00c3$\3\2\2\2\u00c4"+
		"\u00c5\7?\2\2\u00c5\u00c6\7?\2\2\u00c6&\3\2\2\2\u00c7\u00c8\7?\2\2\u00c8"+
		"(\3\2\2\2\u00c9\u00ca\7?\2\2\u00ca\u00cb\7@\2\2\u00cb*\3\2\2\2\u00cc\u00cd"+
		"\7<\2\2\u00cd\u00ce\7?\2\2\u00ce,\3\2\2\2\u00cf\u00d0\7<\2\2\u00d0.\3"+
		"\2\2\2\u00d1\u00d2\7-\2\2\u00d2\60\3\2\2\2\u00d3\u00d4\7/\2\2\u00d4\62"+
		"\3\2\2\2\u00d5\u00d6\7,\2\2\u00d6\64\3\2\2\2\u00d7\u00d8\7\61\2\2\u00d8"+
		"\66\3\2\2\2\u00d9\u00da\7\'\2\2\u00da8\3\2\2\2\u00db\u00dc\7%\2\2\u00dc"+
		":\3\2\2\2\u00dd\u00de\7@\2\2\u00de<\3\2\2\2\u00df\u00e0\7@\2\2\u00e0\u00e1"+
		"\7?\2\2\u00e1>\3\2\2\2\u00e2\u00e3\7>\2\2\u00e3@\3\2\2\2\u00e4\u00e5\7"+
		">\2\2\u00e5\u00e6\7?\2\2\u00e6B\3\2\2\2\u00e7\u00e8\7\61\2\2\u00e8\u00e9"+
		"\7\61\2\2\u00e9\u00ed\3\2\2\2\u00ea\u00ec\n\b\2\2\u00eb\u00ea\3\2\2\2"+
		"\u00ec\u00ef\3\2\2\2\u00ed\u00eb\3\2\2\2\u00ed\u00ee\3\2\2\2\u00ee\u00f0"+
		"\3\2\2\2\u00ef\u00ed\3\2\2\2\u00f0\u00f1\b\"\2\2\u00f1D\3\2\2\2\u00f2"+
		"\u00f3\7\61\2\2\u00f3\u00f4\7,\2\2\u00f4\u00f8\3\2\2\2\u00f5\u00f7\13"+
		"\2\2\2\u00f6\u00f5\3\2\2\2\u00f7\u00fa\3\2\2\2\u00f8\u00f9\3\2\2\2\u00f8"+
		"\u00f6\3\2\2\2\u00f9\u00fb\3\2\2\2\u00fa\u00f8\3\2\2\2\u00fb\u00fc\7,"+
		"\2\2\u00fc\u00fd\7\61\2\2\u00fd\u00fe\3\2\2\2\u00fe\u00ff\b#\2\2\u00ff"+
		"F\3\2\2\2\u0100\u0101\7\60\2\2\u0101\u0102\7\60\2\2\u0102\u0103\7\60\2"+
		"\2\u0103H\3\2\2\2\u0104\u0105\7\f\2\2\u0105J\3\2\2\2\u0106\u0108\t\t\2"+
		"\2\u0107\u0106\3\2\2\2\u0108\u0109\3\2\2\2\u0109\u0107\3\2\2\2\u0109\u010a"+
		"\3\2\2\2\u010a\u010b\3\2\2\2\u010b\u010c\b&\2\2\u010cL\3\2\2\2\22\2Z\u0080"+
		"\u0085\u0089\u008b\u008e\u0093\u0099\u009e\u00a4\u00ac\u00b0\u00ed\u00f8"+
		"\u0109\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}