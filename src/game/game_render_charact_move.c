/*
** EPITECH PROJECT, 2020
** game_render_charact_move
** File description:
** game_render_charact_move
*/

#include "my_rpg.h"

static void display_run(obj_t *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->charact->clock);
    int sec = time.microseconds / 150000;
    sfVector2f pos = define_charact_pos(obj);
    int dir = 0;

    if (obj->charact->dir == -1) {
        dir = 64;
        pos.x -= 48;
    }
    pos.x -= 48;
    pos.y -= 64 + obj->charact->z;
    sfSprite_setTextureRect(obj->charact->spr_run,
                            (sfIntRect){sec % 8 * 96, dir, 96, 64});
    sfSprite_setPosition(obj->charact->spr_run, pos);
    sfRenderWindow_drawSprite(obj->win, obj->charact->spr_run, NULL);
}

static void display_jump(obj_t *obj, int fall)
{
    sfTime time = sfClock_getElapsedTime(obj->charact->clock);
    int sec = time.microseconds / 130000;
    sfVector2f pos = define_charact_pos(obj);
    int dir = 0;
    int dist = 432;

    if (obj->charact->dir == -1)
        dir = 64;
    pos.x -= 72;
    pos.y -= 64 + obj->charact->z;
    if (fall == 1) {
        fall = 2;
        dist = 1152;
        sec /= 2;
    } else
        fall = 14;
    sfSprite_setTextureRect(obj->charact->spr_jump,
                            (sfIntRect){sec % fall * 144 + dist, dir, 144, 64});
    sfSprite_setPosition(obj->charact->spr_jump, pos);
    sfRenderWindow_drawSprite(obj->win, obj->charact->spr_jump, NULL);
}

static void display_ladder(obj_t *obj)
{
    sfVector2f pos = define_charact_pos(obj);
    int nb = obj->charact->pos.y / 50;

    pos.x -= 32;
    pos.y -= 64;
    sfSprite_setTextureRect(obj->charact->spr_lad,
                            (sfIntRect){nb % 4 * 64, 0, 64, 64});
    sfSprite_setPosition(obj->charact->spr_lad, pos);
    sfRenderWindow_drawSprite(obj->win, obj->charact->spr_lad, NULL);
}

static void choose_jump_fall(obj_t *obj)
{
    if (obj->charact->act == 3)
        display_jump(obj, 0);
    if (obj->charact->act == 2)
        display_jump(obj, 1);
}

void game_render_charact_move(obj_t *obj)
{
    if (obj->charact->act == 1)
        display_run(obj);
    if (obj->charact->act == 3 || obj->charact->act == 2)
        choose_jump_fall(obj);
    if (obj->charact->act == 4)
        display_ladder(obj);
}
