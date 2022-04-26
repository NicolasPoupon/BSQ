/*
** EPITECH PROJECT, 2021
** infinsub.c
** File description:
** infin sub for infinadd
*/

#include "../../include/my.h"
#include <stdlib.h>

char *calc_infin_sub(char *res, char *nb1, char *nb2)
{
    int i = 0;
    int ret = 0;
    int nb1_10;

    for (; nb1[i] != '\0'; i++) {
        if ((nb1[i] - '0') >= (nb2[i] - '0' + ret)) {
            res[i] = (nb1[i] - '0') - (nb2[i]  - '0' + ret) + '0';
            ret = 0;
        }
        if ((nb1[i] - '0') < (nb2[i] - '0' + ret)) {
            nb1_10 = (nb1[i] - '0') + 10;
            res[i] = nb1_10 - (nb2[i]  - '0' + ret) + '0';
            ret = 1;
        }
    }
    res[i] = '\0';
    return (res);
}

int find_str_minus_and_delete_min(char *str1, char *str2)
{
    if (str1[0] == '-') {
        my_revstr(str1);
        str1[my_strlen(str1) - 1] = '\0';
        my_revstr(str1);
        return (1);
    }
    if (str2[0] == '-') {
        my_revstr(str2);
        str2[my_strlen(str2) - 1] = '\0';
        my_revstr(str2);
        return (2);
    }
    return (0);
}

char *infin_sub2(char *nb1, char *nb2, char *res)
{
    my_revstr(nb2);
    my_revstr(nb1);
    res = calc_infin_sub(res, nb1, nb2);
    res = my_revstr(res);
    clear_first0(res);
    free(nb2);
    return (res);
}

char *infin_sub(char *str1, char *str2, char *res)
{
    int i = 0;
    int who_min = find_str_minus_and_delete_min(str1, str2);
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
    res = infin_sub2(nb1, nb2, res);
    if (who_min == 1 && find_bigger_str_min(save1, save2) == save1
        || who_min == 2 && find_bigger_str_min(save1, save2) == save2)
        res = add_minus_str(res);
    free(save1);
    free(save2);
    return (res);
}
