# include <stdio.h>

int get_num();

int main(void)
{
	int a, b;
    a = get_num();
    b = get_num();

    if ((a > 0) && (b > 0)) printf("1");
    else if((a > 0) && (b < 0)) printf("2");
    else if((a < 0) && (b > 0)) printf("3");
    else printf("4");
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
