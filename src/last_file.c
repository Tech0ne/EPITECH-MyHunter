/*
** EPITECH PROJECT, 2022
** last file
** File description:
** last file, for all functions that don't fit anywhere else
*/

#include "project.h"

bool float_rect_contains(sfFloatRect rct, float x, float y)
{
    if ((x > rct.left) && (x < (rct.left + rct.width)) &&
        (y > rct.top) && (y < (rct.top + rct.height)))
        return true;
    return false;
}

void check_shoot(linked_list_part *enemys, sfVector2f pos)
{
    enemy_t *enemy;
    linked_list_part *current = enemys;
    for (; current->prev; current = current->prev);
    for (; current->next; current = current->next) {
        if (!current->data) continue;
        enemy = (enemy_t *)current->data;
        sfSprite_setPosition(enemy->sprites_walk[enemy->index], enemy->pos);
        sfFloatRect rct = sfSprite_getLocalBounds(
                enemy->sprites_walk[enemy->index]);
        rct.left = enemy->pos.x;
        rct.top = enemy->pos.y;
        if (float_rect_contains(rct, pos.x, pos.y) && !enemy->is_dead) {
            enemy->is_dead = true;
            enemy->index = 0;
            sfClock_restart(enemy->clock);
            return;
        }
    }
}

sfSprite *create_sprite(char *filename, int x, int y)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {x, y};

    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);

    return sprite;
}

sfSprite **load_animation(char *path, int count, sfVector2f scale)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * count);
    char *full_path = malloc(sizeof(char) * (my_strlen(path) + 6));

    my_strcpy(full_path, path);
    my_strcat(full_path, "X.png");
    for (int i = 0; i < count; i++) {
        full_path[my_strlen(path)] = (char)(65 + i);
        sprites[i] = create_sprite(full_path, 0, 0);
        sfSprite_setScale(sprites[i], scale);
    }
    free(full_path);

    return sprites;
}

char **get_sprites_paths(void)
{
    char **paths = malloc(sizeof(char *) * 6);
    for (int i = 0; i < 6; i++) paths[i] = malloc(sizeof(char) * 33);

    my_strcpy(paths[0], "assets/enemies/enemy1_walk/walk_");
    my_strcpy(paths[1], "assets/enemies/enemy2_walk/walk_");

    my_strcpy(paths[2], "assets/enemies/enemy1_run/run_");
    my_strcpy(paths[3], "assets/enemies/enemy2_run/run_");

    my_strcpy(paths[4], "assets/enemies/enemy1_die/die_");
    my_strcpy(paths[5], "assets/enemies/enemy2_die/die_");

    return paths;
}
