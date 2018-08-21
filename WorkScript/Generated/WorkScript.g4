grammar WorkScript;

program: (expression NEWLINE | NEWLINE)* EOF;

expression:
	 LEFT_PARENTHESE expression RIGHT_PARENTHESE	# ParentheseExpression
	|LEFT_BRACKET (expression (COMMA? expression)*)? RIGHT_BRACKET						# ListExpression
	| expression LEFT_PARENTHESE parameterExpression RIGHT_PARENTHESE					# FunctionInvocationExpression
	| expression POINT IDENTIFIER LEFT_PARENTHESE parameterExpression RIGHT_PARENTHESE	#
		MethodInvocationExpression
	| expression POINT IDENTIFIER					# MemberEvaluateExpression
	| expression (MULTIPLY | DIVIDE) expression		# MultiplyDivideExpression
	| expression (PLUS | MINUS) expression			# PlusMinusExpression
	| functionExpression							# FunctionExpression_
	| expression EQUALS expression					# AssignmentExpression
	| expression (
		GREATER_THAN
		| GREATER_THAN_EQUAL
		| LESS_THAN
		| LESS_THAN_EQUAL
	) expression	# CompareExpression
	| NUMBER		# NumberExpression
	| STRING		# StringExpression
	| IDENTIFIER	# VariableExpression;

parameterExpression: (expression (COMMA? expression)*)?;

functionExpression:
	IDENTIFIER? LEFT_PARENTHESE parameterExpression RIGHT_PARENTHESE (EQUALS expression
	| NEWLINE* EQUALS? NEWLINE* blockExpression);

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