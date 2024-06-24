#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define DIST_MAX 100000001
int n, m;
int d[101][101];

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

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == DIST_MAX)
                printf("%d ", 0);
            else
                printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}
