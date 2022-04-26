/*
** EPITECH PROJECT, 2021
** fill_map_bsq.c
** File description:
** fill the map of bsq
*/

#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *fill_buff_map(char *buff_map, char *pathname, struct stat sb);

int **alloc_mem_array_int(int **array, char *pathname, char *buff_map)
{
    int pos_start_map = find_pos_start_map(buff_map);
    int nb_line = my_getnbr(buff_map);
    int nb_char_per_line = 0;
    int k = 0;

    array = malloc(sizeof(int*) * (nb_line + 1));
    if (array == NULL)
        return NULL;
    for (int i = pos_start_map; buff_map[i] != '\n'; i++)
        nb_char_per_line++;
    for (; nb_line > 0; k++, nb_line--) {
        array[k] = malloc(sizeof(int) * (nb_char_per_line + 1));
        if (array[k] == NULL)
            return NULL;
    }
    array[k] = NULL;
    return (array);
}

int fill_one_line_array_int(char *buff_map, int **map, int j, int i)
{
    int k = 0;

    for (; buff_map[i] != '\n'; i++, k++) {
        if (buff_map[i] == '.')
            map[j][k] = 1;
        if (buff_map[i] == 'o')
            map[j][k] = 0;
    }
    map[j][k] = -1;
    return (i);
}

int **fill_my_map_int(int **map, char *pathname)
{
    struct stat sb;
    char *buff_map = fill_buff_map(buff_map, pathname, sb);
    int i = 0;
    int k = 0;

    if (buff_map == NULL)
        return NULL;
    i = find_pos_start_map(buff_map);
    map = alloc_mem_array_int(map, pathname, buff_map);
    if (map == NULL)
        return NULL;
    for (int j = 0; map[j] != NULL; j++) {
        i = fill_one_line_array_int(buff_map, map, j, i);
        i++;
    }
    free(buff_map);
    return (map);
}

int it_is_char_bsq(char c)
{
    if (c == 'o' || c == '.' || c == '\n')
        return (0);
    return (1);
}
