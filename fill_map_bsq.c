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

char *fill_buff_map(char *buff_map, char *pathname, struct stat sb)
{
    int fd = open(pathname, O_RDONLY);

    if (fd < 0) {
        write(2, "open error\n", 11);
        return NULL;
    }
    if (stat(pathname, &sb) == -1) {
        write(2, "stat error\n", 11);
        return NULL;
    }
    buff_map = malloc(sizeof(char) * ((sb.st_size) + 1));
    if (buff_map == NULL)
        return NULL;
    if (read(fd, buff_map, sb.st_size) == -1) {
        write(2, "read error\n", 11);
        return NULL;
    }
    buff_map[sb.st_size] = '\0';
    close(fd);
    return (buff_map);
}

int find_pos_start_map(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i + 1);
}

char **alloc_mem_array(char **array, char *pathname, char *buff_map)
{
    int pos_start_map = find_pos_start_map(buff_map);
    int nb_line = my_getnbr(buff_map);
    int nb_char_per_line = 0;
    int k = 0;

    array = malloc(sizeof(char*) * (nb_line + 1));
    if (array == NULL)
        return NULL;
    for (int i = pos_start_map; buff_map[i] != '\n'; i++)
        nb_char_per_line++;
    for (; nb_line > 0; k++, nb_line--) {
        array[k] = malloc(sizeof(char) * (nb_char_per_line + 2));
        if (array[k] == NULL)
            return NULL;
    }
    array[k] = NULL;
    return (array);
}

char **fill_my_map(char **map, char *pathname, int k)
{
    struct stat sb;
    char *buff_map = fill_buff_map(buff_map, pathname, sb);
    int i = 0;

    if (buff_map == NULL)
        return NULL;
    i = find_pos_start_map(buff_map);
    map = alloc_mem_array(map, pathname, buff_map);
    if (map == NULL)
        return NULL;
    for (int j = 0; map[j] != NULL; j++) {
        for (; buff_map[i] != '\n'; i++, k++)
            map[j][k] = buff_map[i];
        map[j][k] = '\n';
        map[j][k + 1] = '\0';
        k = 0;
        i++;
    }
    free(buff_map);
    return (map);
}
