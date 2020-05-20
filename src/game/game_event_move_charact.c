/*
** EPITECH PROJECT, 2020
** game_event_move_charact
** File description:
** game_event_move_charact
*/

#include "my_rpg.h"

static int check_move(obj_t *obj, int dist)
{
    for (int i = 0; i < obj->map->nb_wall; i++)
        if (sfIntRect_contains(&obj->map->wall[i],
        obj->charact->pos.x + dist, obj->charact->pos.y) == 1)
            return (1);
    return (0);
}

static void move_charact_ground(obj_t *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) == 1 && check_move(obj, -15) == 0) {
        obj->charact->act = 1;
        obj->charact->pos.x -= 15;
        obj->charact->dir = -1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) == 1 && check_move(obj, 15) == 0) {
        obj->charact->act = 1;
        obj->charact->pos.x += 15;
        obj->charact->dir = 1;
    }
}

static void move_charact_air(obj_t *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) == 1 && check_move(obj, -15) == 0) {
        obj->charact->pos.x -= 15;
        obj->charact->dir = -1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) == 1 && check_move(obj, 15) == 0) {
        obj->charact->pos.x += 15;
        obj->charact->dir = 1;
    }
}

void game_event_move_charact(obj_t *obj)
{
    if (obj->charact->act == 0)
        move_charact_ground(obj);
    if (obj->charact->act == 2 || obj->charact->act == 3)
        move_charact_air(obj);
    game_event_move_charact_depth(obj);
}
