/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** returns the smallest prime number that is greater than nb
*/

int my_is_prime_sup(int nb)
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

int my_find_prime_sup(int nb)
{
    if (nb < 0)
        return (2);
    if (nb > 2147483629)
        return (2147483647);
    while (nb <= 2147483647) {
        if (my_is_prime_sup(nb) == 1)
            return (nb);
        nb++;
    }
    return (0);
}
