/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** my_cd.c
*/

#include "./include/my.h"
#include "./include/minishell1.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

char *get_env(char **env, char *str)
{
    int i = 0;
    int len = my_strlen(str);

    while (env[i] != NULL)
        if (my_strncmp(env[i++], str, len) == 0)
            return (env[i - 1] + len);
    return NULL;
}

void my_cd_home(char ***env)
{
    char *home = get_env(*env, "HOME=");

    if (home == NULL) {
        my_printf("cd: No home directory.\n");
        return;
    }
    chdir(home);
}

void my_cd(char **cmd, char ***env)
{
    if (array_len(cmd) > 2)
        my_putstr("Too many arguments\n");
    if (array_len(cmd) == 1)
        my_cd_home(env);
    else if (array_len(cmd) == 2) {
        chdir(cmd[1]);
    }
}