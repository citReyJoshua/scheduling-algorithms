#include "SortedList.h"

#include <stdio.h>
#include <stdlib.h>

SortedList newSortedList(char criterion) {
  SortedList l = (SortedList)malloc(sizeof(struct list));
  l->items = (listItem *)malloc(sizeof(listItem *) * MAX_SIZE);
  l->length = 0;
  l->criterion = criterion;
  return l;
}
void display(SortedList list) {
  printf("[ ");
  for (int i = 0; i < list->length; i++) {
    printf("%d ", list->items[i].at);
  }
  printf("]");
}
void shiftRight(SortedList list, int index) {
  for (int i = list->length; i > index; i--) {
    list->items[i] = list->items[i - 1];
  }
}

int binarySearch(SortedList list, int item, int low, int high) {
  if (list->length == 0) return 0;
  if (list->length == 1) return (item > list->items[0].at);
  if (high <= low) return (item > list->items[low].at) ? (low + 1) : low;

  int mid = (low + high) / 2;

  if (item == list->items[mid].at) return mid + 1;

  if (item > list->items[mid].at)
    return binarySearch(list, item, mid + 1, high);
  return binarySearch(list, item, low, mid - 1);
}

void add(SortedList list, listItem item) {
  int loc = binarySearch(list, item.at, 0, list->length - 1);
  shiftRight(list, loc);
  list->items[loc] = item;
  list->length++;
}
void destroy(SortedList *list) {
  free((*list)->items);
  free(*list);
  *list = NULL;
}