/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:41 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 20:09:29 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct nodes
{
	int				position;
	int				value;
	int				lis;
	int				bool_lis;
	int				moves_count;
	struct nodes	*previous;
	struct nodes	*next;
	struct nodes	*first;
	struct nodes	*last;
}	t_node;

int			print_addresse(unsigned long int adr);
int			ft_printf(const char *f, ...);
int			print_nbr(int n);
int			print_hex_lower(unsigned int nbr);
int			print_hex_upper(unsigned int nbr);
int			print_nbr_unsigned(unsigned int nbr);
int			print_str(char *str);
int			print_char(char chr);
size_t		ft_strlen(const char *str);
t_node		*new_node(int value);
void		add_element(t_node **stack_a, int value);
void		show_elements(t_node *stack_a);
void		clear_elements(t_node **stack_a);
int			list_size(t_node *stack_a);
t_node		*duplicate_node(t_node *old);
void		remove_element(t_node **stack_a);
void		set_min_first(t_node **stack_a);
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);
void		calculate_lis(t_node **stack_a);
void		bool_lis_calculator(t_node **stack_a);
void		send_zeros(t_node **stack_a, t_node **stack_b);
void		calculate_moves(t_node **stack_a, t_node **stack_b);
void		first_calculation(t_node **stack_b);
void		second_calculation(t_node **stack_a, t_node **stack_b);
void		push_values(t_node **stack_a, t_node **stack_b);
void		three_algo(t_node **stack);
void		five_algo(t_node **stack_a, t_node **stack_b);
long int	ft_atoi(char *str);
void		parsin(char *arg, t_node **stack_a);
int			is_sorted(t_node **stack);
t_node		*get_biggest(t_node **stack_a);
t_node		*get_next_number(int value, t_node **stack_a);
t_node		*get_min_moves(t_node *stack_b);
void		get_element_top_a(t_node **stack, int value, int side);
void		get_element_top_b(t_node **stack, int value, int side);
void		error(t_node **stack);
int			is_num(char arg);
int			ft_strcmp(char *s1, char *s2);
int			non_int(char *arg);
#endif
