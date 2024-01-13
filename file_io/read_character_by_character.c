#include <stdio.h>

int main(void){

	FILE *fp; // file descriptor

	// returns NULL if error
	fp = fopen("hello.txt", "r");

	// an int... mysterious
	// reason is...
	int c = fgetc(fp);

	// the EOF value isnt recognized as a char
	// in assembly it's literally
	// EOF = -1
	// note ASCII 7 ringed a bell
	// in other words
	// a subset of the integers used to represent text (via ascii)
	// translate to text characters
	// ascii was used to control an actual typewrite so also has
	// CONTROL character encoding

	// new line = 10  LF  (NL line feed, new line)
	// new page =  12  FF  (NP form feed, new page)
	// carriage return = 13  CR  (carriage return) 

	printf("%c\n", c);

	fclose(fp);

	// to read the whole file:

	fp = fopen("hello.txt", "r");

	// NOTE: (c = fgetc(fp)) != EOF
	// is considered idiomatic C...

	// NOTE: You also get EOF when there is an error
	// Then: ferror(fp) != 0 --> error handling

	while ((c = fgetc(fp)) != EOF){
		printf("%c", c);
	}

	fclose(fp);

	return 0;
}