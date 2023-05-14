/*
** EPITECH PROJECT, 2022
** my_showstr
** File description:
** const *str
*/

#include "includes.h"

int my_showstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < ' ' || str[i] > '~') {
            my_putchar('\\');
            my_putnbr_base((int)str[i], "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
    }
    return 0;
}
