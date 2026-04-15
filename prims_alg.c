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
s
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int V;
int graph[MAX][MAX];

void printMST(int parent[]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[parent[i]][i]);
    }
}

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST() {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST();
    return 0;
}
    


