#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define abs(x) ((x) < 0 ? -(x) : (x))
int n, s[20][20], t1[10], t2[10];
int ans = 100 * 10 * 9;

void f(int cur, int t1_size, int t2_size, int t1_pow, int t2_pow)
{
    if (cur == n)
    {
        if (abs(t1_pow - t2_pow) < ans)
            ans = abs(t1_pow - t2_pow);
        return;
    }

    if (t1_size < n / 2)
    {
        int pow = 0;
        for (int i = 0; i < t1_size; i++)
        {
            pow += s[cur][t1[i]] + s[t1[i]][cur];
        }

        t1[t1_size] = cur;
        f(cur + 1, t1_size + 1, t2_size, t1_pow + pow, t2_pow);
    }

    if (t2_size < n / 2)
    {
        int pow = 0;
        for (int i = 0; i < t2_size; i++)
        {
            pow += s[cur][t2[i]] + s[t2[i]][cur];
        }

        t2[t2_size] = cur;
        f(cur + 1, t1_size, t2_size + 1, t1_pow, t2_pow + pow);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &s[i][j]);

    f(1, 1, 0, 0, 0);
    printf("%d\n", ans);

    return 0;
}