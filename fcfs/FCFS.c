#include "FCFS.h"

#include <stdio.h>

#include "Queue.h"

void inputValues(Queue q) {
  int size, accumulatedFT = 0;

  printf("\nInput number of processes: ");
  scanf("%d", &size);

  for (int i = 1; i <= size; i++) {
    int burstTime;

    // get arrival and burst value
    printf("\n\nP%d: ", i);
    printf("\nBurst Time: ");
    scanf("%d", &burstTime);

    accumulatedFT += burstTime;

    queueItem item;

    item.bt = burstTime;
    item.wt = accumulatedFT - burstTime;
    item.tat = burstTime + item.wt;

    enqueue(q, item);
  }
}

void displayTable(Queue q) {
  int count = 0;
  float waitingTimes, turnaroundTimes;

  printf("\nP\tBT\tWT\tTAT");
  while (!isEmpty(q)) {
    count++;

    // get last dequeued item
    queueItem item = head(q);
    dequeue(q);

    // accumulate wt and tat to get average
    waitingTimes += item.wt;
    turnaroundTimes += item.tat;
    printf("\nP%d\t%d\t%d\t%d", count, item.bt, item.wt, item.tat);
  }
  printf("\nAverage WT = %.2f", waitingTimes / count);
  printf("\nAverage TAT = %.2f", turnaroundTimes / count);
}
