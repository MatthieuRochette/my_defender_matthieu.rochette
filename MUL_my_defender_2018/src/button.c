/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_button
*/

#include "my_defender.h"

int create_button(button_t *button, const char *file, sfVector2f pos,
    char size)
{
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(file, NULL);
    button->rect_shape = sfRectangleShape_create();
    if (!button->sprite || !button->texture || !button->rect_shape)
        return (MY_FAILURE);
    button->pos_scale[0] = pos;
    if (size == 'B') {
        button->pos_scale[1] = SIZE_BIG_BUTTON;
        sfRectangleShape_setSize(button->rect_shape, button->pos_scale[1]);
    } else {
        button->pos_scale[1] = SIZE_SMALL_BUTTON;
        sfRectangleShape_setSize(button->rect_shape, button->pos_scale[1]);
    }
    button->rect = sfRectangleShape_getGlobalBounds(button->rect_shape);
    sfRectangleShape_setPosition(button->rect_shape, pos);
    sfRectangleShape_setTexture(button->rect_shape, button->texture, sfTrue);
    button->cooldown = 0;
    return (MY_SUCCESS);
}

int init_button(game_t *game)
{
    button_t *button = malloc(sizeof(button_t) * NB_BUTTON);
    const char *file_sprite[NB_BUTTON] = {ALL_BUT_PATHS};
    const sfVector2f position_button[NB_BUTTON] = {POS_ALL_BUT};
    char small_buttons[] = {'2', '3', '4', '7', '8', '9', ':'};
    char c;

    if (!button)
        return (MY_FAILURE);
    game->button = button;
    for (int i = 0; i < NB_BUTTON; i++) {
        c = char_found(small_buttons, i + 48) ? 'S' : 'B';
        if (create_button(&game->button[i], file_sprite[i],
            position_button[i], c) == 84)
            return (MY_FAILURE);
    }
    return (MY_SUCCESS);
}

void manage_button(game_t *game, button_t *button, int next, sfEvent event)
{
    int old_scene = game->scene;
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect_shape);

    if (event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (sfFloatRect_contains(&rect, game->position_mouse.x,
            game->position_mouse.y) == sfTrue)
            game->scene = next;
    }
    if (sfFloatRect_contains(&rect, game->position_mouse.x,
        game->position_mouse.y) == sfTrue)
        sfRectangleShape_setFillColor(button->rect_shape, sfRed);
    else
        sfRectangleShape_setFillColor(button->rect_shape, sfWhite);
    if (game->scene == next && next == GAME_SCENE && old_scene != PAUSE_SCENE
        && old_scene != SHOP_SCENE)
        reset_game(game);
}

void manage_entity_button(game_t *game, button_t *button,
    char type, sfEvent event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect_shape);

    if (button->cooldown > 0)
        return;
    if (type == 't' && count_entity_type(game->list[ALLY_LIST], 't') > 0) {
        sfRectangleShape_setFillColor(button->rect_shape, sfBlack);
        return;
    }
    if (sfFloatRect_contains(OVER_BUTTON) == sfTrue)
        sfRectangleShape_setFillColor(button->rect_shape, sfRed);
    else
        sfRectangleShape_setFillColor(button->rect_shape, sfWhite);
    if (event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (sfFloatRect_contains(&rect, game->position_mouse.x,
            game->position_mouse.y) == sfTrue) {
            sfRectangleShape_setFillColor(button->rect_shape, sfWhite);
            add_entity(game->list[ALLY_LIST], type, 'a');
            sfRectangleShape_setFillColor(button->rect_shape, sfBlue);
            button->cooldown = 3;
        }
    }
}