/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** const *str
*/

#include "includes.h"

static int is_in(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int my_getnbr_base(char const *str, char const *base)
{
    int sign = 1;
    int i;
    int nb = 0;



    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        if (nb == 2147483640 && str[i] > '7')
            return 0;
        nb += str[i] - 48;
        if (str[i + 1] < '0' || str[i + 1] > '9')
            return (nb * sign);
        if (nb > 214748364)
            return 0;
        nb *= 10;
    }
}
