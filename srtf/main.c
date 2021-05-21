#include <stdio.h>

#include "PriorityQueue.h"
#include "SRTF.h"

int main() {
  PriorityQueue main_q = newPriorityQueue(ARRIVAL);
  PriorityQueue waiting_q = newPriorityQueue(BURST);
  PriorityQueue result_q = newPriorityQueue(ARRIVAL);

  getValues(main_q);
  computeWaitingTime(main_q, waiting_q, result_q);

  displayTable(result_q);

  destroy(&main_q);
  destroy(&waiting_q);
  destroy(&result_q);

  return 0;
}