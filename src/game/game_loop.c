/*
** EPITECH PROJECT, 2020
** game_loop
** File description:
** game_loop
*/

#include "my_rpg.h"

void play_attack_sound(obj_t *obj)
{
    if (obj->check_s == 0)
        sfSound_play(obj->sound->attack);
}

void game_loop(obj_t *obj)
{
    sfEvent event = {0};
    sfClock *clock = sfClock_create();
    sfTime time = {0};

    if (obj->check_s == 0)
        sfSound_play(obj->sound->song);
    sfRenderWindow_setFramerateLimit(obj->win, 60);
    while (sfRenderWindow_isOpen(obj->win) && obj->quit == 0) {
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds > 60000) {
            sfClock_restart(clock);
            game_engine(obj);
            game_event(obj, event);
            game_render(obj);
        }
    }
    sfSoundBuffer_destroy(obj->sound->buf1);
    sfSoundBuffer_destroy(obj->sound->buf2);
    sfSound_destroy(obj->sound->song);
    sfSound_destroy(obj->sound->attack);
}
