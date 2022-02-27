#include <stdio.h>
#include <stdlib.h>

// represents a node
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // list of size 0
    node *list = NULL;

    // add number to list
    node *n = malloc(sizeof(node));
    
}