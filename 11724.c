#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n, m;
int g[1001][1001], stack[5000];
int visited[1001];

void dfs(int start)
{
    int top = 0;
    stack[top++] = start;

    while (top)
    {
        int v = stack[--top];

        if (visited[v])
            continue;

        visited[v] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && g[v][i])
            {
                stack[top++] = i;
            }
        }
    }
}
int main()
{
    int start;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }

    int components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            components++;
            dfs(i);
        }
    }

    printf("%d\n", components);
    return 0;
}