/*
** EPITECH PROJECT, 2020
** events
** File description:
** manage events
*/

#include "my_rpg.h"

int menu_events(sfRenderWindow *window, m_menu *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
    m_button_menu(menu, &event, window);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return (0);
}
