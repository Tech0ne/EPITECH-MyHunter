/*
** EPITECH PROJECT, 2022
** my str comp
** File description:
** compare the 2 strings passed as argument
*/

#include "includes.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] || s2[i]) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }

    return 0;
}
