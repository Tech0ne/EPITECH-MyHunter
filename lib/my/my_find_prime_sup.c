/*
** EPITECH PROJECT, 2022
** my find prime sup
** File description:
** find the smallest prime number greater than the given number
*/

#include "includes.h"

int my_find_prime_sup(int nb)
{
    int i = nb + 1;
    while (1) {
        if (my_is_prime(i))
            return i;
        i++;
    }
}
