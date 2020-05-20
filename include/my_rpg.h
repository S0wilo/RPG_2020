/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** header my_defender
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdlib.h>

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

typedef struct character
{
    sfTexture *tex_idle;
    sfTexture *tex_run;
    sfTexture *tex_jump;
    sfTexture *tex_att;
    sfTexture *tex_lad;
    sfTexture *tex_lb;
    sfTexture *tex_hp;
    sfTexture *tex_dead;
    sfSprite *spr_idle;
    sfSprite *spr_run;
    sfSprite *spr_jump;
    sfSprite *spr_att;
    sfSprite *spr_lad;
    sfSprite *spr_lb;
    sfSprite *spr_hp;
    sfSprite *spr_dead;
    sfVector2f pos;
    int z;
    int act;
    int dir;
    int hp;
    int key;
    int xp;
    int att;
    int def;
    sfClock *clock;
} charact_t;

typedef struct mob
{
    sfIntRect rect;
    int act;
    int dir;
    int z;
    int hp;
    sfClock *clock;
} mob_t;

typedef struct map
{
    sfTexture *tex;
    sfSprite *spr;
    sfTexture *tex_bg;
    sfSprite *spr_bg;
    sfIntRect *ground;
    sfIntRect *wall;
    sfIntRect *door;
    sfIntRect *ladder;
    mob_t *mob;
    struct map **door_map;
    sfVector2f *door_pos;
    int nb_platform;
    int nb_wall;
    int nb_door;
    int nb_ladder;
    int nb_mob;
    sfVector2f dim;
} map_t;

typedef struct mob_tex
{
    sfTexture *tex_mob_walk;
    sfTexture *tex_mob_hit;
    sfTexture *tex_mob_att;
    sfTexture *tex_mob_dead;
    sfTexture *tex_key;
    sfSprite *spr_mob_walk;
    sfSprite *spr_mob_hit;
    sfSprite *spr_mob_att;
    sfSprite *spr_mob_dead;
    sfSprite *spr_key;
} mob_tex_t;

typedef struct res_pause
{
    sfTexture *tex_bg;
    sfTexture *tex_cur;
    sfTexture *tex_opt;
    sfTexture *tex_htp;
    sfTexture *tex_exit;
    sfSprite *spr_bg;
    sfSprite *spr_cur;
    sfSprite *spr_opt;
    sfSprite *spr_htp;
    sfSprite *spr_exit;
} res_pause_t;

typedef struct sound
{
    sfSound *song;
    sfSound *attack;
    sfSoundBuffer *buf1;
    sfSoundBuffer *buf2;
} sound_t;

typedef struct obj
{
    sfRenderWindow *win;
    charact_t *charact;
    map_t *map;
    map_t *map_list;
    mob_tex_t *mob;
    int quit;
    sound_t *sound;
    int check_s;
    int check_v;
} obj_t;

void game_initialize(obj_t *);
void game_init_charact(charact_t *);
void init_rect(sfIntRect *, sfIntRect);
void game_init_room1(obj_t *, map_t *);
void game_init_room2(obj_t *, map_t *);
void game_init_room3(obj_t *, map_t *);
void game_init_room4(obj_t *, map_t *);
void game_init_room5(obj_t *, map_t *);
void game_loop(obj_t *);
void game_render(obj_t *);
sfVector2f define_map_pos(obj_t *);
sfVector2f define_charact_pos(obj_t *);
void game_render_charact(obj_t *);
void game_render_charact_move(obj_t *);
void game_render_charact_static(obj_t *);
void game_render_mob(obj_t *, mob_t *);
void game_event(obj_t *, sfEvent);
void game_event_move_charact(obj_t *);
void game_event_move_charact_depth(obj_t *);
void game_engine(obj_t *);
void game_engine_charact(obj_t *);
void game_engine_mob(obj_t *, mob_t *);
void game_menu_pause(obj_t *);
void game_dialogue(obj_t *);
void game_stat(obj_t *);
void play_attack_sound(obj_t *);
void execute_cursor(obj_t *, int, int *);

typedef struct button_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2i size_sprite;
    sfIntRect *hitbox;
    sfIntRect bounds;
    int click;
    int passed;
} button_t;

typedef struct game_object
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f move;
    sfIntRect *hitbox;
} game_object_t;

typedef struct manage_menu
{
    game_object_t background;
    button_t button_play;
    button_t button_quit;
    button_t button_option;
    button_t button_how_to_play;
    sfSound *song;
    sfSoundBuffer *soundBuffer;
    int check_s;
    int check_v;
}m_menu;

typedef struct manage_how_to_play
{
    game_object_t background;
    button_t button_quit;
    int quit_pressed;
}m_htp;

typedef struct manage_menu_opt
{
    game_object_t background;
    button_t button_sound;
    button_t button_video;
    button_t button_quit;
    int quit_pressed;
}m_opt;

typedef struct m_opt_video
{
    game_object_t background;
    game_object_t vsync;
    button_t button_checkbox;
    button_t button_quit;
    int quit_pressed;
    int sprite;
}m_opt_video;

// create_object.c
game_object_t create_object (char *, int, int);
void move_object(game_object_t *);
void destroy_object(game_object_t *);
void init_hitbox(game_object_t *);

// events.c
sfBool is_mouse_on_button(button_t *button);
sfBool mouse_button_pressed(void);
sfBool button_pressed(button_t *button);

// menu.c
m_menu init_texture_menu(void);
void display_menu(sfRenderWindow *, m_menu *);
void destroy_menu(m_menu *);

// events.c
int menu_events(sfRenderWindow *window, m_menu *menu);

// create_button.c
button_t create_button (char *path, int x, int y, sfVector2i);
void init_bounds(sfIntRect *bounds, sfVector2i s_sprite);
void init_hitbox_button(button_t *button);
void destroy_button(button_t *);

//button_menu
void button_quit(m_menu *, sfEvent *);
void button_play(m_menu *menu, sfRenderWindow *window);
void button_how_to_play(m_menu *menu, sfRenderWindow *Window);
void button_option(m_menu *menu, sfRenderWindow *window);
void m_button_menu(m_menu *, sfEvent *, sfRenderWindow *window);

#endif /* !MY_DEFENDER_H_ */
