#ifndef BANKER_H
#define BANKER_H

void accept(int A[][10], int N[][10], int M[10][10], int W[1][10], int *n,
            int *m);
int banker(int A[][10], int N[][10], int W[1][10], int n, int m);

#endif