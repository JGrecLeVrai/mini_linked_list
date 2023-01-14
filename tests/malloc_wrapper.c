/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** A wrapper for a toggleable failing malloc
*/
#include "malloc_wrapper.h"
#include <errno.h>
#include <stdlib.h>

static int *switch_malloc(void)
{
    static int n = 1;

    return &n;
}

void *real_malloc(size_t size);

__attribute__((unused)) void *wrap_malloc(size_t size)
{
    if ((*switch_malloc()) == 0) {
        errno = ENOMEM;
        return NULL;
    }
    (void) *switch_malloc();
    return real_malloc(size);
}

extern void __attribute__((unused)) fix_malloc(void)
{
    *switch_malloc() = -1;
    errno = 0;
}

extern void __attribute__((unused)) break_malloc(void)
{
    *switch_malloc() = 0;
}
