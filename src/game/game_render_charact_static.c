/*
** EPITECH PROJECT, 2020
** game_render_charact_static
** File description:
** game_render_charact_static
*/

#include "my_rpg.h"

static void display_idle(obj_t *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->charact->clock);
    int sec = time.microseconds / 150000;
    sfVector2f pos = define_charact_pos(obj);
    int dir = 0;

    if (obj->charact->dir == -1)
        dir = 64;
    pos.x -= 32;
    pos.y -= 64 + obj->charact->z;
    sfSprite_setTextureRect(obj->charact->spr_idle,
                            (sfIntRect){sec % 15 * 64, dir, 64, 64});
    sfSprite_setPosition(obj->charact->spr_idle, pos);
    sfRenderWindow_drawSprite(obj->win, obj->charact->spr_idle, NULL);
}

static void display_attack(obj_t *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->charact->clock);
    int sec = time.microseconds / 130000;
    sfVector2f pos = define_charact_pos(obj);
    int dir = 0;

    if (obj->charact->dir == -1) {
        dir = 64;
        pos.x += 10;
    }
    pos.x -= 72;
    pos.y -= 64 + obj->charact->z;
    sfSprite_setTextureRect(obj->charact->spr_att,
                            (sfIntRect){sec % 6 * 144 + 1038, dir, 144, 64});
    sfSprite_setPosition(obj->charact->spr_att, pos);
    sfRenderWindow_drawSprite(obj->win, obj->charact->spr_att, NULL);
}

static void display_dead(obj_t *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->charact->clock);
    int sec = time.microseconds / 150000;
    sfVector2f pos = define_charact_pos(obj);
    int dir = 0;

    if (obj->charact->dir == -1)
        dir = 64;
    pos.x -= 48;
    pos.y -= 64 + obj->charact->z;
    sfSprite_setTextureRect(obj->charact->spr_dead,
                            (sfIntRect){sec % 15 * 96, dir, 96, 64});
    sfSprite_setPosition(obj->charact->spr_dead, pos);
    sfRenderWindow_drawSprite(obj->win, obj->charact->spr_dead, NULL);
}

static void display_life_bar(obj_t *obj)
{
    sfVector2f pos = {192, 77};
    int nb = obj->charact->hp * 2.6;

    if (nb < 0)
        nb = 0;
    sfRenderWindow_drawSprite(obj->win, obj->charact->spr_lb, NULL);
    sfSprite_setTextureRect(obj->charact->spr_hp,
                            (sfIntRect){0, 0, nb, 50});
    sfSprite_setPosition(obj->charact->spr_hp, pos);
    sfRenderWindow_drawSprite(obj->win, obj->charact->spr_hp, NULL);
}

void game_render_charact_static(obj_t *obj)
{
    if (obj->charact->act == 0)
        display_idle(obj);
    if (obj->charact->act == 5)
        display_attack(obj);
    if (obj->charact->act == 6)
        display_dead(obj);
    display_life_bar(obj);
}
