#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n, num_rides;
int rides[10000];

int main()
{
    scanf("%d %d", &n, &num_rides);
    for (int i = 0; i < num_rides; i++)
        scanf("%d", &rides[i]);

    int ans = 0;
    long long l = 0, r = (long long)30 * 2000000000;

    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        long long done = 0, newcomer = 0;

        for (int i = 0; i < num_rides; i++)
        {
            done += m / rides[i];
            if (m % rides[i])
                done++;
            if (m % rides[i] == 0)
                newcomer++;
        }

        if (done + newcomer < n)
            l = m + 1;
        else if (done < n && n <= done + newcomer)
        {
            int count = n - done;
            for (int i = 0; i < num_rides; i++)
            {
                if (m % rides[i] == 0)
                {
                    count--;
                    if (count == 0)
                    {
                        ans = i + 1;
                        break;
                    }
                }
            }
            break;
        }
        else
            r = m - 1;
    }

    printf("%d\n", ans);

    return 0;
}