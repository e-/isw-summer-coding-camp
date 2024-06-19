#include <stdio.h>
#include <string.h>

int count;

int recursion(const char *s, int l, int r)
{
    count++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s)
{
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    int n;
    char str[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        count = 0;
        int ret = isPalindrome(str);

        printf("%d %d\n", ret, count);
    }
    return 0;
}