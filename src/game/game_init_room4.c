/*
** EPITECH PROJECT, 2020
** game_init_room4
** File description:
** game_init_room4
*/

#include "my_rpg.h"

static void init_tex_spr(map_t *map)
{
    map->tex = sfTexture_createFromFile("assets/room4.jpg", NULL);
    map->spr = sfSprite_create();
    sfSprite_setTexture(map->spr, map->tex, sfFalse);
    map->tex_bg = NULL;
    map->spr_bg = NULL;
    sfSprite_scale(map->spr, (sfVector2f){1.5, 1.5});
}

static void init_ground_wall(map_t *map)
{
    map->nb_platform = 4;
    map->ground = malloc(sizeof(sfIntRect) * 4);
    init_rect(&map->ground[0], (sfIntRect){0, 1150, 5000, 50});
    init_rect(&map->ground[1], (sfIntRect){2000, 960, 980, 50});
    init_rect(&map->ground[2], (sfIntRect){1900, 770, 480, 50});
    init_rect(&map->ground[3], (sfIntRect){700, 590, 1420, 50});
    map->nb_wall = 5;
    map->wall = malloc(sizeof(sfIntRect) * 5);
    init_rect(&map->wall[0], (sfIntRect){2910, 970, 50, 1000});
    init_rect(&map->wall[1], (sfIntRect){2320, 800, 50, 1000});
    init_rect(&map->wall[2], (sfIntRect){2050, 610, 50, 1000});
    init_rect(&map->wall[3], (sfIntRect){1000, 610, 50, 2000});
    init_rect(&map->wall[4], (sfIntRect){0, 0, 50, 2000});
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
    init_rect(&map->mob[0].rect, (sfIntRect){500, 200, 100, 100});
    map->nb_ladder = 1;
    map->ladder = malloc(sizeof(sfIntRect) * 1);
    init_rect(&map->ladder[0], (sfIntRect){910, 600, 50, 580});
}

static void init_door(obj_t *obj, map_t *map)
{
    map->nb_door = 1;
    map->door_map = malloc(sizeof(map_t *) * 1);
    map->door_map[0] = &obj->map[2];
    map->door_pos = malloc(sizeof(sfVector2f) * 1);
    map->door_pos[0].x = 60;
    map->door_pos[0].y = 1810;
    map->door = malloc(sizeof(sfIntRect) * 1);
    init_rect(&map->door[0], (sfIntRect){3460, 0, 50, 5000});
}

void game_init_room4(obj_t *obj, map_t *map)
{
    init_tex_spr(map);
    init_ground_wall(map);
    init_ladder_mob(map);
    init_door(obj, map);
    map->dim.x = 2500 * 1.5;
    map->dim.y = 1080 * 1.5;
}
