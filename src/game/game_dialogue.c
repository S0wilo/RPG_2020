/*
** EPITECH PROJECT, 2020
** game_dialogue
** File description:
** game_dialogue
*/

#include "my_rpg.h"

static sfTexture *define_tex(obj_t *obj)
{
    if (obj->charact->key == 0)
        return (sfTexture_createFromFile("assets/dlg1.png", NULL));
    else
        return (sfTexture_createFromFile("assets/dlg2.png", NULL));
}

static void game_dialogue_event(obj_t *obj, int *quit)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(obj->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE)
            quit[0] = 1;
    }
}

static void game_dialogue_render(obj_t *obj, sfSprite *spr)
{
    sfVector2f pos = {-100, -100};

    sfSprite_setPosition(spr, pos);
    sfRenderWindow_drawSprite(obj->win, spr, NULL);
    sfRenderWindow_display(obj->win);
}

void game_dialogue(obj_t *obj)
{
    int quit = 0;
    sfTexture *tex = define_tex(obj);
    sfSprite *spr = sfSprite_create();

    sfSprite_setTexture(spr, tex, sfFalse);
    game_dialogue_render(obj, spr);
    while (sfRenderWindow_isOpen(obj->win) && quit == 0)
        game_dialogue_event(obj, &quit);
    if (obj->charact->key == 1)
        obj->quit = 1;
}
