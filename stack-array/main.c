#include<stdio.h>
#include"Stack.h"

int main(){

    Stack stack = newStack();
    
    push(stack, 5);
    push(stack, 4);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);

    printf("Elements in Stack: ");
    display(stack);
    printf("\nTop: %d", top(stack));

    printf("\nPush(element): 6");
    push(stack, 6);
    printf("\nElements in Stack: ");
    display(stack);

    printf("\nAfter Pop():");
    pop(stack);
    printf("\nElements in Stack: ");
    display(stack);

    printf("\nAfter Pop():");
    pop(stack);
    printf("\nElements in Stack: ");
    display(stack);

    printf("\nIs stack empty?");
    printf(isEmpty(stack) ? "Yes" : "No");

    clear(stack);
    printf("\nAfter calling clear():");
    printf("\nIs stack empty? ");
    printf(isEmpty(stack) ? "Yes" : "No");
    printf("\nElements in Stack: ");
    display(stack);

    destroy(&stack);
    printf("\n");
    return 0;
}