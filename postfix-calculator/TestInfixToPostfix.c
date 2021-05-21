#include <stdio.h>
#include <string.h>

#include "InfixToPostfix.h"
#include "Stack.h"

int main() {
  char infix[] = "4*5+6/2-1";

  printf("\nInfix to postfix conversion: ");
  String postfix = infixToPostfix(infix);

  printf("\nPostfix evaluation: ");
  printf("\nInfix String: %s", infix);
  printf("\nPostfix String: %s", postfix);

  printf("\n\nPostfix evaluation: ");
  printf("\nPostfix String: %s", postfix);
  printf("\nResult = %s\n", evaluate(postfix));

  return 0;
}