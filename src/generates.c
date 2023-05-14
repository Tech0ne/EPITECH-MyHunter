/*
** EPITECH PROJECT, 2022
** generates
** File description:
** generates file
*/

#include "project.h"

sfMusic *generate_music(char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);

    return music;
}

sfSound *generate_sound(sfSoundBuffer *buffer)
{
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buffer);

    return sound;
}

animation_loader_t *generate_animation_loader(int sprite_count,
    char *base_sprite_path)
{
    animation_loader_t *anim_loader = malloc(sizeof(animation_loader_t));

    anim_loader->sprites_count = sprite_count;
    anim_loader->base_sprites_path = base_sprite_path;

    return anim_loader;
}

enemy_sub_values_t *generate_sub_values(sfVector2f pos, sfVector2f move,
    int time_to_wait, int time_to_wait_die)
{
    enemy_sub_values_t *esv = malloc(sizeof(enemy_sub_values_t));
    esv->pos = pos;
    esv->move = move;
    esv->time_to_wait = time_to_wait;
    esv->time_to_wait_die = time_to_wait_die;

    return esv;
}

sfRenderWindow *generate_window(void)
{
    sfVideoMode video_mode = {1920, 1080, 32};

    sfRenderWindow *window = sfRenderWindow_create(video_mode, "Z Hunter",
        sfClose | sfFullscreen, NULL);
    return window;
}
