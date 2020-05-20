/*
** EPITECH PROJECT, 2020
** game_event
** File description:
** game_event
*/

#include "my_rpg.h"

static void jump_character(obj_t *obj)
{
    if (obj->charact->act == 0 || obj->charact->act == 1) {
        obj->charact->act = 3;
        sfClock_restart(obj->charact->clock);
    }
}

static int attack_character(obj_t *obj)
{
    int dist = 0;
    int mob_y = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) == 0
        || (obj->charact->act != 0 && obj->charact->act != 1))
        return (0);
    obj->charact->act = 5;
    sfClock_restart(obj->charact->clock);
    play_attack_sound(obj);
    for (int i = 0; i < obj->map->nb_mob; i++) {
        dist = obj->map->mob[i].rect.left;
        dist += obj->map->mob[i].rect.width/2-obj->charact->pos.x;
        mob_y = obj->map->mob[i].rect.top + obj->map->mob[i].rect.height;
        if (mob_y == obj->charact->pos.y && dist > -110 && dist < 110) {
            obj->map->mob[i].rect.left += 50 * obj->charact->dir;
            obj->map->mob[i].act = 3;
            obj->map->mob[i].hp -= 30 + obj->charact->att * 5;
            sfClock_restart(obj->map->mob[i].clock);
        }
    }
}

static void touch_interact(obj_t *obj)
{
    if (obj->map == &obj->map_list[4] && obj->charact->pos.x > 2500)
        game_dialogue(obj);
    if (obj->map == &obj->map_list[3] && obj->charact->pos.x < 300)
        obj->charact->key = 1;
}

static void open_menu(obj_t *obj, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        game_menu_pause(obj);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
        game_stat(obj);
}

void game_event(obj_t *obj, sfEvent event)
{
    attack_character(obj);
    if (sfKeyboard_isKeyPressed(sfKeyQ) == 1 ||
    sfKeyboard_isKeyPressed(sfKeyD) == 1
        || sfKeyboard_isKeyPressed(sfKeyZ) == 1
        || sfKeyboard_isKeyPressed(sfKeyS) == 1)
        game_event_move_charact(obj);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == 1)
        jump_character(obj);
    while (sfRenderWindow_pollEvent(obj->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE)
            touch_interact(obj);
        open_menu(obj, event);
    }
}
