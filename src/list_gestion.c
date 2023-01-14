/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** add_list
*/

#include "list.h"

bool ll_add_node_end(linked_list_t *list, void *data)
{
    struct linked_list_node *new = malloc(sizeof(struct linked_list_node));

    if (!new)
        return false;
    new->data = data;
    TAILQ_INSERT_TAIL(&list->head, new, nodes);
    return true;
}

bool ll_add_node_head(linked_list_t *list, void *data)
{
    struct linked_list_node *new = malloc(sizeof(struct linked_list_node));

    if (!new)
        return false;
    new->data = data;
    TAILQ_INSERT_HEAD(&list->head, new, nodes);
    return true;
}

void ll_remove_node(linked_list_t *list, struct linked_list_node *node)
{
    TAILQ_REMOVE(&list->head, node, nodes);
    free(node);
}

void *ll_pop_node(linked_list_t *list)
{
    struct linked_list_node *node = TAILQ_LAST(&list->head, list_head);
    void *data = node->data;

    TAILQ_REMOVE(&list->head, node, nodes);
    free(node);
    return data;
}
