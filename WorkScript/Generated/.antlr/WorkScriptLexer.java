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
		MULTIPLY=13, DIVIDE=14, GREATER_THAN=15, GREATER_THAN_EQUAL=16, LESS_THAN=17, 
		LESS_THAN_EQUAL=18, WS=19;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"IDENTIFIER", "NUMBER", "STRING", "POINT", "NEWLINE", "LEFT_PARENTHESE", 
		"RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "EQUALS", "PLUS", "MINUS", 
		"MULTIPLY", "DIVIDE", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", 
		"LESS_THAN_EQUAL", "WS"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\25y\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\3\2\3\2\7\2,\n\2\f\2\16\2/\13\2\3\3\6\3\62\n\3\r"+
		"\3\16\3\63\3\3\3\3\6\38\n\3\r\3\16\39\5\3<\n\3\3\4\3\4\7\4@\n\4\f\4\16"+
		"\4C\13\4\3\4\3\4\3\4\7\4H\n\4\f\4\16\4K\13\4\3\4\5\4N\n\4\3\5\3\5\3\6"+
		"\3\6\3\6\5\6U\n\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3"+
		"\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\21\3\22\3\22\3\23\3\23"+
		"\3\23\3\24\6\24t\n\24\r\24\16\24u\3\24\3\24\2\2\25\3\3\5\4\7\5\t\6\13"+
		"\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'"+
		"\25\3\2\b\5\2C\\aac|\6\2\62;C\\aac|\3\2\62;\3\2$$\3\2))\4\2\13\13\"\""+
		"\2\u0081\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2"+
		"\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27"+
		"\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2"+
		"\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\3)\3\2\2\2\5\61\3\2\2\2\7M\3\2\2"+
		"\2\tO\3\2\2\2\13T\3\2\2\2\rV\3\2\2\2\17X\3\2\2\2\21Z\3\2\2\2\23\\\3\2"+
		"\2\2\25^\3\2\2\2\27`\3\2\2\2\31b\3\2\2\2\33d\3\2\2\2\35f\3\2\2\2\37h\3"+
		"\2\2\2!j\3\2\2\2#m\3\2\2\2%o\3\2\2\2\'s\3\2\2\2)-\t\2\2\2*,\t\3\2\2+*"+
		"\3\2\2\2,/\3\2\2\2-+\3\2\2\2-.\3\2\2\2.\4\3\2\2\2/-\3\2\2\2\60\62\t\4"+
		"\2\2\61\60\3\2\2\2\62\63\3\2\2\2\63\61\3\2\2\2\63\64\3\2\2\2\64;\3\2\2"+
		"\2\65\67\5\t\5\2\668\t\4\2\2\67\66\3\2\2\289\3\2\2\29\67\3\2\2\29:\3\2"+
		"\2\2:<\3\2\2\2;\65\3\2\2\2;<\3\2\2\2<\6\3\2\2\2=A\7$\2\2>@\n\5\2\2?>\3"+
		"\2\2\2@C\3\2\2\2A?\3\2\2\2AB\3\2\2\2BD\3\2\2\2CA\3\2\2\2DN\7$\2\2EI\t"+
		"\6\2\2FH\n\6\2\2GF\3\2\2\2HK\3\2\2\2IG\3\2\2\2IJ\3\2\2\2JL\3\2\2\2KI\3"+
		"\2\2\2LN\t\6\2\2M=\3\2\2\2ME\3\2\2\2N\b\3\2\2\2OP\7\60\2\2P\n\3\2\2\2"+
		"QR\7\17\2\2RU\7\f\2\2SU\7\f\2\2TQ\3\2\2\2TS\3\2\2\2U\f\3\2\2\2VW\7*\2"+
		"\2W\16\3\2\2\2XY\7+\2\2Y\20\3\2\2\2Z[\7}\2\2[\22\3\2\2\2\\]\7\177\2\2"+
		"]\24\3\2\2\2^_\7?\2\2_\26\3\2\2\2`a\7-\2\2a\30\3\2\2\2bc\7/\2\2c\32\3"+
		"\2\2\2de\7,\2\2e\34\3\2\2\2fg\7\61\2\2g\36\3\2\2\2hi\7@\2\2i \3\2\2\2"+
		"jk\7@\2\2kl\7?\2\2l\"\3\2\2\2mn\7>\2\2n$\3\2\2\2op\7>\2\2pq\7?\2\2q&\3"+
		"\2\2\2rt\t\7\2\2sr\3\2\2\2tu\3\2\2\2us\3\2\2\2uv\3\2\2\2vw\3\2\2\2wx\b"+
		"\24\2\2x(\3\2\2\2\f\2-\639;AIMTu\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}