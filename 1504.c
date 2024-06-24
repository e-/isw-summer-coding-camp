#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define DIST_MAX 100000001
int n, m;
int d[801][801];
int dist[801], visited[801];

int shortest_path(int from, int to)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = DIST_MAX;
        visited[i] = 0;
    }

    dist[from] = 0;

    for (int i = 1; i < n; i++)
    {
        int min_dist = DIST_MAX, min_v = 0;

        for (int j = 1; j <= n; j++)
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_v = j;
            }

        if (min_v == 0)
            break;
        visited[min_v] = 1;

        for (int j = 1; j <= n; j++)
            if (!visited[j] && dist[min_v] + d[min_v][j] < dist[j])
                dist[j] = dist[min_v] + d[min_v][j];
    }

    return dist[to];
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = DIST_MAX;
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        int from, to, dist;
        scanf("%d %d %d", &from, &to, &dist);
        d[from][to] = dist;
        d[to][from] = dist;
    }
    int v1, v2;
    scanf("%d %d", &v1, &v2);

    int min_dist = DIST_MAX;

    int case1 = shortest_path(1, v1) + shortest_path(v1, v2) + shortest_path(v2, n);
    int case2 = shortest_path(1, v2) + shortest_path(v2, v1) + shortest_path(v1, n);

    if (case1 < min_dist)
        min_dist = case1;
    if (case2 < min_dist)
        min_dist = case2;

    if (min_dist == DIST_MAX)
        printf("-1\n");
    else
        printf("%d\n", min_dist);
    return 0;
}
