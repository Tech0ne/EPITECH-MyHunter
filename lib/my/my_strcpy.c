/*
** EPITECH PROJECT, 2022
** my strcpy
** File description:
** copy a string in anotherone
*/

#include "includes.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
