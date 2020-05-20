/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my_rpg.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
    "RPG", sfDefaultStyle | sfClose, NULL);
    m_menu menu = init_texture_menu();

    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        menu_events(window, &menu);
        display_menu(window, &menu);
    }
    destroy_menu(&menu);
    sfRenderWindow_destroy(window);
    return (0);
}
