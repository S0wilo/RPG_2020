/*
** EPITECH PROJECT, 2020
** execute_cursor
** File description:
** execute_cursor
*/

#include "my_rpg.h"
#include "how_to_play.h"
#include "option.h"

void execute_cursor(obj_t *obj, int cursor, int *quit)
{
    m_menu menu = {0};

    menu.song = obj->sound->song;
    menu.check_v = obj->check_v;
    menu.check_s = obj->check_s;
    if (cursor == 0)
        options_loop(obj->win, &menu);
    else if (cursor == 1)
        h_t_p_loop(obj->win);
    else {
        quit[0] = 1;
        obj->quit = 1;
    }
    obj->check_v = menu.check_v;
    obj->check_s = menu.check_s;
}
