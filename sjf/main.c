#include <stdio.h>

#include "PriorityQueue.h"
#include "SJF.h"

int main() {
  PriorityQueue handler = newPriorityQueue();

  inputValues(handler);
  displayTable(handler);

  destroy(&handler);
  return 0;
}