// priority queue in the form of minHeap
// an element of the lowest value has highest priority

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

typedef struct process {
  // here, bt is the priority value
  int processNo, bt, at, wt, tat;
} queueItem;

typedef struct priorityQ {
  queueItem *items;
  int count;
} * PriorityQueue;

// public functions
PriorityQueue newPriorityQueue();
void display(const PriorityQueue q);
void enqueue(PriorityQueue q, const queueItem item);
void dequeue(PriorityQueue q);
int isFull(const PriorityQueue q);
int isEmpty(const PriorityQueue q);
void clear(PriorityQueue q);
queueItem head(const PriorityQueue q);
queueItem tail(const PriorityQueue q);
void destroy(PriorityQueue *q);

// private functions
void heapifyDown(PriorityQueue q);
void heapifyUp(PriorityQueue q);
int getRightChildIndex(const int index);
int getLeftChildIndex(const int index);
int getParentIndex(const int index);
int hasRightChild(const int count, const int index);
int hasLeftChild(const int count, const int index);
int hasParent(const int index);
int leftChildPriorityValue(const PriorityQueue q, const int index);
int rightChildPriorityValue(const PriorityQueue q, const int index);
int parentPriorityValue(const PriorityQueue q, const int index);
void swap(PriorityQueue q, const int indexOne, const int indexTwo);

#endif
