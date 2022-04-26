/*
** EPITECH PROJECT, 2021
** error_handling_bsq.c
** File description:
** error handling for bsq
*/

#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *fill_buff_map(char *buff_map, char *pathname, struct stat sb);

int it_is_char_bsq(char c);

int count_len_one_line(char *map, int i)
{
    int j = 0;

    for (; map[i] != '\n' && map[i] != '0'; i++)
        j++;
    return (j);
}

int check_l_same_size(char *map, int i, int len_one_line)
{
    int j = 0;

    for (; map[i] != '\n'; i++, j++) {
        if (it_is_char_bsq(map[i]) == 1) {
            write(2, "error char bsq\n", 15);
            return (1);
        }
    }
    if (j != len_one_line) {
        write(2, "error char len line\n", 20);
        return (1);
    }
    return (0);
}

int count_line(char *map, int i, int nb_line)
{
    int len_one_line = count_len_one_line(map, i);
    int count_bn = 0;
    int buff_start = i;

    for (; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            count_bn++;
    }
    if (count_bn != nb_line) {
        write(2, "error nb line\n", 14);
        return (1);
    }
    for (; map[buff_start] != '\0'; buff_start += len_one_line + 1) {
        if (check_l_same_size(map, buff_start, len_one_line) == 1)
            return (1);
    }
    return (0);
}

int it_is_good_chara(char *map)
{
    int i = 0;
    int nb_line = 0;

    for (; map[i] != '\n' && map[i] != '\0'; i++) {
        if (it_is_num(map[i]) == 1 && map[i] != '\n')
            return (1);
    }
    if (map[i] != '\n')
        return (1);
    nb_line = my_getnbr(map);
    if (count_line(map, i + 1, nb_line) == 1)
        return (1);
    return (0);
}

int error_handling_bsq(char *pathname)
{
    struct stat sb;
    char *map = fill_buff_map(map, pathname, sb);

    if (map == NULL)
        return (84);
    if (it_is_num(map[0]) == 1) {
        free(map);
        return (84);
    }
    if (it_is_good_chara(map) == 1) {
        free(map);
        return (84);
    }
    free(map);
    return (0);
}
