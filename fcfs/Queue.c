#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

int MAX = 10;

nodeptr createNode(queueItem item) {
  nodeptr p = (nodeptr)malloc(sizeof(struct node));
  p->item = item;
  p->next = NULL;
  p->prev = NULL;
  return p;
}
Queue newQueue() {
  Queue q = (Queue)malloc(sizeof(struct queue));
  q->head = NULL;
  q->tail = NULL;
  q->count = 0;
  return q;
}
int isEmpty(const Queue q) { return q->head == NULL; }

int isFull(const Queue q) { return q->count == 10; }

void clear(Queue q) {
  while (!isEmpty(q)) {
    dequeue(q);
  }
}

void display(const Queue q) {
  nodeptr p = q->head;
  printf("{ ");
  while (p != NULL) {
    printf("[ ");
    printf("BT = %d, WT = %d, TAT = %d, ", p->item.bt, p->item.wt, p->item.tat);
    printf("] ");
    p = p->next;
  }
  printf("}");
}

void enqueue(Queue q, const queueItem item) {
  if (q->count < MAX) {
    nodeptr temp = createNode(item);
    if (q->tail != NULL) {
      q->tail->next = temp;
      temp->prev = q->tail;
    } else {
      q->head = temp;
    }
    q->tail = temp;
    q->count++;
  }
}
void dequeue(Queue q) {
  if (q->head != NULL) {
    nodeptr p = q->head;
    q->head = p->next;
    if (q->head != NULL) {
      q->head->prev = NULL;
    } else {
      q->tail = NULL;
    }
    p->next = NULL;
    free(p);
    q->count--;
  }
}

//-1 signifies none is found
queueItem head(const Queue q) { return q->head->item; }

queueItem tail(const Queue q) { return q->tail->item; }
void destroyQueue(Queue *q) {
  clear(*q);
  free(*q);
  *q = NULL;
}