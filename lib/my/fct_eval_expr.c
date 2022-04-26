/*
** EPITECH PROJECT, 2021
** fct_eval_expr.c
** File description:
** fct of eval expr
*/

#include "../../include/my.h"

int is_there_parent_in_str(char *str, char sign)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sign)
            return (0);
    }
    return (1);
}

int it_is_prio_sign_bistro(char c, char const *s)
{
    if (c == s[4] || c == s[5] || c == s[6])
        return (0);
    return (1);
}

int it_is_a_sign_bistro(char c, char const *s)
{
    if (c == s[2] || c == s[3] || c == s[4] || c == s[5] || c == s[6])
        return (0);
    return (1);
}

char find_my_sign(char c, char const *s)
{
    if (c == s[2])
        return ('+');
    if (c == s[3])
        return ('-');
    if (c == s[4])
        return ('*');
    if (c == s[5])
        return ('/');
    return ('%');
}
