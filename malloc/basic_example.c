#include <stdlib.h>
#include <stdio.h>

int main(void){
	// Allocate space for a single int (sizeof(int) bytes-worth):

	int *p = malloc(sizeof(int));

	// ALSO this is a typical pattern which includes
	// error checking

	// if (*p = malloc(sizeof(int)) == NULL)
	//     printf("Error allocating 10 ints\n");
	//     // do something here to handle it
	// }

	*p = 12;  // Store something there

	printf("%d\n", *(p));  // Print it: 12

	// note also works... we go in some
	// sort of initialized empty zone
	// putting -100 till +30000 (!) works.
	// 30000 bytes = 30kB
	printf("%d\n", *(p + 30000));

	free(p);  // All done with that memory

    printf("\n");

	// The allocated memory contains garbage values
	// if we use malloc
	// instead we can use calloc
	int n = 20;

	// Compare this to the similar call with calloc
	//int *c = malloc(20*32);

	int *c = calloc(20, 32);

	int *cc = c;

	for(int i = 0; i < n; i++){
		printf("%p  %04d  0x%04X\n", c+i, *(c+i), *(c+i));
		}

	free(cc);

    printf("\n");

    // Allocate space for 10 ints
    int *pa = malloc(sizeof(int) * 10);

    // Assign them values 0-45:
    for (int i = 0; i < 10; i++)
        pa[i] = i * 5;

	// So pa[i] = ... seem to be synctactic sugar for
    // *(pa + i) = ...
    
    // Print all values 0, 5, 10, 15, ..., 40, 45
    for (int i = 0; i < 10; i++)
        printf("%d\n", pa[i]);

    // Free the space
    free(pa);

    printf("\n");

    // Do note:
    // Arrays are arrays and pointers are pointers. They are different thing.

    int A[] = {1, 2 ,3};
	int *t = A;
	size_t sz1 = sizeof A;
	size_t sz2 = sizeof t;
	printf("%zu %zu\n", sz1, sz2);
}