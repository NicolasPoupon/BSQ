/*
** EPITECH PROJECT, 2021
** replace_square_by_x.c
** File description:
** replace my square by x for bsq
*/

#include "include/my.h"
#include <stddef.h>

char **copy_x(int i, int j, char **res, int size_square)
{
    int buff_j = j;

    for (int l = 0; l < size_square; l++, i--) {
        j = buff_j;
        for (int k = 0; k < size_square; k++, j--)
            res[i][j] = 'x';
    }
    return (res);
}

int replace_square_by_x(int **map, char **res, int i, int size_square)
{
    int stop = 0;

    for (int j = 0; map[i][j] != -1; j++) {
        if (map[i][j] == size_square && stop == 0) {
            res = copy_x(i, j, res, size_square);
            stop = 1;
        }
    }
    return (stop);
}

void replace_x_one_line(int **map)
{
    int x = 0;

    for (int i = 0; map[0][i] != -1; i++) {
        if (x == 1 && map[0][i] == 1)
            my_putchar('.');
        if (x == 0 && map[0][i] == 1) {
            my_putchar('x');
            x = 1;
        }
        if (map[0][i] == 0)
            my_putchar('o');
    }
    my_putchar('\n');
    free_array_int(map);
}

void replace_x_one_col(int **map)
{
    int x = 0;

    for (int i = 0; map[i] != NULL; i++) {
        if (x == 1 && map[i][0] == 1)
            my_putchar('.');
        if (x == 0 && map[i][0] == 1) {
            my_putchar('x');
            x = 1;
        }
        if (map[i][0] == 0)
            my_putchar('o');
        my_putchar('\n');
    }
    free_array_int(map);
}

int specific_case_bsq(int **map)
{
    if (map[0][0] == 1 && map[0][1] == -1 && map[1] == NULL) {
        my_putchar('x');
        my_putchar('\n');
        free_array_int(map);
        return (0);
    }
    if (map[0][0] == 0 && map[0][1] == -1 && map[1] == NULL) {
        my_putchar('o');
        my_putchar('\n');
        free_array_int(map);
        return (0);
    }
    if (map[1] == NULL) {
        replace_x_one_line(map);
        return (0);
    }
    replace_x_one_col(map);
    return (0);
}
