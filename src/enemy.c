/*
** EPITECH PROJECT, 2022
** enemy
** File description:
** enemy file
*/

#include "project.h"

bool enemy_display(enemy_t *enemy, assets_t *assets)
{
    if (!enemy->is_dead) enemy->index %= enemy->sprites_walk_count;
    enemy->pos.x += (enemy->is_dead) ? 0 : enemy->move.x;
    enemy->pos.y += (enemy->is_dead) ? 0 : enemy->move.y;
    sfSprite_setPosition((enemy->is_dead) ?
        enemy->sprites_die[enemy->index] :
        enemy->sprites_walk[enemy->index], enemy->pos);

    sfRenderWindow_drawSprite(assets->window, (enemy->is_dead) ?
        enemy->sprites_die[enemy->index] :
        enemy->sprites_walk[enemy->index], NULL);

    if ((enemy->is_dead && sfClock_getElapsedTime(enemy->clock).microseconds
        >= 1000000) || enemy->pos.x >= 2000) {
        destroy_enemy(enemy);
        return false;
    } else {
        return true;
    }
}

void enemy_loop(assets_t *assets)
{
    linked_list_part *current = assets->enemys;
    while (current->next) {
        if (!current || !current->data) {
            current = current->next;
            continue;
        }
        enemy_t *enemy = (enemy_t *)current->data;
        bool is_over_ttw = (bool)(
            sfClock_getElapsedTime(enemy->clock).microseconds >= ((enemy
            ->is_dead) ? enemy->time_to_wait_die : enemy->time_to_wait));
        if ((enemy->is_dead && is_over_ttw && enemy->index < enemy->
            sprites_die_count - 1) || (!enemy->is_dead && is_over_ttw)) {
            enemy->index += 1; sfClock_restart(enemy->clock);
        }
        bool out = enemy_display(enemy, assets);
        current = current->next;
        if (!out) ll_remove(current->prev);
    }
    if (current->data && ((enemy_t *)current->data)->is_dead)
        ll_remove(current);
}

void generate_enemy(linked_list_part *enemys)
{
    sfVector2f pos = {-100, 650 + (rand() % 300)};
    bool run = !(bool)(rand() % 7);
    sfVector2f move = {!run ? 0.01 : 0.1, 0};
    int z_type = rand() % 2;
    char **paths = get_sprites_paths();
    int animations[] = {8, 7, 7, 7, 5, 5};
    enemy_t *enemy = load_enemy(generate_animation_loader(
        (run) ? animations[z_type + 2] : animations[z_type],
        (run) ? paths[z_type + 2] : paths[z_type]),
        generate_animation_loader(
        animations[z_type + 4],
        paths[z_type + 4]
        ),
        generate_sub_values(pos, move, run ? 90000 : 130000, 200000));

    ll_append(enemys, ll_create(enemy), true);
    for (int i = 0; i < 6; i++) free(paths[i]);
    free(paths);
}

enemy_t *basic_setup_enemy(enemy_sub_values_t *esv)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy->index = 0;

    enemy->is_dead = false;
    enemy->pos = esv->pos;
    enemy->move = esv->move;
    enemy->time_to_wait = esv->time_to_wait;
    enemy->time_to_wait_die = esv->time_to_wait_die;
    enemy->clock = sfClock_create();
    sfClock_restart(enemy->clock);
    free(esv);

    return enemy;
}

enemy_t *load_enemy(animation_loader_t *walk_animation,
        animation_loader_t *die_animation, enemy_sub_values_t *esv)
{
    enemy_t *enemy = basic_setup_enemy(esv);
    enemy->sprites_walk_count = walk_animation->sprites_count;
    enemy->sprites_die_count = die_animation->sprites_count;

    sfVector2f scale = {2, 2};

    enemy->sprites_walk = load_animation(walk_animation->base_sprites_path,
        walk_animation->sprites_count, scale);
    enemy->sprites_die = load_animation(die_animation->base_sprites_path,
        die_animation->sprites_count, scale);

    free(walk_animation);
    free(die_animation);

    return enemy;
}
