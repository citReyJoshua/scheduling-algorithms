#include <stdio.h>

#include "HRRN.h"
#include "SortedList.h"
int main() {
  SortedList list = newSortedList(ARRIVAL);
  getValues(list);

  computeWaitingTime(list);

  displayTable(list);

  destroy(&list);

  return 0;
}