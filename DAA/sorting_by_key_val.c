#include <stdio.h>

struct Pair {
    char ch;
    int val;
};

int main() {
    int n = 5;

    // Input pairs
    struct Pair A[] = {
        {'a', 5},
        {'b', 3},
        {'c', 1},
        {'d', 4},
        {'e', 2}
    };

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        struct Pair key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j].val > key.val) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

    // Output
    printf("Sorted Output:\n");
    for (int i = 0; i < n; i++) {
        printf("%c-%d\n", A[i].ch, A[i].val);
    }

    return 0;
}
