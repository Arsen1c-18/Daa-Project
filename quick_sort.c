#include <stdio.h>
#include <time.h>

int comparisons = 0;
int maxDepth = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int depth) {
    if (depth > maxDepth)
        maxDepth = depth;

    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1, depth + 1);
        quickSort(arr, pi + 1, high, depth + 1);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of transactions: ");
    scanf("%d", &n);

    int arr[n];
    int original[n];

    printf("Enter transaction amounts:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        original[i] = arr[i];
    }

    printf("\nOriginal Array:\n");
    printArray(arr, n);

    comparisons = 0;
    maxDepth = 0;

    quickSort(arr, 0, n - 1, 1);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    printf("\nTotal Comparisons: %d\n", comparisons);
    printf("Maximum Recursion Depth: %d\n", maxDepth);

    clock_t start = clock();

    for(int k = 0; k < 5000; k++) {
        int temp[n];
        for(int i = 0; i < n; i++)
            temp[i] = original[i];

        quickSort(temp, 0, n - 1, 1);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\n", time_taken);

    return 0;
}