/*
** EPITECH PROJECT, 2020
** game_stat
** File description:
** game_stat
*/

#include "my_rpg.h"

static void game_stat_render_cur(obj_t *obj, sfSprite *spr_cur,
sfVector2f pos, int nb)
{
    for (int i = 0; i < nb; i++) {
        sfSprite_setPosition(spr_cur, pos);
        sfRenderWindow_drawSprite(obj->win, spr_cur, NULL);
        pos.x += 50;
    }
}

static void game_stat_render(obj_t *obj, sfSprite *spr_bg,
sfSprite *spr_cur, sfSprite *spr_bt)
{
    sfRenderWindow_drawSprite(obj->win, spr_bg, NULL);
    game_stat_render_cur(obj, spr_cur, (sfVector2f){0, 0}, obj->charact->xp);
    game_stat_render_cur(obj, spr_cur, (sfVector2f){0, 140},
    obj->charact->att);
    game_stat_render_cur(obj, spr_cur, (sfVector2f){0, 240},
    obj->charact->def);
    sfSprite_setTextureRect(spr_bt, (sfIntRect){0, 0, 73, 73});
    sfSprite_setPosition(spr_bt, (sfVector2f){250, 200});
    sfRenderWindow_drawSprite(obj->win, spr_bt, NULL);
    sfSprite_setPosition(spr_bt, (sfVector2f){250, 300});
    sfRenderWindow_drawSprite(obj->win, spr_bt, NULL);
    sfRenderWindow_display(obj->win);
}

static void clic_button(obj_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->win);
    sfIntRect bt1 = {250, 200, 73, 73};
    sfIntRect bt2 = {250, 300, 73, 73};

    if (sfIntRect_contains(&bt1, pos.x, pos.y) == 1 && obj->charact->xp > 0) {
        obj->charact->xp -= 1;
        obj->charact->att += 1;
    }
    if (sfIntRect_contains(&bt2, pos.x, pos.y) == 1 && obj->charact->xp > 0) {
        obj->charact->xp -= 1;
        obj->charact->def += 1;
    }
}

static void game_stat_event(obj_t *obj, int *quit)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(obj->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj->win);
        if (event.type == sfEvtMouseButtonPressed)
            clic_button(obj);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
            quit[0] = 1;
    }
}

void game_stat(obj_t *obj)
{
    sfTexture *tex_bg = sfTexture_createFromFile("assets/stat_bg.jpg", NULL);
    sfTexture *tex_cur = sfTexture_createFromFile("assets/stat_cur.png", NULL);
    sfTexture *tex_bt = sfTexture_createFromFile("assets/stat_button.png",
    NULL);
    sfSprite *spr_bg = sfSprite_create();
    sfSprite *spr_cur = sfSprite_create();
    sfSprite *spr_bt = sfSprite_create();
    int quit = 0;

    sfSprite_setTexture(spr_bg, tex_bg, sfFalse);
    sfSprite_setTexture(spr_cur, tex_cur, sfFalse);
    sfSprite_setTexture(spr_bt, tex_bt, sfFalse);
    while (sfRenderWindow_isOpen(obj->win) && quit == 0) {
        game_stat_event(obj, &quit);
        game_stat_render(obj, spr_bg, spr_cur, spr_bt);
    }
}
