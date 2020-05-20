/*
** EPITECH PROJECT, 2020
** game_init_room2
** File description:
** game_init_room2
*/

#include "my_rpg.h"

static void init_tex_spr(map_t *map)
{
    map->tex = sfTexture_createFromFile("assets/room2.jpg", NULL);
    map->spr = sfSprite_create();
    sfSprite_setTexture(map->spr, map->tex, sfFalse);
    map->tex_bg = NULL;
    map->spr_bg = NULL;
}

static void init_ground_wall(map_t *map)
{
    map->nb_platform = 7;
    map->ground = malloc(sizeof(sfIntRect) * 7);
    init_rect(&map->ground[0], (sfIntRect){0, 619, 500, 50});
    init_rect(&map->ground[1], (sfIntRect){650, 619, 1400, 50});
    init_rect(&map->ground[2], (sfIntRect){130, 1184, 850, 50});
    init_rect(&map->ground[3], (sfIntRect){1125, 1184, 820, 50});
    init_rect(&map->ground[4], (sfIntRect){110, 1740, 1400, 50});
    init_rect(&map->ground[5], (sfIntRect){0, 2310, 1550, 50});
    init_rect(&map->ground[6], (sfIntRect){0, 3150, 1920, 50});
    map->nb_wall = 2;
    map->wall = malloc(sizeof(sfIntRect) * 2);
    init_rect(&map->wall[0], (sfIntRect){0, 0, 50, 3200});
    init_rect(&map->wall[1], (sfIntRect){1650, 0, 50, 3200});
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
    init_rect(&map->mob[0].rect, (sfIntRect){500, 1200, 100, 100});
    init_rect(&map->mob[1].rect, (sfIntRect){900, 2000, 100, 100});
    map->nb_ladder = 4;
    map->ladder = malloc(sizeof(sfIntRect) * 4);
    init_rect(&map->ladder[0], (sfIntRect){1400, 2315, 50, 850});
    init_rect(&map->ladder[1], (sfIntRect){200, 1750, 50, 600});
    init_rect(&map->ladder[2], (sfIntRect){1280, 1190, 50, 570});
    init_rect(&map->ladder[3], (sfIntRect){410, 615, 50, 570});
}

static void init_door(obj_t *obj, map_t *map)
{
    map->nb_door = 3;
    map->door_map = malloc(sizeof(map_t *) * 3);
    map->door_map[0] = &obj->map[2];
    map->door_map[1] = &obj->map[0];
    map->door_map[2] = &obj->map[4];
    map->door_pos = malloc(sizeof(sfVector2f) * 3);
    map->door_pos[0].x = 4700;
    map->door_pos[0].y = 670;
    map->door_pos[1].x = 5400;
    map->door_pos[1].y = 850;
    map->door_pos[2].x = 150;
    map->door_pos[2].y = 1750;
    map->door = malloc(sizeof(sfIntRect) * 3);
    init_rect(&map->door[0], (sfIntRect){0, 3000, 100, 600});
    init_rect(&map->door[1], (sfIntRect){0, 0, 100, 1000});
    init_rect(&map->door[2], (sfIntRect){1600, 0, 100, 1000});
}

void game_init_room2(obj_t *obj, map_t *map)
{
    init_tex_spr(map);
    init_ground_wall(map);
    init_ladder_mob(map);
    init_door(obj, map);
    map->dim.x = 1920;
    map->dim.y = 3400;
}
