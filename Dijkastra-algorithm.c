#include <stdio.h>
#include <limits.h>
#define V 5

// Function to find the vertex with the minimum distance value that is not yet included in the shortest path tree
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }

    return minIndex;
}

// Dijkstra's Algorithm for shortest path
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the result
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 0, 4},
        {5, 2, 0, 0, 3},
        {0, 0, 4, 3, 0}
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}