/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_h_t_p
*/

#include "my_rpg.h"
#include "how_to_play.h"

m_htp init_texture_h_t_p(void)
{
    m_htp h_t_p;
    sfVector2i s_sprite = {200, 60};

    h_t_p.quit_pressed = 0;
    h_t_p.background = create_object("sprite/How_to_play/background.png", 0, 0);
    h_t_p.button_quit = create_button("sprite/How_to_play/button_quit.png",
    400, 900, s_sprite);
    return (h_t_p);
}

void upgrade_h_t_p(m_htp *h_t_p)
{
    sfSprite_setTextureRect(h_t_p->button_quit.sprite,
    h_t_p->button_quit.bounds);
}

void display_h_t_p(sfRenderWindow *window, m_htp *h_t_p)
{
    sfRenderWindow_clear(window, sfBlack);
    upgrade_h_t_p(h_t_p);
    sfRenderWindow_drawSprite(window, h_t_p->background.sprite, NULL);
    sfRenderWindow_drawSprite(window, h_t_p->button_quit.sprite, NULL);
    sfRenderWindow_display(window);
}

void destroy_h_t_p(m_htp *h_t_p)
{
    destroy_object(&h_t_p->background);
    destroy_button(&h_t_p->button_quit);
}
