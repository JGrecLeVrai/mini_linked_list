/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** reverse_list
*/

#include "list.h"

void ll_reverse_list(linked_list_t *list)
{
    struct linked_list_node *node = TAILQ_FIRST(&list->head);
    struct linked_list_node *tmp = NULL;

    while (node != NULL) {
        tmp = TAILQ_PREV(node, list_head, nodes);
        TAILQ_REMOVE(&list->head, node, nodes);
        TAILQ_INSERT_TAIL(&list->head, node, nodes);
        node = tmp;
    }
}
