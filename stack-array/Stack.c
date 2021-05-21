#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#define MAX 10

Stack newStack(){
    Stack s = (Stack) malloc(sizeof(struct stack));
    s->items = (stackItem*) malloc(sizeof(int) * MAX);
    s->top = 0;
    return s;
}

void destroy(Stack *s){
    free(*s);
    *s = NULL;
}

void display(const Stack s){
    printf("[ ");
    for(int i = s->top - 1; i >= 0; i--){
        printf("%d ", s->items[i]);
    }
    printf("]");
}

void push(Stack s, const stackItem item){
    if (s->top < MAX)
        s->items[s->top++] = item;
}

void pop(Stack s){
    if(s->top > 0) s->top--;
}

stackItem top(const Stack s){ // peek
    if (s->top > 0) return s->items[s->top-1];
    else return -1; // invalid operation
}

stackItem rear(const Stack s){
    if(s->top > 0) return s->items[0];
    else return -1; // invalid operation
}

int isEmpty(const Stack s){
    return s->top == 0;
}

void clear(Stack s){
    s->top = 0;
}