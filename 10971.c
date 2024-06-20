#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n;
int dist[10][10];
int visited[10];
int ans = 12 * 1000000;

void tsp(int v, int cost, int num_visited)
{
    if (num_visited == n)
    {
        if (dist[v][0] > 0 && cost + dist[v][0] < ans)
            ans = cost + dist[v][0];
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[v][i] > 0)
        {
            visited[i] = 1;
            tsp(i, cost + dist[v][i], num_visited + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    int start;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    visited[0] = 1;
    tsp(0, 0, 1);

    printf("%d\n", ans);

    return 0;
}