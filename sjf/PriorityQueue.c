#include "PriorityQueue.h"

#include <stdio.h>
#include <stdlib.h>
int MAX_SIZE = 10;

// public functions
PriorityQueue newPriorityQueue() {
  PriorityQueue q = (PriorityQueue)malloc(sizeof(struct priorityQ));
  q->items = (queueItem *)malloc(sizeof(queueItem *) * MAX_SIZE);
  q->count = 0;
  return q;
}
void display(const PriorityQueue q) {
  printf("\n[");
  for (int i = 0; i < q->count; i++) {
    printf("\n\t{");
    printf("\n\t\tNo = %d", q->items[i].processNo);
    printf("\n\t\tBT = %d", q->items[i].bt);
    printf("\n\t\tAT = %d", q->items[i].at);
    printf("\n\t}");
  }
  printf("\n]");
}
void enqueue(PriorityQueue q, const queueItem item) {
  if (q->count < MAX_SIZE) {
    q->items[q->count].processNo = item.processNo;
    q->items[q->count].bt = item.bt;
    q->items[q->count].at = item.at;
    q->items[q->count].wt = item.wt;
    q->items[q->count++].tat = item.tat;
    heapifyUp(q);
  }
}
void dequeue(PriorityQueue q) {
  if (q->count > 0) {
    q->items[0] = q->items[--(q->count)];
    heapifyDown(q);
  }
}
int isFull(const PriorityQueue q) { return q->count == MAX_SIZE; }
int isEmpty(const PriorityQueue q) { return q->count == 0; }
void clear(PriorityQueue q) { q->count = 0; }
queueItem head(const PriorityQueue q) { return q->items[0]; }
queueItem tail(const PriorityQueue q) { return q->items[q->count - 1]; }
void destroy(PriorityQueue *q) {
  free((*q)->items);
  free(*q);
  *q = NULL;
}

// private functions
int getRightChildIndex(const int index) { return 2 * index + 2; }
int getLeftChildIndex(const int index) { return 2 * index + 1; }
int getParentIndex(const int index) { return (index - 1) / 2; }
int hasRightChild(const int count, const int index) {
  return getRightChildIndex(index) < count;
}
int hasLeftChild(const int count, const int index) {
  return getLeftChildIndex(index) < count;
}
int hasParent(const int index) { return getParentIndex(index) >= 0; }
int leftChildPriorityValue(const PriorityQueue q, const int index) {
  return q->items[getLeftChildIndex(index)].bt;
}
int rightChildPriorityValue(const PriorityQueue q, const int index) {
  return q->items[getRightChildIndex(index)].bt;
}
int parentPriorityValue(const PriorityQueue q, const int index) {
  return q->items[getParentIndex(index)].bt;
}
void swap(PriorityQueue q, const int indexOne, const int indexTwo) {
  int temp;

  temp = q->items[indexOne].processNo;
  q->items[indexOne].processNo = q->items[indexTwo].processNo;
  q->items[indexTwo].processNo = temp;

  temp = q->items[indexOne].bt;
  q->items[indexOne].bt = q->items[indexTwo].bt;
  q->items[indexTwo].bt = temp;

  temp = q->items[indexOne].at;
  q->items[indexOne].at = q->items[indexTwo].at;
  q->items[indexTwo].at = temp;

  temp = q->items[indexOne].wt;
  q->items[indexOne].wt = q->items[indexTwo].wt;
  q->items[indexTwo].wt = temp;

  temp = q->items[indexOne].tat;
  q->items[indexOne].tat = q->items[indexTwo].tat;
  q->items[indexTwo].tat = temp;
}

void heapifyDown(PriorityQueue q) {
  int index = 0;
  while (hasLeftChild(q->count, index)) {
    int smallerChildIndex = getLeftChildIndex(index);
    if (hasRightChild(q->count, index) &&
        rightChildPriorityValue(q, index) < leftChildPriorityValue(q, index))
      smallerChildIndex = getRightChildIndex(index);

    if (q->items[index].bt < q->items[smallerChildIndex].bt)
      break;
    else
      swap(q, index, smallerChildIndex);

    index = smallerChildIndex;
  }
}
void heapifyUp(PriorityQueue q) {
  int index = q->count - 1;
  while (hasParent(index) &&
         parentPriorityValue(q, index) > q->items[index].bt) {
    swap(q, getParentIndex(index), index);
    index = getParentIndex(index);
  }
}