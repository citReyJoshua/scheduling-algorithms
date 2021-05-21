#include<stdio.h>
#include"PriorityQueue.h"

int main(){
    PriorityQueue queue = newPriorityQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 6);

    printf("Elements in Queue: ");
    display(queue);
    printf("\nHead: %d", head(queue));
    printf("\nTail: %d", tail(queue));

    printf("\nEnqueue (element): 5");
    enqueue(queue, 5);

    printf("\nElements in Queue: ");
    display(queue);
    printf("\nHead: %d", head(queue));
    printf("\nTail: %d", tail(queue));

    dequeue(queue);
    printf("\nAfter Dequeue():");
    printf("\nElements in Queue: ");
    display(queue);

    printf("\nIs queue empty? ");
    printf(isEmpty(queue) ? "Yes" : "No");
    printf("\nIs queue full? ");
    printf(isFull(queue) ? "Yes" : "No");

    clear(queue);
    printf("\nAfter calling clear():");
    printf("\nIs queue empty? ");
    printf(isEmpty(queue) ? "Yes" : "No");

    printf("\nElements in Queue: ");
    display(queue);

    // must destroy queue to avoid garbage memory or dangling reference
    destroy(&queue);
    
    printf("\n");
    return 0;
}