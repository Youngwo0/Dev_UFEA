# include <stdio.h>

int get_num();

int main(void)
{
	int a;
    int b;
    a = get_num();
    b = get_num();

    if (a > b) printf(">");
    else if (a < b) printf(">");
    else printf("==");
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
