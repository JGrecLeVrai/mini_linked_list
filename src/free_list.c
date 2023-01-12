/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** free_list
*/

#include "list.h"

void ll_free_list(linked_list_t *list, FREE_CALLBACK)
{
    struct linked_list_node *node;

    while (!TAILQ_EMPTY(&list->head)) {
        node = TAILQ_FIRST(&list->head);
        TAILQ_REMOVE(&list->head, node, nodes);
        free_func(node->data);
    }
    free(list);
}
