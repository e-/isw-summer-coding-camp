#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define DIST_MAX 1000 * 100 + 1
int n, m, x;
int d1[1001][1001], d2[1001][1001];
int dist1[1001], dist2[1001], visited[1001];

void shortest_path1()
{
    for (int i = 1; i <= n; i++)
    {
        dist1[i] = DIST_MAX;
        visited[i] = 0;
    }

    dist1[x] = 0;

    for (int i = 1; i < n; i++)
    {
        int min_dist = DIST_MAX, min_v = 0;

        for (int j = 1; j <= n; j++)
            if (dist1[j] < min_dist && !visited[j])
            {
                min_dist = dist1[j];
                min_v = j;
            }

        if (min_v == 0)
            break;
        visited[min_v] = 1;

        for (int j = 1; j <= n; j++)
            if (dist1[min_v] + d1[min_v][j] < dist1[j])
                dist1[j] = dist1[min_v] + d1[min_v][j];
    }
}

void shortest_path2()
{
    for (int i = 1; i <= n; i++)
    {
        dist2[i] = DIST_MAX;
        visited[i] = 0;
    }

    dist2[x] = 0;

    for (int i = 1; i < n; i++)
    {
        int min_dist = DIST_MAX, min_v = 0;

        for (int j = 1; j <= n; j++)
            if (dist2[j] < min_dist && !visited[j])
            {
                min_dist = dist2[j];
                min_v = j;
            }

        if (min_v == 0)
            break;
        visited[min_v] = 1;

        for (int j = 1; j <= n; j++)
            if (dist2[min_v] + d2[min_v][j] < dist2[j])
                dist2[j] = dist2[min_v] + d2[min_v][j];
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &x);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d1[i][j] = d2[i][j] = DIST_MAX;

    for (int i = 1; i <= m; i++)
    {
        int from, to, dist;
        scanf("%d %d %d", &from, &to, &dist);
        d1[to][from] = dist;
        d2[from][to] = dist;
    }

    shortest_path1();
    shortest_path2();
    int max_dist = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = dist1[i] + dist2[i];
        if (t > max_dist)
            max_dist = t;
    }
    printf("%d\n", max_dist);
    return 0;
}