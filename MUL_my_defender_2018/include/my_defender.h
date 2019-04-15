/*
** EPITECH PROJECT, 2019
** workshop
** File description:
** workshop
*/

#ifndef FUNCTION_H
    #define FUNCTION_H
    #include "macro.h"
    #include "structure.h"

void menu_event(game_t *);
void game_event(game_t *);
void how_to_play_event(game_t *);
void shop_event(game_t *);
void game_over_event(game_t *);
void pause_event(game_t *);
void settings_event(game_t *);
void victory_event(game_t *);
int my_game(int);
int init_tower(game_t *);
int init_button(game_t *);
void manage_music(game_t *);
void display_menu(game_t *);
void display_game(game_t *);
void display_how_to_play(game_t *);
void display_shop(game_t *);
void display_pause(game_t *);
void display_game_over(game_t *);
void display_settings(game_t *);
void display_victory(game_t *);
int create_button(button_t *, const char *, sfVector2f, char);
void manage_button(game_t *, button_t *, int, sfEvent);
void manage_exit(game_t *, sfEvent);
int init_backgrounds(game_t *);
int init_musics_and_sounds(game_t *);
int char_found(char *, char);
void display_list(head_t *);
head_t *init_list(void);
int add_entity(head_t *, char, char);
void free_csfml(game_t *);
void free_structure(game_t *);
sfIntRect get_entity_rect(char, char);
sfIntRect create_rect(int, int, int, int);
sfVector2f get_spawn(char, char);
void free_list(head_t *);
void manage_entity_button(game_t *, button_t *, char, sfEvent);
void switch_music(game_t *, int, int);
int count_entity_type(head_t *, char);
void del_elem(head_t *, entity_t *);
entity_t *get_previous_elem(head_t *, entity_t *);
int fill_new_elem(entity_t *, char, char);
void manage_key(game_t *, int, sfEvent, char);
int get_number_image(char);
void anim_entities(entity_t *);
sfIntRect modify_rect(entity_t *, int, int);
void animate_turret(entity_t *);
void update(entity_t *);
int get_left_type(char, char);
int get_life(char);
int length_nb(int);
char *my_itoa(unsigned int);
int init_text(game_t *);
void display_score(game_t *);
void check_collision(game_t *, head_t *, head_t *);
void check_end(game_t *);
void add_bases(game_t *);
void reset_game(game_t *);
void do_cooldown(game_t *game);
void play_soundfx(char, sfMusic **);

#endif