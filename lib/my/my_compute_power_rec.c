/*
** EPITECH PROJECT, 2022
** my compute power rec
** File description:
** Return nb power p using recursiv
*/

#include "includes.h"

int my_compute_power_rec(int nb, int power)
{
    if (power < 0)
        return 0;
    if (power == 0)
        return 1;

    return nb * my_compute_power_rec(nb, power - 1);
}
