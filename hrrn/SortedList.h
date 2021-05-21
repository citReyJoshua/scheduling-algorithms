#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#define MAX_SIZE 20
#define ARRIVAL 'a'

typedef struct process {
  int id, bt, at, wt, complete;
} listItem;

typedef struct list {
  listItem *items;
  int length;
  char criterion;
} * SortedList;

SortedList newSortedList(char criterion);
void display(SortedList list);
void add(SortedList list, listItem item);
void destroy(SortedList *list);
#endif