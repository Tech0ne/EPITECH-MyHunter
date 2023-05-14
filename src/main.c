/*
** EPITECH PROJECT, 2022
** main file
** File description:
** main myhunter file
*/

#include "project.h"

int main(int argc, char **argv)
{
    if (argc >= 2 && my_strcmp(argv[1], "-h") == 0) return help_banner();
    srand(time(NULL));
    sfRenderWindow *window = generate_window();
    assets_t *assets = generate_assets(window);
    if (!menu_waiter(assets))
        return 0;
    lock_mouse(window); long long min_spawn_rate = 2000000;
    sfClock *spawn_clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, assets->bg, NULL);
        clock_loop(spawn_clock, &min_spawn_rate, assets);
        enemy_loop(assets);
        change_mouse_pos_on_time(window, assets->cursor);
        sfRenderWindow_display(window);
        analyse_events(window, assets);
        sfRenderWindow_clear(window, sfBlack);
    }
    delet_assets(assets);
    return 0;
}
