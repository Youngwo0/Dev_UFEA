#include <stdio.h>

int get_num();

int main(void)
{
    int a, b;
    a = get_num();
    b = get_num();
    
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j< b; j++)
        {
            printf("*");
        }
        printf("\n");
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
