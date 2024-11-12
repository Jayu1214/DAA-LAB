#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int board[MAX][MAX];
void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
bool isSafe(int row, int col, int n) {
    int i, j;
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
bool solveNQueens(int n, int row) {
    if (row >= n)
        return true;
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;
            if (solveNQueens(n, row + 1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}
int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    if (solveNQueens(n, 0)) {
        printf("Solution found:\n");
        printSolution(n);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}