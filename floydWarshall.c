/*
Algorithm FloydWarshall(W, n)

# W is the weight matrix of size n × n
# n is the number of vertices
# D will store shortest distances

1. Initialize D ← W

2. for k ← 1 to n do
3.     for i ← 1 to n do
4.         for j ← 1 to n do
5.             if D[i][k] + D[k][j] < D[i][j] then
6.                 D[i][j] ← D[i][k] + D[k][j]
7.             end if
8.         end for
9.     end for
10. end for

11. return D
*/

#include <stdio.h>

#define INF 99999

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int D[n][n];

    printf("Enter adjacency matrix (0 for no edge):\n");

    // Input handling
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &D[i][j]);

            if (i == j) {
                D[i][j] = 0;  // distance to itself
            }
            else if (D[i][j] == 0) {
                D[i][j] = INF;  // no edge
            }
        }
    }

    // Floyd–Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Prevent overflow and invalid paths
                if (D[i][k] != INF && D[k][j] != INF &&
                    D[i][k] + D[k][j] < D[i][j]) {

                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    // Optional: Negative cycle detection
    for (int i = 0; i < n; i++) {
        if (D[i][i] < 0) {
            printf("\nNegative cycle detected!\n");
            return 0;
        }
    }

    // Output result
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