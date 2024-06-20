#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

typedef struct xy_t_
{
    int x;
    int y;
    int dist;
} xy_t;

int n, m;
char map[101][101];
int visited[100][100];
xy_t queue[10001];

int main()
{
    int start;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", map[i]);
    }

    int front, rear;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    front = rear = 0;

    queue[rear++] = (xy_t){0, 0, 1};
    visited[0][0] = 1;

    while (front < rear)
    {
        xy_t xy = queue[front++];
        int x = xy.x, y = xy.y;

        if (x == n - 1 && y == m - 1)
        {
            printf("%d\n", xy.dist);
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && map[nx][ny] == '1')
            {
                visited[nx][ny] = 1;
                queue[rear++] = (xy_t){nx, ny, xy.dist + 1};
            }
        }
    }

    return 0;
}