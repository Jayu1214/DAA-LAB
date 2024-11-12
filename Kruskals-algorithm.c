#include <stdio.h>

#define V 5
#define INF 9999

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to find the subset of an element i (with path compression)
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Function to perform union of two subsets
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Function to perform Kruskal's MST algorithm
void kruskalMST(struct Edge edges[], int edgeCount) {
    struct Edge result[V];
    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int e = 0;  // Number of edges in MST
    int i = 0;  // Index variable for sorted edges

    while (e < V - 1 && i < edgeCount) {
        struct Edge nextEdge = edges[i++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, rank, x, y);
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    struct Edge edges[] = {
        {0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8},
        {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    kruskalMST(edges, edgeCount);

    return 0;
}