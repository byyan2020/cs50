#include <stdio.h>

int main(void)
{
    int i = 3;
    int *j = &i;
    printf("%i\n", i);
    printf("%i\n", *j);

    char x = 'a';
    char *y = "b";
    printf("%c\n", x);
    printf("%c\n", *y);
}