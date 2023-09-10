# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: werrahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 19:11:35 by werrahma          #+#    #+#              #
#    Updated: 2023/04/17 02:02:31 by werrahma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c ft_atoi.c checker.c monitor.c routine.c
NAME = philo

OBJ = $(SRC:.c=.o)

CC = CC

CFLAGS = -Wall -Wextra -Werror
all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all