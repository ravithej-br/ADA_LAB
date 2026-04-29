/*
Prim(G):
    Input: A weighted connected graph G = (V, E)
    Output: A set of edges ET forming a minimum spanning tree

    Choose any starting vertex v0
    VT ← { v0 }          // tree vertices
    ET ← ∅               // tree edges

    while |VT| < |V| do
        Find the edge e* = (v*, u*) with minimum weight
            where v* ∈ VT and u* ∉ VT
        Add u* to VT
        Add e* to ET

    return ET   */

#include <stdio.h>

void prims(int n, int a[10][10], int source) {
    int s[10], i, j, min, sum = 0, u = -1, v = -1, k, t = 0;

    for (i = 0; i < n; i++)
        s[i] = 0;
    s[source] = 1;

    k = 1;
    while (k <= n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (s[i] == 1 && s[j] == 0) {
                    if (i != j && a[i][j] < min) {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("\n(%d,%d) = %d", u, v, min);
            sum += min;
            s[v] = 1;
            k++;
        } else {
            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (s[i] != 1)
            t = 1;
    }

    if (t == 0)
        printf("\nCost of minimum spanning tree is %d\n", sum);
    else
        printf("\nMinimum spanning tree not possible\n");
}

int main() {
    int a[10][10], n, i, j, source;

    printf("==========================================\n");
    printf(" Find minimum cost spanning tree using Prim's Algorithm \n");
    printf("==========================================\n");

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (0 for self loop and 99 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source node (0 to %d): ", n - 1);
    scanf("%d", &source);

    prims(n, a, source);

    return 0;
}

