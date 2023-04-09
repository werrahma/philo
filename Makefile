# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: werrahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 19:11:35 by werrahma          #+#    #+#              #
#    Updated: 2023/04/09 01:43:05 by werrahma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = test.c philo.c ft_atoi.c checker.c
NAME = philo

OBJ = $(SRC:.c=.o)

CC = CC

CFLAGS = #-fsanitize=thread -g #-Wall -Wextra -Werror
all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all