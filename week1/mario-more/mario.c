#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the size of the pyramid
    int size;
    do
    {
        size = get_int("Please input the size of the pyramid: ");
    }
    while (size < 1 || size > 8);

    // print line 1 to line n
    for (int line = 1; line <= size; line++)
    {
        // print the first pyramid
        // print space*(size-i)
        for (int i = 1; i <= size - line; i++)
        {
            printf(" ");
        }
        // print #*i
        for (int j = 1; j <= line; j++)
        {
            printf("#");
        }

        // print two spaces
        printf("  ");

        // print the second pyramid
        for (int m = 1; m <= line; m++)
        {
            printf("#");
        }

        printf("\n");
    }


}