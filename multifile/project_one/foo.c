// File foo.c

#include <stdio.h>

// we get our function from the local header file :-)
#include "bar.h"

// not necessary anymore since we have
// the prototype in bar.h:

// // our function prototype!
// int add(int, int); 

int main(void)
{
    printf("%d\n", add(2, 3));  // 5!
}