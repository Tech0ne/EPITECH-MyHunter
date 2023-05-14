/*
** EPITECH PROJECT, 2022
** my lib
** File description:
** contains all protos for the lib my
*/

#ifndef INCLUDE_MY_H
    #define INCLUDE_MY_H

int my_compute_power_rec(int nb, int power);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int n);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest , char const *src , int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *my_strdup(char const *src);

int my_putnbr_base(int nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);

#endif
