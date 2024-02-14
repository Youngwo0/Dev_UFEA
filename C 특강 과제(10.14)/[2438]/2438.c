// divide and conquer의 철학을 계속 생각할 것.

#include <stdio.h>

int get_num();

int main(void)
{
    int a = 0;
    a = get_num();
    
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j <= i; j++)
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