#include "InfixToPostfix.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Stack.h"

// private functions
int equals(String first, String second) { return strcmp(first, second) == 0; }

int isOpenPar(String token) { return equals(token, "("); }

int isClosePar(String token) { return equals(token, ")"); }

int precedence(String operator) {
  return equals(operator, "*") || equals(operator, "/") ||
         equals(operator, "%");
}

int isOperand(String token) {
  int length = strlen(token);

  for (int i = 0; i < length; i++) {
    if (token[i] < '0' || token[i] > '9') return 0;
  }
  return 1;
}

int isOperator(String token) {
  return equals(token, "+") || equals(token, "-") || equals(token, "*") ||
         equals(token, "/") || equals(token, "%");
}

String process(String text) {
  static char processedString[50];

  int length = strlen(text), i = 0, j = 0;

  while (i < length) {
    if (text[i] == ' ')
      i++;
    else if (text[i] >= '0' && text[i] <= '9') {
      processedString[j++] = text[i++];
    } else {
      processedString[j++] = ' ';
      processedString[j++] = text[i++];
      processedString[j++] = ' ';
    }
  }
  processedString[j] = '\0';

  return processedString;
}

String compute(String num1, String num2, String operator) {
  int left = atoi(num1);
  int right = atoi(num2);

  int res;

  static char result[50];

  if (equals(operator, "+"))
    res = left + right;
  else if (equals(operator, "-"))
    res = left - right;
  else if (equals(operator, "*"))
    res = left * right;
  else if (equals(operator, "/"))
    res = left / right;

  sprintf(result, "%d", res);

  return result;
}

// public functions

// assumes string has only operands and operators
String infixToPostfix(String expression) {
  // initialize utility stack
  Stack stack = newStack();

  // process sting
  expression = process(expression);

  // string initializations
  static char result[50] = "";
  char space[2] = " ";

  // tokenizer initialization
  String token = strtok(expression, space);

  while (token != NULL) {
    if (isOperand(token)) {
      strcat(result, token);
      strcat(result, space);
    } else if (isOperator(token)) {
      if (!(isEmpty(stack) || isOpenPar(peek(stack)) ||
            precedence(token) > precedence(peek(stack)))) {
        while (!(isEmpty(stack) || isOpenPar(peek(stack)))) {
          strcat(result, pop(stack));
          strcat(result, space);
        }
      }
      push(stack, token);
    } else if (isOpenPar(token)) {
      push(stack, token);
    } else if (isClosePar(token)) {
      while (!isOpenPar(peek(stack))) {
        strcat(result, pop(stack));
        strcat(result, space);
      }
      pop(stack);
    }

    token = strtok(NULL, space);
  }

  while (!isEmpty(stack)) {
    strcat(result, pop(stack));
    strcat(result, space);
  }

  // destroy allocated memory for stack
  destroyStack(&stack);

  return result;
}

// assumes expression is formatted into postfix form
String evaluate(String postfix) {
  Stack stack = newStack();

  char space[2] = " ";
  String token = strtok(postfix, space), right, left;

  static String result;

  while (token != NULL) {
    if (isOperand(token))
      push(stack, token);
    else {
      right = pop(stack);
      left = pop(stack);
      push(stack, compute(left, right, token));
    }

    token = strtok(NULL, space);
  }

  result = pop(stack);

  destroyStack(&stack);

  return result;
}