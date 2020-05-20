/*
** EPITECH PROJECT, 2020
** CSFML
** File description:
** create_object
*/

#include <stdlib.h>
#include "my_rpg.h"

game_object_t create_object (char *path, int x, int y)
{
    game_object_t object;

    object.texture = malloc(sizeof(sfTexture *));
    object.texture = sfTexture_createFromFile(path, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.pos.x = x;
    object.pos.y = y;
    object.move.x = 1;
    object.move.y = 1;
    sfSprite_setPosition(object.sprite, object.pos);
    object.hitbox = malloc(sizeof(sfIntRect));
    return (object);
}

void move_object(game_object_t *object)
{
    object->pos.x += object->move.x;
    object->pos.y += object->move.y;
    sfSprite_setPosition(object->sprite, object->pos);
}

void destroy_object(game_object_t *object)
{
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
}

void init_hitbox(game_object_t *object)
{
    sfVector2u size_texture = sfTexture_getSize (object->texture);

    object->hitbox->top = object->pos.y;
    object->hitbox->left = object->pos.x;
    object->hitbox->width = size_texture.x;
    object->hitbox->height = size_texture.y;
}
