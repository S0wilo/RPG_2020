/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_option
*/

#include "my_rpg.h"
#include "option.h"

m_opt init_texture_option(void)
{
    m_opt option;
    sfVector2i s_sprite = {200, 60};

    option.quit_pressed = 0;
    option.background = create_object("sprite/Options/background.png"
    , 0, 0);
    option.button_sound = create_button("sprite/Options/button_sound.png",
    400, 300, s_sprite);
    option.button_video = create_button("sprite/Options/button_video.png",
    400, 450, s_sprite);
    option.button_quit = create_button("sprite/Options/button_quit.png",
    400, 600, s_sprite);
    return (option);
}

void upgrade_option(m_opt *option)
{
    sfSprite_setTextureRect(option->button_sound.sprite,
    option->button_sound.bounds);
    sfSprite_setTextureRect(option->button_video.sprite,
    option->button_video.bounds);
    sfSprite_setTextureRect(option->button_quit.sprite,
    option->button_quit.bounds);
}

void display_option(sfRenderWindow *window, m_opt *option)
{
    sfRenderWindow_clear(window, sfBlack);
    upgrade_option(option);
    sfRenderWindow_drawSprite(window, option->background.sprite, NULL);
    sfRenderWindow_drawSprite(window, option->button_sound.sprite, NULL);
    sfRenderWindow_drawSprite(window, option->button_video.sprite, NULL);
    sfRenderWindow_drawSprite(window, option->button_quit.sprite, NULL);
    sfRenderWindow_display(window);
}

void destroy_option(m_opt *option)
{
    destroy_object(&option->background);
    destroy_button(&option->button_sound);
    destroy_button(&option->button_video);
    destroy_button(&option->button_quit);
}
