grammar WorkScript;

program: (NEWLINE | command NEWLINE?)* (
		NEWLINE
		| expression NEWLINE?
	)* EOF;

command: includeCommand;

includeCommand: HASH INCLUDE STRING;

expression:
	LEFT_PARENTHESE expression RIGHT_PARENTHESE											# ParentheseExpression
	| expression LEFT_PARENTHESE parameterExpression RIGHT_PARENTHESE					# FunctionInvocationExpression
	| LEFT_BRACKET (expression (COMMA expression)*)? RIGHT_BRACKET						# ListExpression
	| expression POINT identifier LEFT_PARENTHESE parameterExpression RIGHT_PARENTHESE	#
		MethodInvocationExpression
	| expression POINT identifier							# MemberEvaluateExpression
	| functionExpression									# FunctionExpression_
	| expression (MULTIPLY | DIVIDE | MODULUS) expression	# MultiplyDivideModulusExpression
	| numberExpression variableExpression					# NonSignMultiplyExpression
	| expression (PLUS | MINUS) expression					# PlusMinusExpression
	| numberExpression										# NumberExpression_
	| MINUS expression										# NegativeExpression
	| PLUS expression										# PositiveExpression
	| expression ASSIGN expression							# AssignmentExpression
	| expression DOUBLE_EQUAL expression					# EqualsExpression
	| expression EQUALS expression							# AssignmentOrEqualsExpression
	| expression (
		GREATER_THAN
		| GREATER_THAN_EQUAL
		| LESS_THAN
		| LESS_THAN_EQUAL
	) expression			# CompareExpression
	| stringExpression		# StringExpression_
	| booleanExpression		# BooleanExpression_
	| variableExpression	# VariableExpression_;

parameterExpression:
	(
		NEWLINE* parameterExpressionItem (
			NEWLINE* (NEWLINE | COMMA) NEWLINE* parameterExpressionItem
		)*
	)? NEWLINE* COMMA? NEWLINE*;
parameterExpressionItem: (expression | varargsExpression);

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
	identifier? LEFT_PARENTHESE parameterExpression RIGHT_PARENTHESE;

functionImplementationExpression:
	(EQUALS | RIGHT_ARROW) expression
	| NEWLINE* (EQUALS | RIGHT_ARROW)? NEWLINE* blockExpression;

functionConstraintExpression:
	WHEN NEWLINE* (blockExpression | expression);

blockExpression:
	LEFT_BRACE NEWLINE* ((expression NEWLINE+)* expression)? NEWLINE* RIGHT_BRACE;

booleanExpression: BOOLEAN;

varargsExpression: APOSTROPHE variableExpression;

identifier: BOOLEAN | WHEN | INCLUDE | IDENTIFIER;

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
NEWLINE:
	'\r\n'
	| '\n'
	| SINGLE_LINE_COMMENT
	| MULTILINE_COMMENT;
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
SINGLE_LINE_COMMENT: '//' ~'\n'*;
MULTILINE_COMMENT_IN_SINGLE_LINE: '/*' ~'\n'*? '*/' -> skip;
MULTILINE_COMMENT: '/*' .*? '\n' .*? '*/';
APOSTROPHE: '...';

WS: [ \t]+ -> skip;