/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** print_list
*/

#include "list.h"

void ll_print_list(linked_list_t *list, PRINT_CALLBACK)
{
    struct linked_list_node *node;

    TAILQ_FOREACH(node, &list->head, nodes) {
        print_func(node->data);
    }
}
