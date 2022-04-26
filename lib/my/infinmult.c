/*
** EPITECH PROJECT, 2021
** infinmult.c
** File description:
** fct infinmult2 2 strings
*/

#include "../../include/my.h"
#include <stdlib.h>

char *fill_res_0(char *res, int len)
{
    res = malloc(sizeof(char) * len);
    if (res == NULL)
        return (NULL);
    res[0] = '0';
    res[1] = '\0';
    return (res);
}

char *fbuff(char *res_buff, int len)
{
    res_buff = malloc(sizeof(char) * len);
    if (res_buff == NULL)
        return (NULL);
    return (res_buff);
}

char *calc_infin_mult(char *res, char *nb1, char nb2)
{
    int i = 0;
    int ret = 0;

    for (; nb1[i] != '\0'; i++) {
        if ((nb1[i] - '0') * (nb2  - '0') + ret < 10) {
            res[i] = (nb1[i] - '0') * (nb2  - '0') + ret + '0';
            ret = 0;
        }
        if ((nb1[i] - '0') * (nb2  - '0') + ret >= 10) {
            res[i] = ((nb1[i] - '0') * (nb2  - '0') + ret) % 10 + '0';
            ret = ((nb1[i] - '0') * (nb2  - '0') + ret) / 10;
        }
    }
    if (ret != 0) {
        res[i] = ret + '0';
        res[i + 1] = '\0';
    } else
        res[i] = '\0';
    my_revstr(res);
    return (res);
}

char *infin_mult_2pos(char *str1, char *str2, char *res)
{
    char *nb1 = my_strdup(find_bigger_str_min(str1, str2));
    char *nb2 = my_strdup(find_smallest_strm(str1, str2));
    int m10 = 0;
    char *res_buff;
    char *res_add;

    res = fill_res_0(res, my_strlen(nb1) + my_strlen(nb2) + 2);
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    for (int j = 0; j != my_strlen(nb2); j++) {
        res_buff = fbuff(res_buff, my_strlen(nb1) + my_strlen(nb2) + 2);
        res_buff = calc_infin_mult(res_buff, nb1, nb2[j]);
        res_buff = mult_str_by_10(res_buff, m10);
        res_add = my_infin_add(res, res_buff, res_add);
        res = my_strdup(res_add);
        free_2str(res_buff, res_add);
        m10++;
    }
    free_2str(nb1, nb2);
    return (res);
}

char *my_infin_mult(char *nb1, char *nb2, char *res)
{
    if (nb1[0] != '-' && nb2[0] != '-')
        res = infin_mult_2pos(nb1, nb2, res);
    if (nb1[0] == '-' && nb2[0] == '-') {
        nb1 = delete_min_str(nb1);
        nb2 = delete_min_str(nb2);
        res = infin_mult_2pos(nb1, nb2, res);
    }
    if (nb1[0] == '-' && nb2[0] != '-') {
        nb1 = delete_min_str(nb1);
        res = infin_mult_2pos(nb1, nb2, res);
        res = add_minus_str(res);
    }
    if (nb1[0] != '-' && nb2[0] == '-') {
        nb2 = delete_min_str(nb2);
        res = infin_mult_2pos(nb1, nb2, res);
        res = add_minus_str(res);
    }
    clear_first0_let_one(res);
    return (res);
}
