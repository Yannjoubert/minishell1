/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** is_alpha.c
*/

#include "my.h"
#include "minishell1.h"

int is_num(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (1);
    }
    return (0);
}

int is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else
        return (0);
}