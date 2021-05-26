/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_put_nbr(int nb);

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int comptmoin = 0;

    while ((str[i] == '+' || str[i] == '-') && str[i] != '\0') {
        if (str[i] == '-')
            comptmoin = comptmoin + 1;
        i = i + 1;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        nb = (nb * 10) + str[i] - 48;
        if (str[i + 1] < '0' || str[i + 1] > '9')
            break;
        i = i + 1;
    }
    if ((comptmoin % 2) == 1)
        return (nb * (-1));
    return (nb);
}
