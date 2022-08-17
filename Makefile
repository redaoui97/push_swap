# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnabil <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 17:51:55 by rnabil            #+#    #+#              #
#    Updated: 2022/08/15 13:01:40 by rnabil           ###   ########.fr        #
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
FUNCTIONS_printf = ft_printf/ft_printf ft_printf/ft_strlen \
		   ft_printf/print_addresse ft_printf/print_char \
		   ft_printf/print_hex_lower ft_printf/print_hex_upper \
		   ft_printf/print_nbr ft_printf/print_nbr_unsigned \
		   ft_printf/print_str
FUNCTIONS_algo = push_swap algo/lis_algo/calculate_lis algo/lis_algo/bool_lis_calculator algo/lis_algo/send_zeros algo/lis_algo/calculate_moves \
		   algo/lis_algo/first_calculation algo/lis_algo/second_calculation algo/lis_algo/push_values algo/three_elem_algo/three_algo \
		   algo/five_elem_algo/five_algo algo/lis_algo/src_push_values algo/lis_algo/push_values_src
FUNCTIONS_src = src/atoi src/parsin src/is_sorted src/src_parsin src/split

OBJS_list = $(FUNCTIONS_list_management:=.o)
OBJS_moves = $(FUNCTIONS_moves:=.o)
OBJS_algo = $(FUNCTIONS_algo:=.o)
OBJS_printf = $(FUNCTIONS_printf:=.o)
OBJS_src = $(FUNCTIONS_src:=.o)
NAME = push_swap

Compiling = 1
Color1 = \e[92;5;118m
Color2 = \033[0;33m

#Bonus

FUNCTIONS_moves_bonus = bonus/moves/pa bonus/moves/pb bonus/moves/ra bonus/moves/rb bonus/moves/rr \
		  bonus/moves/rra bonus/moves/rrb bonus/moves/rrr bonus/moves/sa bonus/moves/sb \
		  bonus/moves/ss
FUNCTIONS_src_bonus = bonus/checker bonus/src/atoi bonus/src/parsin bonus/src/is_sorted bonus/src/src_parsin bonus/src/split
FUNCTIONS_gnl_bonus = bonus/get_next_line/get_next_line bonus/get_next_line/get_next_line_utils

OBJS_moves_bonus = $(FUNCTIONS_moves_bonus:=.o)
OBJS_src_bonus = $(FUNCTIONS_src_bonus:=.o)
OBJS_gnl_bonus = $(FUNCTIONS_gnl_bonus:=.o)
NAME2 = checker

.PHONY: all clean fclean re bonus

all : $(NAME)

bonus : $(NAME2)

$(NAME): $(OBJS_list) $(OBJS_moves) $(OBJS_algo) $(OBJS_printf) $(OBJS_src)
	@$(CC) $(Flag) $(OBJS_list) $(OBJS_moves) $(OBJS_algo) $(OBJS_printf) $(OBJS_src) -o $(NAME)

$(NAME2): $(OBJS_list) $(OBJS_moves_bonus) $(OBJS_printf) $(OBJS_src_bonus) $(OBJS_gnl_bonus)
	@$(CC) $(Flag) $(OBJS_list) $(OBJS_moves_bonus) $(OBJS_printf) $(OBJS_gnl_bonus) $(OBJS_src_bonus) -o $(NAME2)
	@printf "\n${Color1}Compiling bonus..."

%.o: %.c header/push_swap.h bonus/header/checker.h
	@if [ $(Compiling) = '1' ]; then\
		printf "${Color1}│                 ${Color1}Compiling...                ${Color1}│\n${Color1}│";\
	fi
	$(eval Compiling=$(shell echo $$(($(Compiling)+1))))
	@printf "${Color1}▓"
	@$(CC) $(Flag) -c $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader *

clean:
	@rm -f $(OBJS_list) $(OBJS_moves) $(OBJS_algo) $(OBJS_printf) $(OBJS_src) $(OBJS_moves_bonus) $(OBJS_src_bonus) $(OBJS_gnl_bonus)
	@printf "${Color2}Removing object files...\n"

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@printf "${Color2}Removing executable...\n"

re: fclean all
