/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it.c
** File description:
** returns the factorial of the number given as a parameter
*/

int my_compute_factorial_it(int nb)
{
    int i = 0;
    int j = nb;
    int stock_res = nb;
    int res = 0;

    if (nb < 0 || nb >= 13)
        return (0);
    if (nb == 0)
        return (1);
    if (nb == 1)
        return (1);
    nb--;
    while (i != j - 1) {
        res = stock_res * (nb);
        stock_res = res;
        nb--;
        i++;
    }
    return (res);
}
