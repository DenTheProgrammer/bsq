# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubyrd <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 18:42:33 by ubyrd             #+#    #+#              #
#    Updated: 2019/03/20 16:32:49 by ubyrd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
HEADER	= ./includes/square_head.h
HDOBJ	= ./includes/square_head.h.gch
SRCS	= ./srcs/*.c
OBJ		= *.o

all:	$(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -I $(HEADER) -c $(SRCS)
		gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ) $(HDOBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all
