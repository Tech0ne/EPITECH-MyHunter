/*
** EPITECH PROJECT, 2022
** my str is upper
** File description:
** check if a string only contains UPPER case chars
*/

#include "includes.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 65 || str[i] > 90)
            return 0;
    }
    return 1;
}
