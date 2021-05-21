#ifndef STACK_H
#define STACK_H

typedef int stackItem;
typedef struct node *nodeptr;

struct node {
  stackItem item;
  nodeptr next;
};

typedef nodeptr Stack;

Stack newStack();
int isEmpty(Stack s);
void display(Stack s);
void clear(Stack s);
void destroyStack(Stack *s);
void pop(Stack s);
void push(Stack s, stackItem item);
stackItem peek(Stack s);

#endif