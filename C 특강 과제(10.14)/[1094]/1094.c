# include <stdio.h>

int main(void)
{
    int x, stick, sum;
    scanf("%d", &x);

    stick = 0;

    for (int i = 64; i > 0; i /= 2)
    {
        if (i > x)
        {
            continue;
        }

        else if (i == x)
        {
            stick = 1;
            break;
        }

        if (sum + i <= x)
        {
            sum += i;
            stick ++;
        }
    }
    printf("%d", stick);
}
