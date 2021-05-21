#ifndef STACK_H
#define STACK_H

typedef char *stackItem;
typedef struct node *nodeptr;

struct node {
  stackItem item;
  nodeptr next;
};

typedef nodeptr Stack;

Stack newStack();
int isEmpty(const Stack s);
void display(const Stack s);
void clear(Stack s);
void destroyStack(Stack *s);
stackItem pop(Stack s);
void push(Stack s, stackItem item);
stackItem peek(const Stack s);

#endif