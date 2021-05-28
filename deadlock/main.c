#include <stdio.h>

#include "Banker.h"
int main() {
  int ret;
  int A[10][10];
  int M[10][10];
  int N[10][10];
  int W[1][10];
  int n, m, pid, ch;
  printf("\n DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");
  accept(A, N, M, W, &n, &m);
  ret = banker(A, N, W, n, m);
  return 0;
}