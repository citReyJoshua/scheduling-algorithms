#include "SJF.h"

#include <stdio.h>

#include "PriorityQueue.h"

void inputValues(PriorityQueue q) {
  int size;

  printf("\nInput number of processes: ");
  scanf("%d", &size);

  for (int i = 1; i <= size; i++) {
    int burstTime;

    // get arrival and burst value
    printf("\nP%d: ", i);
    printf("\n\nBurst Time: ");
    scanf("%d", &burstTime);
    printf("Arrival Time: 0");

    queueItem item;

    item.processNo = i;
    item.bt = burstTime;
    item.at = 0;
    item.wt = 0;
    item.tat = 0;
    enqueue(q, item);
  }
}

void displayTable(PriorityQueue q) {
  int count = 0, accumulatedFT = 0;
  float waitingTimes, turnaroundTimes;

  printf("\nP\tBT\tAT\tWT\tTAT");
  while (!isEmpty(q)) {
    count++;

    // get last dequeued item
    queueItem item = head(q);
    dequeue(q);

    accumulatedFT += item.bt;
    item.wt = accumulatedFT - item.at - item.bt;
    item.tat = item.bt + item.wt;

    // accumulate wt and tat to get average
    waitingTimes += item.wt;
    turnaroundTimes += item.tat;
    printf("\nP%d\t%d\t%d\t%d\t%d", item.processNo, item.bt, item.at, item.wt,
           item.tat);
  }
  printf("\nAverage WT = %.2f", waitingTimes / count);
  printf("\nAverage TAT = %.2f", turnaroundTimes / count);
}