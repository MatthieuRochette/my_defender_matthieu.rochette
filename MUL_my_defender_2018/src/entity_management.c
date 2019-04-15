/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** entity_management.c
*/

#include "my_defender.h"

int count_entity_type(head_t *ally, char type)
{
    entity_t *tmp;
    int nb_entities = 0;

    for (tmp = ally->first; tmp; tmp = tmp->next)
        if (tmp->type == type)
            nb_entities++;
    return (nb_entities);
}

sfIntRect get_entity_rect(char type, char side)
{
    const int height[] = {HEIGHT_BASE, HEIGHT_WALK_SOLDIER, HEIGHT_TURRET,
        HEIGHT_HELICOPTER, HEIGHT_TANK};
    const int width[] = {WIDTH_BASE, WIDTH_WALK_SOLDIER, WIDTH_TURRET,
        WIDTH_HELICOPTER, WIDTH_TANK};
    const int top[] = {TOP_BASE, TOP_WALK_SOLDIER, TOP_TURRET, TOP_HELICOPTER,
        TOP_TANK};
    const int left = get_left_type(type, side);
    const char entity[] = {'b', 's', 't', 'h', 'a'};
    sfIntRect rect;

    for (int i = 0; i != 5; i++) {
        if (type == entity[i]) {
            rect = create_rect(height[i], left, top[i], width[i]);
            return (rect);
        }
    }
    return ((sfIntRect){0, 0, 0, 0});
}

sfIntRect create_rect(int height, int left, int top, int width)
{
    sfIntRect rect;

    rect.height = height;
    rect.left = left;
    rect.top = top;
    rect.width = width;
    return (rect);
}

sfVector2f get_spawn(char type, char side)
{
    const sfVector2f pos_ally[] = {SPAWN_ALLY_BASE, SPAWN_ALLY_WALK_SOLDIER,
        SPAWN_ALLY_TURRET, SPAWN_ALLY_HELICOPTER, SPAWN_ALLY_TANK};
    const sfVector2f pos_enemy[] = {SPAWN_ENEMY_BASE,
        SPAWN_ENEMY_WALK_SOLDIER, SPAWN_ENEMY_TURRET, SPAWN_ENEMY_HELICOPTER,
        SPAWN_ENEMY_TANK};
    const char entity[] = {'b', 's', 't', 'h', 'a'};

    for (int i = 0; i <= 5; i++) {
        if (side == 'e' && type == entity[i])
            return (pos_enemy[i]);
        else if (type == entity[i])
            return (pos_ally[i]);
    }
    return ((sfVector2f){0, 0});
}

int get_life(char type)
{
    const char entity[] = {'b', 's', 't', 'h', 'a'};
    const int life[] = {10, 1, 4, 1, 4};

    for (int i = 0; i < 5; i++) {
        if (type == entity[i])
            return (life[i]);
    }
    return (0);
}