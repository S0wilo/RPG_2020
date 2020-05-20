/*
** EPITECH PROJECT, 2020
** game_init_room3
** File description:
** game_init_room3
*/

#include "my_rpg.h"

static void init_tex_spr(map_t *map)
{
    map->tex = sfTexture_createFromFile("assets/room3.jpg", NULL);
    map->spr = sfSprite_create();
    sfSprite_setTexture(map->spr, map->tex, sfFalse);
    map->tex_bg = NULL;
    map->spr_bg = NULL;
    sfSprite_scale(map->spr, (sfVector2f){2, 2});
}

static void init_ground_wall(map_t *map)
{
    map->nb_platform = 4;
    map->ground = malloc(sizeof(sfIntRect) * 4);
    init_rect(&map->ground[0], (sfIntRect){3200, 670, 2000, 50});
    init_rect(&map->ground[1], (sfIntRect){2000, 1300, 2000, 50});
    init_rect(&map->ground[2], (sfIntRect){1190, 1100, 1030, 50});
    init_rect(&map->ground[3], (sfIntRect){0, 1800, 2030, 50});
    map->nb_wall = 3;
    map->wall = malloc(sizeof(sfIntRect) * 3);
    init_rect(&map->wall[0], (sfIntRect){3440, 700, 50, 1000});
    init_rect(&map->wall[1], (sfIntRect){2080, 1200, 50, 1000});
    init_rect(&map->wall[2], (sfIntRect){1400, 1200, 50, 1000});
}

static void init_ladder_mob(map_t *map)
{
    map->nb_mob = 2;
    map->mob = malloc(sizeof(mob_t) * 2);
    map->mob[0].act = 0;
    map->mob[1].act = 0;
    map->mob[0].clock = sfClock_create();
    map->mob[1].clock = sfClock_create();
    map->mob[0].dir = 1;
    map->mob[1].dir = 1;
    map->mob[0].z = 0;
    map->mob[1].z = 0;
    map->mob[0].hp = 100;
    map->mob[1].hp = 100;
    init_rect(&map->mob[0].rect, (sfIntRect){500, 300, 100, 100});
    init_rect(&map->mob[1].rect, (sfIntRect){900, 300, 100, 100});
    map->nb_ladder = 2;
    map->ladder = malloc(sizeof(sfIntRect) * 2);
    init_rect(&map->ladder[0], (sfIntRect){3300, 660, 50, 680});
    init_rect(&map->ladder[1], (sfIntRect){1280, 1105, 50, 690});
}

static void init_door(obj_t *obj, map_t *map)
{
    map->nb_door = 2;
    map->door_map = malloc(sizeof(map_t *) * 2);
    map->door_map[0] = &obj->map[1];
    map->door_map[1] = &obj->map[3];
    map->door_pos = malloc(sizeof(sfVector2f) * 2);
    map->door_pos[0].x = 100;
    map->door_pos[0].y = 3150;
    map->door_pos[1].x = 3450;
    map->door_pos[1].y = 1150;
    map->door = malloc(sizeof(sfIntRect) * 2);
    init_rect(&map->door[0], (sfIntRect){4750, 0, 50, 5000});
    init_rect(&map->door[1], (sfIntRect){0, 0, 50, 5000});
}

void game_init_room3(obj_t *obj, map_t *map)
{
    init_tex_spr(map);
    init_ground_wall(map);
    init_ladder_mob(map);
    init_door(obj, map);
    map->dim.x = 2500 * 2;
    map->dim.y = 1080 * 2;
}
