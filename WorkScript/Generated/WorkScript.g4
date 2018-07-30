grammar WorkScript;

program: (expression | NEWLINE)* | EOF;

expression: (polynomialExpression | relationExpression) (
		NEWLINE
		| EOF
	);

relationExpression:
	polynomialExpression EQUALS polynomialExpression;

polynomialExpression: termExpression (COMMA? termExpression)*;

termExpression:
	NUMBER			# NumberExpression
	| STRING		# StringExpression
	| IDENTIFIER	# IdentifierExpression
	| LEFT_PARENTHESE polynomialExpression? RIGHT_PARENTHESE (
		LEFT_PARENTHESE polynomialExpression? RIGHT_PARENTHESE
	)+ # EvaluatedFunctionExpression
	| termExpression (
		LEFT_PARENTHESE polynomialExpression? RIGHT_PARENTHESE
	)+															# DirectFunctionExpression
	| LEFT_PARENTHESE polynomialExpression? RIGHT_PARENTHESE	# IndependentParentheseExpression
	| termExpression POINT termExpression						# MemberEvaluateExpression
	| termExpression (MULTIPLY | DIVIDE) termExpression			# MultiplyDivideExpression
	| termExpression (PLUS | MINUS) termExpression				# PlusMinusExpression
	| termExpression (
		GREATER_THAN
		| GREATER_THAN_EQUAL
		| LESS_THAN
		| LESS_THAN_EQUAL
	) termExpression # CompareExpression;

// blockExpression: LEFT_BRACE expression* RIGHT_BRACE;
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
NUMBER: [0-9]+ (POINT [0-9]+)?;
STRING: '"' ~'"'* '"' | ['] ~[']* ['];
POINT: '.';
COMMA: ',';
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