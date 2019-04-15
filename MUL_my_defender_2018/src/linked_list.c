/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** linked_list.c
*/

#include "my_defender.h"

int fill_new_elem(entity_t *new, char type, char side)
{
    new->enemy = side == 'e' ? 'e' : 'a';
    new->life = get_life(type);
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(PATH_ENTITIES, NULL);
    if (!new->sprite || !new->texture)
        return (MY_FAILURE);
    new->pos_scale[0] = get_spawn(type, new->enemy);
    new->seconds = 0;
    if (side == 'e')
        sfSprite_setScale(new->sprite, (side == 'e' && type != 'b' &&
            type != 's' ? ENEMY_SCALE : (sfVector2f){1, 1}));
    new->rect = get_entity_rect(type, new->enemy);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setPosition(new->sprite, new->pos_scale[0]);
    new->type = type;
    return (MY_SUCCESS);
}

entity_t *get_previous_elem(head_t *ally, entity_t *elem)
{
    entity_t *tmp = ally->first;

    if (elem == ally->first)
        return (NULL);
    for (tmp = ally->first; tmp->next != elem; tmp = tmp->next);
    return (tmp);
}

int add_entity(head_t *list, char type, char side)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        return (84);
    new->next = list->first;
    if (fill_new_elem(new, type, side) == 84)
        return (MY_FAILURE);
    if (list->last == NULL)
        list->last = new;
    list->first = new;
    list->act = new;
    return (MY_SUCCESS);
}

void del_elem(head_t *ally, entity_t *elem)
{
    entity_t *prev = get_previous_elem(ally, elem);

    if (prev != NULL)
        prev->next = elem->next;
    if (elem == ally->first)
        ally->first = elem->next;
    if (elem == ally->last) {
        if (prev)
            prev->next = NULL;
        ally->last = prev;
    }
    ally->act = elem->next;
    free(elem);
}

head_t *init_list(void)
{
    head_t *ally = malloc(sizeof(head_t));

    if (!ally)
        return (NULL);
    ally->act = NULL;
    ally->first = NULL;
    ally->last = NULL;
    return (ally);
}