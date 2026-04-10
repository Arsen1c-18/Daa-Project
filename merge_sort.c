#include <stdio.h>
#include <time.h>

int comparisons = 0;
int maxDepth = 0;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right, int depth) {
    if (depth > maxDepth)
        maxDepth = depth;

    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1, 1);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    printf("\nTotal Comparisons: %d\n", comparisons);
    printf("Maximum Recursion Depth: %d\n", maxDepth);

    clock_t start = clock();

    for(int k = 0; k < 5000; k++) {
        int temp[n];
        for(int i = 0; i < n; i++)
            temp[i] = original[i];

        mergeSort(temp, 0, n - 1, 1);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\n", time_taken);

    return 0;
}