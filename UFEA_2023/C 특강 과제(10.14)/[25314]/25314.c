# include <stdio.h>

int get_num();

int main(void)
{
	int n = 0;
    n = get_num();

    for (int i = 1; i <= n / 4; i++)
    {
        printf("long ");
    }

    printf("int");
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
