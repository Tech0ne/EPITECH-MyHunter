/*
** EPITECH PROJECT, 2022
** my str cat
** File description:
** concatenate 2 strings together
*/

#include "includes.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_length + i] = src[i];
    }

    dest[dest_length + i] = '\0';

    return dest;
}
