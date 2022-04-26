/*
** EPITECH PROJECT, 2021
** find str.c
** File description:
** find biggest / smallest str, fill_str of 0
*/

#include "../../include/my.h"

char *find_smallest_str(char *str1, char *str2)
{
    if (my_strlen(str1) >= my_strlen(str2))
        return (str2);
    return (str1);
}

char *find_bigger_str(char *str1, char *str2)
{
    if (my_strlen(str1) >= my_strlen(str2))
        return (str1);
    return (str2);
}

char *fill_str_of0(char *dest, char *src, int size)
{
    int i = 0;
    int len_src = my_strlen(src);
    int j = len_src;

    for (; i < size - len_src; i++)
        dest[i] = '0';
    dest[i] = '\0';
    my_strcat(dest, src);
    return (dest);
}

void clear_first0(char *str)
{
    int i = 0;
    int len = my_strlen(str);

    while (str[i] == '0')
        i++;
    my_revstr(str);
    str[len - i] = '\0';
    my_revstr(str);
}

int compare_str(char *str1, char *str2)
{
    int i = 0;
    int j = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return (1);
    while (str1[i] != '\0') {
        if (str1[i] == str2[i])
            j++;
        i++;
    }
    if (j == i)
        return (0);
    return (1);
}
