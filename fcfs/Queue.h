#ifndef QUEUE_H
#define QUEUE_H

typedef struct process {
  int bt, wt, tat;
} queueItem;

typedef struct node *nodeptr;

struct node {
  queueItem item;
  nodeptr next;
  nodeptr prev;
};

struct queue {
  nodeptr head;
  nodeptr tail;
  int count;
};

typedef struct queue *Queue;

Queue newQueue();
int isEmpty(const Queue q);
int isFull(const Queue q);
void clear(Queue q);
void display(const Queue q);
void enqueue(Queue q, const queueItem item);
void dequeue(Queue q);
queueItem head(const Queue q);
queueItem tail(const Queue q);
void destroyQueue(Queue *q);

#endif