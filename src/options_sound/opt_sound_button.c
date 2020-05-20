/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** opt_sound_button
*/

#include "my_rpg.h"
#include "options_sound.h"

void opt_sound_button_quit(m_opt_video *option)
{
    sfBool click = button_pressed(&option->button_quit);

    if (click == sfTrue)
        option->quit_pressed = 1;
}

void opt_sound_button_sound(m_opt_video *option, m_menu *menu)
{
    menu->check_s = checkbox_pressed_v(&option->button_checkbox, menu);
}

void m_opt_b_sound(m_opt_video *opt, m_menu *menu)
{
    opt_sound_button_quit(opt);
    opt_sound_button_sound(opt, menu);
}

static void checkbox_sound(m_menu *menu)
{
    if (menu->check_s == 0) {
        menu->check_s = 1;
        sfSound_pause(menu->song);
    } else if (menu->check_s == 1) {
        sfSound_play(menu->song);
        menu->check_s = 0;
    }
}

int checkbox_pressed_v(button_t *button, m_menu *menu)
{
    sfBool pos = sfFalse;
    sfBool pressed = sfFalse;

    pos = is_mouse_on_button(button);
    pressed = mouse_button_pressed();
    if (menu->check_s == 0)
        button->bounds.left = 0;
    else if (menu->check_s == 1)
        button->bounds.left = button->size_sprite.x;
    if (pos == sfTrue && pressed == sfTrue) {
        checkbox_sound(menu);
    }
    return (menu->check_s);
}
