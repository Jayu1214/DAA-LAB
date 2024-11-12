#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int board[MAX][MAX];

// Function to print the board configuration
void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check the column for the same queen
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Function to solve the N-Queens problem using Backtracking
bool solveNQueens(int n, int row) {
    // If all queens are placed, return true
    if (row >= n)
        return true;

    // Consider this row and try placing this queen in all columns
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            // Place the queen on the board
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(n, row + 1))
                return true;

            // If placing queen in this column doesn't lead to a solution,
            // remove the queen (Backtrack)
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column in this row, return false
    return false;
}

int main() {
    int n;

    // Input the size of the chessboard
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    // Initialize the board with 0s (No queens placed)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    // Try to solve the problem starting from the first row
    if (solveNQueens(n, 0)) {
        printf("Solution found:\n");
        printSolution(n);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
