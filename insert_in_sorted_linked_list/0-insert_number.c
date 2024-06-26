#include "lists.h"
#include <stdlib.h>
/*
insert a number into a sorted singly linked list
@head
@int number
Return address of new node or NULL if failed*/
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    listint_t *prev;

    current = *head;
    prev = NULL;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current != NULL && current->n < number)
        {
            prev = current;
            current = current->next;
        }
        if (prev == NULL)
        {
            new->next = *head;
            *head = new;
        }
        else
        {
            prev->next = new;
            new->next = current;
        }
    }

    return (new);
}
