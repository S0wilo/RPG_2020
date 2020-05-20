##
## EPITECH PROJECT, 2019
## Makefile for eval_expr
## File description:
## Root Makefile
##

SRC		=	main.c								\
			menu/create_object.c				\
			menu/create_button.c				\
			menu/menu_events.c					\
			menu/menu.c							\
			menu/button_menu.c					\
			menu/button_click.c					\
			options/loop.c						\
			options/init_option.c				\
			options/option_button.c				\
			options/option_events.c				\
			options_sound/loop_sound.c			\
			options_sound/init_opt_sound.c		\
			options_sound/opt_sound_button.c	\
			options_sound/opt_sound_events.c	\
			options_video/loop_video.c			\
			options_video/init_opt_video.c		\
			options_video/opt_video_button.c	\
			options_video/opt_video_events.c	\
			how_to_play/h_t_p_events.c			\
			how_to_play/init_h_t_p.c			\
			how_to_play/loop_h_t_p.c	\
			game/game_initialize.c  \
                        game/game_init_charact.c        \
                        game/game_init_room1.c  \
                        game/game_init_room2.c  \
                        game/game_init_room3.c  \
                        game/game_init_room4.c  \
                        game/game_init_room5.c  \
                        game/game_loop.c        \
                        game/game_render.c      \
                        game/game_render_charact.c      \
                        game/game_render_charact_move.c \
                        game/game_render_charact_static.c       \
                        game/game_render_mob.c  \
                        game/game_event.c       \
                        game/game_event_move_charact.c  \
                        game/game_event_move_charact_depth.c    \
                        game/game_engine.c      \
                        game/game_engine_charact.c      \
                        game/game_engine_mob.c  \
                        game/game_menu_pause.c  \
                        game/game_dialogue.c    \
                        game/game_stat.c	\
			game/execute_cursor.c

$(eval SRC = $(addprefix src/, $(SRC)))

SRC_TEST	=	tests/eval_expr_tests.c	\

NAME	=	my_rpg

RUN_TESTS	=	./test_crite

Flag	=	-Wall -Wextra

CC	=	gcc

all:	run

run:
	$(CC) -o $(NAME) $(SRC) -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -I./include $(Flag)
	rm -f $(OBJ)

debug:
	$(CC) -o $(NAME) $(SRC) -l csfml-graphics -l csfml-window -l csfml-audio -I./include -g3
clean:
	find -name "*.o" -delete

fclean:
	rm -f test_crite
	rm -f $(NAME)
	make fclean -C lib/my
	make fclean -C lib/Csfml

re:     fclean, all

.PHONY: all, clean, fclean, re, tests_run, run
