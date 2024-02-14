# include <stdio.h>

int get_num();

int main(void)
{
	int H, M;
    H = get_num();
    M = get_num();

    if (M >= 45) M -= 45;
    else
    {
        M += 15;
        if (H > 0)
            H -= 1;
        else H = 23;
    }

    printf("%d %d", H, M);
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
