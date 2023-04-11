# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: werrahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 19:11:35 by werrahma          #+#    #+#              #
#    Updated: 2023/04/10 20:28:17 by werrahma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c ft_atoi.c checker.c monitor.c help.c
NAME = philo

OBJ = $(SRC:.c=.o)

CC = CC

CFLAGS = #-fsanitize=thread -g3 #-Wall -Wextra -Werror #
all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all