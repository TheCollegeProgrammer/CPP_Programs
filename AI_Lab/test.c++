#include <bits/stdc++.h>
using namespace std;

// Depth Limited DFS
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

int main() {

}