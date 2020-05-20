/*
** EPITECH PROJECT, 2020
** game_engine_mob
** File description:
** game_engine_mob
*/

#include "my_rpg.h"

static int mob_gravity(obj_t *obj, mob_t *mob)
{
    if (mob->act == 2)
        mob->act = 0;
    else if (mob->act == 3 || mob->act == 4)
        return (0);
    for (int i = 0; i < obj->map->nb_platform; i++)
        if (sfIntRect_contains(&obj->map->ground[i],
        mob->rect.left+mob->rect.width/2,
        mob->rect.top + mob->rect.height) == 1) {
            mob->rect.top = obj->map->ground[i].top + 1 - mob->rect.height;
            return (0);
        }
    mob->act = 2;
    mob->rect.top += 40;
    return (0);
}

static int mob_move_depth(obj_t *obj, mob_t *mob)
{
    int dist = mob->z - obj->charact->z;

    if (dist < 15 && dist > -15)
        return (0);
    if (mob->z > obj->charact->z) {
        mob->z -= 5;
        return (0);
    }
    mob->z += 5;
    return (0);
}

static int mob_move(obj_t *obj, mob_t *mob)
{
    int dist = mob->rect.left + mob->rect.width / 2 - (obj->charact->pos.x+32);

    if (mob->rect.top + mob->rect.height != obj->charact->pos.y
        || (dist < 80 && dist > -80) || dist > 700 || dist < -700) {
        mob->act = 0;
        return (0);
    }
    mob_move_depth(obj, mob);
    mob->act = 1;
    if (mob->rect.left + mob->rect.width / 2 < obj->charact->pos.x + 32) {
        mob->dir = 1;
        mob->rect.left += 10;
        return (1);
    }
    mob->dir = -1;
    mob->rect.left -= 10;
    return (1);
}

static int mob_attack(obj_t *obj, mob_t *mob)
{
    int dist = mob->rect.left + mob->rect.width / 2 - (obj->charact->pos.x+32);
    int dist_y = mob->rect.top + mob->rect.height - obj->charact->pos.y;
    sfTime time = sfClock_getElapsedTime(mob->clock);
    int sec = time.microseconds / 150000;

    if (mob->act == 3 || mob->act == 5 || (mob->act == 4 && sec < 6))
        return (0);
    if (mob->act == 4 && sec >= 6)
        mob->act = 0;
    if (dist > 85 || dist < -85 || dist_y != 0)
        return (0);
    play_attack_sound(obj);
    mob->act = 4;
    obj->charact->hp -= 20 - obj->charact->def;
    sfClock_restart(mob->clock);
    return (0);
}

void game_engine_mob(obj_t *obj, mob_t *mob)
{
    mob_gravity(obj, mob);
    mob_attack(obj, mob);
    if (mob->act == 0 || mob->act == 1)
        mob_move(obj, mob);
}
