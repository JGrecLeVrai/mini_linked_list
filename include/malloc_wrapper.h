/*
** EPITECH PROJECT, 2022
** tailq
** File description:
** Header for malloc wrapper
*/
#ifndef WRAP_MALLOC_H_
    #define WRAP_MALLOC_H_

    #define real_malloc __real_malloc
    #define wrap_malloc __wrap_malloc

extern void fix_malloc(void);
extern void break_malloc(void);
#endif
