grammar WorkScript;

program: line* EOF;

line: (SEMICOLON* (function | expression) SEMICOLON*)+ NEWLINE?
	| SEMICOLON+ NEWLINE?
	| NEWLINE;

function:
	stdFunctionDecl		# StdFunctionDecl_
	| functionDefine	# FunctionDefine_;

expression:
	ACCESS_LEVEL COLON								# AccessLevel
	| LEFT_PARENTHESE expression RIGHT_PARENTHESE	# Parenthese
	// | LEFT_BRACKET (expression (COMMA expression)*)? RIGHT_BRACKET # List | expression POINT
	// identifier # MemberEvaluate
	| call												# Call_
	| expression (STAR | SLASH | PERCENT) expression	# MultiplyDivideModulus
	| expression (PLUS | MINUS) expression				# PlusMinus
	| (PLUS | MINUS)? (DOUBLE | INTEGER)				# Number
	| MINUS expression									# Negative
	| PLUS expression									# Positive
	| expression ASSIGN expression						# Assignment
	| expression EQUALS expression						# AssignmentOrEquals
	| expression (
		DOUBLE_EQUAL
		| GREATER_THAN
		| GREATER_THAN_EQUAL
		| LESS_THAN
		| LESS_THAN_EQUAL
	) expression	# BinaryCompare
	| STRING		# String
	| BOOLEAN		# Boolean
	| identifier	# Variable;

call: identifier LEFT_PARENTHESE multiValue RIGHT_PARENTHESE;

multiValue: ( NEWLINE* expression ( newlineOrComma expression)*)?;

stdFunctionDecl:
	type STAR* functionName LEFT_PARENTHESE stdFormalParameter RIGHT_PARENTHESE;

stdFormalParameter:
	NEWLINE* (
		stdFormalParameterItem (
			newlineOrComma stdFormalParameterItem
		)*
	)? (newlineOrComma APOSTROPHE)?;

stdFormalParameterItem: type STAR* identifier?;

functionDefine:
	(functionConstraint NEWLINE*)? functionDeclaration NEWLINE* functionImplementation
	| functionDeclaration NEWLINE* functionConstraint NEWLINE* functionImplementation
	| functionDeclaration NEWLINE* functionImplementation NEWLINE* functionConstraint;

functionDeclaration:
	(functionName? | type STAR* functionName) LEFT_PARENTHESE formalParameter RIGHT_PARENTHESE;

type: (typeQualifier | typeSpecifier | storageClassSpecifier)+;
typeSpecifier: identifier;
typeQualifier: CONST | VOLATILE;
storageClassSpecifier : STATIC | EXTERN;
functionName: identifier;

formalParameter:
	NEWLINE* (
		formalParameterItem (newlineOrComma formalParameterItem)*
	)?;

formalParameterItem: (type STAR*)? expression;

functionImplementation:
	(EQUALS | RIGHT_ARROW) expression
	| NEWLINE* (EQUALS | RIGHT_ARROW)? NEWLINE* block;

functionConstraint: WHEN NEWLINE* (block | expression);

block: LEFT_BRACE line* RIGHT_BRACE;

staticVarargs: APOSTROPHE identifier;

newlineOrComma: COMMA | NEWLINE+ | NEWLINE* COMMA NEWLINE*;

identifier: IDENTIFIER;

ACCESS_LEVEL: 'public' | 'private';
INCLUDE: 'include';
WHEN: 'when';
CONST: 'const';
VOLATILE: 'volatile';
EXTERN: 'extern';
STATIC: 'static';

BOOLEAN:
	'true'
	| 'yes'
	| 'ok'
	| 'good'
	| 'false'
	| 'no'
	| 'bad';
IDENTIFIER:
	([a-zA-Z_] | ~[\u0000-\u00ff]) (
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