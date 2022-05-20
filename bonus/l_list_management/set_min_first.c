/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:31:58 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:25:35 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

static t_node	*get_min(t_node *stack_a)
{
	t_node	*min;

	min = stack_a;
	while (stack_a)
	{
		if (stack_a->value < min->value)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void	set_min_first(t_node **stack_a)
{
	t_node	*first_node;
	t_node	*min_node;
	int		min;

	first_node = *stack_a;
	min_node = get_min(*stack_a);
	min = min_node->value;
	if (((min_node->position + 1) / list_size((*stack_a)->first)) >= 0.5)
	{
		while (min != (*stack_a)->first->value)
			rra(&*stack_a);
	}
	else
	{
		while ((*stack_a)->first->value != min)
			ra(&*stack_a);
	}
	*stack_a = (*stack_a)->first;
}
