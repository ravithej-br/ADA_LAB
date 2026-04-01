#include <stdio.h>
#include <time.h>

// Merge function
void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[100000];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

// Merge Sort
void mergesort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;

    // Start time
    start = clock();

    mergesort(arr, 0, n - 1);

    // End time
    end = clock();

    // Print sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Time calculation
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nExecution time: %f seconds\n", time_taken);

    return 0;
}