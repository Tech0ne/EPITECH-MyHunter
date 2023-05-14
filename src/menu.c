/*
** EPITECH PROJECT, 2022
** menu
** File description:
** main menu file
*/

#include "project.h"

sfText *create_text(char *text, int x, int y)
{
    sfVector2f pos = {x, y};
    sfFont *font;
    font = sfFont_createFromFile("assets/font.ttf");

    sfText *t = sfText_create();

    sfText_setString(t, text);
    sfText_setColor(t, sfWhite);
    sfText_setFont(t, font);
    sfText_setCharacterSize(t, 52);

    float p = sfText_getGlobalBounds(t).width / 2.0;
    pos.x -= p;
    sfText_setPosition(t, pos);

    return t;
}

void display_menu(assets_t *assets, sfText *title,
    sfText *button_1, sfText *button_2)
{
    sfRenderWindow_drawSprite(assets->window, assets->menu_bg, NULL);
    sfRenderWindow_drawText(assets->window, title, NULL);
    sfRenderWindow_drawText(assets->window, button_1, NULL);
    sfRenderWindow_drawText(assets->window, button_2, NULL);

    sfRenderWindow_display(assets->window);
    sfRenderWindow_clear(assets->window, sfBlack);
}

bool menu_check_position(assets_t *assets,
    sfText *play, sfText *quit, bool *ret)
{
    sfVector2i mouse_pos_i = sfMouse_getPositionRenderWindow(assets->window);
    sfVector2f mouse_pos_f = {mouse_pos_i.x - 0, mouse_pos_i.y - 0};
    if (float_rect_contains(sfText_getGlobalBounds(play),
        mouse_pos_f.x, mouse_pos_f.y)) {
        *ret = true;
        return false;
    }
    if (float_rect_contains(sfText_getGlobalBounds(quit),
        mouse_pos_f.x, mouse_pos_f.y)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            return *ret = false;
        }
        sfVector2f pos = {sfText_getGlobalBounds(quit).left,
            (sfText_getGlobalBounds(quit).top < 700) ? 800 : 600};
        sfText_setPosition(quit, pos);
        return *ret = true;
    }
    return *ret = true;
}

void mouse_check_pos(assets_t *assets, sfText *button_1, sfText *button_2)
{
    sfVector2i mouse_pos_i = sfMouse_getPositionRenderWindow(assets->window);
    sfVector2f mouse_pos_f = {mouse_pos_i.x - 0, mouse_pos_i.y - 0};

    if (float_rect_contains(sfText_getGlobalBounds(button_1),
        mouse_pos_f.x, mouse_pos_f.y))
        sfText_setColor(button_1, sfRed);
    else
        sfText_setColor(button_1, sfWhite);
    if (float_rect_contains(sfText_getGlobalBounds(button_2),
        mouse_pos_f.x, mouse_pos_f.y))
        sfText_setColor(button_2, sfRed);
    else
        sfText_setColor(button_2, sfWhite);
}

bool menu_waiter(assets_t *assets)
{
    sfEvent event; bool is_active = true; bool ret = true;
    unsigned size = sfRenderWindow_getSize(assets->window).x;
    sfText *title = create_text("Z hunter", size / 2, 150);
    sfText *button_1 = create_text("Play Z hunter", size / 2, 400);
    sfText *button_2 = create_text("Quit the game", size / 2, 600);
    while (is_active) {
        while (sfRenderWindow_pollEvent(assets->window, &event))
            is_active = (event.type == sfEvtMouseButtonPressed) ?
                menu_check_position(assets, button_1, button_2, &ret) :
                is_active;
        mouse_check_pos(assets, button_1, button_2);
        display_menu(assets, title, button_1, button_2);
    }
    sfText_destroy(title); sfText_destroy(button_1); sfText_destroy(button_2);
    if (!ret) {
        sfRenderWindow_close(assets->window);
        delet_assets(assets);
    }
    return ret;
}
