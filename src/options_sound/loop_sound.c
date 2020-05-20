/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop_sound
*/

#include "my_rpg.h"
#include "options_sound.h"
#include "option.h"

int opt_loop_sound(sfRenderWindow *window, m_opt *option, m_menu *menu)
{
    m_opt_video opt_s = init_texture_sound();

    while (opt_s.quit_pressed == 0) {
        opt_eve_s(window, &opt_s, option, menu);
        display_opt_sound(window, &opt_s);
    }
    destroy_opt_sound(&opt_s);
    return (0);
}