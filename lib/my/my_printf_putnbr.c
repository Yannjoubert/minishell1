/*
** EPITECH PROJECT, 2020
** my_printf_putnbr.c
** File description:
** my_printf_putnbr.c
*/

#include <stdarg.h>
#include "my.h"

void my_printf_putnbr(va_list *ap)
{
    int i = va_arg(*ap, int);
    my_put_nbr3(i);
}