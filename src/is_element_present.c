/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** is_element_present
*/

#include "list.h"

bool ll_is_element_present(linked_list_t *list, void *element, CMP_CALLBACK)
{
    struct linked_list_node *node;

    TAILQ_FOREACH(node, &list->head, nodes) {
        if (cmp_func(node->data, element))
            return true;
    }
    return false;
}

bool ll_is_element_present_remove(linked_list_t *list, void *element,
CMP_CALLBACK)
{
    struct linked_list_node *node;

    TAILQ_FOREACH(node, &list->head, nodes) {
        if (cmp_func(node->data, element)) {
            TAILQ_REMOVE(&list->head, node, nodes);
            return true;
        }
    }
    return false;
}
