/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** h_t_p_events
*/

#include "my_rpg.h"
#include "how_to_play.h"

int h_t_p_events(sfRenderWindow *window, m_htp *option)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        h_t_p_button_quit(option);
        if (event.type == sfEvtClosed) {
            option->quit_pressed = 1;
            sfRenderWindow_close(window);
        }
    }
    return (0);
}

void h_t_p_button_quit(m_htp *h_t_p)
{
    sfBool click = button_pressed(&h_t_p->button_quit);

    if (click == sfTrue)
        h_t_p->quit_pressed = 1;
}
