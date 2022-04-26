/*
** EPITECH PROJECT, 2021
** infinmult.c
** File description:
** infinmult 2 strings
*/

#include "../../include/my.h"
#include <stdlib.h>

char *mult_str_by_10(char *str, int time_m10)
{
    int i = 0;
    int len = my_strlen(str);

    while (i < time_m10) {
        str[len] = '0';
        str[len + 1] = '\0';
        len++;
        i++;
    }
    return (str);
}

void free_2str(char *str1, char *str2)
{
    free(str1);
    free(str2);
}

void clear_first0_let_one(char *str)
{
    int i = 0;
    int len = my_strlen(str);

    while (str[i] == '0')
        i++;
    if (i > 0)
        i = i - 1;
    my_revstr(str);
    str[len - i] = '\0';
    my_revstr(str);
}
