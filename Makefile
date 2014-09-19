#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbell <vbell@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 18:31:54 by vbell             #+#    #+#              #
#    Updated: 2014/03/10 19:54:08 by bdelpey          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
NAME = puissance4
SRC = src/main.c src/init_map.c src/is_num.c src/check_info.c \
	src/player_turn.c src/insert_piece.c src/who_s_begin.c src/ia_turn.c \
	src/is_winner.c src/check_diag.c src/lets_play.c src/ia_functs.c \
	src/versus.c
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L libft -lft
INCLUDES = -I includes -I libft/includes
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean re fclean
