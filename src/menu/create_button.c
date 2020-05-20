/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_button
*/

#include <stdlib.h>
#include "my_rpg.h"

button_t create_button(char *path, int x, int y, sfVector2i s_sprite)
{
    button_t button;

    button.texture = malloc(sizeof(sfTexture *));
    button.texture = sfTexture_createFromFile(path, NULL);
    button.sprite = sfSprite_create();
    button.pos.x = x;
    button.pos.y = y;
    button.size_sprite = s_sprite;
    init_bounds(&button.bounds, s_sprite);
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    sfSprite_setTextureRect(button.sprite, button.bounds);
    sfSprite_setPosition(button.sprite, button.pos);
    button.hitbox = malloc(sizeof(sfIntRect));
    init_hitbox_button(&button);
    return (button);
}

void init_bounds(sfIntRect *bounds, sfVector2i s_sprite)
{
    bounds->height = s_sprite.y;
    bounds->left = 0;
    bounds->top = 0;
    bounds->width = s_sprite.x;
}

void destroy_button(button_t *button)
{
    sfTexture_destroy(button->texture);
    sfSprite_destroy(button->sprite);
}

void init_hitbox_button(button_t *button)
{
    button->hitbox->top = (int)button->pos.y + (button->size_sprite.y);
    button->hitbox->left = (int)button->pos.x;
    button->hitbox->width = button->size_sprite.x;
    button->hitbox->height = button->size_sprite.y;
}
