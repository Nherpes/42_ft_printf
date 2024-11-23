# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:52:00 by david-fe          #+#    #+#              #
#    Updated: 2024/11/19 14:57:44 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#files

NAME = libftptrintf.a

OBJ = $(SRC:.c=.o)
SRC = ft_printf.c ft_strchr.c ft_strlen.c ft_putchar.c ft_putnbr.c ft_putunbr.c ft_putstr.c ft_puthex.c ft_calloc.c ft_putptr.c
#BONUS_OBJ = $(BONUS_SRC:.c=.o)
#BONUS_SRC = 

#rules

all: $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
