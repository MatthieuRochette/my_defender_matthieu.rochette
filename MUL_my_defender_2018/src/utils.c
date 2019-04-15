/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** utils.c
*/

#include "my_defender.h"

int char_found(char *str, char c)
{
    if (!str)
        return (MY_FAILURE);
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == c)
            return (MY_TRUE);
    }
    return (MY_FALSE);
}

char *my_itoa(unsigned int nb)
{
    int length_result = length_nb(nb);
    char *result = malloc(sizeof(char) * length_result);
    int i = length_result - 2;

    if (nb == 0) {
        result[0] = '0';
        result[1] = '\0';
        return (result);
    }
    for (; nb != 0; i--) {
        result[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    result[length_result - 1] = nb % 10 + '0';
    result[length_result - 1] = '\0';
    return (result);
}

int length_nb(int nb)
{
    int result = 0;

    if (nb == 0)
        return (2);
    for (; nb != 0; result++)
        nb = nb / 10;
    result++;
    return (result);
}