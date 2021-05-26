/*
** EPITECH PROJECT, 2020
** B-PSU-210-RUN-2-1-minishell2-yann.joubert
** File description:
** Tests_funct.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_get_redirected_stderr();
}

Test(my_strlen, test_my_strlen)
{
    int len = my_strlen("hello");
    int expect = 5;

    cr_assert_eq(len, expect);
}

Test(my_putstr, write_a_string, .init=redirect_all_std)
{
    my_putstr("test");
    cr_assert_stdout_eq_str("test");
}

Test(my_putchar, write_a_char, .init=redirect_all_std)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(my_strncmp, test_funct)
{
    char *str = "hello world\n";
    char *expected = "hello world\n";

    cr_assert_eq(0, my_strncmp(str, expected, 13));
}