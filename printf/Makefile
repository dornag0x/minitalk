# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 17:33:04 by hfeufeu           #+#    #+#              #
#    Updated: 2024/11/03 17:35:07 by hfeufeu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = ft_printf.c \
		ft_mininbr.c \
		ft_ministr.c \
		ft_uputnbr.c \
		ft_pointprint.c \
		ft_puthexa.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
