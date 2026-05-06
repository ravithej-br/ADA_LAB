/*
Algorithm Warshall(A[1..n, 1..n])

# Input: Adjacency matrix A (0 or 1)
# Output: Reachability matrix R

1. R ← A

2. for k ← 1 to n do
3.     for i ← 1 to n do
4.         for j ← 1 to n do
5.             R[i][j] ← R[i][j] OR (R[i][k] AND R[k][j])
6.         end for
7.     end for
8. end for

9. return R
*/

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int R[n][n];

    printf("Enter adjacency matrix (0 or 1):\n");

    // Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &R[i][j]);
        }
    }

    // Warshall’s Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
    }

    // Output
    printf("\nTransitive closure (reachability matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Enter number of vertices: 4
Enter adjacency matrix (0 or 1):
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0

Transitive closure (reachability matrix):
1 1 1 1 
1 1 1 1 
0 0 0 0 
1 1 1 1
*/