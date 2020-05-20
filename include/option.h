/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** option
*/

#ifndef OPTION_H_
#define OPTION_H_

//  loop.c
int options_loop(sfRenderWindow *window, m_menu *menu);

//  init_option.c
m_opt init_texture_option(void);
void upgrade_option(m_opt *option);
void display_option(sfRenderWindow *window, m_opt *option);
void destroy_option(m_opt *option);

//  option_events.c
int option_events(sfRenderWindow *window, m_opt *option, m_menu *menu);

//  option_button.c
void opt_button_quit(m_opt *option);
void opt_button_video(m_opt *option, sfRenderWindow *window, m_menu *menu);
void opt_button_sound(m_opt *option, sfRenderWindow *window, m_menu *menu);
void m_button_option(m_opt *option, sfRenderWindow *window, m_menu *menu);
#endif /* !OPTION_H_ */
