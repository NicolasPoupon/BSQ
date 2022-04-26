/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** test BSQ
*/

#include <criterion/criterion.h>
#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *fill_buff_map(char *buff_map, char *pathname, struct stat sb);

Test(fill_buff_map, test_n)
{
    char *buff_map;
    char pathname[] = "test.txt";
    char res[] = "2\nje suis\nun test\n";
    struct stat sb;

    cr_assert_str_eq(fill_buff_map(buff_map, pathname, sb), res);
}
