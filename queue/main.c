#include <stdio.h>

#include "Queue.h"
int main() {
  // initialize
  Queue q = newQueue();
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);

  // display
  printf("\nElements in Queue = ");
  display(q);
  printf("\nHead: %d", head(q));
  printf("\nTail: %d", tail(q));

  // enqueue 6
  enqueue(q, 6);
  printf("\nEnqueued 6");

  // display
  printf("\nElements in Queue = ");
  display(q);
  printf("\nHead: %d", head(q));
  printf("\nTail: %d", tail(q));

  // dequeue
  dequeue(q);
  printf("\nDequeued");

  // display
  printf("\nElements in Queue = ");
  display(q);
  printf("\nHead: %d", head(q));
  printf("\nTail: %d", tail(q));

  // check if empty
  printf("\nIs queue empty? ");
  printf(isEmpty(q) ? "YES" : "NO");

  // check if full
  printf("\nIs queue full? ");
  printf(isFull(q) ? "YES" : "NO");

  // clear queue
  clear(q);
  printf("\nQUEUE CLEARED");

  // check if empty
  printf("\nIs queue empty? ");
  printf(isEmpty(q) ? "YES" : "NO");

  // display
  printf("\nElements in Queue = ");
  display(q);

  // destroy queue
  destroyQueue(&q);

  printf("\n");
  return 0;
}