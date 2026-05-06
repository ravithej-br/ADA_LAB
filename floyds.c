/*
Algorithm Floyd(W[1..n, 1..n])

# Input: Weight matrix W
# Output: Distance matrix D

1. D ← W

2. for k ← 1 to n do
3.     for i ← 1 to n do
4.         for j ← 1 to n do
5.             D[i][j] ← min(D[i][j], D[i][k] + D[k][j])
6.         end for
7.     end for
8. end for

9. return D
*/

#include <stdio.h>

#define INF 99999

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int D[n][n];

    printf("Enter weight matrix (0 for no edge):\n");

    // Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &D[i][j]);

            if (i == j)
                D[i][j] = 0;
            else if (D[i][j] == 0)
                D[i][j] = INF;
        }
    }

    // Floyd’s Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] != INF && D[k][j] != INF &&
                    D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    // Output
    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Enter number of vertices: 4
Enter adjacency matrix (0 for no edge):
0 3 0 7
8 0 2 0
5 0 0 1
2 0 0 0

Shortest distance matrix:
0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0 
*/