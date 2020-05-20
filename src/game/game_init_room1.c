/*
** EPITECH PROJECT, 2020
** game_init_room1
** File description:
** game_init_room1
*/

#include "my_rpg.h"

static void init_tex_spr(map_t *map)
{
    map->tex = sfTexture_createFromFile("assets/room1.png", NULL);
    map->spr = sfSprite_create();
    sfSprite_setTexture(map->spr, map->tex, sfFalse);
    map->tex_bg = sfTexture_createFromFile("assets/out.jpg", NULL);
    map->spr_bg = sfSprite_create();
    sfSprite_setTexture(map->spr_bg, map->tex_bg, sfFalse);
    map->dim.x = 5800;
    map->dim.y = 1080;
}

static void init_ground_wall(map_t *map)
{
    map->nb_platform = 5;
    map->ground = malloc(sizeof(sfIntRect) * 5);
    init_rect(&map->ground[0], (sfIntRect){0, 630, 1700, 50});
    init_rect(&map->ground[1], (sfIntRect){1070, 420, 600, 70});
    init_rect(&map->ground[2], (sfIntRect){1480, 220, 780, 50});
    init_rect(&map->ground[3], (sfIntRect){1480, 850, 4500, 50});
    init_rect(&map->ground[4], (sfIntRect){3200, 230, 1600, 50});
    map->nb_wall = 6;
    map->wall = malloc(sizeof(sfIntRect) * 6);
    init_rect(&map->wall[0], (sfIntRect){50, -2000, 50, 4000});
    init_rect(&map->wall[1], (sfIntRect){1110, 440, 50, 500});
    init_rect(&map->wall[2], (sfIntRect){1500, 230, 50, 500});
    init_rect(&map->wall[3], (sfIntRect){1970, 230, 50, 2000});
    init_rect(&map->wall[4], (sfIntRect){3440, 250, 50, 2000});
    init_rect(&map->wall[5], (sfIntRect){4640, 250, 50, 2000});
}

static void init_ladder_mob(map_t *map)
{
    map->nb_mob = 1;
    map->mob = malloc(sizeof(mob_t) * 1);
    map->mob[0].act = 0;
    map->mob[0].clock = sfClock_create();
    map->mob[0].dir = 1;
    map->mob[0].z = 0;
    map->mob[0].hp = 100;
    init_rect(&map->mob[0].rect, (sfIntRect){3000, 500, 100, 100});
    map->nb_ladder = 2;
    map->ladder = malloc(sizeof(sfIntRect) * 2);
    init_rect(&map->ladder[0], (sfIntRect){2060, 230, 50, 620});
    init_rect(&map->ladder[1], (sfIntRect){3350, 240, 50, 610});
}

static void init_door(obj_t *obj, map_t *map)
{
    map->nb_door = 1;
    map->door = malloc(sizeof(sfIntRect) * 1);
    init_rect(&map->door[0], (sfIntRect){5500, 0, 50, 2000});
    map->door_map = malloc(sizeof(map_t *) * 1);
    map->door_map[0] = &obj->map[1];
    map->door_pos = malloc(sizeof(sfVector2f) * 1);
    map->door_pos[0].x = 200;
    map->door_pos[0].y = 620;
}

void game_init_room1(obj_t *obj, map_t *map)
{
    init_tex_spr(map);
    init_ground_wall(map);
    init_ladder_mob(map);
    init_door(obj, map);
    map->dim.x = 5800;
    map->dim.y = 1080;
}
