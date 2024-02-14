# include <stdio.h>
int get_num();
int main(void)
{
	int n = 0;
    n = get_num();
    for (int i = n; i > 0; i--)
    {
        // blank
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        // stars
        for (int j = 0; j < (2 * i) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

int get_num()
{
    int result = 0;
    char temp_char = ' ';

    temp_char = getchar();
    while(temp_char != ' ' && temp_char != '\n')
    {
        result *= 10;
        result += temp_char - '0';
        temp_char = getchar();
        
    }
    return result;
}
