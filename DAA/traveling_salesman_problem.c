#include <stdio.h>
#include <limits.h>
#include <string.h>

#define N 4
#define VISITED_ALL (1 << N) - 1

//  GREEDY 
int tsp_greedy(int graph[N][N]) {
    int visited[N] = {0};
    int cost = 0;
    int current = 0;

    printf("\n[Greedy Path] : 0 ");

    visited[current] = 1;

    for (int count = 1; count < N; count++) {
        int next = -1;
        int min = INT_MAX;

        for (int i = 0; i < N; i++) {
            if (!visited[i] && graph[current][i] < min) {
                min = graph[current][i];
                next = i;
            }
        }

        printf("-> %d ", next);
        visited[next] = 1;
        cost += min;
        current = next;
    }

    printf("-> 0");
    cost += graph[current][0];

    return cost;
}

//  DP
int dp[1 << N][N];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp_dp(int mask, int pos, int graph[N][N]) {

    if (mask == VISITED_ALL)
        return graph[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {

            int newAns = graph[pos][city] +
                tsp_dp(mask | (1 << city), city, graph);

            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {

    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    printf("=========== TSP BATTLE ===========\n");

    // Greedy
    int greedy_cost = tsp_greedy(graph);
    printf("\nGreedy Cost: %d\n", greedy_cost);

    // DP init
    memset(dp, -1, sizeof(dp));

    int dp_cost = tsp_dp(1, 0, graph);
    printf("\n[DP Optimal Cost]: %d\n", dp_cost);

    // Winner
    printf("\n=========== RESULT ===========\n");

    if (greedy_cost == dp_cost)
        printf(" Greedy got lucky! Same result as DP!\n");
    else
        printf(" DP wins! Greedy missed the optimal path.\n");

    return 0;
}
