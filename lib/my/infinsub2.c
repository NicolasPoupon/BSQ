/*
** EPITECH PROJECT, 2021
** infinsub2.c
** File description:
** infin sub2 for infinadd
*/

#include "../../include/my.h"
#include <stdlib.h>

char *infin_sub_2pos_next(char *nb1, char *nb2, char *res)
{
    my_revstr(nb2);
    my_revstr(nb1);
    res = calc_infin_sub(res, nb1, nb2);
    res = my_revstr(res);
    clear_first0(res);
    free(nb2);
    return (res);
}

char *infin_sub_2pos(char *str1, char *str2, char *res)
{
    int i = 0;
    char *nb1 = find_bigger_str_min(str1, str2);
    char *nb2 = malloc(sizeof(char) * my_strlen(nb1));
    char *save1 = my_strdup(str1);
    char *save2 = my_strdup(str2);

    if (my_strlen(str1) == my_strlen(str2)
        && compare_str(str1, str2) == 0) {
        return "0";
    }
    res = malloc(sizeof(char) * (my_strlen(nb1) + 2));
    fill_str_of0(nb2, find_smallest_strm(str1, str2), my_strlen(nb1));
    res = infin_sub_2pos_next(nb1, nb2, res);
    if (find_bigger_str_min(save1, save2) == save2)
        res = add_minus_str(res);
    free(save1);
    free(save2);
    return (res);
}

char *infin_sub_2min_next(char *nb1, char *nb2, char *res)
{
    my_revstr(nb2);
    my_revstr(nb1);
    res = calc_infin_sub(res, nb1, nb2);
    my_revstr(res);
    clear_first0(res);
    free(nb2);
    return (res);
}

char *infin_sub_2min(char *str1, char *str2, char *res)
{
    int i = 0;
    char *nb1 = find_bigger_str_min(str1, str2);
    char *nb2 = malloc(sizeof(char) * my_strlen(nb1));
    char *save1 = my_strdup(str1);
    char *save2 = my_strdup(str2);

    if (my_strlen(str1) == my_strlen(str2)
        && compare_str(str1, str2) == 0) {
        return "0";
    }
    res = malloc(sizeof(char) * (my_strlen(nb1) + 2));
    fill_str_of0(nb2, find_smallest_strm(str1, str2), my_strlen(nb1));
    res = infin_sub_2min_next(nb1, nb2, res);
    if (find_bigger_str_min(save1, save2) == save1)
        res = add_minus_str(res);
    free(save1);
    free(save2);
    return (res);
}

char *my_true_infin_sub(char *nb1, char *nb2, char *res)
{
    if (nb1[0] != '-' && nb2[0] != '-') {
        res = infin_sub_2pos(nb1, nb2, res);
    }
    if (nb1[0] == '-' && nb2[0] == '-') {
        nb1 = delete_min_str(nb1);
        nb2 = delete_min_str(nb2);
        res = infin_sub_2min(nb1, nb2, res);
    }
    if (nb1[0] == '-' && nb2[0] != '-') {
        nb1 = delete_min_str(nb1);
        res = my_infin_add(nb1, nb2, res);
        res = add_minus_str(res);
    }
    if (nb1[0] != '-' && nb2[0] == '-') {
        nb2 = delete_min_str(nb2);
        res = my_infin_add(nb1, nb2, res);
    }
    return (res);
}
