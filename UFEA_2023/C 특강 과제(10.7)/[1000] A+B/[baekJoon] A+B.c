# include <stdio.h>

int get_num();

int main(void)
{
    int A, B;
    A = get_num();
    B = get_num();

    printf("%d", A+B);

    return 0;
}

int get_num()
{
    int result = 0;
    char temp_char = ' ';

    temp_char = getchar();
    while (temp_char != ' ' && temp_char != '\n')
    {
        result *= 10;
        result += temp_char - '0';
        temp_char = getchar();
    }

    return result;
}