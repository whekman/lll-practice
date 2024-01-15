#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = "349x0";  // "x" is not a valid digit in base 10!
    char *badchar;

    // Convert string s, a number in base 10, to an unsigned long int.

    unsigned long int x = strtoul(s, &badchar, 10);

    // Check if things went well

    if (*badchar == '\0') {
        printf("Success! %lu\n", x);
    } else  {
        printf("Partial conversion: %lu\n", x);
        printf("Invalid character: %c\n", *badchar);
    }

    // some fun with decimal chars
    int d = 6;

    char c = d + '0';  // c has value 54

    printf("%d\n", c);  // prints 54
    printf("%c\n", c);  // prints 6 with %c

}