/*
** EPITECH PROJECT, 2020
** game_event_move_charact_depth
** File description:
** game_event_move_charact_depth
*/

#include "my_rpg.h"

static void leave_ladder(obj_t *obj)
{
    for (int i = 0; i < obj->map->nb_ladder; i++) {
        if (sfKeyboard_isKeyPressed(sfKeyZ)
            && sfIntRect_contains(&obj->map->ladder[i],
            obj->charact->pos.x, obj->charact->pos.y) == 1
            && sfIntRect_contains(&obj->map->ladder[i],
            obj->charact->pos.x, obj->charact->pos.y-10) == 0) {
            obj->charact->pos.y -= 10;
            obj->charact->pos.x = obj->map->ladder[i].left + 25;
            obj->charact->act = 0;
        } else if (sfKeyboard_isKeyPressed(sfKeyS)
        && sfIntRect_contains(&obj->map->ladder[i],
        obj->charact->pos.x, obj->charact->pos.y) == 1
        && sfIntRect_contains(&obj->map->ladder[i],
        obj->charact->pos.x, obj->charact->pos.y+10) == 0) {
            obj->charact->pos.y += 10;
            obj->charact->pos.x = obj->map->ladder[i].left + 25;
            obj->charact->act = 0;
        }
    }
}

static int take_ladder(obj_t *obj)
{
    for (int i = 0; i < obj->map->nb_ladder; i++) {
        if (sfKeyboard_isKeyPressed(sfKeyZ) &&
        sfIntRect_contains(&obj->map->ladder[i],
        obj->charact->pos.x , obj->charact->pos.y - 10) == 1) {
            obj->charact->pos.y -= 10;
            obj->charact->pos.x = obj->map->ladder[i].left + 25;
            obj->charact->act = 4;
            obj->charact->z = 0;
            return (0);
        } else if (sfKeyboard_isKeyPressed(sfKeyS)
        && sfIntRect_contains(&obj->map->ladder[i],
        obj->charact->pos.x, obj->charact->pos.y + 10) == 1) {
            obj->charact->pos.y += 10;
            obj->charact->pos.x = obj->map->ladder[i].left + 25;
            obj->charact->act = 4;
            obj->charact->z = 0;
            return (0);
        }
    }
}

void game_event_move_charact_depth(obj_t *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == 1 && obj->charact->z < 65
        && (obj->charact->act == 0 || obj->charact->act == 1)) {
        obj->charact->z += 5;
        obj->charact->act = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) == 1 && obj->charact->z > 0
        && (obj->charact->act == 0 || obj->charact->act == 1)) {
        obj->charact->z -= 5;
        obj->charact->act = 1;
    }
    leave_ladder(obj);
    take_ladder(obj);
}
