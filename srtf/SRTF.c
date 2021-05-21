#include "SRTF.h"

#include <stdio.h>

#include "PriorityQueue.h"

void getValues(PriorityQueue q) {
  int size;

  printf("\nInput number of processes: ");
  scanf("%d", &size);

  for (int i = 1; i <= size; i++) {
    int burstTime, arrivalTime;

    // get arrival and burst value
    printf("\nP%d: ", i);
    printf("\n\nBurst Time: ");
    scanf("%d", &burstTime);
    printf("Arrival Time: ");
    scanf("%d", &arrivalTime);

    queueItem item;

    item.processNo = i;
    item.bt = burstTime;
    item.rb = burstTime;
    item.at = arrivalTime;
    item.wt = 0;  // temporary
    enqueue(q, item);
  }
}

// assumes waiting queue and result_q is empty
void computeWaitingTime(PriorityQueue ready_q, PriorityQueue waiting_q,
                        PriorityQueue result_q) {
  int completed = 0, n = ready_q->count;

  queueItem temp = head(ready_q);
  dequeue(ready_q);

  int currentTime = temp.at;

  enqueue(waiting_q, temp);

  while (completed != n) {
    if (!isEmpty(ready_q) && head(ready_q).at == currentTime) {
      queueItem next = head(ready_q);
      enqueue(waiting_q, next);
      dequeue(ready_q);
    }
    if (isEmpty(waiting_q)) {
      currentTime++;
      continue;
    }
    queueItem current = head(waiting_q);
    decreaseRB(waiting_q);
    if (current.rb == 0) {
      current.wt = currentTime - current.at - current.bt;
      enqueue(result_q, current);
      dequeue(waiting_q);
      completed++;
      continue;
    }
    currentTime++;
  }
}

void displayTable(PriorityQueue q) {
  int count = 0;
  double waitingTimes, turnaroundTimes;

  printf("\nP\tBT\tAT\tWT\tTAT");
  while (!isEmpty(q)) {
    count++;
    queueItem item = head(q);
    dequeue(q);

    waitingTimes += item.wt;
    turnaroundTimes += item.wt + item.bt;
    printf("\nP%d\t%d\t%d\t%d\t%d", item.processNo, item.bt, item.at, item.wt,
           item.wt + item.bt);
  }

  printf("\nAverage WT = %.2f", waitingTimes / count);
  printf("\nAverage TAT = %.2f", turnaroundTimes / count);
}