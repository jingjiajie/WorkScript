grammar WorkScript;

program: (expression | NEWLINE)* | EOF;

expression: (polynomialExpression | relationExpression) (
		NEWLINE
		| EOF
	);

relationExpression:
	polynomialExpression EQUALS polynomialExpression;

polynomialExpression:
	termExpression													# TermExpressionInPolynomial
	| polynomialExpression (MULTIPLY | DIVIDE) polynomialExpression	# MultiplyDivideExpression
	| polynomialExpression (PLUS | MINUS) polynomialExpression		# PlusMinusExpression;

termExpression:
	NUMBER													# NumberExpression
	| STRING												# StringExpression
	| IDENTIFIER											# IdentifierExpression
	| termExpression POINT termExpression					# MemberEvaluateExpression
	| LEFT_PARENTHESE polynomialExpression RIGHT_PARENTHESE	# ParentheseExpression
	| termExpression termExpression+						# MultiTermExpression;

// blockExpression: LEFT_BRACE expression* RIGHT_BRACE;

IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
NUMBER: [0-9]+ (POINT [0-9]+)?;
STRING: '"' ~'"'* '"' | ['] ~[']* ['];
POINT: '.';
NEWLINE: '\r\n' | '\n';
LEFT_PARENTHESE: '(';
RIGHT_PARENTHESE: ')';
LEFT_BRACE: '{';
RIGHT_BRACE: '}';
EQUALS: '=';
PLUS: '+';
MINUS: '-';
MULTIPLY: '*';
DIVIDE: '/';
GREATER_THAN: '>';
GREATER_THAN_EQUAL: '>=';
LESS_THAN: '<';
LESS_THAN_EQUAL: '<=';

WS: [ \t]+ -> skip;