# include <stdio.h>

int get_num();

int main(void)
{
	int A, B, C;
    A = get_num();
    B = get_num();
    C = get_num();

    A += C / 60;
    B += C % 60;

    if (B >= 60)
    {
        A += B / 60;
        B -= 60;
    }

    printf("%d %d",A % 24, B);
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
