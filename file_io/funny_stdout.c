#include <stdio.h>

int main(void)
{
    FILE *fp;
    int x = 32;


    fp = fopen("output.txt", "w");

    fp = stdout;
    // is also a valid file descripter

    fputc('B', fp);
    fputc('\n', fp);   // newline
    fprintf(fp, "x = %d\n", x);
    fputs("Hello, world!\n", fp);

    fclose(fp);
}