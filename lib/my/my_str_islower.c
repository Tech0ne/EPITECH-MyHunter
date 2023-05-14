/*
** EPITECH PROJECT, 2022
** my str islower
** File description:
** return 1 if string contains lower alpha numbers
*/

#include "includes.h"

int my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 97 || str[i] > 122)
            return 0;
    }
    return 1;
}
