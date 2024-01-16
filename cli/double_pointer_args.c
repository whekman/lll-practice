#include <stdio.h>
#include <stdlib.h>

//ugly method but sometimes used by people
//better us argv[i]
int main(int argc, char **argv)
{
    int total = 0;
    
    // Cute trick to get the compiler to stop warning about the
    // unused variable argc:
    (void)argc;

    // start at i = 1 since argv[0] holds filename...
    for (int i = 1; i < argc; i++) {

        // equivalent to something like
        // *p = argv[0+i]
        char **p = argv + i;
        
        int value = atoi(*p);  // Use strtol() for better error handling

        total += value;
    }

    printf("%d\n", total);
}