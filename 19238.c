#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

typedef struct xy_t_
{
    int x;
    int y;
    int dist;
} xy_t;

xy_t queue[10001];
int visited[21][21];
int n, m, map[21][21];
int gas;
xy_t guest_start[401], guest_end[401];
int guest_done[401];

int bfs(xy_t start, xy_t end)
{
    int front, rear;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    front = rear = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            visited[i][j] = 0;

    queue[rear++] = (xy_t){start.x, start.y, 0};
    visited[0][0] = 1;

    while (front < rear)
    {
        xy_t xy = queue[front++];
        int x = xy.x, y = xy.y;

        if (x == end.x && y == end.y)
        {
            return xy.dist;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !visited[nx][ny] && !map[nx][ny])
            {
                visited[nx][ny] = 1;
                queue[rear++] = (xy_t){nx, ny, xy.dist + 1};
            }
        }
    }

    return -1;
}

int main()
{
    xy_t taxi;
    scanf("%d %d %d", &n, &m, &gas);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);

    scanf("%d %d", &taxi.x, &taxi.y);
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d %d", &guest_start[i].x, &guest_start[i].y, &guest_end[i].x, &guest_end[i].y);

    for (int t = 1; t <= m; t++)
    {
        int min_guest = -1;
        int min_dist = 500;

        for (int i = 1; i <= m; i++)
        {
            if (guest_done[i])
                continue;
            int dist = bfs(taxi, guest_start[i]);
            if (dist < 0)
                continue;
            if (dist < min_dist || (dist == min_dist && (guest_start[i].x < guest_start[min_guest].x ||
                                                         guest_start[i].x == guest_start[min_guest].x && guest_start[i].y < guest_start[min_guest].y)))
            {
                min_guest = i;
                min_dist = dist;
            }
        }

        if (min_guest == -1)
        {
            gas = -1;
            break;
        }

        if (gas < min_dist)
        {
            gas = -1;
            break;
        }

        gas -= min_dist;
        taxi = guest_start[min_guest];

        int dist = bfs(taxi, guest_end[min_guest]);
        if (dist < 0)
        {
            gas = -1;
            break;
        }
        if (gas < dist)
        {
            gas = -1;
            break;
        }

        gas += dist;
        taxi = guest_end[min_guest];
        guest_done[min_guest] = 1;
    }
    printf("%d\n", gas);

    return 0;
}