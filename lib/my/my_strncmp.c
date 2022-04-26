/*
** EPITECH PROJECT, 2021
** my_strncmp.c
** File description:
** compare 2 strings at n char
*/

int my_strlen_strncmp(char const *str, int n)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    if (i > n)
        return (n);
    return (i);
}

int str_same_or_not_n(char const *s1, char const *s2, int n)
{
    int size_1 = my_strlen_strncmp(s1, n);
    int size_s2 = my_strlen_strncmp(s2, n);
    int i = 0;

    if (size_1 != size_s2)
        return (1);
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    if (i == size_s2)
        return (0);
    return (1);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = str_same_or_not_n(s1, s2, n);

    if (j == 0)
        return (0);
    while (s1[i] == s2[i])
        i++;
    if (s1[i] == '\0')
        return (-s2[i]);
    if (s2[i] == '\0')
        return (s1[i]);
    return (s1[i] - s2[i]);
}
