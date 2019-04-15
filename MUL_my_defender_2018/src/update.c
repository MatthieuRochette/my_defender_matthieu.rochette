/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** update.c
*/

#include "my_defender.h"

void update(entity_t *act)
{
    const float speeds[] = {SPEED_WALK_SOLDIER, SPEED_TANK,
        SPEED_HELICOPTER};
    const char types[] = "sah";

    if (act->type == 't' || act->type == 'b')
        return;
    for (int i = 0; i < 3; i++) {
        if (act->type == types[i] && act->enemy == 'a')
            act->pos_scale[0].x += speeds[i];
        else if (act->type == types[i] && act->enemy == 'e')
            act->pos_scale[0].x -= speeds[i];
    }
}