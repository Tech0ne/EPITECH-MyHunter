/*
** EPITECH PROJECT, 2022
** My swap
** File description:
** Swap two variables using pointers
*/

#include "includes.h"

void my_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
