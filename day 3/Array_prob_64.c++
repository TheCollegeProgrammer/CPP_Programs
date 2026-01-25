#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    // Edge case: empty grid
    if (grid.empty() || grid[0].empty()) return 0;

    int m = grid.size();
    int n = grid[0].size();

    // Create DP table
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base case: start cell
    dp[0][0] = grid[0][0];

    // Fill first row (only from left)
    for (int j = 1; j < n; j++) {
        dp[0][j] = grid[0][j] + dp[0][j - 1];
    }

    // Fill first column (only from top)
    for (int i = 1; i < m; i++) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }

    // Fill rest of the grid
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Final answer
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum Path Sum = " << minPathSum(grid) << endl;

    return 0;
}
