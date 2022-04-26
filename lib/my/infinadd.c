/*
** EPITECH PROJECT, 2021
** infinadd.c
** File description:
** infinadd 2 strings
*/

#include "../../include/my.h"
#include <stdlib.h>

char *calc_infin_add(char *res, char *nb1, char *nb2)
{
    int i = 0;
    int ret = 0;

    for (; nb1[i] != '\0'; i++) {
        if (nb1[i] - '0' + nb2[i]  - '0' + ret < 10) {
            res[i] = nb1[i] - '0' + nb2[i]  - '0' + ret + '0';
            ret = 0;
        }
        if (nb1[i] - '0' + nb2[i]  - '0' + ret >= 10) {
            res[i] = nb1[i] - '0' + nb2[i]  - '0' + ret - 10 + '0';
            ret = 1;
        }
    }
    if (ret == 1) {
        res[i] = '1';
        res[i + 1] = '\0';
    } else
        res[i] = '\0';
    return (res);
}

char *infin_add(char *str1, char *str2, char *res)
{
    int i = 0;
    char *nb1 = find_bigger_str(str1, str2);
    char *nb2 = malloc(sizeof(char) * my_strlen(nb1));

    if (nb2 == NULL)
        return (NULL);
    res = malloc(sizeof(char) * (my_strlen(nb1) + 2));
    if (res == NULL)
        return (NULL);
    fill_str_of0(nb2, find_smallest_str(str1, str2), my_strlen(nb1));
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    res = calc_infin_add(res, nb1, nb2);
    res = my_revstr(res);
    free(nb2);
    return (res);
}

char *infin_add_min(char *str1, char *str2, char *res)
{
    int i = 0;
    char *nb1 = find_bigger_str(str1, str2);
    char *nb2 = malloc(sizeof(char) * my_strlen(nb1));

    res = malloc(sizeof(char) * (my_strlen(nb1) + 2));
    fill_str_of0(nb2, find_smallest_str(str1, str2), my_strlen(nb1));
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    res = calc_infin_add(res, nb1, nb2);
    res = my_revstr(res);
    res = add_minus_str(res);
    free(nb2);
    return (res);
}

char *my_infin_add(char *nb1, char *nb2, char *res)
{
    if (nb1[0] != '-' && nb2[0] != '-')
        res = infin_add(nb1, nb2, res);
    if (nb1[0] == '-' && nb2[0] == '-') {
        my_revstr(nb1);
        nb1[my_strlen(nb1) - 1] = '\0';
        my_revstr(nb2);
        nb2[my_strlen(nb2) - 1] = '\0';
        my_revstr(nb1);
        my_revstr(nb2);
        res = infin_add_min(nb1, nb2, res);
    }
    if ((nb1[0] == '-' && nb2[0] != '-')
        || (nb1[0] != '-' && nb2[0] == '-'))
        res = infin_sub(nb1, nb2, res);
    return (res);
}
