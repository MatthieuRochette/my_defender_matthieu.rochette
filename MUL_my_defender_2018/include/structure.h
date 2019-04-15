/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** structure
*/

#ifndef STRUCTURE_H
    #define STRUCTURE_H

typedef struct s_entity {
    struct s_entity *next;
    sfVector2f pos_scale[2];
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    float seconds;
    int life;
    char enemy;
    char type;
} entity_t;

typedef struct s_head {
    entity_t *first;
    entity_t *act;
    entity_t *last;
} head_t;

typedef struct s_background {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
} background_t;

typedef struct s_button {
    sfRectangleShape *rect_shape;
    sfTexture *texture;
    sfSprite *sprite;
    sfFloatRect rect;
    sfVector2f pos_scale[2];
    float cooldown;
} button_t;

typedef struct s_game {
    head_t **list;
    background_t *backgrounds;
    button_t *button;
    sfMusic **musics_and_sounds;
    sfRenderWindow *window;
    sfClock *clock;
    sfFont *font;
    sfText *text;
    sfVector2i position_mouse;
    sfTime time;
    float spawn_time;
    float clock_time;
    int score;
    char scene;
} game_t;

typedef struct s_scene {
    void(*ptr)(game_t*);
    int index;
} scene_t;

enum scenes {
    MENU_SCENE,
    SETTINGS_SCENE,
    HTP_SCENE,
    PAUSE_SCENE,
    GAME_SCENE,
    SHOP_SCENE,
    GAME_OVER_SCENE,
    VICTORY_SCENE
};

enum buttons {
    PLAY_BUTTON,
    SETTINGS_BUTTON,
    EXIT_BUTTON,
    HTP_BUTTON,
    BACK_BUTTON,
    RESUME_BUTTON,
    MAIN_MENU_BUTTON,
    SOLDIER_BUTTON,
    TURRET_BUTTON,
    HELI_BUTTON,
    ARMY_TANK_BUTTON
};

enum musics_and_sounds {
    MENU_MUSIC,
    GAME_MUSIC,
    GAME_OVER_MUSIC,
    VICTORY_MUSIC,
    EXPLOS_SOUND,
    GUNSHOT_SOUND
};

enum backgrounds {
    GAME_BG,
    SHOP_BG,
    WIN_BG,
    GAME_OVER_BG,
    HTP_BG
};

#endif