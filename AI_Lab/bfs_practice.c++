#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<int> adj[5];

    // Build the same graph
    // adj[0].push_back(1);
    // adj[1].push_back(0);

    // adj[1].push_back(2);
    // adj[2].push_back(1);

    // adj[2].push_back(3);
    // adj[3].push_back(2);

    // adj[3].push_back(4);
    // adj[4].push_back(3);

    // adj[4].push_back(0);
    // adj[0].push_back(4);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    int start = 0;
    int end   = 3;

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    bool found = false;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end) {
            found = true;
            break;
        }

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;   // <-- key line
                q.push(v);
            }
        }
    }

    if (!found) {
        cout << "No path found\n";
        return 0;
    }

    // Reconstruct path
    vector<int> path;
    int cur = end;

    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    cout << "Shortest path: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
