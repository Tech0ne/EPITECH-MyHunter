/*
** EPITECH PROJECT, 2022
** my strncpy
** File description:
** copy src to dest OR only n chars
*/

#include "includes.h"

char *my_strncpy(char *dest , char const *src , int n)
{
    int i = 0;
    while (src[i]) {
        if (i == n)
            return dest;
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}
