#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);
    int *x = p;
    n = 20;
    printf("%p\n", x);
    printf("%i\n", *x);
}