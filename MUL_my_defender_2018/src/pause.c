/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** pause.c
*/

#include "my_defender.h"

void pause_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->position_mouse = sfMouse_getPositionRenderWindow(game->window);
        manage_button(game, &game->button[RESUME_BUTTON], GAME_SCENE, event);
        manage_button(game, &game->button[EXIT_BUTTON], -1, event);
        manage_button(game, &game->button[MAIN_MENU_BUTTON], MENU_SCENE,
            event);
        manage_exit(game, event);
    }
}

void display_pause(game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[RESUME_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[MAIN_MENU_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[EXIT_BUTTON].rect_shape, NULL);
}