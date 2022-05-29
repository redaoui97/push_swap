# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnabil <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 23:29:21 by rnabil            #+#    #+#              #
#    Updated: 2022/05/20 23:29:24 by rnabil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
Flag = -Wall -Wextra -Werror
FUNCTIONS_list_management = l_list_management/add_element l_list_management/clear_elements \
	    l_list_management/duplicate_node l_list_management/list_size \
	    l_list_management/new_node l_list_management/remove_element \
	    l_list_management/show_elements l_list_management/set_min_first
FUNCTIONS_moves = moves/pa moves/pb moves/ra moves/rb moves/rr \
		  moves/rra moves/rrb moves/rrr moves/sa moves/sb \
		  moves/ss
FUNCTIONS_printf = ../ft_printf/ft_printf ../ft_printf/ft_strlen \
		   ../ft_printf/print_addresse ../ft_printf/print_char \
		   ../ft_printf/print_hex_lower ../ft_printf/print_hex_upper \
		   ../ft_printf/print_nbr ../ft_printf/print_nbr_unsigned \
		   ../ft_printf/print_str
FUNCTIONS_src = checker src/atoi src/parsin src/is_sorted src/src_parsin
FUNCTIONS_gnl = get_next_line/get_next_line get_next_line/get_next_line_utils

OBJS_list = $(FUNCTIONS_list_management:=.o)
OBJS_moves = $(FUNCTIONS_moves:=.o)
OBJS_printf = $(FUNCTIONS_printf:=.o)
OBJS_src = $(FUNCTIONS_src:=.o)
OBJS_gnl = $(FUNCTIONS_gnl:=.o)
NAME = checker
AR = ar rc

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME): $(OBJS_list) $(OBJS_moves) $(OBJS_printf) $(OBJS_src) $(OBJS_gnl)
	$(CC) $(FLAGS) $(OBJS_list) $(OBJS_moves) $(OBJS_printf) $(OBJS_gnl) $(OBJS_src) -o $(NAME)

%.o: %.c header/bonus.h
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS_list) $(OBJS_moves) $(OBJS_printf) $(OBJS_src) $(OBJS_gnl)

fclean: clean
	rm -f $(NAME)

re: fclean all
