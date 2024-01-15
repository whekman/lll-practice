#include <stdio.h>

int shared = 10;    // File scope! Visible to the whole file after this!

void func1(void)
{
    shared += 100;  // Now shared holds 110
}

void func2(void)
{
    shared += 200;
}
 

int main(void)
{
    int a = 12;         // Local to outer block, but visible in inner block

    // we can change the 'global'
    shared = 20;

    if  (a == 12) {

        // takes precende over a = 12...
        int a = 4;

        int b = 99;     // Local to inner block, not visible in outer block


        printf("%d %d\n", a, b);  // OK: "4 99"


    }


    func1();
    func2();

    printf("%d\n",shared);

    printf("%d\n", a);  // OK, we're still in a's scope

    // printf("%d\n", b);  // ILLEGAL, out of b's scope

    for (int i = 0; i < 5; i++) {
        int i = 999;  // Hides the i in the for-loop scope
        printf("%d\n", i);
    }

}