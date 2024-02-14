# include <stdio.h>

int get_num();

int main(void)
{
	int n = 0;
    n = get_num();
    for (int i = 1; i <= n; i++)
    {
        // stars left
        for (int j = 1; j <= i; j++) printf("*");
        // blank 8 - 6 - 4 - 2
        for (int j = n - i; j > 0; j--) printf("  ");
        // stars right
        for (int j = 1; j <= i; j++) printf("*");
        printf("\n");
    }
    for (int i = n - 1; i > 0; i--)
    {
        /* stars left*/
        for (int j = i; j > 0; j--) printf("*");
        // blanks 2 - 4 - 6 - 8
        for (int j = n - i; j > 0; j--) printf("  ");
        // stars right
        for (int j = i; j > 0; j--) printf("*");
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
