/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** options_sound
*/

#include "my_rpg.h"

#ifndef OPTIONS_SOUND_H_
#define OPTIONS_SOUND_H_

//  loop_sound.c
int opt_loop_sound(sfRenderWindow *window, m_opt *option, m_menu *menu);

//  init_opt_sound.c
m_opt_video init_texture_sound(void);
void upgrade_opt_sound(m_opt_video *option);
void display_opt_sound(sfRenderWindow *window, m_opt_video *option);
void destroy_opt_sound(m_opt_video *option);

//  opt_sound_events.c
int opt_eve_s(sfRenderWindow *win, m_opt_video *opti, m_opt *opt, m_menu *menu);

//  opt_sound_button.c
int checkbox_pressed_v(button_t *button, m_menu *menu);
void opt_sound_button_quit(m_opt_video *option);
void opt_sound_button_sound(m_opt_video *option, m_menu *menu);
void m_opt_b_sound(m_opt_video *opt, m_menu *menu);
#endif /* !OPTIONS_SOUND_H_ */
