/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** my_exit.c
*/

#include "./include/my.h"
#include "minishell1.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

void is_numbers(char **command)
{
    if (command[1][0] >= '0' && command[1][0] <= '9')
        my_printf("exit: Badly formed number.\n");
    else
        my_printf("exit: Expression Syntax.\n");
}

int count_number(char **command)
{
    int count = 0;

    while (command[count] != NULL)
        count++;
    return (count);
}

void my_exit(char **command, char ***env)
{
    int arg = count_number(command);
    int value = 0;

    if (arg == 1) {
        my_printf("exit\n");
        tab_free(command);
        tab_free(*env);
        exit(0);
    }
    if (is_num(command[1]) == 1 && arg == 2) {
        is_numbers(command);
    } else if (arg == 2 && is_num(command[1]) == 0) {
        value = my_getnbr(command[1]);
        my_printf("exit\n");
        tab_free(command);
        tab_free(*env);
        exit(value);
    }
    else
        my_printf("exit: Expression Syntax.\n");
}