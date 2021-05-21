#include "NPP.h"

#include <stdio.h>

#include "PriorityQueue.h"

void getValues(PriorityQueue q) {
  int size;

  printf("\nInput number of processes: ");
  scanf("%d", &size);

  for (int i = 1; i <= size; i++) {
    int burstTime, priorityNo;

    // get arrival and burst value
    printf("\nP%d: ", i);
    printf("\nBurst Time: ");
    scanf("%d", &burstTime);
    printf("Priority No: ");
    scanf("%d", &priorityNo);

    queueItem item;

    item.id = i;
    item.bt = burstTime;
    item.priority_no = priorityNo;
    item.wt = 0;  // temporary
    enqueue(q, item);
  }
}

void computeWaitingTime(PriorityQueue q, PriorityQueue result_q) {
  int accumulatedFT = 0;
  while (!isEmpty(q)) {
    // get top item
    queueItem item = head(q);
    dequeue(q);
    accumulatedFT += item.bt;
    item.wt = accumulatedFT - item.bt;

    enqueue(result_q, item);
  }
}

void displayTable(PriorityQueue q) {
  int count = 0;
  double waitingTimes, turnaroundTimes;

  printf("\nP\tPN\tBT\tWT\tTAT");
  while (!isEmpty(q)) {
    count++;
    queueItem item = head(q);
    dequeue(q);

    waitingTimes += item.wt;
    turnaroundTimes += item.wt + item.bt;
    printf("\nP%d\t%d\t%d\t%d\t%d", item.id, item.priority_no, item.bt, item.wt,
           item.wt + item.bt);
  }

  printf("\nAverage WT = %.2f", waitingTimes / count);
  printf("\nAverage TAT = %.2f", turnaroundTimes / count);
}