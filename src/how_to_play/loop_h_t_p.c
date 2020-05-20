/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop_h_t_p
*/

#include "my_rpg.h"
#include "how_to_play.h"

int h_t_p_loop(sfRenderWindow *window)
{
    m_htp h_t_p = init_texture_h_t_p();

    while (h_t_p.quit_pressed == 0) {
        h_t_p_events(window, &h_t_p);
        display_h_t_p(window, &h_t_p);
    }
    destroy_h_t_p(&h_t_p);
    return (0);
}