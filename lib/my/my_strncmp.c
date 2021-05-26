/*
** EPITECH PROJECT, 2020
** Day03
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while ((s1[i] || s2[i]) && s1[i] == s2[i] && i != n - 1) {
        i = i + 1;
    }
    if (n == '-')
        return (0);
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] == s2[i])
        return (0);
    if (s1[i] < s2[i])
        return (-1);
    return (0);
}