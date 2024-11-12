#include <stdio.h>
int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; 
        }
    }
    return -1;
}
int binarySearch(int arr[], int left, int right, int element) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == element) {
            return mid;
        }
        if (arr[mid] > element) {
            return binarySearch(arr, left, mid - 1, element);
        }
        return binarySearch(arr, mid + 1, right, element);
    }
    
    return -1; 
}
int main() {
    int n, element, linearResult, binaryResult;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &element);
    linearResult = linearSearch(arr, n, element);
    if (linearResult != -1) {
        printf("Linear Search Result: Element found at index %d\n", linearResult);
    } else {
        printf("Linear Search Result: Element not found\n");
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    binaryResult = binarySearch(arr, 0, n - 1, element);
    if (binaryResult != -1) {
        printf("Binary Search Result: Element found at index %d (sorted array)\n", binaryResult);
    } else {
        printf("Binary Search Result: Element not found\n");
    }
    return 0;
}