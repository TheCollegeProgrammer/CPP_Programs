#include <stdio.h>

int linearSearch(int arr[], int n, int key, int *comp) {
    *comp = 0;
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key, int *comp) {
    int low = 0, high = n - 1;
    *comp = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        (*comp)++;

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
    int n = 100;
    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int linCompTotal = 0, binCompTotal = 0;
    int linComp, binComp;

    for (int key = 1; key <= n; key++) {
        linearSearch(arr, n, key, &linComp);
        binarySearch(arr, n, key, &binComp);

        linCompTotal += linComp;
        binCompTotal += binComp;
    }

    printf("Array Size: %d\n", n);
    printf("Average Linear Search Comparisons: %.2f\n", (float)linCompTotal/n);
    printf("Average Binary Search Comparisons: %.2f\n", (float)binCompTotal/n);

    return 0;
}
