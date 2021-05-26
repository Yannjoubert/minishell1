/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str = str + 1;
    }
    return (1);
}