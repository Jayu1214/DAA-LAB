#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    // Build the table in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or no capacity
            } else if (weights[i - 1] <= w) {
                // Item can be included, so choose maximum of including or excluding the item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Item cannot be included, exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is in the bottom-right corner of the table
    return dp[n][capacity];
}

int main() {
    int values[] = {60, 100, 120};   // Values of the items
    int weights[] = {10, 20, 30};    // Weights of the items
    int capacity = 50;               // Capacity of the knapsack
    int n = sizeof(values) / sizeof(values[0]);  // Number of items

    int max_value = knapsack(capacity, weights, values, n);
    printf("Maximum value in knapsack = %d\n", max_value);

    return 0;
}
