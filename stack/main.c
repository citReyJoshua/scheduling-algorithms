#include <stdio.h>

#include "Stack.h"

int main() {
  Stack stack = newStack();

  // display
  printf("\nStack = ");
  display(stack);

  // push multiple items
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);

  // display
  printf("\nStack = ");
  display(stack);
  printf("\nTop item = %d", peek(stack));

  // push 6
  push(stack, 6);

  // display
  printf("\nPushed(6) = ");
  display(stack);
  printf("\nTop item = %d", peek(stack));

  // pop once
  pop(stack);

  // display
  printf("\nPopped Once = ");
  display(stack);
  printf("\nTop item = %d", peek(stack));

  // pop once more
  pop(stack);

  // display
  printf("\nPopped Once More = ");
  display(stack);
  printf("\nTop item = %d", peek(stack));

  // check if empty
  printf("\nIs stack empty? ");
  printf(isEmpty(stack) ? "YES" : "NO");

  // clear stack
  clear(stack);
  printf("\nSTACK CLEARED");

  // check if empty once more
  printf("\nIs stack empty? ");
  printf(isEmpty(stack) ? "YES" : "NO");

  // display stack
  printf("\nStack = ");
  display(stack);

  // destroy stack
  destroyStack(&stack);

  printf("\n");
  return 0;
}