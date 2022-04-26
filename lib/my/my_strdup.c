/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** allocates memory to a string and copies
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}

char *my_strndup(char const *src, int start, int end)
{
    char *dest;
    int len = end - start;
    int i = 0;

    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return (NULL);
    while (start != end) {
        dest[i] = src[start];
        i++;
        start++;
    }
    dest[i] = '\0';
    return (dest);
}
