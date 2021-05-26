/*
** EPITECH PROJECT, 2020
** B-PSU-210-RUN-2-1-minishell2-yann.joubert
** File description:
** Tests_funct2.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

void redirect_all_std3(void)
{
    cr_redirect_stdout();
    cr_get_redirected_stderr();
}


Test(my_strcmp, test_strcmp, .init=redirect_all_std3)
{
    char *str = "toto tata";
    char *expected = "toto tata";

    cr_assert_eq(0, my_strcmp(str, expected));
}