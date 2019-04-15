/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** text
*/

#include "my_defender.h"

int init_text(game_t *game)
{
    game->text = sfText_create();
    game->font = sfFont_createFromFile(PATH_FONT);
    if (!game->text || !game->font)
        return (MY_FAILURE);
    sfText_setFont(game->text, game->font);
    sfText_setColor(game->text, sfRed);
    sfText_scale(game->text, (sfVector2f){2, 2});
    return (MY_SUCCESS);
}

void display_score(game_t *game)
{
    static const char *score = "Score:";
    char *result = my_itoa(game->score);

    sfText_setPosition(game->text, POS_SCORE_TEXT);
    sfText_setString(game->text, score);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    sfText_setPosition(game->text, POS_SCORE_VALUE);
    sfText_setString(game->text, result);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    free(result);
}