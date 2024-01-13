

// C program to implement
// scanf
#include <stdio.h>
 
// Driver code
int main() 
{
    int a;
    char b;
   
    printf("Enter a number: ");
    scanf("%d", &a);

    // oddly enough we have to put a space
    // in the format otherwise it doesnt work...

    // if we put a character in the number prompt
    // the program seems to put the return value 0
    // back into the next prompt
    // e.g.
    // entering b gives
    // a: 0
    // b: b

    // crushmastac (reddit)
    // Once scanf attempts to read something from the input buffer
    // if it can't get what it's looking for, it leaves that something on the buffer.
    // Long story short, scanf is evil,
    // and you should do everything in your power to avoid using it. 

    // John Bode (stackoverflow)
    // if using %d or %f to read numeric input, certain bad patterns cannot
    // be caught and rejected completely -- if you're reading an integer with %d
    // and the user types "12r4", scanf will
    // convert and assign the 12 while leaving r4 in the input stream
    // to foul up the next read;

    printf("Enter a character: ");
    scanf(" %c", &b);

    printf("a: %d\n", a);
    printf("b: %c\n", b);
   
    return 0;
}
