CC = gcc
Flag = -Wall -Wextra -Werror
FUNCTIONS_list_management = l_list_management/add_element l_list_management/clear_elements \
	    l_list_management/duplicate_node l_list_management/list_size \
	    l_list_management/new_node l_list_management/remove_element \
	    l_list_management/show_elements
FUNCTIONS_moves = moves/pa moves/pb moves/ra moves/rb moves/rr \
		  moves/rra moves/rrb moves/rrr moves/sa moves/sb \
		  moves/ss
FUNCTIONS_printf = ft_printf/ft_printf ft_printf/ft_strlen \
		   ft_printf/print_addresse ft_printf/print_char \
		   ft_printf/print_hex_lower ft_printf/print_hex_upper \
		   ft_printf/print_nbr ft_printf/print_nbr_unsigned \
		   ft_printf/print_str
FUNCTIONS_algo = push_swap
OBJS_list = $(FUNCTIONS_list_management:=.o)
OBJS_moves = $(FUNCTIONS_moves:=.o)
OBJS_algo = $(FUNCTIONS_algo:=.o)
OBJS_printf = $(FUNCTIONS_printf:=.o)
NAME = push_swap.a
AR = ar rc

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME): $(OBJS_list) $(OBJS_moves) $(OBJS_algo) $(OBJS_printf)
	$(AR) $(NAME) $(OBJS_list) $(OBJS_moves) $(OBJS_algo) $(OBJS_printf)

%.o: %.c header/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_list) $(OBJS_moves) $(OBJS_algo) $(OBJS_prinf)

fclean: clean
	rm -f $(NAME)

re: fclean all
