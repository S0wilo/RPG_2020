/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** option_button
*/

#include "my_rpg.h"
#include "option.h"
#include "options_sound.h"
#include "options_video.h"

void opt_button_quit(m_opt *option)
{
    sfBool click = button_pressed(&option->button_quit);

    if (click == sfTrue)
        option->quit_pressed = 1;
}

void opt_button_video(m_opt *option, sfRenderWindow *window, m_menu *menu)
{
    sfBool click = button_pressed(&option->button_video);

    if (click == sfTrue)
        opt_loop_video(window, option, menu);
}

void opt_button_sound(m_opt *option, sfRenderWindow *window, m_menu *menu)
{
    sfBool click = button_pressed(&option->button_sound);

    if (click == sfTrue)
        opt_loop_sound(window, option, menu);
}

void m_button_option(m_opt *option, sfRenderWindow *window, m_menu *menu)
{
    opt_button_quit(option);
    opt_button_sound(option, window, menu);
    opt_button_video(option, window, menu);
}
