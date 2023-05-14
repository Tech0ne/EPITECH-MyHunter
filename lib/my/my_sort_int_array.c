/*
** EPITECH PROJECT, 2022
** my sort int array
** File description:
** sort a int array
*/

#include "includes.h"

static void might_swap(int *a, int *b)
{
    if (*a > *b) {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
}

void my_sort_int_array(int *tab, int size)
{
    for (int a = 0; a < size - 1; a++) {
        for (int b = 0; b < size - a - 1; b++) {
            might_swap(&tab[b], &tab[b + 1]);
        }
    }
}
