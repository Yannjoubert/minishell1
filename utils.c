/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** outils.c
*/

#include "./include/my.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int array_len(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        i = i + 1;
    }
    return (i);
}

char **tab_dup(char **env)
{
    int i = 0;
    char **env_copy = malloc(sizeof(char *) * (array_len(env) + 1));

    while (env[i] != NULL) {
        env_copy[i] = my_strdup(env[i]);
        i = i + 1;
    }
    env_copy[i] = NULL;
    return (env_copy);
}

void display_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        my_printf("%s", array[i]);
        i = i + 1;
    }
}

void input(char *pathname, char **av, char **env)
{
    pid_t pid = fork();
    int status_man = 0;

    if (pid != 0)
        waitpid(pid, &status_man, 0);
    if (pid == 0) {
        execve(pathname, av, env);
        exit(status_man);
    }
}

void tab_free(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}