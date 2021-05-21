#include "RR.h"

#include <stdio.h>

void computeWaitingTime(Queue q, int quantum) {
  int completed = 0, currentTime = 0, n = q->count;

  while (completed != n) {
    queueItem current = head(q);
    dequeue(q);

    if (current.rb == 0) {
      enqueue(q, current);
      continue;
    }

    else {
      if (current.rb <= quantum) {
        currentTime += current.rb;
        current.rb = 0;
        current.wt = currentTime - current.bt;
        completed++;
      } else {
        current.rb -= quantum;
        currentTime += quantum;
      }
      enqueue(q, current);
    }
  }
}
void displayTable(Queue q) {
  int count = q->count;
  double waitingTimes, turnaroundTimes;

  printf("\nP\tBT\tWT\tTAT");
  while (!isEmpty(q)) {
    queueItem item = head(q);
    dequeue(q);

    waitingTimes += item.wt;
    turnaroundTimes += item.wt + item.bt;
    printf("\nP%d\t%d\t%d\t%d", item.processNo, item.bt, item.wt,
           (item.wt + item.bt));
  }

  printf("\nAverage WT = %.2f", waitingTimes / count);
  printf("\nAverage TAT = %.2f", turnaroundTimes / count);
}
void getValues(Queue q) {
  int size;

  printf("\nInput number of processes: ");
  scanf("%d", &size);

  for (int i = 1; i <= size; i++) {
    int burstTime, arrivalTime;

    // get arrival and burst value
    printf("\nP%d: ", i);
    printf("\nBurst Time: ");
    scanf("%d", &burstTime);

    queueItem item;

    item.processNo = i;
    item.bt = burstTime;
    item.rb = burstTime;
    item.wt = 0;  // temporary
    enqueue(q, item);
  }
}