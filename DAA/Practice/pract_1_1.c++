#include <stdio.h>

int linearSearch(int arr[], int n, int key, int *comparisons) {
    *comparisons = 0;

    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n = 10;
    int arr[10];

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int totalComparisons = 0;

    for (int i = 0; i < n; i++) {
        int comps = 0;
        linearSearch(arr, n, arr[i], &comps);
        totalComparisons += comps;
    }

    double avgComparisons = (double)totalComparisons / n;

    printf("Linear Search Verification\n");
    printf("n = %d\n", n);
    printf("Total comparisons = %d\n", totalComparisons);
    printf("Average comparisons = %.2f\n", avgComparisons);
    printf("Expected average = (n+1)/2 = %.2f\n", (double)(n + 1) / 2);

    return 0;
}
