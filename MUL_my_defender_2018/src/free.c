/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** free.c
*/

#include "my_defender.h"

void free_list(head_t *ally)
{
    free(ally);
}

void free_structure(game_t *game)
{
    free(game->backgrounds);
    free(game->button);
    free(game->musics_and_sounds);
}

void free_csfml(game_t *game)
{
    for (int i = 0; i < NB_MUSICS_AND_SOUNDS; i++)
        sfMusic_destroy(game->musics_and_sounds[i]);
    for (int i = 0; i < NB_BUTTON; i++) {
        sfRectangleShape_destroy(game->button[i].rect_shape);
        sfSprite_destroy(game->button[i].sprite);
        sfTexture_destroy(game->button[i].texture);
    }
    for (int i = 0; i < NB_BACKGROUNDS; i++) {
        sfSprite_destroy(game->backgrounds[i].sprite);
        sfTexture_destroy(game->backgrounds[i].texture);
    }
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window);
}