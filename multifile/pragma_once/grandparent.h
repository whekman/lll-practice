// here this non-standard but widely supported preprocessor directive
// #pragma once
// makes sure this header is only included once per compilation
// not necessarily available in all compilers
// and its implementation is tricky and might not always be reliable

#pragma once

#include <stdio.h>

void printfoo(void){
    printf("foo\n");
}
