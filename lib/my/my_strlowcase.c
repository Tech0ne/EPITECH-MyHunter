/*
** EPITECH PROJECT, 2022
** my str lowercase
** File description:
** Put every letter in lower case (that sounds easy, right ?)
*/

#include "includes.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = (str[i] + 32);
        }
    }
    return str;
}
