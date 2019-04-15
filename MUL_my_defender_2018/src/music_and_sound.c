/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** music_and_sound.c
*/

#include "my_defender.h"

void play_soundfx(char type, sfMusic **sounds)
{
    int index = GUNSHOT_SOUND;

    if (type == 'b')
        index = EXPLOS_SOUND;
    sfMusic_setLoop(sounds[index], sfFalse);
    sfMusic_play(sounds[index]);
}

int init_musics_and_sounds(game_t *game)
{
    const char *musics_and_sounds[NB_MUSICS_AND_SOUNDS] = {PATH_MENU_MUSIC,
        PATH_GAME_MUSIC, PATH_GAME_OVER_MUSIC, PATH_VICTORY_MUSIC,
        PATH_EXPLOS_SOUND, PATH_GUNSHOT_SOUND};

    game->musics_and_sounds = malloc(sizeof(sfMusic*) * NB_MUSICS_AND_SOUNDS);
    if (!game->musics_and_sounds)
        return (MY_FAILURE);
    for (int i = 0; i < NB_MUSICS_AND_SOUNDS; i++) {
        game->musics_and_sounds[i] =
            sfMusic_createFromFile(musics_and_sounds[i]);
        if (!game->musics_and_sounds[i])
            return (MY_FAILURE);
        sfMusic_setLoop(game->musics_and_sounds[i], sfTrue);
    }
    return (MY_SUCCESS);
}

void switch_music(game_t *game, int actual, int new)
{
    if (sfMusic_getStatus(game->musics_and_sounds[actual]) == sfPlaying)
        sfMusic_stop(game->musics_and_sounds[actual]);
    if (sfMusic_getStatus(game->musics_and_sounds[new]) != sfPlaying)
        sfMusic_play(game->musics_and_sounds[new]);
}