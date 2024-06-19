#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void hanoi(int n, int from, int via, int to)
{
    if (n == 1)
    {
        printf("%d %d\n", from, to);
        return;
    }
    hanoi(n - 1, from, to, via);
    printf("%d %d\n", from, to);
    hanoi(n - 1, via, from, to);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n, 1, 2, 3);

    return 0;
}