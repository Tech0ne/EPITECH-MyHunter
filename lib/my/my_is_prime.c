/*
** EPITECH PROJECT, 2022
** my is prime
** File description:
** check out if an int is prime
*/

#include "includes.h"

int my_is_prime(int nb)
{
    if (nb <= 2)
        return 1;
    if (nb == 4)
        return 0;

    for (int i = 3; i < nb; i++) {
        if (nb % i == 0)
            return 0;
    }

    return 1;
}
