#include <stdio.h>

struct foo {
    int a;
    char b;
    int c;
    char d;
};

int main(void)
{
    printf("Int: %zu\n", sizeof(int));
    printf("Char: %zu\n", sizeof(char));
    
    printf("Naive: %zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
    printf("Actual: %zu\n", sizeof(struct foo));
}