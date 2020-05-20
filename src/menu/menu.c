/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include "my_rpg.h"

m_menu init_texture_menu(void)
{
    m_menu menu;
    sfVector2i s_sprite = {300, 99};

    menu.background = create_object("sprite/Menu/background.jpg",
    0, 0);
    menu.button_play = create_button("sprite/Menu/button_play.png",
    100, 800, s_sprite);
    menu.button_quit = create_button("sprite/Menu/button_quit.png",
    555, 800, s_sprite);
    menu.button_option = create_button("sprite/Menu/button_options.png",
    1010, 800, s_sprite);
    menu.button_how_to_play = create_button(
        "sprite/Menu/button_how_to_play.png", 1465, 800, s_sprite);
    menu.check_v = 0;
    menu.check_s = 0;
    menu.song = sfSound_create();
    menu.soundBuffer = sfSoundBuffer_createFromFile("audio/musique_menu.ogg");
    sfSound_setBuffer(menu.song, menu.soundBuffer);
    sfSound_play(menu.song);
    return (menu);
}

void upgrade_menu(m_menu *menu)
{
    sfSprite_setTextureRect(menu->button_play.sprite,
    menu->button_play.bounds);
    sfSprite_setTextureRect(menu->button_option.sprite,
    menu->button_option.bounds);
    sfSprite_setTextureRect(menu->button_how_to_play.sprite,
    menu->button_how_to_play.bounds);
    sfSprite_setTextureRect(menu->button_quit.sprite,
    menu->button_quit.bounds);
}

void display_menu(sfRenderWindow *window, m_menu *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    upgrade_menu(menu);
    sfRenderWindow_drawSprite(window, menu->background.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->button_play.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->button_quit.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->button_option.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->button_how_to_play.sprite, NULL);
    sfRenderWindow_display(window);
}

void destroy_menu(m_menu *menu)
{
    destroy_object(&menu->background);
    destroy_button(&menu->button_play);
    destroy_button(&menu->button_quit);
    destroy_button(&menu->button_how_to_play);
    destroy_button(&menu->button_option);
    sfSound_destroy(menu->song);
    sfSoundBuffer_destroy(menu->soundBuffer);
}
