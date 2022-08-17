/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:31:54 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 17:20:25 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static t_node	*get_biggest_here(t_node **stack_a)
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

static t_node	*get_next_number_here(int value, t_node **stack_a)
{
	t_node	*next;
	t_node	*first_node;

	next = get_biggest_here(&*stack_a);
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

void	second_calculation(t_node **stack_a, t_node **stack_b)
{
	t_node	*first_node_a;
	t_node	*first_node_b;
	t_node	*next;

	first_node_b = *stack_b;
	first_node_a = *stack_a;
	while (*stack_b)
	{
		next = get_next_number_here((*stack_b)->value, &*stack_a);
		if (next->position <= (list_size(first_node_a) / 2))
			(*stack_b)->moves_count += next->position;
		else
			(*stack_b)->moves_count += list_size(first_node_a) - next->position;
		*stack_b = (*stack_b)->next;
	}
	*stack_a = first_node_a;
	*stack_b = first_node_b;
}
