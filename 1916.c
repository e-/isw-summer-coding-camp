#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define DIST_MAX 100000001
int n, m, from, to;
int d[1001][1001];
int dist[1001], visited[1001];

void shortest_path()
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
        if (d[from][to] > dist)
            d[from][to] = dist;
    }
    scanf("%d %d", &from, &to);

    shortest_path();

    printf("%d\n", dist[to]);
    return 0;
}