grammar WorkScript;

program: (includeCommand NEWLINE? | NEWLINE)* (
		expression NEWLINE?
		| NEWLINE
	)* EOF;

includeCommand: HASH INCLUDE STRING;

expression:
	ACCESS_LEVEL COLON								# AccessLevelExpression
	| LEFT_PARENTHESE expression RIGHT_PARENTHESE	# ParentheseExpression
	// | LEFT_BRACKET (expression (COMMA expression)*)? RIGHT_BRACKET # ListExpression | expression
	// POINT identifier # MemberEvaluateExpression
	| functionExpression									# FunctionExpression_
	| callExpression										# CallExpression_
	| expression (MULTIPLY | DIVIDE | MODULUS) expression	# MultiplyDivideModulusExpression
	| expression (PLUS | MINUS) expression					# PlusMinusExpression
	| numberExpression										# NumberExpression_
	| MINUS expression										# NegativeExpression
	| PLUS expression										# PositiveExpression
	| expression ASSIGN expression							# AssignmentExpression
	| expression EQUALS expression							# AssignmentOrEqualsExpression
	| expression (
		DOUBLE_EQUAL
		| GREATER_THAN
		| GREATER_THAN_EQUAL
		| LESS_THAN
		| LESS_THAN_EQUAL
	) expression			# BinaryCompareExpression
	| stringExpression		# StringExpression_
	| booleanExpression		# BooleanExpression_
	| variableExpression	# VariableExpression_;

callExpression:
	identifier LEFT_PARENTHESE multiValueExpression RIGHT_PARENTHESE;

multiValueExpression:
	(
		NEWLINE* expression (
			NEWLINE* (NEWLINE | COMMA) NEWLINE* expression
		)*
	)? NEWLINE* COMMA? NEWLINE*;

numberExpression: (PLUS | MINUS)? (DOUBLE | INTEGER);
stringExpression: STRING;
variableExpression: identifier;

functionExpression:
	(functionConstraintExpression NEWLINE*)? functionDeclarationExpression NEWLINE*
		functionImplementationExpression
	| functionDeclarationExpression NEWLINE* functionConstraintExpression NEWLINE*
		functionImplementationExpression
	| functionDeclarationExpression NEWLINE* functionImplementationExpression NEWLINE*
		functionConstraintExpression;

functionDeclarationExpression:
	identifier? LEFT_PARENTHESE formalParameterExpression RIGHT_PARENTHESE;

formalParameterExpression: ((identifier COMMA)* identifier)?; //TODO 函数的参数类型

functionImplementationExpression:
	(EQUALS | RIGHT_ARROW) expression
	| NEWLINE* (EQUALS | RIGHT_ARROW)? NEWLINE* blockExpression;

functionConstraintExpression:
	WHEN NEWLINE* (blockExpression | expression);

blockExpression:
	LEFT_BRACE NEWLINE* ((expression NEWLINE+)* expression)? NEWLINE* RIGHT_BRACE;

booleanExpression: BOOLEAN;

varargsExpression: APOSTROPHE variableExpression;

identifier:
	BOOLEAN
	| WHEN
	| INCLUDE
	| ACCESS_LEVEL
	| IDENTIFIER;

ACCESS_LEVEL: 'public' | 'private';
INCLUDE: 'include';
WHEN: 'when';
BOOLEAN:
	'true'
	| 'yes'
	| 'ok'
	| 'good'
	| 'false'
	| 'no'
	| 'bad';
IDENTIFIER:
	WHEN
	| ([a-zA-Z_] | ~[\u0000-\u00ff]) (
		[a-zA-Z0-9_]
		| ~[\u0000-\u00ff]
	)*;
DOUBLE: [0-9]+ POINT [0-9]+;
INTEGER: [0-9]+;
STRING: '"' ~'"'* '"' | ['] ~[']* ['];
POINT: '.';
COMMA: ',';
LEFT_PARENTHESE: '(';
RIGHT_PARENTHESE: ')';
LEFT_BRACE: '{';
RIGHT_BRACE: '}';
LEFT_BRACKET: '[';
RIGHT_BRACKET: ']';
DOUBLE_EQUAL: '==';
EQUALS: '=';
RIGHT_ARROW: '=>';
ASSIGN: ':=';
COLON: ':';
PLUS: '+';
MINUS: '-';
MULTIPLY: '*';
DIVIDE: '/';
MODULUS: '%';
HASH: '#';
GREATER_THAN: '>';
GREATER_THAN_EQUAL: '>=';
LESS_THAN: '<';
LESS_THAN_EQUAL: '<=';
SINGLE_LINE_COMMENT: '//' ~'\n'* -> skip;
MULTILINE_COMMENT: '/*' .*? '*/' -> skip;
APOSTROPHE: '...';
NEWLINE: '\n';

WS: [ \t\r]+ -> skip;