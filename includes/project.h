/*
** EPITECH PROJECT, 2022
** Project includes
** File description:
** includes
*/

#ifndef INCLUDED_PROJECT_H
    #define INCLUDED_PROJECT_H

    #include "lib/includes.h"
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Music.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    #define true 1
    #define false 0

    #define bool unsigned char

typedef struct enemy {
    int index;
    int sprites_walk_count;
    sfSprite **sprites_walk;
    int sprites_die_count;
    sfSprite **sprites_die;
    bool is_dead;
    sfVector2f pos;
    sfVector2f move;
    long long time_to_wait;
    long long time_to_wait_die;
    sfClock *clock;
} enemy_t;

typedef struct animation_loader {
    int sprites_count;
    char *base_sprites_path;
} animation_loader_t;

typedef struct enemy_sub_values {
    sfVector2f pos;
    sfVector2f move;
    int time_to_wait;
    int time_to_wait_die;
} enemy_sub_values_t;

typedef struct assets {
    sfRenderWindow *window;
    sfSprite *bg;
    sfSprite *menu_bg;
    sfSprite *cursor;
    sfMusic *music;
    sfSoundBuffer *buffer;
    sfSound *shoot;
    sfVector2f bg_scale;
    sfClock *spawn_clock;
    linked_list_part *enemys;
} assets_t;

assets_t *generate_assets(sfRenderWindow *window);
void delet_assets(assets_t *assets);
bool enemy_display(enemy_t *enemy, assets_t *assets);
void enemy_loop(assets_t *assets);
void generate_enemy(linked_list_part *enemys);
enemy_t *basic_setup_enemy(enemy_sub_values_t *esv);
enemy_t *load_enemy(animation_loader_t *walk_animation,
    animation_loader_t *die_animation, enemy_sub_values_t *esv);
sfMusic *generate_music(char *path);
sfSound *generate_sound(sfSoundBuffer *buffer);
animation_loader_t *generate_animation_loader(int sprite_count,
    char *base_sprite_path);
enemy_sub_values_t *generate_sub_values(sfVector2f pos, sfVector2f move,
    int time_to_wait, int time_to_wait_die);
sfRenderWindow *generate_window(void);
void change_mouse_pos_on_time(sfRenderWindow *window, sfSprite *cursor);
void lock_mouse(sfRenderWindow *window);
void clock_loop(sfClock *clock, long long *min_spawn_rate, assets_t *assets);
void analyse_events(sfRenderWindow *window, assets_t *assets);
void destroy_enemy(enemy_t *enemy);
sfText *create_text(char *text, int x, int y);
void display_menu(assets_t *assets, sfText *title,
    sfText *button_1, sfText *button_2);
bool menu_check_position(assets_t *assets,
    sfText *play, sfText *quit, bool *ret);
void mouse_check_pos(assets_t *assets, sfText *button_1, sfText *button_2);
bool menu_waiter(assets_t *assets);
bool float_rect_contains(sfFloatRect rct, float x, float y);
void check_shoot(linked_list_part *enemys, sfVector2f pos);
sfSprite *create_sprite(char *filename, int x, int y);
sfSprite **load_animation(char *path, int count, sfVector2f scale);
char **get_sprites_paths(void);
int help_banner(void);

#endif
