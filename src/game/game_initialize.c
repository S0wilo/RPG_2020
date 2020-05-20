/*
** EPITECH PROJECT, 2020
** game_initialize
** File description:
** game_initialize
*/

#include "my_rpg.h"

void init_rect(sfIntRect *rect, sfIntRect value)
{
    rect->left = value.left;
    rect->top = value.top;
    rect->width = value.width;
    rect->height = value.height;
}

void game_init_mob2(obj_t *obj)
{
    obj->mob->tex_mob_att = sfTexture_createFromFile("assets/dem_attack.png",
    NULL);
    obj->mob->spr_mob_att = sfSprite_create();
    sfSprite_setTexture(obj->mob->spr_mob_att, obj->mob->tex_mob_att, sfFalse);
    sfSprite_scale(obj->mob->spr_mob_att, (sfVector2f){4, 4});
    obj->mob->tex_mob_dead = sfTexture_createFromFile("assets/dem_death.png",
    NULL);
    obj->mob->spr_mob_dead = sfSprite_create();
    sfSprite_setTexture(obj->mob->spr_mob_dead, obj->mob->tex_mob_dead,
    sfFalse);
    sfSprite_scale(obj->mob->spr_mob_dead, (sfVector2f){4, 4});
    obj->mob->tex_key = sfTexture_createFromFile("assets/key.png", NULL);
    obj->mob->spr_key = sfSprite_create();
    sfSprite_setTexture(obj->mob->spr_key, obj->mob->tex_key, sfFalse);
    sfSprite_scale(obj->mob->spr_key, (sfVector2f){0.5, 0.5});
}

static void game_init_mob(obj_t *obj)
{
    obj->mob = malloc(sizeof(mob_tex_t));
    obj->mob->tex_mob_walk = sfTexture_createFromFile("assets/dem_walk.png",
    NULL);
    obj->mob->spr_mob_walk = sfSprite_create();
    sfSprite_setTexture(obj->mob->spr_mob_walk, obj->mob->tex_mob_walk,
    sfFalse);
    sfSprite_scale(obj->mob->spr_mob_walk, (sfVector2f){4, 4});
    obj->mob->tex_mob_hit = sfTexture_createFromFile("assets/dem_hit.png",
    NULL);
    obj->mob->spr_mob_hit = sfSprite_create();
    sfSprite_setTexture(obj->mob->spr_mob_hit, obj->mob->tex_mob_hit, sfFalse);
    sfSprite_scale(obj->mob->spr_mob_hit, (sfVector2f){4, 4});
    game_init_mob2(obj);
}

void game_initialize(obj_t *obj)
{
    obj->map = malloc(sizeof(map_t) * 5);
    obj->map_list = obj->map;
    game_init_room1(obj, &obj->map[0]);
    game_init_room2(obj, &obj->map[1]);
    game_init_room3(obj, &obj->map[2]);
    game_init_room4(obj, &obj->map[3]);
    game_init_room5(obj, &obj->map[4]);
    obj->charact = malloc(sizeof(charact_t));
    game_init_charact(obj->charact);
    game_init_mob(obj);
    obj->sound = malloc(sizeof(sound_t));
    obj->sound->song = sfSound_create();
    obj->sound->attack = sfSound_create();
    obj->sound->buf1 = sfSoundBuffer_createFromFile("audio/game_song.ogg");
    obj->sound->buf2 = sfSoundBuffer_createFromFile("audio/attack.ogg");
    sfSound_setBuffer(obj->sound->song, obj->sound->buf1);
    sfSound_setBuffer(obj->sound->attack, obj->sound->buf2);
    sfSound_setLoop(obj->sound->song, sfTrue);
}
