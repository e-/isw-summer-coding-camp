#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n, m;
int g[1001][1001];
int stack[10001], queue[1001];
int visited[1001];

int main()
{
    int start;
    scanf("%d %d %d", &n, &m, &start);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }

    int top = 0;

    stack[top++] = start;

    while (top)
    {
        int v = stack[--top];

        if (visited[v])
            continue;

        printf("%d ", v);
        visited[v] = 1;

        for (int i = n; i >= 1; i--)
        {
            if (!visited[i] && g[v][i])
            {
                stack[top++] = i;
            }
        }
    }

    printf("\n");

    int front, rear;
    front = rear = 0;
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int v = queue[front++];

        printf("%d ", v);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && g[v][i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}