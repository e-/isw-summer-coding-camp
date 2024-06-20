#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n, target;
int trees[1000000];

int main()
{
    scanf("%d %d", &n, &target);
    for (int i = 0; i < n; i++)
        scanf("%d", &trees[i]);

    int ans = 0;
    int l = 0, r = 1000000000;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (trees[i] > m)
                sum += trees[i] - m;
        }

        if (sum < target)
            r = m - 1;
        else
        {
            ans = m;
            l = m + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}