#include "get.h"

#ifdef __linux__
char folder[] = "./";
#else
char folder[] = "C:\\Users\\LG\\Data\\2023-10-13\\";
#endif

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

long get_len(char str[])
{
    long result = 0;

    while (str[result++] != '\0') {}
    return --result;
}

char* get_str()
{
    char* result = (char*)malloc(sizeof(char) * 1);
    long size = 1;
    char temp_char = ' ';

    temp_char = getchar();
    while (temp_char != ' ' && temp_char != '\n')
    {
        result = (char*)realloc(result, sizeof(char) * (size + 1));
        result[size - 1] = temp_char;
        temp_char = getchar();
        size++;
    }
    result[--size] = '\0';
    return result;
}

char* get_address(char file[])
{
    long path_size = get_len(folder);
    long file_size = get_len(file);
    long address_size = path_size + file_size;
    char* result = (char*)malloc(sizeof(char) * (address_size + 1));

    for (long i = 0; i < path_size; i++)
    {
        result[i] = folder[i];
    }

    for (long i = 0; i < file_size; i++)
    {
        result[path_size + i] = file[i];
    }
    result[address_size] = '\0';

    return result;
}