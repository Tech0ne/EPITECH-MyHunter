/*
** EPITECH PROJECT, 2022
** my put str
** File description:
** like my_putchar but for a ... str :eyes:
*/

#include "includes.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
}

void my_put_error(char *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar_error(str[i]);
    }
}
