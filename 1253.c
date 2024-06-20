#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n, nums[2000];
int good[2000];

int lower_bound(int q)
{
    int l = 0, r = n - 1;
    int ans = -1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] == q)
        {
            ans = m;
            r = m - 1;
        }
        else if (q < nums[m])
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

        if (nums[m] == q)
        {
            ans = m;
            l = m + 1;
        }
        else if (q < nums[m])
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
        scanf("%d", &nums[i]);

    qsort(nums, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (good[i])
                break;
            int target = nums[i] - nums[j];
            int l = lower_bound(target), u = upper_bound(target);

            if (l < 0)
                continue;

            for (int k = l; k <= u; k++)
            {
                if (k != i && k != j)
                {
                    good[i] = 1;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += good[i];

    printf("%d\n", ans);

    return 0;
}