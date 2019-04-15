/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** animation
*/

#include "my_defender.h"

int get_left_type(char type, char side)
{
    const int lefts[] = {LEFT_ENEMY_BASE, LEFT_WALK_ENEMY_SOLDIER,
        LEFT_ENEMY_TURRET, LEFT_ENEMY_HELICOPTER, LEFT_ENEMY_TANK};
    const char types[] = "bstha";

    if (side != 'e')
        return (LEFT_ALLY);
    for (int i = 0; i < 5; i++) {
        if (type == types[i])
            return (lefts[i]);
    }
    return (0);
}

static int get_top_type(char type)
{
    const int tops[] = {TOP_WALK_SOLDIER, TOP_TURRET, TOP_HELICOPTER,
        TOP_TANK};
    const char types[] = "stha";

    for (int i = 0; i < 4; i++) {
        if (types[i] == type)
            return (tops[i]);
    }
    return (0);
}

void anim_entities(entity_t *entity)
{
    const int height[] = {HEIGHT_BASE, HEIGHT_WALK_SOLDIER, HEIGHT_TURRET,
        HEIGHT_HELICOPTER, HEIGHT_TANK};
    const int width[] = {WIDTH_BASE, WIDTH_WALK_SOLDIER, WIDTH_TURRET,
        WIDTH_HELICOPTER, WIDTH_TANK};
    const char entity_type[] = "bstha";

    for (int i = 0; i < 5; i++) {
        if (entity_type[i] == entity->type)
            entity->rect = modify_rect(entity, height[i], width[i]);
    }
}

sfIntRect modify_rect(entity_t *entity, int height, int width)
{
    const int number_image = get_number_image(entity->type);

    if (entity->type == 's') {
        if (entity->rect.left < width * (number_image- 1) +
            get_left_type(entity->type, entity->enemy))
            entity->rect.left += width;
        else
            entity->rect.left = get_left_type(entity->type, entity->enemy);
    } else {
        if (entity->rect.top < height * (number_image - 1) +
            get_top_type(entity->type))
            entity->rect.top += height;
        else
            entity->rect.top = get_top_type(entity->type);
    }
    return (entity->rect);
}

int get_number_image(char c)
{
    const int number_image[] = {NB_SPRITE_BASE, NB_WALK_SOLDIER, NB_TURRET,
        NB_HELICOPTER, NB_TANK};
    const char entity[] = {'b', 's', 't', 'h', 'a'};

    for (int i = 0; i < 5; i++) {
        if (c == entity[i])
            return (number_image[i]);
    }
    return (0);
}