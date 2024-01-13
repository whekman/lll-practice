#include <stdio.h>

int main(void)
{
    FILE *fp;

    // signed char is almost never used...
    unsigned char c;

    fp = fopen("output.bin", "rb"); // rb for "read binary"!

    while (fread(&c, sizeof(char), 1, fp) > 0)
        printf("%d\n", c);
}