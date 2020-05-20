/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_option
*/

#include "my_rpg.h"
#include "option.h"

int option_events(sfRenderWindow *window, m_opt *option, m_menu *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        m_button_option(option, window, menu);
        if (event.type == sfEvtClosed) {
            option->quit_pressed = 1;
            sfRenderWindow_close(window);
        }
    }
    return (0);
}
