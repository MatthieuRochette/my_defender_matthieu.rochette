/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** combat
*/

#include "my_defender.h"

static void manage_collision(game_t *game, entity_t *ally, entity_t *enemy)
{
    if (ally->type == 'b' && enemy->type != 'b')
        ally->life--;
    else if (ally->type != 'b' && enemy->type != 'b') {
        ally->life--;
        enemy->life--;
        game->score += 100;
    } else {
        enemy->life--;
        game->score += 100;
    }
}

static void check_intersection(game_t *game, head_t *ally_army, head_t
    *enemy_army, sfFloatRect *rect)
{
    while (enemy_army->act) {
        rect[1] = sfSprite_getGlobalBounds(enemy_army->act->sprite);
        if (sfFloatRect_intersects(&rect[0], &rect[1], NULL))
            manage_collision(game, ally_army->act, enemy_army->act);
        enemy_army->act = enemy_army->act->next;
    }
}

void check_collision(game_t *game, head_t *ally_army, head_t *enemy_army)
{
    sfFloatRect *rect = malloc(sizeof(sfFloatRect) * 2);

    if (!rect)
        return;
    ally_army->act = ally_army->first;
    enemy_army->act = enemy_army->first;
    while (ally_army->act) {
        rect[0] = sfSprite_getGlobalBounds(ally_army->act->sprite);
        check_intersection(game, ally_army, enemy_army, rect);
        enemy_army->act = enemy_army->first;
        ally_army->act = ally_army->act->next;
    }
    free(rect);
}