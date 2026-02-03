#include <bits/stdc++.h>
using namespace std;

bool DLS(int node, int target, int depth, vector<vector<int>>& graph) {
    if (node == target)
        return true;

    if (depth == 0)
        return false;

    for (int child : graph[node]) {
        if (DLS(child, target, depth - 1, graph))
            return true;
    }
    return false;
}

bool IDDFS(int start, int target, int maxDepth, vector<vector<int>>& graph) {
    for (int depth = 0; depth <= maxDepth; depth++) {
        if (DLS(start, target, depth, graph)) {
            cout << "Target found at depth " << depth << endl;
            return true;
        }
    }
    return false;
}

int main() {
    int n = 7; 
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5, 6};

    int start = 0;
    int target = 6;
    int maxDepth = 3;

    if (!IDDFS(start, target, maxDepth, graph))
        cout << "Target not found\n";

    return 0;
}
