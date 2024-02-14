#include "number.h"

int get_num()
{
    int result = 0;
    int sign = 0;
    char temp_char = ' ';

    temp_char = getchar();
    while (temp_char != ' ' && temp_char != '\n')
    {
        if ((temp_char == '-') && sign == 0) {
            sign = -1;
            temp_char = getchar();
        }
        else {
            if (sign == 0) sign = 1;
            result *= 10;
            result += temp_char - '0';
            temp_char = getchar();
        }
    }

    return sign * result;
}

