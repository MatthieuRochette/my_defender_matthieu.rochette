/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** menu.c
*/

#include "my_defender.h"

void menu_event(game_t *game)
{
    sfEvent event;

    switch_music(game, GAME_MUSIC, MENU_MUSIC);
    switch_music(game, VICTORY_MUSIC, MENU_MUSIC);
    switch_music(game, GAME_OVER_MUSIC, MENU_MUSIC);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->position_mouse = sfMouse_getPositionRenderWindow(game->window);
        manage_button(game, &game->button[PLAY_BUTTON], GAME_SCENE, event);
        manage_button(game, &game->button[SETTINGS_BUTTON],
            SETTINGS_SCENE, event);
        manage_button(game, &game->button[EXIT_BUTTON], -1, event);
        manage_button(game, &game->button[HTP_BUTTON], HTP_SCENE, event);
        manage_exit(game, event);
    }
}

void display_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->backgrounds[0].sprite,
        NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[PLAY_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[SETTINGS_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[EXIT_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[HTP_BUTTON].rect_shape, NULL);
}