
// Reads a file line by line using fgets

// fgets():

// The fgets() function shall read bytes from stream into the array
//        pointed to by s until n-1 bytes are read, or a <newline> is read
//        and transferred to s, or an end-of-file condition is encountered.
//        A null byte shall be written immediately after the last byte read
//        into the array.  If the end-of-file condition is encountered
//        before any bytes are read, the contents of the array pointed to
//        by s shall not be changed.

// Upon successful completion, fgets() shall return s.  If the
//        stream is at end-of-file, the end-of-file indicator for the
//        stream shall be set and fgets() shall return a null pointer.  If
//        a read error occurs, the error indicator for the stream shall be
//        set, fgets() shall return a null pointer, and shall set errno to
//        indicate the error.

#include <stdio.h>

int main(void){

	FILE *fp;
	char s[1024]; // big enough for a line
	int linecount = 0;

	fp = fopen("quote.txt", "r");

	// it turns out C has a special type to represent
	// the return value from sizeof. It’s size_t, pronounced “size tee”39.
	// All we know is that it’s an unsigned
	// integer type that can hold the size in bytes of anything you can give to sizeof

	printf("Sizeof s: %lu\n\n", sizeof s);

	// s point to char buffer (starting at s[0])
	while (fgets(s, sizeof s, fp) != NULL){

		printf("%d: %s", ++linecount, s);
		// NOTE: Uses pre-increment
		// printf gets incremented the value of linecount

	}

	fclose(fp);

	// NOTE: String literals
	// initialized as char-arrays
	// implicitly end with a NUL character
	// which is a 0 valued byte.
	
	// This saves us from what we have to do in assembly:
	// pass the string length each time we want to do something
	// or use a special sub-routine to calculate the length.

	char t[] = "Test";
	printf("\n\nString Terminator: %c\n", t[4]);


}