#include <stdio.h>
#include <math.h>

int binarySearch(int arr[], int n, int key, int *comparisons) {
    int low = 0, high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        (*comparisons)++;
        int mid = (low + high) / 2;

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
    int n = 16;
    int arr[16];

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int totalComparisons = 0;

    for (int i = 0; i < n; i++) {
        int comps = 0;
        binarySearch(arr, n, arr[i], &comps);
        totalComparisons += comps;
    }

    double avgComparisons = (double)totalComparisons / n;

    printf("Binary Search Verification\n");
    printf("n = %d\n", n);
    printf("Total comparisons = %d\n", totalComparisons);
    printf("Average comparisons = %.2f\n", avgComparisons);
    printf("log2(n) = %.2f\n", log2(n));
    return 0;
}
//and