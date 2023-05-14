/*
** EPITECH PROJECT, 2022
** my str uppercase
** File description:
** Put every letter in upper case (that sounds easy, right ?)
*/

#include "includes.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = (str[i] - 32);
        }
    }
    return str;
}
