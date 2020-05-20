/*
** EPITECH PROJECT, 2020
** game_init_room5
** File description:
** game_init_room5
*/

#include "my_rpg.h"

static void init_tex_spr(map_t *map)
{
    map->tex = sfTexture_createFromFile("assets/room5.png", NULL);
    map->spr = sfSprite_create();
    sfSprite_setTexture(map->spr, map->tex, sfFalse);
    map->tex_bg = sfTexture_createFromFile("assets/out2.jpg", NULL);
    map->spr_bg = sfSprite_create();
    sfSprite_setTexture(map->spr_bg, map->tex_bg, sfFalse);
    sfSprite_scale(map->spr, (sfVector2f){2, 2});
    sfSprite_scale(map->spr_bg, (sfVector2f){1.5, 1.5});
}

static void init_ground_wall(map_t *map)
{
    map->nb_platform = 2;
    map->ground = malloc(sizeof(sfIntRect) * 2);
    init_rect(&map->ground[0], (sfIntRect){0, 1750, 2000, 50});
    init_rect(&map->ground[1], (sfIntRect){1570, 1600, 2000, 50});
    map->nb_wall = 2;
    map->wall = malloc(sizeof(sfIntRect) * 2);
    init_rect(&map->wall[0], (sfIntRect){1600, 1620, 50, 500});
    init_rect(&map->wall[1], (sfIntRect){2800, 0, 50, 2000});
}

static void init_ladder_mob(map_t *map)
{
    map->nb_mob = 0;
    map->nb_ladder = 0;
}

static void init_door(obj_t *obj, map_t *map)
{
    map->nb_door = 1;
    map->door_map = malloc(sizeof(map_t *) * 1);
    map->door_map[0] = &obj->map[1];
    map->door_pos = malloc(sizeof(sfVector2f) * 1);
    map->door_pos[0].x = 1500;
    map->door_pos[0].y = 620;
    map->door = malloc(sizeof(sfIntRect) * 1);
    init_rect(&map->door[0], (sfIntRect){0, 0, 100, 4000});
}

void game_init_room5(obj_t *obj, map_t *map)
{
    init_tex_spr(map);
    init_ground_wall(map);
    init_ladder_mob(map);
    init_door(obj, map);
    map->dim.x = 2000 * 2;
    map->dim.y = 1080 * 2;
}
