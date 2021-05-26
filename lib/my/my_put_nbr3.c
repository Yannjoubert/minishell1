/*
** EPITECH PROJECT, 2020
** my_put_nbr3.c
** File description:
** my_put_nbr3.c
*/

#include <unistd.h>
#include "my.h"

void my_put_nbr3(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb == 0)
        my_putchar('0');
    if (nb >= 10) {
        my_put_nbr3(nb / 10);
        my_putchar(nb % 10 +'0');
    } else {
        my_putchar(nb + '0');
    }
}