/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** init
*/

#include "my_defender.h"

int init_backgrounds(game_t *game)
{
    background_t *backgrounds = malloc(sizeof(background_t) * NB_BACKGROUNDS);
    const char *texture[] = {PATH_MENU_BG, PATH_SHOP_BG, PATH_WIN_BG,
        PATH_LOSE_BG, PATH_HTP_BG};

    if (!backgrounds)
        return (MY_FAILURE);
    for (int i = 0; i < NB_BACKGROUNDS; i++) {
        backgrounds[i].sprite = sfSprite_create();
        backgrounds[i].texture = sfTexture_createFromFile(texture[i], NULL);
        if (backgrounds[i].sprite == NULL || backgrounds[i].texture == NULL)
            return (MY_FAILURE);
        backgrounds[i].rect = sfSprite_getTextureRect(backgrounds[i].sprite);
        sfSprite_setTexture(backgrounds[i].sprite, backgrounds[i].texture,
            sfTrue);
    }
    game->backgrounds = backgrounds;
    return (MY_SUCCESS);
}