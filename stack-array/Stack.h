#ifndef STACK_H
#define STACK_H

typedef int stackItem;

typedef struct stack {
    stackItem *items;
    int top;
} *Stack;

Stack newStack();
void push(Stack s, const stackItem item);
void pop(Stack s);
stackItem top(const Stack s);
stackItem rear(const Stack s);
void display(const Stack s);
int isEmpty(const Stack s);
void clear(Stack s);
void destroy(Stack *s);
#endif
