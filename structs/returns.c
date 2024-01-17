// you can return structs by value
// and access their values directly
// reminds of OO languages like eg python/js etc

#include <stdio.h>

struct foo {
    int x, y;
};

struct foo f(void)
{
    return (struct foo){.x=34, .y=90};
}

int main(void)
{
    struct foo a = f();  // Copy is made

    printf("%d %d\n", a.x, a.y);
    printf("%d %d\n", f().x, f().y);
}