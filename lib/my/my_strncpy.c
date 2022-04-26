/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** copy n char of a string in other string
*/

int my_strlen_strcpy(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i != n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy_rev(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[n] != '\0') {
        dest[i] = src[n];
        n++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
