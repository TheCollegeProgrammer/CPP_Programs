#include <bits/stdc++.h>
using namespace std;

int main() {
    // Adjacency list
    unordered_map<char, vector<char>> graph;

    // Build the graph
    graph['A'] = {'B', 'C'};
    graph['B'] = {'D'};
    graph['C'] = {'E'};
    graph['D'] = {'G'};
    graph['E'] = {'F'};
    graph['G'] = {'I','H'};

    char start = 'A';
    char target = 'H';

    // BFS structures
    queue<char> q;
    unordered_map<char, bool> visited;
    unordered_map<char, char> parent;

    q.push(start);
    visited[start] = true;
    parent[start] = '\0';   // No parent for start

    bool found = false;

    // BFS
    while (!q.empty()) {
        char node = q.front();
        q.pop();

        if (node == target) {
            found = true;
            break;
        }

        for (char neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    // Print shortest path
    if (found) {
        vector<char> path;
        char curr = target;

        while (curr != '\0') {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());

        cout << "Shortest path from A to H: ";
        for (char ch : path) {
            cout << ch << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from A to H\n";
    }

    return 0;
}
