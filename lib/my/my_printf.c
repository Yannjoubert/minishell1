/*
** EPITECH PROJECT, 2020
** my_printf_flags.c
** File description:
** my_printf_flags.c
*/

#include "my_printf_funct.h"
#include "my.h"

int my_vprintf(char const *str, va_list *ap, int b)
{
    int i = 0;
    const struct my_printf_funct print[8] = {
        {"d", &my_printf_putnbr}, {"c", &my_printf_putchar},
        {"s", &my_printf_putstr}, {"i", &my_printf_putnbr},
        {"x", &my_printf_convert_base_x}, {"X", &my_printf_convert_base_x2},
        {"o", &my_printf_convert_base_o}, {"u", &my_printf_convert_base_u},
    };

    if (str[b] == '%')
        my_putchar('%');
    while (i != 8) {
            if (str[b] == print[i].str[0])
                print[i].flags(ap);
            i = i + 1;
        }
        return (b);
}

int my_printf(char const *str, ...)
{
    va_list ap;
    int b = 0;

    va_start(ap, str);
    while (str[b] != '\0') {
        if (str[b] == '%') {
            b = b + 1;
            b = my_vprintf(str, &ap, b);
        } else
            my_putchar(str[b]);
        b = b + 1;
    }
    va_end(ap);
    return (b);
}