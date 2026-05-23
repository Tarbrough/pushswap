# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 11:16:12 by jbauch            #+#    #+#              #
#    Updated: 2026/05/23 12:55:58 by jbauch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC         =	src/main.c \
				src/parse.c \
				src/errors.c \
				src/utils.c \
				src/utils_addendum.c \
				src/swap.c \
				src/push.c \
				src/rotate.c \
				src/reverse.c \
				src/indexing.c \
				src/small_sorting.c \
				src/radix.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
