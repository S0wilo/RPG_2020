/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** how_to_play
*/

#ifndef HOW_TO_PLAY_H_
#define HOW_TO_PLAY_H_

//  loop_h_t_p.c
int h_t_p_loop(sfRenderWindow *window);

//  init_h_t_p.c
m_htp init_texture_h_t_p(void);
void upgrade_h_t_p(m_htp *h_t_p);
void display_h_t_p(sfRenderWindow *window, m_htp *h_t_p);
void destroy_h_t_p(m_htp *h_t_p);

//  h_t_p_events.c
int h_t_p_events(sfRenderWindow *window, m_htp *option);
void h_t_p_button_quit(m_htp *h_t_p);
#endif /* !HOW_TO_PLAY_H_ */
