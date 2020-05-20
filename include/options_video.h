/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** options_video
*/

#include "my_rpg.h"

#ifndef OPTIONS_VIDEO_H_
#define OPTIONS_VIDEO_H_

//  loop_video.c
int opt_loop_video(sfRenderWindow *window, m_opt *option, m_menu *menu);

//  init_opt_video.c
m_opt_video init_texture_video(void);
void upgrade_opt_video(m_opt_video *option);
void display_opt_video(sfRenderWindow *window, m_opt_video *option);
void destroy_opt_video(m_opt_video *option);

//  opt_video_events.c
int opt_eve_v(sfRenderWindow *win, m_opt_video *opti, m_opt *opt, m_menu *menu);

//  opt_video_button.c
void opt_video_button_quit(m_opt_video *option);
void opt_video_button_v(m_opt_video *opt, m_menu *menu, sfRenderWindow * win);
void m_opt_b_video(m_opt_video *opt, m_menu *menu, sfRenderWindow * win);
int checkbox_pressed(button_t *button, int sprite);

#endif /* !OPTIONS_VIDEO_H_ */
