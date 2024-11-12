#include <stdio.h>
#include <stdlib.h>

// Function to create a Min-Heap
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        // Swap heap[i] and heap[smallest]
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        // Recursively heapify the affected sub-tree
        minHeapify(heap, n, smallest);
    }
}

// Function to extract the minimum element from the heap
int extractMin(int heap[], int* n) {
    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;  // Decrease the size of heap
    minHeapify(heap, *n, 0);
    return min;
}

// Function to insert a new element into the heap
void insertMinHeap(int heap[], int* n, int value) {
    (*n)++;
    int i = *n - 1;
    heap[i] = value;

    // Fix the heap property if it is violated
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        // Swap heap[i] and heap[(i-1)/2]
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to implement the Optimal Merge Pattern
int optimalMerge(int files[], int n) {
    // Create a min-heap
    int heap[n];
    for (int i = 0; i < n; i++) {
        heap[i] = files[i];
    }

    // Build the min-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }

    int totalCost = 0;

    // Repeat until we have only one file left
    while (n > 1) {
        // Extract two minimum files
        int min1 = extractMin(heap, &n);
        int min2 = extractMin(heap, &n);

        // Merge the two files and add the cost
        int mergedCost = min1 + min2;
        totalCost += mergedCost;

        // Insert the merged file back into the heap
        insertMinHeap(heap, &n, mergedCost);
    }

    return totalCost;
}

int main() {
    // Example: File sizes (weights)
    int files[] = {10, 20, 30, 40, 50};
    int n = sizeof(files) / sizeof(files[0]);

    // Call the optimal merge function
    int totalMergeCost = optimalMerge(files, n);

    // Output the total cost of merging all files
    printf("Total cost of merging files: %d\n", totalMergeCost);

    return 0;
}
