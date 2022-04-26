/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** returns the factorial of the number given as a parameter rec
*/

int my_compute_square_root(int nb)
{
    int square = 1;

    if (square <= 0)
        return (0);
    while (square * square < nb)
        square++;
    if (square * square == nb)
        return (square);
    return (0);
}
