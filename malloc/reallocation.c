#include <stdio.h>
#include <stdlib.h>


// Basic example of memory reallocation
// note the jump in address value

int main(void)
{

    int n = 20;

    // Allocate space for 20 ints
    int *p = malloc(sizeof *p * n);  // sizeof *p same as sizeof(float)

    // Assign them fractional values 0.0-1.0:
    for (int i = 0; i < n; i++)
        p[i] = i;

    for(int i = 0; i < n; i++){
        printf("%p  %04d  0x%04X\n", p+i, *(p+i), *(p+i));
        }

    n = 40;

    // But wait! Let's actually make this an array of 40 elements
    int *new_p = realloc(p, sizeof *p * n);

    // Check to see if we successfully reallocated
    if (new_p == NULL) {
        printf("Error reallocing\n");
        return 1;
    }

    printf("\n");

    // If we did, we can just reassign p
    p = new_p;

    // And assign the new elements values in the range 1.0-2.0
    for (int i = 20; i < n; i++)
        p[i] = i;

    // Print all values 0.0-2.0 in the 40 elements:
    for (int i = 20; i < 40; i++){
        printf("%p  %04d  0x%04X\n", p+i, *(p+i), *(p+i));
        }
    // Free the space
    free(p);
}