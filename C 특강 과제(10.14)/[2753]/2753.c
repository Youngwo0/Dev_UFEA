# include <stdio.h>

int get_num();

int main(void)
{
	int n = 0;
    n = get_num();

    if (n % 4 == 0)
    {
        if (n % 100 == 0)
        {
            if (n % 400 == 0)
            {
                printf("1");
            }

            else printf("0");
        }
        else printf("1");
    }

    else printf("0");

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