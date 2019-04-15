/*
** EPITECH PROJECT, 2019
** workshop
** File description:
** workshop
*/

#ifndef MY_FUNCTION_H_
    #define MY_FUNCTION_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>

    #define TITLE "Commando Slug"
    #define FPS 60
    #define WINDOW_WIDTH 1600
    #define WINDOW_HEIGHT 900
    #define NB_BUTTON 11
    #define NB_BIG_BUTTON 6
    #define NB_SCENE 8
    #define NB_TOWER 4
    #define NB_ENEMY 2
    #define NB_MUSICS 2
    #define NB_SOUNDS 2
    #define NB_BACKGROUNDS 5
    #define NB_MUSICS_AND_SOUNDS 6
    #define NB_ENTITY_TYPE 10
    #define MY_SUCCESS 0
    #define MY_FAILURE 84
    #define MY_TRUE 1
    #define MY_FALSE 0

    #define ALLY_LIST 0
    #define ENEMY_LIST 1

    #define PATH_FONT "./assets/my_font.otf"
    #define PATH_ENTITIES "./assets/sprite/entities.png"
    #define PATH_MENU_BG "./assets/sprite/bg/background.png"
    #define PATH_SHOP_BG "./assets/sprite/bg/shop.png"
    #define PATH_WIN_BG "./assets/sprite/bg/victory.png"
    #define PATH_LOSE_BG "./assets/sprite/bg/defeat.png"
    #define PATH_HTP_BG "./assets/sprite/bg/howtoplay.png"
    #define PATH_SOLDIER "./assets/sprite/button/soldier_button.png"
    #define PATH_TURRET "./assets/sprite/button/turret_button.png"
    #define PATH_HELI "./assets/sprite/button/helicopter_button.png"
    #define PATH_TANK "./assets/sprite/button/tank_button.png"
    #define PATH_PLAY "./assets/sprite/button/play_button.png"
    #define PATH_SETTINGS "./assets/sprite/button/settings_button.png"
    #define PATH_EXIT "./assets/sprite/button/exit_button.png"
    #define PATH_HTP "./assets/sprite/button/how_to_play_button.png"
    #define PATH_BACK "./assets/sprite/button/back_button.png"
    #define PATH_RESUME "./assets/sprite/button/ok_button.png"
    #define PATH_MAIN_MENU "./assets/sprite/button/menu_button.png"
    #define PATH_MENU_MUSIC "./assets/music/menu_music.ogg"
    #define PATH_GAME_MUSIC "./assets/music/game_music.ogg"
    #define PATH_VICTORY_MUSIC "./assets/music/victory_fanfare.ogg"
    #define PATH_GAME_OVER_MUSIC "./assets/music/game_over.ogg"
    #define PATH_EXPLOS_SOUND "./assets/sounds/explosion_base.ogg"
    #define PATH_GUNSHOT_SOUND "./assets/sounds/gunshot.ogg"

    #define MENU_BUT_PATH PATH_PLAY, PATH_SETTINGS, PATH_EXIT, PATH_HTP
    #define PAUSE_BUT_PATH PATH_BACK, PATH_RESUME, PATH_MAIN_MENU
    #define ENTITY_BUT_PATH PATH_SOLDIER, PATH_TURRET, PATH_HELI, PATH_TANK
    #define ALL_BUT_PATHS MENU_BUT_PATH, PAUSE_BUT_PATH, ENTITY_BUT_PATH

    #define P_PLAY_BUT (sfVector2f){600, 200}
    #define P_SETTINGS_BUT (sfVector2f){600, 400}
    #define P_EXIT_BUT (sfVector2f){50, 750}
    #define P_BACK_BUT (sfVector2f){700, 600}
    #define P_RESUME_BUT (sfVector2f){600, 200}
    #define P_MENU_BUT (sfVector2f){600, 600}
    #define P_HTP_BUT (sfVector2f){0, 0}
    #define P_SOLD_BUT (sfVector2f){100, 25}
    #define P_TURR_BUT (sfVector2f){300, 25}
    #define P_HELI_BUT (sfVector2f){500, 25}
    #define P_TANK_BUT (sfVector2f){700, 25}
    #define POS_SCORE_TEXT (sfVector2f){100, 120}
    #define POS_SCORE_VALUE (sfVector2f){300, 120}

    #define SPAWN_ALLY_BASE (sfVector2f){0, 742}
    #define SPAWN_ALLY_WALK_SOLDIER (sfVector2f){0, 780}
    #define SPAWN_ALLY_TURRET (sfVector2f){200, 790}
    #define SPAWN_ALLY_HELICOPTER (sfVector2f){-100, 700}
    #define SPAWN_ALLY_TANK (sfVector2f){0, 780}

    #define SPAWN_ENEMY_BASE (sfVector2f){1505, 742}
    #define SPAWN_ENEMY_WALK_SOLDIER (sfVector2f){1600, 780}
    #define SPAWN_ENEMY_TURRET (sfVector2f){1400, 790}
    #define SPAWN_ENEMY_HELICOPTER (sfVector2f){1700, 700}
    #define SPAWN_ENEMY_TANK (sfVector2f){1600, 780}

    #define ENEMY_SCALE (sfVector2f){-1, 1}

    #define SPEED_WALK_SOLDIER 2.7
    #define SPEED_HELICOPTER 4.2
    #define SPEED_TANK 3.14

    #define POS_MENU_BUT P_PLAY_BUT, P_SETTINGS_BUT, P_EXIT_BUT, P_HTP_BUT
    #define POS_PAUSE_BUT P_BACK_BUT, P_RESUME_BUT, P_MENU_BUT
    #define POS_ENT_BUT P_SOLD_BUT, P_TURR_BUT, P_HELI_BUT, P_TANK_BUT
    #define POS_ALL_BUT POS_MENU_BUT, POS_PAUSE_BUT, POS_ENT_BUT

    #define WIDTH_BG 1600
    #define HEIGHT_BG 900

    #define HEIGHT_BIG_BUTTON 400
    #define WIDTH_BIG_BUTTON 200
    #define HEIGHT_SMALL_BUTTON 100
    #define WIDTH_SMALL_BUTTON 100
    #define SIZE_BIG_BUTTON (sfVector2f){400, 200}
    #define SIZE_SMALL_BUTTON (sfVector2f){100, 100}

    #define LEFT_ALLY 0

    #define HEIGHT_BASE 97
    #define LEFT_ENEMY_BASE 96
    #define TOP_BASE 0
    #define WIDTH_BASE 95
    #define NB_SPRITE_BASE 1

    #define HEIGHT_WALK_SOLDIER 57
    #define LEFT_WALK_ENEMY_SOLDIER 113
    #define TOP_WALK_SOLDIER 98
    #define WIDTH_WALK_SOLDIER 55
    #define NB_WALK_SOLDIER 2

    #define HEIGHT_DEATH_SOLDIER 56
    #define LEFT_DEATH_ENEMY_SOLDIER 250
    #define TOP_DEATH_SOLDIER 154
    #define WIDTH_DEATH_SOLDIER 56
    #define NB_DEATH_SOLDIER 4

    #define HEIGHT_TURRET 54
    #define LEFT_ENEMY_TURRET 96
    #define TOP_TURRET 210
    #define WIDTH_TURRET 95
    #define NB_TURRET 3

    #define HEIGHT_HELICOPTER 46
    #define LEFT_ENEMY_HELICOPTER 92
    #define TOP_HELICOPTER 372
    #define WIDTH_HELICOPTER 92
    #define NB_HELICOPTER 2

    #define HEIGHT_TANK 57
    #define LEFT_ENEMY_TANK 76
    #define TOP_TANK 465
    #define WIDTH_TANK 76
    #define NB_TANK 2

    #define OVER_BUTTON &rect,game->position_mouse.x, game->position_mouse.y
#endif
