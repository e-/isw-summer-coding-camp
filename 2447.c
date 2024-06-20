#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int cantor(int i, int j, int w)
{
    if (w == 1)
        return 1;

    if (w / 3 <= i && i < w * 2 / 3 && w / 3 <= j && j < w * 2 / 3)
        return 0;
    else
        return cantor(i % (w / 3), j % (w / 3), w / 3);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", cantor(i, j, n) ? '*' : ' ');
        }
        printf("\n");
    }

    return 0;
}