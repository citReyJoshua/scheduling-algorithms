// priority queue in the form of minHeap
// an element of the lowest value has highest priority

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#define MAX_SIZE 10

typedef struct process {
  int id, bt, wt, priority_no;
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

#endif
