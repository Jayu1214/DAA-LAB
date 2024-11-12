#include <stdio.h>
#include <limits.h>

#define V 4  // Number of vertices in the graph

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[][V]) {
    // Create a distance matrix and initialize it as the same as the input graph
    int dist[V][V];

    // Initialize the distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 0 && i != j)
                dist[i][j] = INT_MAX; // No path
            else
                dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the distance matrix
    printf("The shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Input graph represented as an adjacency matrix
    // graph[i][j] holds the weight of the edge between vertex i and vertex j
    // Use 0 to represent no edge between vertices (except for the diagonal, which represents the self-loop with zero cost)
    int graph[V][V] = {
        {0, 5, 0, 10},
        {0, 0, 3, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    // Call Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}
