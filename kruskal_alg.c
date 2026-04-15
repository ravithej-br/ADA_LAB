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
#include <stdlib.h>

int comparator(const void *a, const void *b) {
    return ((int *)a)[2] - ((int *)b)[2];
}

void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[]) {
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int V, int E, int edge[E][3]) {
    qsort(edge, E, sizeof(edge[0]), comparator);

    int parent[V], rank[V];
    makeSet(parent, rank, V);

    int minCost = 0, count = 0;

    printf("Edges in MST:\n");

    for (int i = 0; i < E; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        int p1 = findParent(parent, u);
        int p2 = findParent(parent, v);

        if (p1 != p2) {
            unionSet(p1, p2, parent, rank);
            printf("%d - %d : %d\n", u, v, wt);
            minCost += wt;
            count++;

            if (count == V - 1)
                break;
        }
    }

    printf("Total cost: %d\n", minCost);
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int edge[E][3];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("\n %d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }

    kruskalAlgo(V, E, edge);

    return 0;
}