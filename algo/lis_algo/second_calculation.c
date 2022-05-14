/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:31:54 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/13 17:44:58 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static node	*get_biggest(node **stack_a)
{
	node	*first_node;
	node	*biggest;

	biggest = *stack_a;
	first_node = *stack_a;
	while (*stack_a)
	{
		if((*stack_a)->value > biggest->value)
			biggest = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first_node;
	return (biggest);
}

static node	*get_next_number(int value, node **stack_a)
{
	node	*next;
	node	*first_node;
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

void second_calculation(node **stack_a, node **stack_b)
{
	node	*first_node_a;
	node	*first_node_b;
	node	*next;

	first_node_b = *stack_b;
	first_node_a = *stack_a;
	while (*stack_b)
    {
		next = get_next_number((*stack_b)->value, &*stack_a);
        if (next->position <= (list_size(first_node_a) / 2))
            (*stack_b)->moves_count += next->position;
        else
            (*stack_b)->moves_count += list_size(first_node_a) - next->position;
        *stack_b = (*stack_b)->next;
    }
	*stack_a = first_node_a;
	*stack_b = first_node_b;
}
