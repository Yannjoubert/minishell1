/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** minishell1.c
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

int check_exec(char *cmd, char **cmd_args,  char **env)
{
    if (access(cmd, X_OK) == 0) {
        function_exec(cmd, cmd_args, env);
        return 0;
    }
    return 1;
}

char **recup_var(char *pathname, char **env)
{
    int i = 0;
    char **new_array = NULL;

    while (env[i] != NULL) {
        new_array = str_to_word_array(env[i], '=');
        if (my_strcmp(new_array[0], pathname) == 0)
            return (new_array);
        i = i + 1;
    }
    return (new_array);
}

char **print_env(char **env)
{
    int i = 0;
    char **dup_env = tab_dup(env);

    while (env[i] != NULL) {
        dup_env[i] = env[i];
        my_printf("%s\n", dup_env[i]);
        i = i + 1;
    }
    return dup_env;
}

int function_waitpid(pid_t pid)
{
    int status = 0;

    waitpid(pid, &status, 0);
    if (status == 139)
        write(2, "Segmentation fault (core dumped)\n", 33);
    if (status == 11)
        write(2, "Segmentation fault\n", 19);
    if (status == 8)
        write(2, "Floating exception\n", 19);
    if (status == 136)
        write(2, "Floating exception (core dumped)\n", 33);
    return (0);
}

int function_exec(char *path, char **command, char **env)
{
    pid_t pid = fork();

    if (pid < 0)
        my_putstr("fork error\n");
    else if (pid == 0) {
        if (execve(path, command, env) == -1)
            exit (0);
    } else
        function_waitpid(pid);
    return 0;
}