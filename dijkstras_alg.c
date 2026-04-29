/* Algorithm Dijkstra(G, s)
 Input: Graph G = (V, E) with nonnegative edge weights
        Source vertex s
 Output: Shortest distance d[v] from s to each vertex v
        Predecessor p[v] for each vertex v

1. For each vertex v in V:
       d[v] ← ∞
       p[v] ← null
       visited[v] ← false

2. d[s] ← 0

3. Repeat |V| times:
       u ← vertex with minimum d[u] among unvisited vertices
       visited[u] ← true

       For each neighbor v of u:
            If visited[v] = false AND d[u] + w(u, v) < d[v]:
                 d[v] ← d[u] + w(u, v)
                 p[v] ← u

4. End Repeat

5. Result:
       For each vertex v:
            d[v] = shortest distance from s to v
            p[v] = predecessor of v on shortest path */


            #include <stdio.h>

int d[10], p[10], visited[10];

void dijkstra(int a[10][10], int s, int n) {
    int u = -1, v, i, j, min;

    // Initialize distances and parents
    for (v = 0; v < n; v++) {
        d[v] = 99;
        p[v] = -1;
        visited[v] = 0;
    }
    d[s] = 0;

    // Main loop
    for (i = 0; i < n; i++) {
        // Select u with minimum distance among unvisited
        min = 99;
        for (j = 0; j < n; j++) {
            if (d[j] < min && visited[j] == 0) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1) break; // no reachable vertex left
        visited[u] = 1;

        // Update distances for neighbors of u
        for (v = 0; v < n; v++) {
            if ((d[u] + a[u][v] < d[v]) && (u != v) && visited[v] == 0) {
                d[v] = d[u] + a[u][v];
                p[v] = u;
            }
        }
    }
}

void path(int v, int s) {
    if (p[v] != -1)
        path(p[v], s);
    if (v != s)
        printf("->%d", v);
}

void display(int s, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i != s) {
            printf("%d", s);
            path(i, s);
            printf(" = %d\n", d[i]);
        }
    }
}

int main() {
    int a[10][10], i, j, n, s;

    printf("Program for Single Source Shortest Path using Dijkstra's Algorithm\n\n");

    // Read the weighted graph as cost matrix
    printf("Enter the number of vertices (size of the graph): ");
    scanf("%d", &n);

    printf("Enter the %d x %d cost matrix:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &s);

    // Run Dijkstra
    dijkstra(a, s, n);

    // Display the result
    printf("\nOUTPUT\n");
    printf("The shortest paths from %d to remaining vertices are:\n\n", s);
    display(s, n);

    printf("\nThank You\n");
    return 0;
}

