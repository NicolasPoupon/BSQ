/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec.c
** File description:
** returns the factorial of the number given as a parameter rec
*/

int my_calc_compute_factorial_rec(int nb)
{
    if (nb > 1)
        nb = nb * my_calc_compute_factorial_rec(nb - 1);
    return (nb);
}

int my_compute_factorial_rec(int nb)
{
    int res = 0;

    if (nb < 0 || nb >= 13)
        return (0);
    if (nb == 0)
        return (1);
    res = my_calc_compute_factorial_rec(nb);
    return (res);
}
