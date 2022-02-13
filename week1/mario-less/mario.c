#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // user input a the size of the pyramid between 1 and 8
    int size;
    do
    {
        size = get_int("Please enter the size of this pyramid: ");
    }
    while (size < 1 || size > 8);

    for (int i = 1; i <= size; i++)
    {
        // print space*(size-i)
        for (int j = 1; j <= size - i; j++)
        {
            printf(" ");
        }
        // print #*i
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        // another line
        printf("\n");
    }

}

