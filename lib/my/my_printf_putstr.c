/*
** EPITECH PROJECT, 2020
** my_printf_putstr.c
** File description:
** my_printf_putstr.c
*/

#include <stdarg.h>
#include "my.h"

void my_printf_putstr(va_list *ap)
{
    char *str = va_arg(*ap, char *);
    my_putstr(str);
}