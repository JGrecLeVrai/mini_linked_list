/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** get_list_lenght
*/

#include "list.h"

int ll_get_list_length(linked_list_t *list)
{
    struct linked_list_node *node;
    int i = 0;

    TAILQ_FOREACH(node, &list->head, nodes) {
        i++;
    }
    return i;
}
