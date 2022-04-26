/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** compare 2 strings
*/

int my_strlen_strcmp(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int str_same_or_not(char const *s1, char const *s2)
{
    int size_1 = my_strlen_strcmp(s1);
    int size_s2 = my_strlen_strcmp(s2);
    int i = 0;

    if (size_1 != size_s2)
        return (1);
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    if (i == size_s2)
        return (0);
    return (1);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = str_same_or_not(s1, s2);

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
