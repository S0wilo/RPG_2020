/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** opt_sound_events
*/

#include "my_rpg.h"
#include "options_sound.h"
#include "option.h"

int opt_eve_s(sfRenderWindow *win, m_opt_video *opti, m_opt *opt, m_menu *menu)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(win, &event)) {
        m_opt_b_sound(opti, menu);
        if (event.type == sfEvtClosed) {
            opti->quit_pressed = 1;
            opt->quit_pressed = 1;
            sfRenderWindow_close(win);
        }
    }
    return (0);
}