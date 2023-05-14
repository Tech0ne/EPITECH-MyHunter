/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** const *str
*/

#include "includes.h"

int my_getnbr(char const *str)
{
    int sign = 1;
    int i;
    int nb = 0;
    for (i = 0; (str[i] < '0' || str[i] > '9') && str[i] != '\0'; i++)
        if (str[i] == '-')
            sign *= -1;

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
