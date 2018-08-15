grammar WorkScript;

program: (expression NEWLINE | NEWLINE)* EOF;

expression: termExpression;

termExpression:
	NUMBER								# NumberExpression
	| STRING							# StringExpression
	| IDENTIFIER						# VariableExpression
	| IDENTIFIER EQUALS termExpression	# AssignmentExpression
	| IDENTIFIER? LEFT_PARENTHESE listExpression RIGHT_PARENTHESE (
		EQUALS termExpression
		| blockExpression
	)																					# FunctionExpression
	| termExpression LEFT_PARENTHESE listExpression RIGHT_PARENTHESE					# FunctionInvocationExpression
	| termExpression POINT IDENTIFIER LEFT_PARENTHESE listExpression RIGHT_PARENTHESE	#
		MethodInvocationExpression
	| termExpression POINT IDENTIFIER					# MemberEvaluateExpression
	| LEFT_PARENTHESE termExpression RIGHT_PARENTHESE	# ParentheseExpression
	| termExpression (MULTIPLY | DIVIDE) termExpression	# MultiplyDivideExpression
	| termExpression (PLUS | MINUS) termExpression		# PlusMinusExpression
	| termExpression (
		GREATER_THAN
		| GREATER_THAN_EQUAL
		| LESS_THAN
		| LESS_THAN_EQUAL
	) termExpression	# CompareExpression
	| blockExpression	# TermBlockExpression;

listExpression:
	termExpression (COMMA termExpression)*
	| LEFT_BRACKET (termExpression (COMMA termExpression)*)? RIGHT_BRACKET;

blockExpression:
	LEFT_BRACE NEWLINE* ((expression NEWLINE+)* expression)? NEWLINE* RIGHT_BRACE;

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
LEFT_BRACKET: '[';
RIGHT_BRACKET: ']';
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