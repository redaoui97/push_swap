/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_push_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:21:11 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:12:14 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

t_node	*get_biggest(t_node **stack_a)
{
	t_node	*first_node;
	t_node	*biggest;

	biggest = *stack_a;
	first_node = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->value > biggest->value)
			biggest = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first_node;
	return (biggest);
}

t_node	*get_next_number(int value, t_node **stack_a)
{
	t_node	*next;
	t_node	*first_node;
	int		next_value;

	next = get_biggest(&*stack_a);
	first_node = *stack_a;
	*stack_a = (*stack_a)->first;
	while (*stack_a)
	{
		if ((*stack_a)->value > value && (*stack_a)->value < next->value)
			next = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first_node;
	return (next);
}

t_node	*get_min_moves(t_node *stack_b)
{
	t_node	*min;

	min = stack_b;
	while (stack_b)
	{
		if (stack_b->moves_count < min->moves_count)
			min = stack_b;
		stack_b = stack_b->next;
	}
	return (min);
}

void	get_element_top_a(t_node **stack, int value, int side)
{
	while ((*stack)->first->value != value)
	{
		if (!side)
			ra(&*stack);
		else
			rra(&*stack);
	}
}

void	get_element_top_b(t_node **stack, int value, int side)
{
	while ((*stack)->first->value != value)
	{
		if (!side)
			rb(&*stack);
		else
			rrb(&*stack);
	}
}
