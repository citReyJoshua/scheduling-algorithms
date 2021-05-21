#include <stdio.h>

#include "FCFS.h"
#include "Queue.h"

int main() {
  Queue handler = newQueue();

  inputValues(handler);

  displayTable(handler);

  destroyQueue(&handler);
  return 0;
}
