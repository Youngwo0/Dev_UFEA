# include <stdio.h>

int get_num();

int main(void)
{
	int n = 0;
    n = get_num();
    for (int i = 1; i <= n; i++)
    {
        //blanks; left triangle
        for (int j = i-1; j > 0 ;j--) printf(" ");

        // stars
        for (int j = 2 * n - 2 * i + 1; j > 0; j--) printf("*");
        printf("\n");
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i - 1; j > 0; j--) printf(" ");
        for (int j = 2 * n - 2 * i + 1; j > 0; j--) printf("*");
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
