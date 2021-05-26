/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** minishell1.h
*/

#ifndef MINISHELL1_H_
#define MINISHELL1_H_
#include <stdbool.h>
#include <sys/signal.h>

#define ERROR_E "setenv: Variable name must contain alphanumeric characters.\n"

int array_len(char **env);
char **tab_dup(char **env);
void prompt(char ***env, char *cmd);
char **print_unsetenv(char *name, char **env);
char **print_env(char **env);
void exec(char **av, char **env);
void fork_ls(char **av, char **env);
char **recup_var(char *pathname, char **env);
void display_array(char **array);
void input(char *pathname, char **av, char **env);
void prompt_funct(char **env);
void tab_free(char **tab);
int function_exec(char *path, char **command, char **env);
int function_waitpid(pid_t pid);
void my_cd(char **cmd, char ***env);
void my_setenv(char **arg, char ***env);
int is_alpha(char c);
int my_unsetenv(char **arg, char **env);
int is_num(char *str);
void my_exit(char **command, char ***env);
char *get_env(char **env, char *str);
char **get_tab(char *str, char sep);
char **my_separator(char **av);
int check_exec(char *cmd, char **cmd_args,  char **env);
char *get_cmd(void);

#endif