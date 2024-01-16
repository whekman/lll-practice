
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int total = 0;


    for (int i = 1; i < argc; i++) {  // Start at 1, the first argument

    	// NOTE: Apparently atoi returns 0
    	// if we try to convert a single character...

        int value = atoi(argv[i]);    // Use strtol() for better error handling

        total += value;
    }

    printf("%d\n", total);
}