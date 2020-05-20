/*
** EPITECH PROJECT, 2020
** game_menu_pause
** File description:
** game_menu_pause
*/

#include "my_rpg.h"
#include "how_to_play.h"
#include "option.h"

static void game_pause_render(obj_t *obj, int cursor, res_pause_t res)
{
    sfVector2f pos = {0, cursor * 85};

    sfRenderWindow_drawSprite(obj->win, res.spr_bg, NULL);
    if (cursor == 0)
        sfRenderWindow_drawSprite(obj->win, res.spr_opt, NULL);
    else if (cursor == 1)
        sfRenderWindow_drawSprite(obj->win, res.spr_htp, NULL);
    else
        sfRenderWindow_drawSprite(obj->win, res.spr_exit, NULL);
    sfSprite_setPosition(res.spr_cur, pos);
    sfRenderWindow_drawSprite(obj->win, res.spr_cur, NULL);
    sfRenderWindow_display(obj->win);
}

static void move_cursor(sfEvent event, int *cursor, int *quit)
{
    if (event.key.code == sfKeyZ)
        cursor[0] = (cursor[0] + 2) % 3;
    else if (event.key.code == sfKeyS)
        cursor[0] = (cursor[0] + 1) % 3;
    else
        quit[0] += 1;
}

static void game_pause_event(obj_t *obj, int *cursor, int *quit)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(obj->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj->win);
        if (event.type == sfEvtKeyPressed
            && (event.key.code == sfKeyZ
                || event.key.code == sfKeyS
                || event.key.code == sfKeyEscape))
            move_cursor(event, cursor, quit);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
            execute_cursor(obj, cursor[0], quit);
    }
}

static void init_res(res_pause_t *res)
{
    res->tex_bg = sfTexture_createFromFile("assets/pause_bg.jpg", NULL);
    res->spr_bg = sfSprite_create();
    sfSprite_setTexture(res->spr_bg, res->tex_bg, sfFalse);
    res->tex_cur = sfTexture_createFromFile("assets/cursor.png", NULL);
    res->spr_cur = sfSprite_create();
    sfSprite_setTexture(res->spr_cur, res->tex_cur, sfFalse);
    res->tex_opt = sfTexture_createFromFile("assets/options.png", NULL);
    res->spr_opt = sfSprite_create();
    sfSprite_setTexture(res->spr_opt, res->tex_opt, sfFalse);
    res->tex_htp = sfTexture_createFromFile("assets/htp.png", NULL);
    res->spr_htp = sfSprite_create();
    sfSprite_setTexture(res->spr_htp, res->tex_htp, sfFalse);
    res->tex_exit = sfTexture_createFromFile("assets/exit.png", NULL);
    res->spr_exit = sfSprite_create();
    sfSprite_setTexture(res->spr_exit, res->tex_exit, sfFalse);
}

void game_menu_pause(obj_t *obj)
{
    res_pause_t res;
    int cursor = 0;
    int quit = 0;

    init_res(&res);
    while (sfRenderWindow_isOpen(obj->win) && quit == 0) {
        game_pause_event(obj, &cursor, &quit);
        game_pause_render(obj, cursor, res);
    }
}
