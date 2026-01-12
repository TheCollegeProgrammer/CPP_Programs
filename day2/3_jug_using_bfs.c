#include <stdio.h>
#include <stdbool.h>

#define CA 8
#define CB 5
#define CC 3

#define MAX 300

typedef struct {
    int a, b, c;
} State;

typedef struct {
    int from;
    int to;
} Action;

State queue[MAX];
int front = 0, rear = 0;

bool visited[CA + 1][CB + 1][CC + 1];
State parent[CA + 1][CB + 1][CC + 1];
Action parentAction[CA + 1][CB + 1][CC + 1];

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

    int amount = val[from] < (cap[to] - val[to])
               ? val[from]
               : (cap[to] - val[to]);

    val[from] -= amount;
    val[to]   += amount;

    State next = {val[0], val[1], val[2]};
    return next;
}

char jugName(int x) {
    return (x == 0) ? 'A' : (x == 1 ? 'B' : 'C');
}

void printPath(State goal, State start) {
    State path[100];
    Action actions[100];
    int count = 0;

    State cur = goal;

    while (!(cur.a == start.a && cur.b == start.b && cur.c == start.c)) {
        path[count] = cur;
        actions[count] = parentAction[cur.a][cur.b][cur.c];
        cur = parent[cur.a][cur.b][cur.c];
        count++;
    }

    path[count++] = start;

    printf("\nInitial State: (%d, %d, %d)\n\n",
           start.a, start.b, start.c);

    for (int i = count - 1; i > 0; i--) {
        printf("Pour %c -> %c  =>  (%d, %d, %d)\n",
               jugName(actions[i - 1].from),
               jugName(actions[i - 1].to),
               path[i - 1].a,
               path[i - 1].b,
               path[i - 1].c);
    }
}

int main() {
    State start = {8, 0, 0};

    enqueue(start);
    visited[8][0][0] = true;

    while (front < rear) {
        State cur = dequeue();

        if (isGoal(cur)) {
            printf("Goal reached: (%d, %d, %d)\n",
                   cur.a, cur.b, cur.c);

            printPath(cur, start);
            return 0;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    State next = pour(cur, i, j);

                    if (!visited[next.a][next.b][next.c]) {
                        visited[next.a][next.b][next.c] = true;
                        parent[next.a][next.b][next.c] = cur;
                        parentAction[next.a][next.b][next.c] =
                            (Action){i, j};
                        enqueue(next);
                    }
                }
            }
        }
    }

    printf("No solution found.\n");
    return 0;
}
