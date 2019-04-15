/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** key
*/

#include "my_defender.h"

button_t *get_button_corresponding_to_key(game_t *game, char type)
{
    switch (type) {
        case 's':
            return (&game->button[SOLDIER_BUTTON]);
        case 't':
            return (&game->button[TURRET_BUTTON]);
        case 'h':
            return (&game->button[HELI_BUTTON]);
        case 'a':
            return (&game->button[ARMY_TANK_BUTTON]);
        default:
            return (NULL);
    }
}

void manage_key(game_t *game, int keyboard, sfEvent event, char type)
{
    button_t *button = get_button_corresponding_to_key(game, type);

    if (button->cooldown > 0)
        return;
    if (type == 't' && count_entity_type(game->list[ALLY_LIST], 't') > 0) {
        sfRectangleShape_setFillColor(game->button[TURRET_BUTTON].rect_shape,
            sfBlack);
        return;
    }
    if (event.key.code == keyboard && event.type == sfEvtKeyReleased) {
        add_entity(game->list[ALLY_LIST], type, 'a');
        button->cooldown = 3;
    }
}

void manage_exit(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ))
        sfRenderWindow_close(game->window);
}