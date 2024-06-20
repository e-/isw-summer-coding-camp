#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

typedef struct cell_t_
{
    int x;
    int y;
} cell_t;

int h, w;
int num_papers, n;
cell_t cells[1001];

int cmp(const void *a, const void *b)
{
    return ((cell_t *)a)->x - ((cell_t *)b)->x;
}

int main()
{
    scanf("%d %d %d %d", &h, &w, &num_papers, &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &cells[i].y, &cells[i].x);

    qsort(cells, n, sizeof(cell_t), cmp);

    int l = 0, r = 1000000;
    int ans = -1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int num_used = 0;
        int last = -2000000;

        for (int i = 0; i < n; i++)
        {
            if (cells[i].y > m)
            {
                num_used = num_papers + 1;
                break;
            }

            if (cells[i].x >= last + m)
            {
                num_used++;
                last = cells[i].x;
            }
        }

        if (num_used <= num_papers)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}