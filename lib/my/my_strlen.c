/*
** EPITECH PROJECT, 2022
** My strlen
** File description:
** Print out array length
*/

#include "includes.h"

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i]; i++);
    return i;
}
