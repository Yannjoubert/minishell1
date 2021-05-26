/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** display_tab.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include <stdlib.h>

void display(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        my_printf("%s\n", tab[i]);
}