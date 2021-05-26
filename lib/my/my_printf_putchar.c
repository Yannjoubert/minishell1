/*
** EPITECH PROJECT, 2020
** my_printf_putchar.c
** File description:
** my_printf_putchar.c
*/

#include <stdarg.h>
#include "my.h"

void my_printf_putchar(va_list *ap)
{
    int i = va_arg(*ap, int);
    my_putchar(i);
}