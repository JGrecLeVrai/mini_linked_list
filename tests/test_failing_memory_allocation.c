/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** Testing failing malloc
*/

#include <criterion/criterion.h>

#include "list.h"
#include "malloc_wrapper.h"

Test(linked_list, failing_malloc_init_list)
{
    break_malloc();
    cr_assert_null(ll_init_linked_list());
    fix_malloc();
}

Test(linked_list, failing_malloc_add_node_end)
{
    linked_list_t *list = ll_init_linked_list();
    int data = 42;

    break_malloc();
    cr_assert_eq(ll_add_node_end(list, &data), false);
    free(list);
    fix_malloc();
}

Test(linked_list, failing_malloc_add_node_head)
{
    linked_list_t *list = ll_init_linked_list();
    int data = 42;

    break_malloc();
    cr_assert_eq(ll_add_node_head(list, &data), false);
    free(list);
    fix_malloc();
}
