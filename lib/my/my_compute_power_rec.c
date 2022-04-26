/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec.c
** File description:
** returns the factorial of the number given as a parameter rec
*/

int my_calc_compute_power_rec(int nb, int p)
{
    int res = 0;

    if (p == 0)
        return (1);
    res = nb * my_calc_compute_power_rec(nb, p - 1);
    return (res);
}

int my_compute_power_rec(int nb, int p)
{
    int res = 0;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    res = my_calc_compute_power_rec(nb, p);
    return (res);
}
