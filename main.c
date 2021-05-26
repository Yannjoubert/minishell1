/*
** EPITECH PROJECT, 2020
** B-PSU-210-RUN-2-1-minishell2-yann.joubert
** File description:
** main.c
*/

#include "./include/my.h"
#include "./include/minishell1.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char **av, char **env)
{
    char **copy_env = tab_dup(env);
    char *cmd = NULL;

    (void)av;
    if (ac != 1) {
        write(2, "Invalid argument\n", 17);
        return (84);
    }
    while (1) {
        cmd = get_cmd();
        prompt(&copy_env, cmd);
    }
    tab_free(copy_env);
    return (0);
}