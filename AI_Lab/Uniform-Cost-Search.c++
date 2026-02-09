#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n = 6;

    vector<vector<pair<int,int>>> graph(n);

    auto addEdge = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };

    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 2, 1);
    addEdge(1, 3, 7);
    addEdge(2, 4, 3);
    addEdge(4, 3, 2);
    addEdge(3, 5, 1);

    int start = 0, goal = 5;

    const int INF = 1e9;
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(node == goal) break;
        if(cost > dist[node]) continue;

        for(auto &edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;

            if(dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
    }

    if(dist[goal] == INF) {
        cout << "No path exists from start to goal.\n";
        return 0;
    }

    cout << "Minimum cost from " << start << " to " << goal << " = " << dist[goal] << "\n";

    vector<int> path;
    for(int v = goal; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Path: ";
    for(int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if(i != (int)path.size() - 1) cout << " -> ";
    }
    cout << "\n";

    return 0;
}
// this is comment