#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int main() {
    char X[100], Y[100];
    int m, n, i, j;

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    int L[m+1][n+1];

    // Build LCS table
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {

            if(i == 0 || j == 0)
                L[i][j] = 0;

            else if(X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    printf("Length of Longest Common Subsequence = %d\n", L[m][n]);

    return 0;
}