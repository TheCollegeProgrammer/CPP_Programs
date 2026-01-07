#include <stdio.h>

int arr[100];
int sortComp = 0, searchComp = 0;

int partition(int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j, temp;

    for (j = low; j < high; j++) {
        sortComp++;
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int binarySearch(int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        searchComp++;
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, i, key, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(0, n - 1);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nEnter target element: ");
    scanf("%d", &key);

    pos = binarySearch(n, key);

    if (pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    printf("\nComparisons in Quick Sort: %d", sortComp);
    printf("\nComparisons in Binary Search: %d", searchComp);
    printf("\nTotal Comparisons: %d\n", sortComp + searchComp);

    return 0;
}