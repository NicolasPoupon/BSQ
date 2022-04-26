/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** returns the factorial of the number given as a parameter rec
*/

int my_is_prime(int nb)
{
    int i = 2;
    int j = 0;

    if (nb == 1)
        return (0);
    if (nb <= 0)
        return (0);

    while (i != nb) {
        if (nb % i == 0)
            j++;
        i++;
    }
    if (j == 0)
        return (1);
    return (0);
}
