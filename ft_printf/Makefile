# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnabil <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:20:19 by rnabil            #+#    #+#              #
#    Updated: 2021/12/11 16:50:39 by rnabil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
FUNCTIONS = ft_printf print_addresse print_char print_nbr print_hex_lower \
			print_hex_upper print_nbr_unsigned print_str ft_strlen
OBJS = $(FUNCTIONS:=.o)
NAME = libftprintf.a
AR = ar rc

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
