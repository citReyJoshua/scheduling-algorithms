#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>

nodeptr createNode(stackItem item) {
  nodeptr p = (nodeptr)malloc(sizeof(struct node));
  p->item = item;
  p->next = NULL;
  return p;
}

// creates head node
Stack newStack() { return createNode(0); }

int isEmpty(const Stack s) { return s->next == NULL; }

void display(const Stack s) {
  nodeptr p = s->next;
  printf("{ ");
  while (p != NULL) {
    printf("%s ", p->item);
    p = p->next;
  }
  printf("}");
}

void clear(Stack s) {
  nodeptr prev = s->next;
  nodeptr p;

  while (prev != NULL) {
    p = prev->next;
    free(prev);
    prev = p;
  }
  s->next = NULL;
}

void destroyStack(Stack *s) {
  clear(*s);
  free(*s);
  *s = NULL;
}

stackItem pop(Stack s) {
  stackItem result = peek(s);

  nodeptr temp = s->next;
  s->next = temp->next;
  temp->item = NULL;
  temp->next = NULL;
  free(temp);

  return result;
}

void push(Stack s, stackItem item) {
  nodeptr temp = createNode(item);
  temp->next = s->next;
  s->next = temp;
}

stackItem peek(const Stack s) { return s->next != NULL ? s->next->item : NULL; }