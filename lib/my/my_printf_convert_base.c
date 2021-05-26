/*
** EPITECH PROJECT, 2020
** my_printf_convert_base.c
** File description:
** my_printf_convert_base.c
*/

#include <unistd.h>
#include "my.h"

void my_printf_convert_base_o(va_list *ap)
{
    int i = va_arg(*ap, int);
    convert_base_o(i);
}

void my_printf_convert_base_x2(va_list *ap)
{
    int i = va_arg(*ap, int);
    convert_base_x2(i);
}

void my_printf_convert_base_x(va_list *ap)
{
    int i = va_arg(*ap, int);
    convert_base_x(i);
}

void my_printf_convert_base_u(va_list *ap)
{
    int i = va_arg(*ap, int);
    convert_base_u(i);
}