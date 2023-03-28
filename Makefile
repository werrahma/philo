# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: werrahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 19:11:35 by werrahma          #+#    #+#              #
#    Updated: 2023/03/23 21:52:39 by werrahma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = test.c philo.c ft_atoi.c
NAME = philo

OBJ = $(SRC:.c=.o)

CC = CC

CFLAGS = -fsanitize=address -g #-Wall -Wextra -Werror
all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all