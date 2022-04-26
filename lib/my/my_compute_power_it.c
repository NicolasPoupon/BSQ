/*
** EPITECH PROJECT, 2021
** my_compute_power_it.c
** File description:
** returns the factorial of the number given as a parameter rec
*/

int my_compute_power_it(int nb, int p)
{
    int res = nb;
    int i = p;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    while (i != 1) {
        res = res * nb;
        i--;
    }
    return (res);
}
