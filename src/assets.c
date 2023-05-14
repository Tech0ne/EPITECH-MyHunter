/*
** EPITECH PROJECT, 2022
** assets
** File description:
** assets file
*/

#include "project.h"

assets_t *generate_assets(sfRenderWindow *window)
{
    assets_t *assets = malloc(sizeof(assets_t));
    assets->window = window;
    assets->bg = create_sprite("assets/bg.png", 0, 0);
    assets->menu_bg = create_sprite("assets/menu_bg.png", 0, -100);
    assets->cursor = create_sprite("assets/crosshair.png", 0, 0);
    assets->music = generate_music("assets/music.wav");
    assets->buffer = sfSoundBuffer_createFromFile("assets/shoot.wav");
    assets->shoot = generate_sound(assets->buffer);
    sfVector2f scale = {6, 5.6};
    sfSprite_setScale(assets->bg, scale);
    sfVector2f menu_scale = {2.5, 2.5};
    sfSprite_setScale(assets->menu_bg, menu_scale);
    assets->enemys = ll_create(NULL);
    generate_enemy(assets->enemys);
    generate_enemy(assets->enemys);
    return assets;
}

void delet_assets(assets_t *assets)
{
    sfSprite_destroy(assets->bg);
    sfSprite_destroy(assets->cursor);
    sfMusic_destroy(assets->music);
    sfSoundBuffer_destroy(assets->buffer);
    sfSound_destroy(assets->shoot);

    linked_list_part *current = assets->enemys;
    for (; current->prev; current = current->prev);
    for (; current->next; current = current->next)
        if (current->data != NULL)
            destroy_enemy((enemy_t *)current->data);
    ll_destroy(current, 1);
}

int help_banner(void)
{
    my_putstr("usage : ./my_hunter\n");
    my_putstr("\tSimple CSFML Duck Hunt game\n");
    my_putstr("\tremade on a more apocaliptic way\n\n");
    my_putstr("\tEnjoy your play !\n");

    return 0;
}
