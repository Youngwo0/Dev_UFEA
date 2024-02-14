# include <stdio.h>

int get_num();

int main(void)
{
    int n = 0;

    n = get_num();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i) printf("*");
            else printf(" ");
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
