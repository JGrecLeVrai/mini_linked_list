/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** init_list
*/

#include "list.h"

linked_list_t *ll_init_linked_list(void)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    if (!list)
        return NULL;
    TAILQ_INIT(&list->head);
    return list;
}
