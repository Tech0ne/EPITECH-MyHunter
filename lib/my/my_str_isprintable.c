/*
** EPITECH PROJECT, 2022
** my str is printable
** File description:
** check if a string can be printed out or not
*/

#include "includes.h"

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] > 126)
            return 0;
    }
    return 1;
}
