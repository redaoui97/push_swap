/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:31:54 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/09 05:37:13 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//calculate the moves necessary to above the right element in stack_a
static int	calculate_superior (node *stack_a, int value)
{
	int		count;
	node	*index;

	count = 0;
	index = stack_a;
	while (stack_a)
	{
		if (stack_a
		count++;
		stack_a = stack_a->next;
	}
}

//calculate the moves necessary to be below the right element in stack_a
static int calculate_down (node *stack_a, int value)
{

}

static void second_calculation(node **stack_a, node **stack_b)
{
	node	*first_node;

	first_node = *stack_b;
	while (*stack_b)
	{
		if (calculate_superior(*stack_a,(*stack_b)->value) > calculate_inferior(*stack_a,(*stack_b)->value))
			(*stack_b)->moves += calculate_inferior(*stack_a, (*stack_b)->value)
		else
			(*stack_b)->moves += calculate_superior(*stack_a, (*stack_b)->value);
		*stack_b = (*stack_b)->next;
	}
}
