/*
** EPITECH PROJECT, 2020
** game_init_charact
** File description:
** game_init_charact
*/

#include "my_rpg.h"

void init_tex_spr2(charact_t *charact)
{
    charact->spr_jump = sfSprite_create();
    sfSprite_setTexture(charact->spr_jump, charact->tex_jump, sfFalse);
    sfSprite_scale(charact->spr_jump, (sfVector2f){4, 4});
    charact->tex_att = sfTexture_createFromFile("assets/KnightAttack.png",
    NULL);
    charact->spr_att = sfSprite_create();
    sfSprite_setTexture(charact->spr_att, charact->tex_att, sfFalse);
    sfSprite_scale(charact->spr_att, (sfVector2f){4, 4});
    charact->tex_lad = sfTexture_createFromFile("assets/KnightLadder.png",
    NULL);
    charact->spr_lad = sfSprite_create();
    sfSprite_setTexture(charact->spr_lad, charact->tex_lad, sfFalse);
    sfSprite_scale(charact->spr_lad, (sfVector2f){4, 4});
}

static void init_tex_spr(charact_t *charact)
{
    charact->tex_idle = sfTexture_createFromFile("assets/KnightIdle.png",
    NULL);
    charact->spr_idle = sfSprite_create();
    sfSprite_setTexture(charact->spr_idle, charact->tex_idle, sfFalse);
    sfSprite_scale(charact->spr_idle, (sfVector2f){4, 4});
    charact->tex_run = sfTexture_createFromFile("assets/KnightRun.png", NULL);
    charact->spr_run = sfSprite_create();
    sfSprite_setTexture(charact->spr_run, charact->tex_run, sfFalse);
    sfSprite_scale(charact->spr_run, (sfVector2f){4, 4});
    charact->tex_jump = sfTexture_createFromFile("assets/KnightJump.png",
    NULL);
    init_tex_spr2(charact);
}

static void init_life_hp(charact_t *charact)
{
    charact->tex_lb = sfTexture_createFromFile("assets/life_bar.png", NULL);
    charact->spr_lb = sfSprite_create();
    sfSprite_setTexture(charact->spr_lb, charact->tex_lb, sfFalse);
    charact->tex_hp = sfTexture_createFromFile("assets/hp.png", NULL);
    charact->spr_hp = sfSprite_create();
    sfSprite_setTexture(charact->spr_hp, charact->tex_hp, sfFalse);
    charact->tex_dead = sfTexture_createFromFile("assets/KnightDeath.png",
    NULL);
    charact->spr_dead = sfSprite_create();
    sfSprite_setTexture(charact->spr_dead, charact->tex_dead, sfFalse);
    sfSprite_scale(charact->spr_dead, (sfVector2f){4, 4});
}

void game_init_charact(charact_t *charact)
{
    init_tex_spr(charact);
    init_life_hp(charact);
    charact->pos.x = 200;
    charact->pos.y = - 1000;
    charact->dir = 1;
    charact->z = 0;
    charact->act = 0;
    charact->hp = 100;
    charact->key = 0;
    charact->xp = 3;
    charact->att = 0;
    charact->def = 0;
    charact->clock = sfClock_create();
}
