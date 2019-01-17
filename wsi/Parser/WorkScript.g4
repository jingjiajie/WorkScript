grammar WorkScript;

program: line* EOF;

line: (SEMICOLON* expression SEMICOLON*)+ NEWLINE? | SEMICOLON+ NEWLINE? | NEWLINE;

expression:
	ACCESS_LEVEL COLON								# AccessLevelExpression
	| LEFT_PARENTHESE expression RIGHT_PARENTHESE	# ParentheseExpression
	// | LEFT_BRACKET (expression (COMMA expression)*)? RIGHT_BRACKET # ListExpression | expression
	// POINT identifier # MemberEvaluateExpression
	| stdFunctionDeclExpression							# StdFunctionDeclExpression_
	| functionExpression								# FunctionExpression_
	| callExpression									# CallExpression_
	| expression (STAR | SLASH | PERCENT) expression	# MultiplyDivideModulusExpression
	| expression (PLUS | MINUS) expression				# PlusMinusExpression
	| numberExpression									# NumberExpression_
	| MINUS expression									# NegativeExpression
	| PLUS expression									# PositiveExpression
	| expression ASSIGN expression						# AssignmentExpression
	| expression EQUALS expression						# AssignmentOrEqualsExpression
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

stdFunctionDeclExpression:
	typeName STAR* functionName LEFT_PARENTHESE stdFormalParameterExpression RIGHT_PARENTHESE;

stdFormalParameterExpression:
	NEWLINE* (
		stdFormalParameterItem (
			NEWLINE* (NEWLINE | COMMA) NEWLINE* stdFormalParameterItem
		)*
	)? (NEWLINE* (NEWLINE | COMMA) NEWLINE* APOSTROPHE)? NEWLINE* COMMA? NEWLINE*;

stdFormalParameterItem: typeName STAR* identifier;

functionExpression:
	(functionConstraintExpression NEWLINE*)? functionDeclarationExpression NEWLINE*
		functionImplementationExpression
	| functionDeclarationExpression NEWLINE* functionConstraintExpression NEWLINE*
		functionImplementationExpression
	| functionDeclarationExpression NEWLINE* functionImplementationExpression NEWLINE*
		functionConstraintExpression;

functionDeclarationExpression:
	(functionName? | typeName STAR* functionName) LEFT_PARENTHESE formalParameterExpression
		RIGHT_PARENTHESE;

typeName: identifier;
functionName: identifier;

formalParameterExpression:
	NEWLINE* (
		formalParameterItem (
			NEWLINE* (NEWLINE | COMMA) NEWLINE* formalParameterItem
		)*
	)? NEWLINE* COMMA? NEWLINE*;

formalParameterItem: (typeName STAR*)? expression;

functionImplementationExpression:
	(EQUALS | RIGHT_ARROW) expression
	| NEWLINE* (EQUALS | RIGHT_ARROW)? NEWLINE* block;

functionConstraintExpression:
	WHEN NEWLINE* (block | expression);

block:
	LEFT_BRACE line* RIGHT_BRACE;

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
SEMICOLON: ';';
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
STAR: '*';
SLASH: '/';
PERCENT: '%';
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