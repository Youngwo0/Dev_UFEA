# include <stdio.h>

int get_num();

int main(void)
{
	int X = 0, N = 0, x = 0;
    int a = 0, b = 0;
    X = get_num();
    N = get_num();

    for (int i = 1; i <= N; i++)
    {
        a = get_num();
        b = get_num();
        x += a * b;
    }

    if (X == x) printf("Yes");
    else printf("No");
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
