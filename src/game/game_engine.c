/*
** EPITECH PROJECT, 2020
** game_engine
** File description:
** game_engine
*/

#include "my_rpg.h"

static int change_map(obj_t *obj)
{
    for (int i = 0; i < obj->map->nb_door; i++)
        if (sfIntRect_contains(&obj->map->door[i],
        obj->charact->pos.x, obj->charact->pos.y) == 1) {
            obj->charact->pos.x = obj->map->door_pos[i].x;
            obj->charact->pos.y = obj->map->door_pos[i].y;
            obj->map = obj->map->door_map[i];
            return (0);
        }
    return (0);
}

static void mob_death(obj_t *obj, mob_t *mob)
{
    if (mob->hp <= 0 && mob->act != 5) {
        mob->act = 5;
        obj->charact->xp += 1;
        sfClock_restart(mob->clock);
    }
}

void game_engine(obj_t *obj)
{
    if (obj->charact->act == 1)
        obj->charact->act = 0;
    game_engine_charact(obj);
    for (int i = 0; i < obj->map->nb_mob; i++) {
        game_engine_mob(obj, &obj->map->mob[i]);
        mob_death(obj, &obj->map->mob[i]);
    }
    change_map(obj);
}
