# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 13:45:43 by hfeufeu           #+#    #+#              #
#    Updated: 2025/01/30 13:14:42 by hfeufeu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/client.c \
		  src/server.c \
		  src/err_handle.c \
		  src/lst_handle.c \

BUILD	= build

OBJS	= $(SRCS:src/%.c=$(BUILD)/%.o)

NAME	= minitalk

CC		= cc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

$(BUILD):
			@mkdir -p $(BUILD)

$(BUILD)/%.o:	src/%.c | $(BUILD)
			@${CC} ${CFLAGS} -Ilibft -Iprintf -c $< -o $@

${NAME}:	server client

server:		$(BUILD)/server.o $(BUILD)/err_handle.o $(BUILD)/lst_handle.o
			@make -C libft --silent
			@make -C printf --silent
			@${CC} ${CFLAGS} $^ -Llibft -lft -Lprintf -lftprintf -o server

client:		$(BUILD)/client.o $(BUILD)/err_handle.o $(BUILD)/lst_handle.o
			@make -C libft --silent
			@make -C printf --silent
			@${CC} ${CFLAGS} $^ -Llibft -lft -Lprintf -lftprintf -o client

libft:
			@make -C libft --silent

printf:
			@make -C printf --silent

clean:
			@make clean -C libft --silent
			@make clean -C printf --silent
			@${RM} -r $(BUILD)

fclean:		clean
			@${RM} server client

re:			fclean all

.PHONY:		libft printf

