/*
** EPITECH PROJECT, 2020
** my_printf_funct.h
** File description:
** my_printf_funct.h
*/

#ifndef MY_PRINT_FUNCT_H_
#define MY_PRINT_FUNCT_H_
#include <stdarg.h>

struct my_printf_funct {
    char *str;
    void (*flags)(va_list *ap);
};
#endif