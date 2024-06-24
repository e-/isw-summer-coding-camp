#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define DIST_MAX 100000001
int n, m;
int d[401][401];

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
        d[from][to] = dist;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }

    int min_dist = DIST_MAX;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && d[i][j] + d[j][i] < min_dist)
                min_dist = d[i][j] + d[j][i];
        }
    }

    if (min_dist == DIST_MAX)
        printf("-1\n");
    else
        printf("%d\n", min_dist);

    return 0;
}
