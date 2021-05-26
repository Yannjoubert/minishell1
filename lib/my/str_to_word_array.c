/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** str_to_word_array.c
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

char *clean_str(char *str)
{
    int i = 0;
    char buff[my_strlen(str)];
    char *str_cp = my_strdup(str);
    int e = 0;
    int d = 0;

    for (int i = 0; str_cp[i] != '\0'; i++)
        if (str_cp[i] == '\t')
            str_cp[i] = ' ';
    for (d = i; str_cp[d] == ' ' && str_cp[d] != '\0'; d++)
        str_cp++;
    for (i = my_strlen(str_cp); i != 0 && str_cp[i] == ' '; i--);
    str_cp[i] = '\0';
    for (int i = 0; str_cp[i] != '\0'; i++)
        ((i > 1 && str_cp[i] == ' ' && str_cp [i - 1] != ' ') ||
            (str_cp[i] != ' ')) ? buff[e++] = str_cp[i] : 0;
    buff[e] = '\0';
    free(str_cp - d);
    return my_strdup(buff);
}

int compt_letters(char *str, char h)
{
    int i = 0;

    while (str && str[i] != '\0' && str[i] != h)
        i = i + 1;
    return (i);
}

int compt_spaces(char *str, char h)
{
    int i = 0;
    int stock = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        if (str[i] == h) {
            stock = stock + 1;
            i++;
        }
        i = i + 1;
    }
    stock = stock + 1;
    return (stock);
}

char **get_tab(char *str, char sep)
{
    char *cleaned = clean_str(str);
    int rows = compt_spaces(cleaned, sep);
    char **tab = NULL;
    int max_len = my_strlen(cleaned);
    int len = 0;
    int add = 0;
    int i = 0;

    if (str == NULL || cleaned == NULL || rows == 0)
        return NULL;
    tab = malloc(sizeof(char *) * (rows + 1));
    for (i = 0; len < max_len; i++){
        add = compt_letters(cleaned + len, sep);
        tab[i] = my_strndup(cleaned + len, add);
        len += add + 1;
    }
    tab[i] = NULL;
    free(cleaned);
    return tab;
}

char **str_to_word_array(char *str, char h)
{
    char **tab = NULL;

    if (str != NULL)
        tab = get_tab(str, h);
    return (tab);
}