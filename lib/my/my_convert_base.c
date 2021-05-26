/*
** EPITECH PROJECT, 2020
** my_convert_base.c
** File description:
** my_convert_base.c
*/

#include <unistd.h>
#include "my.h"

void convert_base_x(int nb)
{
    char hexa[16] = "0123456789abcdef";

    if (nb >= 16) {
        convert_base_x(nb / 16);
    }
    my_putchar(hexa[nb % 16]);
}

void convert_base_x2(int nb)
{
    char hexa[16] = "0123456789ABCDEF";

    if (nb >= 16) {
        convert_base_x(nb / 16);
    }
    my_putchar(hexa[nb % 16]);
}

void convert_base_o(int nb)
{
    char octal[8] = "01234567";

    if (nb >= 8) {
        convert_base_x(nb / 8);
    }
    my_putchar(octal[nb % 8]);
}

void convert_base_u(int nb)
{
    char decimal[10] = "0123456789";

    if (nb >= 10) {
        convert_base_x(nb / 10);
    }
    my_putchar(decimal[nb % 10]);
}