#include <stdio.h>  

struct book
{
    char title[30];
    char author[30];
    int price;
};  

int main(void)
{
    struct book my_book = {"HTML과 CSS", "홍길동", 28000};
    struct book java_book = {.title = "Java language", .price = 30000};  
 
    printf("첫 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n", my_book.title, my_book.author, my_book.price);
    printf("두 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n", java_book.title, java_book.author, java_book.price);

    return 0;
}

// malloc: "Heap에 저장"; 지금까진 Stack에 저장


// # include <stdio.h>

// int main(void)
// {
//     int A[] = {1,2,3};
//     for (int i = 0; i < 3; i++)
//     {
//         printf("%d\n", A[i]);
//     }
// }

// # include <stdio.h>

// int main(void)
// {
//     long* long_ptr = NULL; // pointer : 뭔가를 열어서 "까본다" -> 박스의 개념 | "까고 들어간다!"
//     long A = 7;
//     long_ptr = &A; // &A is "Call by reference"

//     printf("Original: %d\n", A);
//     printf("Pointer: %d\n", long_ptr); //pointer의 주소값은 계속 바뀜; Ram이 Random Access Memory이기 때문에!
//     printf("Value: %d\n", *long_ptr);
//     *long_ptr = 4;
//     printf("Original: %d\n",A);
//     printf("Value: %d\n", *long_ptr);
// }
