/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** how_to_play
*/

#include "my_defender.h"

void how_to_play_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->position_mouse = sfMouse_getPositionRenderWindow(game->window);
        manage_button(game, &game->button[MAIN_MENU_BUTTON], MENU_SCENE,
            event);
        manage_button(game, &game->button[EXIT_BUTTON], -1, event);
        manage_exit(game, event);
    }
}

void display_how_to_play(game_t *game)
{
    sfRectangleShape_setPosition(game->button[MAIN_MENU_BUTTON].rect_shape,
        (sfVector2f){675, 200});
    sfRectangleShape_setScale(game->button[MAIN_MENU_BUTTON].rect_shape,
        (sfVector2f){0.75, 0.75});
    sfRenderWindow_drawSprite(game->window,
        game->backgrounds[HTP_BG].sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[MAIN_MENU_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[EXIT_BUTTON].rect_shape, NULL);
}