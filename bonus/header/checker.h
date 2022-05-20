/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:27:24 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 23:28:20 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

void		add_element(t_node **stack_a, int value);
void		clear_elements(t_node **stack_a);
t_node		*duplicate_node(t_node *old);
int			list_size(t_node *stack_a);
t_node		*new_node(int value);
void		remove_element(t_node **stack_a);
void		set_min_first(t_node **stack_a);
void		show_elements(t_node *stack_a);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
long int	ft_atoi(char *str);
int			is_sorted(t_node **stack);
t_node		*get_min(t_node *stack);
void		parsin(char *arg, t_node **stack_a);
void		error(t_node **stack);
int			is_num(char arg);
int			ft_strcmp(char *s1, char *s2);
int			non_int(char *arg);
#endif
