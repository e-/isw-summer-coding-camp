#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n = 12, m = 6;
char map[12][7], next_map[12][7];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int visited[12][7];

int dfs(int x, int y, int color)
{
    if (visited[x][y])
        return 0;

    visited[x][y] = 1;

    int same = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && map[nx][ny] == color)
        {
            same += dfs(nx, ny, color);
        }
    }

    return same;
}

void destroy(int x, int y, int color)
{
    next_map[x][y] = '.';

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && next_map[nx][ny] == color)
        {
            destroy(nx, ny, color);
        }
    }
}

int main()
{
    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);

    for (int t = 0;; t++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                next_map[i][j] = map[i][j];
                visited[i][j] = 0;
            }

        int removed = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] != '.' && !visited[i][j])
                {
                    int same = dfs(i, j, map[i][j]);
                    if (same >= 4)
                    {
                        removed = 1;
                        destroy(i, j, map[i][j]);
                    }
                }
            }
        }

        if (!removed)
        {
            printf("%d\n", t);
            break;
        }

        for (int i = 0; i < m; i++)
        {
            int row = n - 1;
            for (int j = n - 1; j >= 0; j--)
            {
                if (next_map[j][i] != '.')
                {
                    map[row--][i] = next_map[j][i];
                }
            }
            for (; row >= 0; row--)
                map[row][i] = '.';
        }
    }

    return 0;
}