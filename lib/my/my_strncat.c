/*
** EPITECH PROJECT, 2022
** my str cat
** File description:
** concatenate 2 strings together
*/

#include "includes.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int dest_length = my_strlen(dest);
    int i;
    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[dest_length + i] = src[i];
    }

    if (src[i] != '\0')
        dest[dest_length + i] = '\0';

    return dest;
}
