/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:18:54 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:42:20 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_node	*get_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	is_sorted(t_node **stack)
{
	t_node	*previous;
	t_node	*first_node;

	first_node = *stack;
	if (list_size(*stack) < 3)
		return (1);
	if ((*stack)->last->value == get_min(*stack)->value
		&& list_size(*stack) != 3)
		rra(&*stack);
	while (*stack)
	{
		if ((*stack)->position == 0)
			previous = *stack;
		else
			previous = (*stack)->previous;
		if ((*stack)->value < previous->value)
		{
			*stack = first_node;
			return (0);
		}
		*stack = (*stack)->next;
	}
	*stack = first_node;
	return (1);
}
