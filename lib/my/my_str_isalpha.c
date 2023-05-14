/*
** EPITECH PROJECT, 2022
** my str is alpha
** File description:
** check if a string is only letters
*/

#include "includes.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
            return 0;
        }
    }
    return 1;
}
