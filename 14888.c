#include <stdio.h>

int n, nums[100], ops[4];

int get_max(int i, int res, int o1, int o2, int o3, int o4)
{
    if (i == n)
        return res;
    int max = -1000000000;
    if (o1 > 0)
    {
        max = get_max(i + 1, res + nums[i], o1 - 1, o2, o3, o4);
    }
    if (o2 > 0)
    {
        int temp = get_max(i + 1, res - nums[i], o1, o2 - 1, o3, o4);
        if (temp > max)
            max = temp;
    }
    if (o3 > 0)
    {
        int temp = get_max(i + 1, res * nums[i], o1, o2, o3 - 1, o4);
        if (temp > max)
            max = temp;
    }
    if (o4 > 0)
    {
        int temp = get_max(i + 1, res / nums[i], o1, o2, o3, o4 - 1);
        if (temp > max)
            max = temp;
    }
    return max;
}

int get_min(int i, int res, int o1, int o2, int o3, int o4)
{
    if (i == n)
        return res;
    int min = 1000000000;
    if (o1 > 0)
    {
        min = get_min(i + 1, res + nums[i], o1 - 1, o2, o3, o4);
    }
    if (o2 > 0)
    {
        int temp = get_min(i + 1, res - nums[i], o1, o2 - 1, o3, o4);
        if (temp < min)
            min = temp;
    }
    if (o3 > 0)
    {
        int temp = get_min(i + 1, res * nums[i], o1, o2, o3 - 1, o4);
        if (temp < min)
            min = temp;
    }
    if (o4 > 0)
    {
        int temp = get_min(i + 1, res / nums[i], o1, o2, o3, o4 - 1);
        if (temp < min)
            min = temp;
    }
    return min;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    for (int i = 0; i < 4; i++)
        scanf("%d", &ops[i]);

    printf("%d\n", get_max(1, nums[0], ops[0], ops[1], ops[2], ops[3]));
    printf("%d\n", get_min(1, nums[0], ops[0], ops[1], ops[2], ops[3]));

    return 0;
}