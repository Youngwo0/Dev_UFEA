# include <stdio.h>

int get_num();

int main(void)
{
	int a, b, c, m, answer;
    a = get_num();
    b = get_num();
    c = get_num();

    if((a == b) && (b == c))
    {
        answer = 10000 + a * 1000;
    }
    else if((a == b) || (b == c))
    {
        answer = 1000 + b * 100;
    }
    else if (a == c)
    {
        answer = 1000 + a * 100;
    }
    else
    {
        m = a;

        if (b > m) m = b;
        if (c > m) m = c;

        answer = m * 100;
    }

    printf("%d", answer);
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
