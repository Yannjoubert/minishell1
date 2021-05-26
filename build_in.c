/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** build_in.c
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

void exec(char **command, char **env)
{
    char *path = NULL;
    char **delimitator = NULL;
    char *pathway = NULL;
    char *tmp = NULL;
    int i = 0;

    if (check_exec(command[0], command, env) == 0)
        return;
    path = get_env(env, "PATH=");
    delimitator = str_to_word_array(path, ':');
    for (i = 0; delimitator[i] != NULL; i++) {
        tmp = my_strcat(delimitator[i], "/");
        pathway = my_strcat(tmp, command[0]);
        if (check_exec(pathway, command, env) == 0)
            break;
        free(pathway);
        free(tmp);
    }
    if (delimitator[i] == NULL)
        my_printf("%s: Command not found.\n", command[0]);
    else {
        free(pathway);
        free(tmp);
    }
    tab_free(delimitator);
}

// int build_mysh(char **command)
// {
//     if (my_strcmp(command[1], ";") == 0) {
//         my_separator(command);
//         return (0);
//     }
//     return (1);
// }

int build_in(char **command, char ***env)
{
    if (my_strcmp(command[0], "unsetenv") == 0) {
        my_unsetenv(command, *env);
        return 0;
    }
    if (my_strcmp(command[0], "setenv") == 0) {
        my_setenv(command, env);
        return 0;
    }
    if (my_strcmp(command[0], "cd") == 0) {
        my_cd(command, env);
        return 0;
    }
    if (my_strcmp(command[0], "exit") == 0) {
        my_exit(command, env);
        return 0;
    }
    // build_mysh(command);
    return 1;
}

char *get_cmd(void)
{
    char *buffer = NULL;
    size_t n = 0;
    int len = 0;

    if (isatty(0))
        my_printf("$> ");
    if ((len = getline(&buffer, &n, stdin)) < 0) {
        my_printf("exit");
        exit(0);
    }
    if (buffer[0] == '\n'){
        free(buffer);
        return get_cmd();
    }
    buffer[len - 1] = '\0';
    return buffer;
}

void prompt(char ***env, char *cmd)
{
    char **command = NULL;

    if ((command = str_to_word_array(cmd, ' ')) != NULL){
        free(cmd);
        if (build_in(command, env) != 0)
            exec(command, *env);
        tab_free(command);
    }
}