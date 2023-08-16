# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emoumni <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 03:58:57 by emoumni           #+#    #+#              #
#    Updated: 2023/02/02 03:59:02 by emoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror

NAME =	libftprintf.a

SRC = ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c ft_printf_utils.c ft_printf.c ft_itoa_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	@cc $(FLAG) -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re