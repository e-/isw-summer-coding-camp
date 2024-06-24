#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define DIST_MAX 100000001
int n;
double d[101][101], dist[101];
int visited[101];
double x[101], y[101];

int main()
{
    double ans = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%lf %lf", &x[i], &y[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

    for (int i = 1; i <= n; i++)
        dist[i] = DIST_MAX;
    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        double min_dist = DIST_MAX;
        int min_v = 0;

        for (int j = 1; j <= n; j++)
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_v = j;
            }

        ans += min_dist;
        visited[min_v] = 1;

        for (int j = 1; j <= n; j++)
            if (!visited[j] && d[min_v][j] < dist[j])
                dist[j] = d[min_v][j];
    }

    printf("%.2lf\n", ans);

    return 0;
}
