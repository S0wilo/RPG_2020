/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_opt_sound
*/

#include "my_rpg.h"
#include "option.h"

m_opt_video init_texture_sound(void)
{
    m_opt_video opt;
    sfVector2i s_sprite_check = {100, 50};
    sfVector2i s_sprite_quit = {200, 60};

    opt.quit_pressed = 0;
    opt.sprite = 0;
    opt.background = create_object("sprite/Options_sounds/background.png"
    , 0, 0);
    opt.vsync = create_object("sprite/Options_sounds/sound.png",
    400, 300);
    opt.button_checkbox = create_button("sprite/Options_sounds/checkbox.png",
    650, 300, s_sprite_check);
    opt.button_quit = create_button("sprite/Options_sounds/button_quit.png",
    400, 500, s_sprite_quit);
    return (opt);
}

void upgrade_opt_sound(m_opt_video *option)
{
    sfSprite_setTextureRect(option->button_checkbox.sprite,
    option->button_checkbox.bounds);
    sfSprite_setTextureRect(option->button_quit.sprite,
    option->button_quit.bounds);
}

void display_opt_sound(sfRenderWindow *window, m_opt_video *option)
{
    sfRenderWindow_clear(window, sfBlack);
    upgrade_opt_sound(option);
    sfRenderWindow_drawSprite(window, option->background.sprite, NULL);
    sfRenderWindow_drawSprite(window, option->vsync.sprite, NULL);
    sfRenderWindow_drawSprite(window, option->button_checkbox.sprite, NULL);
    sfRenderWindow_drawSprite(window, option->button_quit.sprite, NULL);
    sfRenderWindow_display(window);
}

void destroy_opt_sound(m_opt_video *option)
{
    destroy_object(&option->background);
    destroy_object(&option->vsync);
    destroy_button(&option->button_checkbox);
    destroy_button(&option->button_quit);
}
