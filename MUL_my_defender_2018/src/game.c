/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** game.c
*/

#include "my_defender.h"

static void manage_animation_speed(entity_t *act)
{
    switch (act->type) {
        case 't':
            animate_turret(act);
            break;
        case 'h':
            if (act->seconds > 0.1) {
                anim_entities(act);
                act->seconds = 0;
            }
            break;
        default:
            if (act->seconds > 0.2) {
                anim_entities(act);
                act->seconds = 0;
            }
    }
}

static void display_entities(head_t *list, sfRenderWindow *win, float seconds,
    sfMusic **musics)
{
    list->act =list->first;
    while (list->act) {
        if (list->act->life <= 0) {
            play_soundfx(list->act->type, musics);
            del_elem(list, list->act);
        }
        if (!list->act)
            break;
        list->act->seconds += seconds;
        update(list->act);
        sfSprite_setPosition(list->act->sprite,
            list->act->pos_scale[0]);
        manage_animation_speed(list->act);
        sfSprite_setTextureRect(list->act->sprite,
            list->act->rect);
        sfRenderWindow_drawSprite(win, list->act->sprite, NULL);
        list->act =list->act->next;
    }
}

static void manage_enemy_spawn(game_t *game)
{
    const char type[] = {'s', 'h', 'a', 't'};
    int random = 0;

    if ((int)game->spawn_time > 1) {
        if (count_entity_type(game->list[ENEMY_LIST], 't') == 0)
            random = rand() % 4;
        else
            random = rand() % 3;
        add_entity(game->list[ENEMY_LIST], type[random], 'e');
        game->spawn_time = 0;
    }
}

void game_event(game_t *game)
{
    sfEvent ev;

    ev.key.code = 0;
    switch_music(game, MENU_MUSIC, GAME_MUSIC);
    while (sfRenderWindow_pollEvent(game->window, &ev)) {
        game->position_mouse = sfMouse_getPositionRenderWindow(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyP) || sfKeyboard_isKeyPressed(36))
            game->scene = PAUSE_SCENE;
        if (sfKeyboard_isKeyPressed(sfKeyS))
            game->scene = SHOP_SCENE;
        manage_key(game, sfKeyNum1, ev, 's');
        manage_key(game, sfKeyNum2, ev, 't');
        manage_key(game, sfKeyNum3, ev, 'h');
        manage_key(game, sfKeyNum4, ev, 'a');
        manage_entity_button(game, &game->button[SOLDIER_BUTTON], 's', ev);
        manage_entity_button(game, &game->button[TURRET_BUTTON], 't', ev);
        manage_entity_button(game, &game->button[HELI_BUTTON], 'h', ev);
        manage_entity_button(game, &game->button[ARMY_TANK_BUTTON], 'a', ev);
        manage_exit(game, ev);
        manage_enemy_spawn(game);
    }
}

void display_game(game_t *game)
{
    do_cooldown(game);
    sfRenderWindow_drawSprite(game->window, game->backgrounds[GAME_BG].sprite,
        NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[SOLDIER_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[TURRET_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[HELI_BUTTON].rect_shape, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        game->button[ARMY_TANK_BUTTON].rect_shape, NULL);
    check_collision(game, game->list[ALLY_LIST], game->list[ENEMY_LIST]);
    check_end(game);
    add_bases(game);
    display_entities(game->list[ALLY_LIST], game->window,
        game->clock_time, game->musics_and_sounds);
    display_entities(game->list[ENEMY_LIST], game->window,
        game->clock_time, game->musics_and_sounds);
    display_score(game);
}