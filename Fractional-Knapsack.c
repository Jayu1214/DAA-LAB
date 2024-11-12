#include <stdio.h>
#include <stdlib.h>

// Structure for an item that stores weight, value, and the value-to-weight ratio
struct Item {
    int weight;
    int value;
    float ratio;
};

// Function to compare items based on value-to-weight ratio (for sorting)
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    if (item2->ratio > item1->ratio) return 1;
    if (item2->ratio < item1->ratio) return -1;
    return 0;
}

// Function to perform the greedy approach for the Fractional Knapsack problem
void knapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    float totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the entire item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Taking full item %d (value: %d, weight: %d)\n", i + 1, items[i].value, items[i].weight);
        } else {
            // Take the fraction of the item that fits
            int remainingCapacity = capacity - currentWeight;
            float fraction = (float)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Taking %.2f fraction of item %d (value: %d, weight: %d)\n", fraction, i + 1, items[i].value, items[i].weight);
            break;
        }
    }

    printf("Total value in knapsack: %.2f\n", totalValue);
}

int main() {
    int capacity = 50;  // Capacity of the knapsack
    struct Item items[] = {
        {10, 60, 0}, {20, 100, 0}, {30, 120, 0}
    };
    int n = sizeof(items) / sizeof(items[0]);

    // Calculate the value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    knapsack(capacity, items, n);

    return 0;
}
