/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** game_over.c
*/

#include "my_defender.h"

void empty_list(head_t *list, entity_t *current)
{
    if (current->next)
        empty_list(list, current->next);
    del_elem(list, current);
}

void reset_game(game_t *game)
{
    game->score = 0;
    sfClock_restart(game->clock);
    for (int i = 0; i != 2; i++) {
        if (game->list[i]->first == NULL)
            break;
        empty_list(game->list[i], game->list[i]->first);
    }
    add_bases(game);
}

void game_over_event(game_t *game)
{
    sfEvent event;

    switch_music(game, GAME_MUSIC, GAME_OVER_MUSIC);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->position_mouse = sfMouse_getPositionRenderWindow(game->window);
        manage_button(game, &game->button[EXIT_BUTTON], -1, event);
        manage_button(game, &game->button[MAIN_MENU_BUTTON],
            MENU_SCENE, event);
        manage_exit(game, event);
    }
}

void check_end(game_t *game)
{
    if (count_entity_type(game->list[ALLY_LIST], 'b') == 0) {
        game->scene = GAME_OVER_SCENE;
    } else if (count_entity_type(game->list[ENEMY_LIST], 'b') == 0) {
        game->scene = VICTORY_SCENE;
    }
}

void display_game_over(game_t *game)
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
        game->backgrounds[GAME_OVER_BG].sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[MAIN_MENU_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[EXIT_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}