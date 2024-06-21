#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

typedef struct xy_t_
{
    int x;
    int y;
} xy_t;

xy_t queue[10001];
int visited[51][51];
int n, l, r;
int pop[51][51];
int sum[2501], count[2501];

void bfs(xy_t start, int cluster)
{
    int front, rear;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    front = rear = 0;

    queue[rear++] = start;
    visited[start.x][start.y] = cluster;

    while (front < rear)
    {
        xy_t xy = queue[front++];
        int x = xy.x, y = xy.y;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], diff = abs(pop[nx][ny] - pop[x][y]);

            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !visited[nx][ny] && l <= diff && diff <= r)
            {
                visited[nx][ny] = cluster;
                queue[rear++] = (xy_t){nx, ny};
            }
        }
    }
}

int main()
{

    scanf("%d %d %d", &n, &l, &r);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &pop[i][j]);

    int t;
    for (t = 0; t <= 2000; t++)
    {
        int cluster = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                visited[i][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!visited[i][j])
                {
                    bfs((xy_t){i, j}, cluster++);
                }
            }
        }

        if (cluster > n * n)
            break;

        for (int i = 1; i < cluster; i++)
            sum[i] = count[i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sum[visited[i][j]] += pop[i][j];
                count[visited[i][j]]++;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                pop[i][j] = sum[visited[i][j]] / count[visited[i][j]];
            }
        }
    }
    printf("%d\n", t);

    return 0;
}