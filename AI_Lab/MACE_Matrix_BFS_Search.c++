// C++ code to find the number of ways in a maze
// with blocked cells using BFS
#include <bits/stdc++.h>
using namespace std;

// Function to find the number of ways using BFS
int findWays(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    // If starting or ending cell is blocked, return 0
    if (mat[0][0] == -1 || mat[n-1][m-1] == -1) {
        return 0;
    }

    // Queue to store the current cell and path count
    queue<pair<int, int>> q;
    q.push({0, 0});

    // Variable to store the number of ways
    int ways = 0;

    // Directions for moving right and down
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}};

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int i = curr.first, j = curr.second;

        // If reached the bottom-right cell, increment ways
        if (i == n-1 && j == m-1) {
            ways++;
            continue;
        }

        // Explore adjacent cells (right and down)
        for (auto dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;

            // Check if within bounds and not blocked
            if (ni < n && nj < m && mat[ni][nj] != -1) {
                q.push({ni, nj});
            }
        }
    }

    return ways;
}

int main() {
    vector<vector<int>> mat = {{ 0,  -1,  -1 },
                               { 0, -1,  -1 },
                               { 0,  0,  0 }};

    cout << findWays(mat);                                                  
}