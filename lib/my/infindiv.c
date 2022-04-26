/*
** EPITECH PROJECT, 2021
** infindiv.c
** File description:
** this function will divide, any infinit number.
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
#include <unistd.h>

int count_len_int(int nb)
{
    int i = 0;

    while (nb != 0) {
        nb = nb / 10;
        i++;
    }
    return (i);
}

char *int_to_str(int nb)
{
    int len_nb = count_len_int(nb);
    char *str = malloc(sizeof(char) * (len_nb + 1));
    int i = 0;
    int m10 = 1;

    for (int j = 0; j != len_nb - 1; j++)
        m10 *= 10;
    while (i != len_nb) {
        str[i] = (nb / m10) + '0';
        nb = nb % m10;
        m10 = m10 / 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *my_infin_div(char *num, char *div, char *res)
{
    int nb1 = my_getnbr(num);
    int nb2 = my_getnbr(div);
    int res1 = 0;
    char *zero = "0";

    if (nb1 == 0)
        return my_strdup(zero);
    if (nb2 == 0) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    res1 = nb1 / nb2;
    res = int_to_str(res1);
    return (res);
}

char *my_infin_modulo(char *num, char *div, char *res)
{
    int nb1 = my_getnbr(num);
    int nb2 = my_getnbr(div);
    int res1 = 0;
    char *zero = "0";

    if (nb2 == 0) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    res1 = nb1 % nb2;
    if (res1 == 0)
        return my_strdup(zero);
    res = int_to_str(res1);
    return (res);
}
