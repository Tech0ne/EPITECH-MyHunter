/*
** EPITECH PROJECT, 2022
** my str capitalize
** File description:
** Put every first letter in upper case (that sounds easy, right ?)
*/

#include "includes.h"

static void my_charup(char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

static void my_charlow(char *c)
{
    if (*c >= 'A' && *c <= 'Z')
        *c += 32;
}

char *my_strcapitalize(char *str)
{
    char last = '\0';

    for (int i = 0; str[i]; i++) {
        my_charup(&str[i]);

        if (last >= '0' && last <= '9')
            my_charlow(&str[i]);

        if (last >= 'A' && last <= 'Z')
            my_charlow(&str[i]);

        if (last >= 'a' && last <= 'z')
            my_charlow(&str[i]);

        last = str[i];
    }
    return str;
}
