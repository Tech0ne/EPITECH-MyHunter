/*
** EPITECH PROJECT, 2022
** my str comp
** File description:
** compare the 2 strings passed as argument. Clamp at n
*/

#include "includes.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;
    for (i = 0; (s1[i] || s2[i]) && i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }

    return 0;
}
