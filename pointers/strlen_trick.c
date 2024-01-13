#include <stdio.h>

int my_strlen(char *s)
{
    // Start scanning from the beginning of the string
    char *p = s;

    // Scan until we find the NUL character
    while (*p != '\0')
        p++;

    // Return the difference in pointers
    return p - s;
}

int main(void)
{

    char *s = "Hello, world!";

    printf("%d\n", my_strlen(s));  // Prints "13"

    for(int i = 0; i <10; i++){
        printf("%p %c\n", s+i, *(s+i));
    }

    int j = 0;
    printf("%d\n",j--);

    j = 0;
    printf("%d\n",--j);
    



}