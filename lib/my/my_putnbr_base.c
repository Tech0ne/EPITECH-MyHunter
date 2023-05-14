/*
** EPITECH PROJECT, 2022
** my putnbr base
** File description:
** echo a nbr in a given base
*/

#include "includes.h"

int my_putnbr_base(int nbr, char const *base)
{
    int total = 0, basenum = my_strlen(base), rest = nbr, power = 1;
    if (nbr < -2147483647 || nbr > 2147483647)
        return 0;
    if (basenum == 0)
        return 0;
    if (nbr < 0) {
        my_putchar('-');
        total++;
        rest = -nbr;
    }
    while ((rest / power) > basenum)
        power *= basenum;
    while (power > 0) {
        my_putchar(base[rest / power]);
        total++;
        rest %= power;
        power /= basenum;
    }
    return total;
}
