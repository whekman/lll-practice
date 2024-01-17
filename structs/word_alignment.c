#include <stdio.h>
#include <stddef.h>

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

    printf("Offsets:\n");
    printf("a: %zu\n", offsetof(struct foo, a));
    printf("b: %zu\n", offsetof(struct foo, b));
    printf("c: %zu\n", offsetof(struct foo, c));
    printf("d: %zu\n", offsetof(struct foo, d));

}