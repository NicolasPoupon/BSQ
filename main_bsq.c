/*
** EPITECH PROJECT, 2021
** main_BSQ.c
** File description:
** main for BSQ
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/my.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    if (error_handling_bsq(av[1]) == 84) {
        write(2, "map is not correct\n", 19);
        return (84);
    }
    if (bsq(av[1]) == 84)
        return (84);
    return (0);
}
