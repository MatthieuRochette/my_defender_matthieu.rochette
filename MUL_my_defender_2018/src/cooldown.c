/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** cooldown.c
*/

#include "my_defender.h"

void do_cooldown(game_t *game)
{
    for (int i = SOLDIER_BUTTON; i <= ARMY_TANK_BUTTON; i++) {
        if (game->button[i].cooldown > 0) {
            game->button[i].cooldown -= 0.1;
            sfRectangleShape_setFillColor(game->button[i].rect_shape,
                sfBlack);
        }
    }
}