#include <stdio.h>

#include "NPP.h"
int main() {
  PriorityQueue q = newPriorityQueue();
  PriorityQueue result_q = newPriorityQueue();
  getValues(q);
  computeWaitingTime(q, result_q);
  displayTable(result_q);

  destroy(&q);
  return 0;
}