#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define DIST_MAX 100000001
int n, m;
int map[12][12], d[11][11];
int dist[11], visited[11];

void fill(int x, int y, int color)
{
    if (map[x][y] == color)
        return;
    map[x][y] = color;

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (map[nx][ny] == 99)
            fill(nx, ny, color);
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
                map[i][j] = 99;
        }

    int color = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == 99)
                fill(i, j, ++color);
        }

    for (int i = 1; i <= color; i++)
    {
        for (int j = 1; j <= color; j++)
            d[i][j] = DIST_MAX;
        d[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j])
            {
                int cur_color = map[i][j];
                for (int k = 1;; k++)
                {
                    if (i + k > n)
                        break;

                    int other_color = map[i + k][j];
                    if (other_color)
                    {
                        if (k >= 3 && d[cur_color][other_color] > k - 1)
                            d[cur_color][other_color] = k - 1;
                        break;
                    }
                }

                for (int k = 1;; k++)
                {
                    if (i - k <= 0)
                        break;
                    int other_color = map[i - k][j];

                    if (other_color)
                    {
                        if (k >= 3 && d[cur_color][other_color] > k - 1)
                            d[cur_color][other_color] = k - 1;
                        break;
                    }
                }

                for (int k = 1;; k++)
                {
                    if (j + k > m)
                        break;
                    int other_color = map[i][j + k];

                    if (other_color)
                    {
                        if (k >= 3 && d[cur_color][other_color] > k - 1)
                            d[cur_color][other_color] = k - 1;
                        break;
                    }
                }

                for (int k = 1;; k++)
                {
                    if (j - k <= 0)
                        break;
                    int other_color = map[i][j - k];

                    if (other_color)
                    {
                        if (k >= 3 && d[cur_color][other_color] > k - 1)
                            d[cur_color][other_color] = k - 1;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= color; i++)
        dist[i] = DIST_MAX;

    dist[1] = 0;
    int cost = 0, connected = 0;

    for (int i = 1; i <= color; i++)
    {
        double min_dist = DIST_MAX;
        int min_v = 0;

        for (int j = 1; j <= color; j++)
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_v = j;
            }

        if (min_v == 0)
            break;
        cost += min_dist;
        connected++;
        visited[min_v] = 1;

        for (int j = 1; j <= color; j++)
            if (!visited[j] && d[min_v][j] < dist[j])
                dist[j] = d[min_v][j];
    }

    if (connected < color)
        printf("-1\n");
    else
        printf("%d\n", cost);

    return 0;
}
