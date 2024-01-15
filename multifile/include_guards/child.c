
// Uses so-called include guards in the header files
// to prevent re-defining header elements
// here printfoo

#include "grandparent.h"
#include "parent.h"

int main(void){
	printfoo();
}