/*
** EPITECH PROJECT, 2020
** game_engine_charact
** File description:
** game_engine_charact
*/

#include "my_rpg.h"

static int character_gravity(obj_t *obj)
{
    if (obj->charact->act == 2)
        obj->charact->act = 0;
    else if (obj->charact->act == 3 || obj->charact->act == 4)
        return (0);
    for (int i = 0; i < obj->map->nb_platform; i++)
        if (sfIntRect_contains(&obj->map->ground[i],
        obj->charact->pos.x, obj->charact->pos.y) == 1) {
            obj->charact->pos.y = obj->map->ground[i].top + 1;
            return (0);
        }
    obj->charact->act = 2;
    obj->charact->pos.y += 40;
    return (0);
}

static void jump_handling(obj_t *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->charact->clock);

    if (time.microseconds < 500000) {
        obj->charact->pos.y -= 60 / ((time.microseconds / 50000) + 0.1);
    } else
        obj->charact->act = 2;
}

static void character_attack(obj_t *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->charact->clock);
    int sec = time.microseconds / 150000;

    if (obj->charact->act == 5 && sec > 5)
        obj->charact->act = 0;
    for (int i = 0; i < obj->map->nb_mob; i++) {
        time = sfClock_getElapsedTime(obj->map->mob[i].clock);
        sec = time.microseconds / 150000;
        if (obj->map->mob[i].act == 3 && sec > 8)
            obj->map->mob[i].act = 0;
    }
}

static void character_death(obj_t *obj)
{
    sfTime time = {0};
    int sec = 0;

    if (obj->charact->hp <= 0 && obj->charact->act != 6) {
        obj->charact->act = 6;
        sfClock_restart(obj->charact->clock);
    }
    time = sfClock_getElapsedTime(obj->charact->clock);
    sec = time.microseconds / 150000;
    if (obj->charact->act == 6 && sec > 15) {
        obj->charact->act = 0;
        obj->charact->pos.x = 200;
        obj->charact->pos.y = -1000;
        obj->charact->hp = 100;
        obj->map = &obj->map_list[0];
    }
}

void game_engine_charact(obj_t *obj)
{
    character_gravity(obj);
    character_attack(obj);
    character_death(obj);
    if (obj->charact->act == 3)
        jump_handling(obj);
}
