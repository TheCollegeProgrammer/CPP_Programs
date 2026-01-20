#include <bits/stdc++.h>
using namespace std;

int main() {
    // Adjacency list
    unordered_map<char, vector<char>> graph;

    // Build the graph
    //FUXZ
    //ABCDEGHIJKLMNOPQRSTVWY
    graph['A'] = {'B', 'E'};
    graph['B'] = {'A', 'C'};
    graph['C'] = {'B', 'D'};
    graph['D'] = {'C', 'E','H'};
    graph['E'] = {'A', 'G','D'};
    graph['G'] = {'F', 'E','J'};
    graph['H'] = {'D', 'I'};
    graph['I'] = {'H', 'J','M'};
    graph['J'] = {'G', 'I','K'};
    graph['K'] = {'J', 'L'};
    graph['L'] = {'K', 'N','O'};
    graph['M'] = {'I', 'N'};
    graph['N'] = {'L', 'M','Q'};
    graph['O'] = {'L', 'P'};
    graph['P'] = {'S', 'O','R'};
    graph['Q'] = {'S', 'N'};
    graph['R'] = {'P', 'U','V'};
    graph['S'] = {'Q', 'P','T'};
    graph['T'] = {'S', 'V'};
    graph['V'] = {'R', 'T','W'};
    graph['W'] = {'X','Y','V'};
    graph['X'] = {'W'};
    graph['Z'] = {'Y'};

    char start = 'A';
    char target = 'Y';

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

        cout << "Shortest path from A to Z: ";
        for (char ch : path) {
            cout << ch << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from A to Z\n";
    }

    return 0;
}
