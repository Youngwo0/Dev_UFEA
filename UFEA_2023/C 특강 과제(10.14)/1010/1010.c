#include <stdio.h>
int main(void)
{
    int t, n, m, result;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        result = 1;
        scanf("%d %d", &n, &m);
        for (int j = 0; j < n; j++)
        {
            result *= m - j;
            result /= 1 + j;
        }
        printf("%d\n", result);
    }
}
