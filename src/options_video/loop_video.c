/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop_sound
*/

#include "my_rpg.h"
#include "options_video.h"
#include "option.h"

int opt_loop_video(sfRenderWindow *window, m_opt *option, m_menu *menu)
{
    m_opt_video opt_v = init_texture_video();

    while (opt_v.quit_pressed == 0) {
        opt_eve_v(window, &opt_v, option, menu);
        display_opt_video(window, &opt_v);
    }
    destroy_opt_video(&opt_v);
    return (0);
}