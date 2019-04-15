/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** gameloop.c
*/

#include "my_defender.h"

void add_bases(game_t *game)
{
    if (count_entity_type(game->list[ALLY_LIST], 'b') == 0)
        add_entity(game->list[ALLY_LIST], 'b', 'a');
    if (count_entity_type(game->list[ENEMY_LIST], 'b') == 0)
        add_entity(game->list[ENEMY_LIST], 'b', 'e');
}

static int create_game_structure(game_t *game)
{
    button_t *button = malloc(sizeof(button_t) * NB_BUTTON);
    background_t *backgrounds = malloc(sizeof(background_t) * NB_BACKGROUNDS);
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

    game->window = sfRenderWindow_create(mode, TITLE, sfTitlebar | sfClose,
        NULL);
    game->list = malloc(sizeof(head_t *) * 2);
    if (!game->list || !game->window || !button || !backgrounds)
        return (MY_FAILURE);
    game->list[ALLY_LIST] = init_list();
    game->list[ENEMY_LIST] = init_list();
    game->button = button;
    game->backgrounds = backgrounds;
    game->clock = sfClock_create();
    game->scene = MENU_SCENE;
    game->spawn_time = 0;
    game->clock_time = 0;
    sfRenderWindow_setFramerateLimit(game->window, FPS);
    return (MY_SUCCESS);
}

static void manage_event(game_t *game)
{
    const scene_t scene[NB_SCENE] = {{&menu_event, MENU_SCENE},
        {&game_event, GAME_SCENE}, {&how_to_play_event, HTP_SCENE},
        {&game_over_event, GAME_OVER_SCENE},{&pause_event, PAUSE_SCENE},
        {&shop_event, SHOP_SCENE}, {&settings_event, SETTINGS_SCENE},
        {&victory_event, VICTORY_SCENE}};

    if (game->scene == -1)
        return (sfRenderWindow_close(game->window));
    for (int i = 0; i < NB_SCENE; i++) {
        if (scene[i].index == game->scene)
            scene[i].ptr(game);
    }
}

static void manage_display(game_t *game)
{
    const scene_t scene[NB_SCENE] = {{&display_menu, MENU_SCENE},
        {&display_game, GAME_SCENE}, {&display_how_to_play, HTP_SCENE},
        {&display_game_over, GAME_OVER_SCENE}, {&display_pause, PAUSE_SCENE},
        {&display_shop, SHOP_SCENE}, {&display_settings, SETTINGS_SCENE},
        {&display_victory, VICTORY_SCENE}};

    if (game->scene == -1)
        return (sfRenderWindow_close(game->window));
    for (int i = 0; i != NB_SCENE; i++) {
        if (scene[i].index == game->scene)
            scene[i].ptr(game);
    }
    sfRenderWindow_display(game->window);
}

int my_game(int first_scene)
{
    game_t game;

    if (create_game_structure(&game) || init_button(&game) ||
        init_backgrounds(&game) || init_musics_and_sounds(&game) ||
        init_text(&game))
        return (MY_FAILURE);
    add_bases(&game);
    if (first_scene == HTP_SCENE)
        game.scene = first_scene;
    while (sfRenderWindow_isOpen(game.window)) {
        manage_event(&game);
        manage_display(&game);
        game.clock_time = sfClock_restart(game.clock).microseconds /
            1000000.0;
        game.spawn_time += game.clock_time;
    }
    free_csfml(&game);
    free_structure(&game);
    return (MY_SUCCESS);
}