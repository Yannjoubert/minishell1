/*
** EPITECH PROJECT, 2020
** B-PSU-210-RUN-2-1-minishell2-yann.joubert
** File description:
** Tests_my_printf.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "my.h"

void redirect_all_std2(void)
{
    cr_redirect_stdout();
    cr_get_redirected_stderr();
}

Test(my_printf, write_a_char, .init=redirect_all_std2)
{
    my_printf("%c", 's');
    cr_assert_stdout_eq_str("s");
}

Test(my_printf, write_a_string, .init=redirect_all_std2)
{
    my_printf("%s", "hello world !");
    cr_assert_stdout_eq_str("hello world !");
}