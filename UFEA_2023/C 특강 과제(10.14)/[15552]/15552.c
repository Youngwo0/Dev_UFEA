# include <stdio.h>

int get_num();

int main(void)
{
	int t=0, a=0, b=0;
    t = get_num();

    for (int i = 1; i <= t; i++)
    {
        a = get_num();
        b = get_num();

        printf("%d\n", a + b);
    }
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
