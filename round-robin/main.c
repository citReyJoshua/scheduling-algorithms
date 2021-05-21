#include <stdio.h>

#include "RR.h"
int main() {
  Queue q = newQueue();
  int quantum;

  getValues(q);

  // get quantum
  printf("\nInput quantum value: ");
  scanf("%d", &quantum);

  computeWaitingTime(q, quantum);

  displayTable(q);

  destroyQueue(&q);

  return 0;
}