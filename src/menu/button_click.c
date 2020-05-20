
/*
** EPITECH PROJECT, 2020
** CSFML
** File description:
** bottom is clicked
*/

#include <stdlib.h>
#include "my_rpg.h"
#include <stdio.h>

sfBool is_mouse_on_button(button_t *button)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    sfBool condition = sfFalse;

    condition = sfIntRect_contains(button->hitbox, mouse.x, mouse.y);
    return (condition);
}

sfBool mouse_button_pressed(void)
{
    sfMouseButton mouse = sfMouseLeft;
    sfBool condition = sfMouse_isButtonPressed(mouse);

    return (condition);
}

sfBool button_pressed(button_t *button)
{
    sfBool pos = sfFalse;
    sfBool pressed = sfFalse;
    sfBool condition = sfFalse;

    pos = is_mouse_on_button(button);
    pressed = mouse_button_pressed();
    if (pos == sfTrue)
        button->bounds.left = button->size_sprite.x;
    else if (pos == sfFalse)
        button->bounds.left = 0;
    if (pos == sfTrue && pressed == sfTrue) {
        button->bounds.left = button->size_sprite.x * 2;
        condition = sfTrue;
    }
    return (condition);
}