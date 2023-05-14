/*
** EPITECH PROJECT, 2022
** my putchar
** File description:
** it definitly put a ... char
*/

#include <unistd.h>
#include "includes.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
