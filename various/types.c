#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    char a = 'a';
    char b = 'B';  // ASCII value 66

    printf("%d, %c\n", a,a); 
    printf("%d, %c\n", b,b);
    printf("%d, %c\n", a + b,a+b);

    if (CHAR_MAX == UCHAR_MAX){
        printf("chars are unsigned!\n");
    } else {
        printf("chars are signed!\n");
    }

    printf("The Radix of floats is base: %d\n", FLT_RADIX);
    printf("The reliable ndigits floats can represent is %d\n", FLT_DIG);

    float f = 123456789;

    printf("%f\n", f);

    f = 3.14159f;
    float g = 0.00000265358f;

    printf("%.5f\n", f);   // 3.14159       -- correct!
    printf("%.11f\n", g);  // 0.00000265358 -- correct!

    // Now add them up
    f += g;                // 3.14159265358 is what f _should_ be

    printf("%.11f\n", f);  // 3.14159274101 -- wrong!


}