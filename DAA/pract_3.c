#include <stdio.h>

int graph[5][5], visited[5];

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < 5; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j;

    for (i = 0; i < 5; i++)
        visited[i] = 0;

    printf("Enter adjacency matrix (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("DFS Traversal starting from node 0:\n");
    DFS(0);

    return 0;
}
