# include <stdio.h>

int get_num();

int main(void)
{
	int n = 0;
    n = get_num();

    if ((n <= 100) && (n >= 90)) printf("A");
    else if ((n >= 80) && (n < 90)) printf("B");
    else if ((n >= 70) && (n < 80)) printf("C");
    else if ((n >= 60) && (n < 70)) printf("D");
    else printf("F");
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
