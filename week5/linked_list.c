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
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;

    // update list to point to new node
    list = n;

    // printf("%i\n", list->number);

    // add a number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;
    // printf("%i\n", list->next->number);

    // add a number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // print numbers
    for (node *tmp = list; tmp != NULL; tmp = list->next)
    {
        printf("%i\n", tmp->number);
    }
}