#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int cantor(int i, int w)
{
    if (w == 1)
        return 1;
    if (i < w / 3)
        return cantor(i, w / 3);
    else if (w / 3 <= i && i < w * 2 / 3)
        return 0;
    else
        return cantor(i - w * 2 / 3, w / 3);
}

int main()
{
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        m = 1;
        for (int i = 0; i < n; i++)
            m *= 3;

        for (int i = 0; i < m; i++)
        {
            printf("%c", cantor(i, m) ? '-' : ' ');
        }
        printf("\n");
    }

    return 0;
}