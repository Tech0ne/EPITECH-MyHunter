/*
** EPITECH PROJECT, 2022
** my strstr
** File description:
** Find sub string in string
*/

#include "includes.h"

static int is_found(char *str, const char *to_find, int i, int j)
{
    if (to_find[j] != str[i + j])
        return 1;
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int found;
    int i = 0;
    int j = 0;

    int length = my_strlen(str) - my_strlen(to_find);

    for (int i = 0; i < length; i++) {
        found = 0;
        for (int j = 0; to_find[j] != '\0'; j++) {
            found += is_found(str, to_find, i, j);
        }
        if (found == 0)
            return &str[i];
    }
    return 0;
}
