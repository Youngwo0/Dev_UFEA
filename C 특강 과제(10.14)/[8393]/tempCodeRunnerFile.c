# include <stdio.h>

int get_num();

int main(void)
{
	int n, answer;
    n = get_num();

    for (int i = n; i > 0; i--)
    {
        answer += i;
    }

    printf("%d",  answer);
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
