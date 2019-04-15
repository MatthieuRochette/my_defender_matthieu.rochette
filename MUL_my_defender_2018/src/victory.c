/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene_event_bis.c
*/

#include "my_defender.h"

void victory_event(game_t *game)
{
    sfEvent event;

    switch_music(game, GAME_MUSIC, VICTORY_MUSIC);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->position_mouse = sfMouse_getPositionRenderWindow(game->window);
        manage_button(game, &game->button[MAIN_MENU_BUTTON], MENU_SCENE,
            event);
        manage_button(game, &game->button[EXIT_BUTTON], -1, event);
        manage_exit(game, event);
    }
}

void display_victory(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRectangleShape_setPosition(game->button[MAIN_MENU_BUTTON].rect_shape,
        (sfVector2f){675, 600});
    sfRectangleShape_setScale(game->button[MAIN_MENU_BUTTON].rect_shape,
        (sfVector2f){0.75, 0.75});
    sfText_setString(game->text, my_itoa(game->score));
    sfText_setPosition(game->text, (sfVector2f){675, 500});
    sfRenderWindow_drawSprite(game->window,
        game->backgrounds[GAME_BG].sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
        game->backgrounds[WIN_BG].sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[MAIN_MENU_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[EXIT_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}