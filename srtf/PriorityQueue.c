#include "PriorityQueue.h"

#include <stdio.h>
#include <stdlib.h>

// public functions
PriorityQueue newPriorityQueue(char type) {
  PriorityQueue q = (PriorityQueue)malloc(sizeof(struct priorityQ));
  q->items = (queueItem *)malloc(sizeof(queueItem *) * MAX_SIZE);
  q->count = 0;
  q->type = type;
  return q;
}
void display(const PriorityQueue q) {
  printf("\n[");
  for (int i = 0; i < q->count; i++) {
    printf("\n\t{");
    printf("\n\t\tNo = %d", q->items[i].processNo);
    printf("\n\t\tBurst Time = %d", q->items[i].rb);
    printf("\n\t\tArrival Time = %d", q->items[i].at);
    printf("\n\t\tPriority Value = %d",
           q->type == BURST ? q->items[i].rb : q->items[i].at);
    printf("\n\t}");
  }
  printf("\n]");
}
void enqueue(PriorityQueue q, const queueItem item) {
  if (q->count < MAX_SIZE) {
    q->items[q->count++] = item;
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
void decreaseRB(PriorityQueue q) { q->items[0].rb--; }
int getPValue(const PriorityQueue q, int index) {
  return q->type == BURST ? q->items[index].rb : q->items[index].at;
}
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
  return getPValue(q, getLeftChildIndex(index));
}
int rightChildPriorityValue(const PriorityQueue q, const int index) {
  return getPValue(q, getRightChildIndex(index));
}
int parentPriorityValue(const PriorityQueue q, const int index) {
  return getPValue(q, getParentIndex(index));
}
void swap(PriorityQueue q, const int indexOne, const int indexTwo) {
  queueItem temp = q->items[indexOne];
  q->items[indexOne] = q->items[indexTwo];
  q->items[indexTwo] = temp;
}

void heapifyDown(PriorityQueue q) {
  int index = 0;
  while (hasLeftChild(q->count, index)) {
    int smallerChildIndex = getLeftChildIndex(index);
    if (hasRightChild(q->count, index) &&
        rightChildPriorityValue(q, index) < leftChildPriorityValue(q, index))
      smallerChildIndex = getRightChildIndex(index);

    if (getPValue(q, index) < getPValue(q, smallerChildIndex))
      break;
    else
      swap(q, index, smallerChildIndex);

    index = smallerChildIndex;
  }
}
void heapifyUp(PriorityQueue q) {
  int index = q->count - 1;
  while (hasParent(index) &&
         parentPriorityValue(q, index) > getPValue(q, index)) {
    swap(q, getParentIndex(index), index);
    index = getParentIndex(index);
  }
}