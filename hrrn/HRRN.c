#include "HRRN.h"

#include <stdio.h>

#include "SortedList.h"

void getValues(SortedList q) {
  int size;

  printf("\nInput number of processes: ");
  scanf("%d", &size);

  int arriv[] = {0, 2, 4, 6, 8};
  int burst[] = {3, 6, 4, 5, 2};

  for (int i = 0; i < size; i++) {
    int burstTime, arrivalTime;

    // get arrival and burst value
    printf("\nP%d: ", i + 1);
    printf("\nArrival Time: ");
    scanf("%d", &arrivalTime);
    printf("Burst Time: ");
    scanf("%d", &burstTime);

    listItem item;

    item.id = i + 1;
    item.bt = burst[i];
    item.at = arriv[i];
    item.complete = 0;  // temporary
    add(q, item);
  }
}

void computeWaitingTime(SortedList q) {
  int sum_bt = 0, tt_sum;

  for (int i = 0; i < q->length; i++) {
    sum_bt += q->items[i].bt;
  }

  for (int t = q->items[0].at; t < sum_bt;) {
    float hrr = -9999, temp;

    int loc;

    for (int i = 0; i < q->length; i++) {
      if (q->items[i].at <= t && q->items[i].complete != 1) {
        temp = (q->items[i].bt + (t - q->items[i].at)) / q->items[i].bt;

        if (hrr < temp) {
          hrr = temp;
          loc = i;
        }
      }
    }

    t += q->items[loc].bt;
    q->items[loc].wt = t - q->items[loc].at - q->items[loc].bt;
    q->items[loc].complete = 1;
  }
}

void displayTable(SortedList q) {
  double waitingTimes, turnaroundTimes;

  printf("\nP\tBT\tAT\tWT\tTAT");
  for (int i = 0; i < q->length; i++) {
    listItem item = q->items[i];

    waitingTimes += item.wt;
    turnaroundTimes += item.wt + item.bt;
    printf("\nP%d\t%d\t%d\t%d\t%d", item.id, item.bt, item.at, item.wt,
           item.wt + item.bt);
  }

  printf("\nAverage WT = %.2f", waitingTimes / q->length);
  printf("\nAverage TAT = %.2f", turnaroundTimes / q->length);
}