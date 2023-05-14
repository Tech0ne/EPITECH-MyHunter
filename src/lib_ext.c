/*
** EPITECH PROJECT, 2022
** lib ext
** File description:
** lib extension file
*/

#include "project.h"


void change_mouse_pos_on_time(sfRenderWindow *window, sfSprite *cursor)
{
    sfVector2i mouse_pos_i = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_f = {mouse_pos_i.x - 33, mouse_pos_i.y - 33};

    sfSprite_setPosition(cursor, mouse_pos_f);
    sfRenderWindow_drawSprite(window, cursor, NULL);
}

void lock_mouse(sfRenderWindow *window)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setMouseCursorGrabbed(window, sfTrue);
}

void clock_loop(sfClock *clock, long long *min_spawn_rate, assets_t *assets)
{
    if (sfClock_getElapsedTime(clock).microseconds >= *min_spawn_rate && !(
        rand() % 10)) {
        *min_spawn_rate -= 10000;
        if (*min_spawn_rate <= 0)
            *min_spawn_rate = 100000;
        generate_enemy(assets->enemys);
        sfClock_restart(clock);
    }
}

void analyse_events(sfRenderWindow *window, assets_t *assets)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
                event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            sfVector2f pos = {event.mouseButton.x, event.mouseButton.y};
            check_shoot(assets->enemys, pos);
            sfSound_play(assets->shoot);
        }
    }
}

void destroy_enemy(enemy_t *enemy)
{
    for (int i = 0; i < enemy->sprites_walk_count; i++)
        sfSprite_destroy(enemy->sprites_walk[i]);
    for (int i = 0; i < enemy->sprites_die_count; i++)
        sfSprite_destroy(enemy->sprites_die[i]);
    free(enemy->sprites_walk);
    free(enemy->sprites_die);
    free(enemy);
}
