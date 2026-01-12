#include <stdio.h>
#include <stdbool.h>

#define CA 8
#define CB 5
#define CC 3
#define MAX 300

typedef struct {
    int a, b, c;
} State;

State queue[MAX];
int front = 0, rear = 0;

bool visited[9][6][4];   // visited[a][b][c]

void enqueue(State s) {
    queue[rear++] = s;
}

State dequeue() {
    return queue[front++];
}

bool isGoal(State s) {
    return (s.a == 4 && s.b == 4 && s.c == 0);
}

State pour(State s, int from, int to) {
    int cap[3] = {CA, CB, CC};
    int val[3] = {s.a, s.b, s.c};

    int amount = val[from];
    if (cap[to] - val[to] < amount)
        amount = cap[to] - val[to];

    val[from] -= amount;
    val[to]   += amount;

    return (State){val[0], val[1], val[2]};
}

int main() {
    State start = {8, 0, 0};

    enqueue(start);
    visited[8][0][0] = true;

    printf("BFS Traversal:\n");

    while (front < rear) {
        State cur = dequeue();
        printf("Visiting (%d, %d, %d)\n", cur.a, cur.b, cur.c);

        if (isGoal(cur)) {
            printf("\nGoal Found: (%d, %d, %d)\n",
                   cur.a, cur.b, cur.c);
            return 0;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    State next = pour(cur, i, j);

                    if (!visited[next.a][next.b][next.c]) {
                        visited[next.a][next.b][next.c] = true;
                        enqueue(next);
                    }
                }
            }
        }
    }

    printf("No solution found.\n");
    return 0;
}
