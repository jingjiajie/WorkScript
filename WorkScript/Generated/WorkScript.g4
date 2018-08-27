grammar WorkScript;

program: (expression (NEWLINE | EOF) | NEWLINE)* EOF?;

expression:
	LEFT_PARENTHESE expression RIGHT_PARENTHESE											# ParentheseExpression
	| expression LEFT_PARENTHESE parameterExpression RIGHT_PARENTHESE					# FunctionInvocationExpression
	| LEFT_BRACKET (expression (COMMA expression)*)? RIGHT_BRACKET						# ListExpression
	| expression POINT identifier LEFT_PARENTHESE parameterExpression RIGHT_PARENTHESE	#
		MethodInvocationExpression
	| expression POINT identifier				# MemberEvaluateExpression
	| functionExpression						# FunctionExpression_
	| expression (MULTIPLY | DIVIDE) expression	# MultiplyDivideExpression
	| numberExpression variableExpression		# NonSignMultiplyExpression
	| expression (PLUS | MINUS) expression		# PlusMinusExpression
	| numberExpression							# NumberExpression_
	| MINUS expression							# NegativeExpression
	| PLUS expression							# PositiveExpression
	| expression ASSIGN expression				# AssignmentExpression
	| expression DOUBLE_EQUAL expression		# EqualsExpression
	| expression EQUALS expression				# AssignmentOrEqualsExpression
	| expression (
		GREATER_THAN
		| GREATER_THAN_EQUAL
		| LESS_THAN
		| LESS_THAN_EQUAL
	) expression			# CompareExpression
	| stringExpression		# StringExpression_
	| variableExpression	# VariableExpression_;

parameterExpression: (expression (COMMA expression)*)?;

numberExpression: (PLUS | MINUS)? NUMBER;
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
	EQUALS expression
	| NEWLINE* EQUALS? NEWLINE* blockExpression;

functionConstraintExpression:
	WHEN NEWLINE* (blockExpression | expression);

blockExpression:
	LEFT_BRACE NEWLINE* ((expression NEWLINE+)* expression)? NEWLINE* RIGHT_BRACE;

identifier: WHEN | IDENTIFIER;

WHEN: 'when';
IDENTIFIER:
	WHEN
	| ([a-zA-Z_] | ~[\u0000-\u00ff]) (
		[a-zA-Z0-9_]
		| ~[\u0000-\u00ff]
	)*;
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
DOUBLE_EQUAL: '==';
EQUALS: '=';
ASSIGN: ':=';
PLUS: '+';
MINUS: '-';
MULTIPLY: '*';
DIVIDE: '/';
GREATER_THAN: '>';
GREATER_THAN_EQUAL: '>=';
LESS_THAN: '<';
LESS_THAN_EQUAL: '<=';

WS: [ \t]+ -> skip;