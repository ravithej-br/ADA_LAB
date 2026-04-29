/* Kruskal(G):
    Input: A weighted connected graph G = (V, E)
    Output: A set of edges ET forming a minimum spanning tree

    ET ← ∅
    Sort all edges E by increasing weight

    Make a separate set for each vertex

    for each edge e = (u, v) in sorted E do
        if u and v are in different sets:
            Add e to ET
            Union the sets containing u and v

        if |ET| = |V| - 1:
            break

    return ET */


#include <stdio.h>

int parent[20];

int find(int m) {
    int p = m;
    while (parent[p] != 0)
        p = parent[p];
    return p;
}

void union_ij(int i, int j) {
    if (i < j)
        parent[i] = j;
    else
        parent[j] = i;
}

void kruskal(int a[10][10], int n) {
    int u, v, min, k = 0, i, j, sum = 0;

    while (k < n - 1) {
        min = 999;
        u = v = -1;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (a[i][j] < min && i != j) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u);
        j = find(v);

        if (i != j) {
            union_ij(i, j);
            printf("(%d,%d) = %d\n", u, v, a[u][v]);
            sum += a[u][v];
            k++;
        }

        a[u][v] = a[v][u] = 999;  // remove edge
    }

    printf("\nThe minimum cost spanning tree is = %d\n", sum);
}

int main() {
    int a[10][10], n, i, j;

    printf("=======================================\n");
    printf(" Find minimum cost spanning tree using Kruskal Algorithm \n");
    printf("=======================================\n");

    printf("\nEnter the number of vertices of the graph: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter a valid number of vertices\n");
        return 1;
    }

    printf("\nEnter the cost adjacency matrix\n");
    printf(" (0 for loops and 999 if there is no direct edge):\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // initialize parent array
    for (i = 1; i <= n; i++)
        parent[i] = 0;

    kruskal(a, n);

    return 0;
}
