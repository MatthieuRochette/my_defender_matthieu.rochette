/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** animate_turret.c
*/

#include "my_defender.h"

void animate_turret(entity_t *act)
{
    static char state = 0;

    if (act->seconds < 1)
        return;
    if (act->seconds > 1.2 && state == 2) {
        anim_entities(act);
        state = 0;
        act->seconds = 0;
    } else if (act->seconds > 1.1 && state == 1) {
        anim_entities(act);
        state = 2;
    } else {
        if (state == 0) {
            anim_entities(act);
            state = 1;
        }
    }
}