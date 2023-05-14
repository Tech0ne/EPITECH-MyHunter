/*
** EPITECH PROJECT, 2022
** my revstr
** File description:
** reverse the given string
*/

#include "includes.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char buffer[len];

    for (int i = 0; i < len; i++) {
        buffer[i] = str[len - i - 1];
    }

    for (int i = 0; i < len; i++) {
        str[i] = buffer[i];
    }

    return str;
}
