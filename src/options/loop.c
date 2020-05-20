/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop
*/

#include "my_rpg.h"
#include "option.h"

int options_loop(sfRenderWindow *window, m_menu *menu)
{
    m_opt option = init_texture_option();

    while (option.quit_pressed == 0) {
        option_events(window, &option, menu);
        display_option(window, &option);
    }
    destroy_option(&option);
    return (0);
}
