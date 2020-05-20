/*
** EPITECH PROJECT, 2020
** game_render_mob
** File description:
** game_render_mob
*/

#include "my_rpg.h"

static void display_mob_attack(obj_t *obj, mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->clock);
    int sec = time.microseconds / 150000;
    sfVector2f pos = define_map_pos(obj);
    int dir = 0;

    if (mob->dir == -1)
        dir = 80;
    pos.x += mob->rect.left - mob->rect.width / 2;
    pos.y += mob->rect.top - mob->rect.height / 2 - 30 - mob->z;
    sfSprite_setTextureRect(obj->mob->spr_mob_att,
                            (sfIntRect){sec % 6 * 100, dir, 100, 80});
    sfSprite_setPosition(obj->mob->spr_mob_att, pos);
    sfRenderWindow_drawSprite(obj->win, obj->mob->spr_mob_att, NULL);
}

static int display_mob_hit(obj_t *obj, mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->clock);
    int sec = time.microseconds / 600000;
    sfVector2f pos = define_map_pos(obj);
    int dir = 0;

    if (mob->act == 4) {
        display_mob_attack(obj, mob);
        return (0);
    }
    if (mob->dir == -1)
        dir = 80;
    pos.x += mob->rect.left - mob->rect.width / 2;
    pos.y += mob->rect.top - mob->rect.height / 2 - 30 - mob->z;
    sfSprite_setTextureRect(obj->mob->spr_mob_hit,
                            (sfIntRect){sec % 2 * 100, dir, 100, 80});
    sfSprite_setPosition(obj->mob->spr_mob_hit, pos);
    sfRenderWindow_drawSprite(obj->win, obj->mob->spr_mob_hit, NULL);
    return (0);
}

static void display_mob_dead(obj_t *obj, mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->clock);
    int sec = time.microseconds / 150000;
    sfVector2f pos = define_map_pos(obj);
    int dir = 0;

    if (mob->dir == -1)
        dir = 80;
    if (sec > 4)
        sec = 4;
    pos.x += mob->rect.left - mob->rect.width / 2;
    pos.y += mob->rect.top - mob->rect.height / 2 - 30 - mob->z;
    sfSprite_setTextureRect(obj->mob->spr_mob_dead,
                            (sfIntRect){sec * 100, dir, 100, 80});
    sfSprite_setPosition(obj->mob->spr_mob_dead, pos);
    sfRenderWindow_drawSprite(obj->win, obj->mob->spr_mob_dead, NULL);
}

static int display_mob(obj_t *obj, mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->clock);
    int sec = time.microseconds / 150000;
    sfVector2f pos = define_map_pos(obj);
    int dir = 0;

    if (mob->dir == -1)
        dir = 80;
    pos.x += mob->rect.left - mob->rect.width / 2;
    pos.y += mob->rect.top - mob->rect.height / 2 - 30 - mob->z;
    if (mob->act == 0 || mob->act == 2)
        sfSprite_setTextureRect(obj->mob->spr_mob_walk,
                                (sfIntRect){0, dir, 100, 80});
    if (mob->act == 1)
        sfSprite_setTextureRect(obj->mob->spr_mob_walk,
                                (sfIntRect){sec % 6 * 100, dir, 100, 80});
    sfSprite_setPosition(obj->mob->spr_mob_walk, pos);
    sfRenderWindow_drawSprite(obj->win, obj->mob->spr_mob_walk, NULL);
    return (0);
}

void game_render_mob(obj_t *obj, mob_t *mob)
{
    if (mob->act == 3 || mob->act == 4)
        display_mob_hit(obj, mob);
    else if (mob->act == 5)
        display_mob_dead(obj, mob);
    else
        display_mob(obj, mob);
}
