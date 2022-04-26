/*
** EPITECH PROJECT, 2021
** my_evil_str.c
** File description:
** reverse a string
*/

void my_putchar(char c);

int my_strlen_evil(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return (i - 1);
}

char *my_evil_str(char *str)
{
    int i = my_strlen_evil(str);
    int j = 0;
    char stock;

    while (j < i) {
        stock = str[j];
        str[j] = str[i];
        str[i] = stock;
        j++;
        i--;
    }
    return (str);
}
