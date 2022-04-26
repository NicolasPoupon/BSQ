/*
** EPITECH PROJECT, 2021
** it_is_smthg.c
** File description:
** return 0 if sign, prio sign, alpha, alphanum
*/

int it_is_prio_sign(char c)
{
    if (c == '*' || c == '/' || c == '%')
        return (0);
    return (1);
}

int it_is_a_sign(char c)
{
    if (c == '*' || c == '/' || c == '%' || c == '+' || c == '-')
        return (0);
    return (1);
}

int it_is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return (0);
    return (1);
}

int it_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (0);
    return (1);
}

int it_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}
