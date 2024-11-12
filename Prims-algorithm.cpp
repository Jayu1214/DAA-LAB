#include <stdio.h>
#include <limits.h>
#define V 5

// Function to find the vertex with the minimum key value that is not yet included in the MST
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    return minIndex;
}

// Prim's Algorithm to find the MST
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key values used to pick minimum weight edges
    int mstSet[V];  // Boolean array to represent the set of vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Starting from the first vertex
    key[0] = 0;    // Make key 0 so this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of the MST

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet included in the MST
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        // Update the key value and parent index of adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
