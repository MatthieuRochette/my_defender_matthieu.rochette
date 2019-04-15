/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** settings.c
*/

#include "my_defender.h"

void settings_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->position_mouse = sfMouse_getPositionRenderWindow(game->window);
        manage_button(game, &game->button[BACK_BUTTON], MENU_SCENE, event);
        manage_exit(game, event);
    }
}

void display_settings(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->backgrounds[GAME_BG].sprite,
        NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[BACK_BUTTON].rect_shape, NULL);
}