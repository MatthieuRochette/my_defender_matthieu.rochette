/*
** EPITECH PROJECT, 2019
** workshop
** File description:
** main
*/

#include "my_defender.h"

int main(int ac, char **av)
{
    if (ac > 2)
        return (MY_FAILURE);
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
            return (my_game(HTP_SCENE));
        else
            return (MY_FAILURE);
    }else
        return (my_game(MENU_SCENE));
}