/*
** EPITECH PROJECT, 2020
** game_render_charact
** File description:
** game_render_charact
*/

#include "my_rpg.h"

static int define_one_pos(int charact, int min, int max, int size)
{
    if (charact <= min)
        return (charact);
    return (size - (max - charact));
}

sfVector2f define_charact_pos(obj_t *obj)
{
    sfVector2f pos = {0};

    if (obj->charact->pos.x > 960 &&
    obj->charact->pos.x < obj->map->dim.x - 960)
        pos.x = 960;
    else
        pos.x = define_one_pos(obj->charact->pos.x, 960,
        obj->map->dim.x, 1920);
    if (obj->charact->pos.y > 540 &&
    obj->charact->pos.y < obj->map->dim.y - 540)
        pos.y = 540;
    else
        pos.y = define_one_pos(obj->charact->pos.y, 540, obj->map->dim.y, 1080);
    return (pos);
}

void game_render_charact(obj_t *obj)
{
    game_render_charact_move(obj);
    game_render_charact_static(obj);
}
