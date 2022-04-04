/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:41 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/04 14:49:43 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes, remember to remove stdio later
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

//linked list
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
} node;

//Functions ft_printf
int		ft_printf(const char *f, ...);
int		print_addresse(unsigned long int adr);
int		print_nbr(int n);
int		print_hex_lower(unsigned int nbr);
int		print_hex_upper(unsigned int nbr);
int		print_nbr_unsigned(unsigned int nbr);
int		print_str(char *str);
int		print_char(char chr);
size_t	ft_strlen(const char *str);

//functions nodes implementation
node	*new_node(int value);
void	add_element(node **stack_a, int value);
void	show_elements(node *stack_a);
void	clear_elements(node **stack_a);
int		list_size(node *stack_a);
node	*duplicate_node(node *old); //it's useless so far
void	remove_element(node **stack_a);

//move operations
void	sa(node **stack_a);
void	sb(node **stack_b); //basically the same as sa.c
void	ss(node **stack_a, node **stack_b);
void	pa(node **stack_a, node **stack_b);
void	pb(node **stack_a, node **stack_b);
void	ra(node **stack_a);
void	rb(node **stack_b);
void	rr(node **stack_a, node **stack_b);
void	rra(node **stack_a);
void	rrb(node **stack_b);
void	rrr(node **stack_a, node **stack_b);

//algo functins
void	calculate_lis(node **stack_a);
void	bool_lis_calculator(node **stack_a);
void	send_zeros(node **stack_a, node **stack_b);
void	calculate_moves(node **stack_a, node **stack_b);

//src functions
int		ft_atoi(char *str);

#endif
