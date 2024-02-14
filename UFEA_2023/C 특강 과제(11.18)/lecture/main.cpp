#include <stdio.h>
#include "libtest-1.h"

int main(void)
{
    long A;
    long B;
    char chr;

    while(1)
    {
        printf("A: ");
        scanf("%ld", &A);
        chr = getchar();

        printf("B: ");
        scanf("%ld", &B);
        chr = getchar();

        printf("resule: %ld\n", sum(A, B));
    }

    return 0;
}