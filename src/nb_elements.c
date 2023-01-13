/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** nb_elements
*/

#include "list.h"

int ll_get_nb_elements(linked_list_t *list, void *data, CMP_CALLBACK)
{
    struct linked_list_node *node;
    int nb = 0;

    TAILQ_FOREACH(node, &list->head, nodes) {
        if (cmp_func(data, node->data))
            nb++;
    }
    return nb;
}

int ll_remove_all_other_occurences(linked_list_t *list, void *data,
CMP_CALLBACK)
{
    struct linked_list_node *node;
    int nb = 0;
    bool seen = false;

    TAILQ_FOREACH(node, &list->head, nodes) {
        if (cmp_func(data, node->data)) {
            if (seen) {
                TAILQ_REMOVE(&list->head, node, nodes);
                nb++;
            } else
                seen = true;
        }
    }
    return nb;
}
