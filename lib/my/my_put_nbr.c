/*
** EPITECH PROJECT, 2022
** My Put number
** File description:
** Write out the number passed as arg
*/

#include "includes.h"

int my_put_nbr(int n)
{
    int total = 0;
    if (n < -2147483647 || n > 2147483647)
        return 0;
    int rest = n;
    int power = 1;

    if (n < 0) {
        my_putchar('-');
        total++;
        rest *= -1;
    }
    while ((rest / power) >= 10)
        power *= 10;
    while (power > 0) {
            my_putchar(48 + (rest / power));
            total++;
            rest %= power;
            power /= 10;
    }
    return total;
}
