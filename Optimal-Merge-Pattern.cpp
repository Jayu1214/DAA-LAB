#include <stdio.h>
#include <stdlib.h>
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, n, smallest);
    }
}
int extractMin(int heap[], int* n) {
    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap, *n, 0);
    return min;
}
void insertMinHeap(int heap[], int* n, int value) {
    (*n)++;
    int i = *n - 1;
    heap[i] = value;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
int optimalMerge(int files[], int n) {
    int heap[n];
    for (int i = 0; i < n; i++) {
        heap[i] = files[i];
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }
    int totalCost = 0;
    while (n > 1) {
        int min1 = extractMin(heap, &n);
        int min2 = extractMin(heap, &n);
        int mergedCost = min1 + min2;
        totalCost += mergedCost;
        insertMinHeap(heap, &n, mergedCost);
    }
    return totalCost;
}
int main() {
    int files[] = {10, 20, 30, 40, 50};
    int n = sizeof(files) / sizeof(files[0]);
    int totalMergeCost = optimalMerge(files, n);
    printf("Total cost of merging files: %d\n", totalMergeCost);
    return 0;
}