/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** my_setenv.c
*/

#include "./include/my.h"
#include "./include/minishell1.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

bool check_name(char **arg, char **env)
{
    if (get_env(env, arg[1]) != NULL)
        return true;
    return false;
}

char **modify_env(char **arg, char **env)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (array_len(env) + 2));

    while (env[i] != NULL) {
        new_env[i] = env[i];
        i++;
    }
    new_env[i] = my_strcat(arg[1], "=");
    if (arg[2] != NULL)
        new_env[i] = my_strcat(new_env[i], arg[2]);
    i = i + 1;
    new_env[i] = NULL;
    return (new_env);
}

char **change_value(char **arg, char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], arg[1], my_strlen(arg[1])) == 0)
            break;
        i++;
    }
    env[i] = my_strcat(arg[1], "=");
    if (arg[2] != NULL)
        env[i] = my_strcat(env[i], arg[2]);

    return (env);
}

bool check_error(char **arg)
{
    int i = 1;

    if (is_alpha(arg[1][0]) == 0) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return true;
    }
    while (arg[1][i] != '\0') {
        if (is_alpha(arg[1][i]) == 0 && (arg[1][i] < '9' && arg[1][i] > '0')
        && arg[1][i] != '_') {
            write(2, ERROR_E, 61);
            return true;
        }
        i++;
    }
    return false;
}

void my_setenv(char **arg, char ***env)
{
    if (array_len(arg) > 3) {
        my_printf("Too many arguments\n");
        return;
    }
    if (array_len(arg) == 1)
        display(*env);
    else if (check_error(arg) == false) {
        if (check_name(arg, *env) == false)
            *env = modify_env(arg, *env);
        else if (check_name(arg, *env) == true)
            *env = change_value(arg, *env);
    }
}