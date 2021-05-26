/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** my_unsetenv.c
*/

#include "./include/my.h"
#include "./include/minishell1.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "stdbool.h"

int my_unsetenv(char **arg, char **env)
{
    int i = 0;
    int phase = -1;

    if (arg[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return 1;
    }
    while (env[i] != NULL) {
        if (my_strncmp(env[i], arg[1], my_strlen(arg[1])) == 0 &&
            env[i][my_strlen(arg[1])] == '=') {
            free(env[i]);
            phase = 0;
        }
        if (phase == 0)
            env[i] = env[i + 1];
        i++;
    }
    return (0);
}