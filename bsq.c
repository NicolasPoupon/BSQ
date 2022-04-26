/*
** EPITECH PROJECT, 2021
** bsq.c
** File description:
** find the biggest square in doctxt
*/

#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int mynb(int nb1, int nb2, int nb3)
{
    if (nb1 == nb2 && nb1 == nb3)
        return (nb1 + 1);
    if (nb1 <= nb2 && nb1 <= nb3)
        return (nb1 + 1);
    if (nb2 <= nb1 && nb2 <= nb3)
        return (nb2 + 1);
    return (nb3 + 1);
}

int change_nb_map(int **map, int i)
{
    int size_square = 0;

    for (int j = 1; map[i][j] != -1; j++) {
        if (map[i][j] != 0)
            map[i][j] = mynb(map[i][j - 1], map[i - 1][j], map[i - 1][j - 1]);
        if (size_square < map[i][j])
            size_square = map[i][j];
    }
    return (size_square);;
}

int find_my_square(int **map)
{
    int i = 1;
    int size_square = 0;
    int buff_size = 0;

    for (; map[i] != NULL; i++) {
        buff_size = change_nb_map(map, i);
        if (size_square < buff_size)
            size_square = buff_size;
    }
    return (size_square);
}

int print_res_bsq(int **map, char **res, int size_square)
{
    int stop = 0;
    int i = 0;
    int size_one_line = 0;

    for (; stop != 1; i++)
        stop = replace_square_by_x(map, res, i, size_square);
    while (res[0][size_one_line] != '\0')
        size_one_line++;
    print_array_char_fast(res, size_one_line);
    map = free_array_int(map);
    res = free_array_char(res);
    return (0);
}

int bsq(char *pathname)
{
    int k = 0;
    int **map = fill_my_map_int(map, pathname);
    char **res;
    int size_square = 0;

    if (map == NULL)
        return (84);
    if (map[0][1] == -1 || map[1] == NULL) {
        specific_case_bsq(map);
        return (0);
    }
    size_square = find_my_square(map);
    res = fill_my_map(res, pathname, k);
    if (res == NULL)
        return (84);
    print_res_bsq(map, res, size_square);
    return (0);
}
