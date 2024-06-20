#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n, m;
int key[500000];

int lower_bound(int q)
{
    int l = 0, r = n - 1;
    int ans = -1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (key[m] == q)
        {
            ans = m;
            r = m - 1;
        }
        else if (q < key[m])
            r = m - 1;
        else
            l = m + 1;
    }

    return ans;
}

int upper_bound(int q)
{
    int l = 0, r = n - 1;
    int ans = -1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (key[m] == q)
        {
            ans = m;
            l = m + 1;
        }
        else if (q < key[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return ans;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &key[i]);
    qsort(key, n, sizeof(int), cmp);

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int q;
        scanf("%d", &q);

        int l = lower_bound(q);
        int u = upper_bound(q);

        if (l == -1)
            printf("0 ");
        else
            printf("%d ", u - l + 1);
    }

    return 0;
}