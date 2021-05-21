#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

typedef char *String;

String infixToPostfix(String expression);
String evaluate(String postfix);

#endif