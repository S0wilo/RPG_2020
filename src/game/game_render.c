/*
** EPITECH PROJECT, 2020
** game_render
** File description:
** game_render
*/

#include "my_rpg.h"

static int define_one_pos(int charact, int min, int max)
{
    if (charact <= min)
        return (0);
    return (max * -1);
}

sfVector2f define_map_pos(obj_t *obj)
{
    sfVector2f pos = {0};

    if (obj->charact->pos.x > 960 && obj->charact->pos.x<obj->map->dim.x - 960)
        pos.x = (obj->charact->pos.x - 960) * -1;
    else
        pos.x = define_one_pos(obj->charact->pos.x, 960, obj->map->dim.x-1920);
    if (obj->charact->pos.y > 540 && obj->charact->pos.y < obj->map->dim.y-540)
        pos.y = (obj->charact->pos.y - 540) * -1;
    else
        pos.y = define_one_pos(obj->charact->pos.y, 540,
        obj->map->dim.y - 1080);
    return (pos);
}

static void display_bg(obj_t *obj, sfVector2f pos)
{
    pos.x /= 2;
    pos.y /= 2;
    sfSprite_setPosition(obj->map->spr_bg, pos);
    sfRenderWindow_drawSprite(obj->win, obj->map->spr_bg, NULL);
}

static void display_map(obj_t *obj)
{
    sfVector2f pos = define_map_pos(obj);

    if (obj->map->spr_bg != NULL)
        display_bg(obj, pos);
    sfSprite_setPosition(obj->map->spr, pos);
    sfRenderWindow_drawSprite(obj->win, obj->map->spr, NULL);
    if (obj->map == &obj->map_list[3] && obj->charact->key == 0) {
        pos.y += 1200;
        pos.x += 200;
        sfSprite_setPosition(obj->mob->spr_key, pos);
        sfRenderWindow_drawSprite(obj->win, obj->mob->spr_key, NULL);
    }
}

void game_render(obj_t *obj)
{
    display_map(obj);
    for (int i = 0; i < obj->map->nb_mob; i++)
        if (obj->map->mob[i].z > obj->charact->z)
            game_render_mob(obj, &obj->map->mob[i]);
    game_render_charact(obj);
    for (int i = 0; i < obj->map->nb_mob; i++)
        if (obj->map->mob[i].z <= obj->charact->z)
            game_render_mob(obj, &obj->map->mob[i]);
    sfRenderWindow_display(obj->win);
}
