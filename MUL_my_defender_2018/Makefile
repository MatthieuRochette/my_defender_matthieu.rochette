##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## This file is used for the compilation of the project.
##

SRC =	src/animate_turret.c			\
		src/animation.c					\
		src/backgrounds.c				\
		src/battle.c					\
		src/button.c					\
		src/cooldown.c					\
		src/entity_management.c			\
		src/free.c						\
		src/game_over.c					\
		src/game.c						\
		src/gameloop.c					\
		src/how_to_play.c				\
		src/key.c						\
		src/linked_list.c				\
		src/main.c						\
		src/menu.c						\
		src/music_and_sound.c			\
		src/pause.c						\
		src/settings.c					\
		src/shop.c						\
		src/text.c						\
		src/update.c					\
		src/utils.c						\
		src/victory.c

CC = gcc -o

CFLAGS	=	-W			\
			-Wall		\
			-Wextra		\
			-Iinclude

LDFLAGS =	-lcsfml-graphics	\
			-lcsfml-system		\
			-lcsfml-window		\
			-lcsfml-audio

NAME	=	my_defender

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
		$(CC)	$(NAME)	$(OBJ) $(LDFLAGS)

debug:		CFLAGS	+=	-g
debug:		re

all:		$(NAME)

clean:
	rm	-f	$(OBJ)

fclean:	clean
	rm	-f	$(NAME)

re:	fclean	all

.PHONY:	all	clean