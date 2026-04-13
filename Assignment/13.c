#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int minDistance(int dist[], int visited[], int n) {
    int min = INF, minIndex = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    int graph[n + 1][n + 1];

    // initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    // fill edges
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }

    int dist[n + 1];
    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[k] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}

int main() {
    int times[][3] = {
        {1,2,1},
        {2,3,1},
        {1,4,4},
        {3,4,1}
    };

    int n = 4;
    int k = 1;
    int timesSize = 4;

    int result = networkDelayTime(times, timesSize, n, k);

    printf("Minimum time = %d\n", result);

    return 0;
}