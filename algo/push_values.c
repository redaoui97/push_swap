/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:33:15 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/15 13:10:27 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static node *get_next_number(int value, node **stack_a)
{
	node *next;
	node *first_node;
	int next_value;

	next = *stack_a;
	first_node = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->next == NULL)
			next_value = first_node->value;
		else
			next_value = (*stack_a)->next->value;
		if ((*stack_a)->value < value && next_value > value)
			next = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first_node;
	return (next);
}

static node *get_min_moves(node *stack_b)
{
	node *min;

	min = stack_b;
	while (stack_b)
	{
		if (stack_b->moves_count < min->moves_count)
			min = stack_b;
		stack_b = stack_b->next;
	}
	return (min);
}

/*static void classic_sort(node **stack_a, node **stack_b)
{
	node *first_node_a;
	node *first_node_b;
	node *next;
	int i;
	int j;

	i = 0;
	first_node_a = *stack_a;
	first_node_b = *stack_b;
	while (*stack_b)
	{
	}
	while (i < list_size(first_node_b))
	{
		j = 0;
		while (j < get_min_index(*stack_b))
		{
			rb(&*stack_b);
			j++;
		}
		j = 0;
		next = get_next_number((*stack_b)->value, &*stack_a);
		while (j < next->position)
		{
			ra(&*stack_a);
			j++;
		}
		pa(&*stack_a, &*stack_b);
		*stack_a = (*stack_a)->first;
		*stack_b = (*stack_b)->first;
		i++;
	}
	*stack_a = (*stack_a)->first;
	*stack_b = (*stack_b)->first;
	show_elements(*stack_a);
	show_elements(*stack_b);
}*/
static void check_moves(node *nodec, int *side, int *moves, node **stack)
{
	if ((float)((*stack)->position / list_size((*stack)->first)) < 0.5)
	{
		*moves = list_size((*stack)->first) - (*stack)->position;
		*side = 1;
	}
	else
	{
		*moves = (*stack)->position;
		*side = 0;
	}
}

void push_values(node **stack_a, node **stack_b)
{
	int side_a;
	int side_b;
	int moves_a;
	int moves_b;
	node *first_node_b;
	node *next;

	while (*stack_b)
	{
		*stack_b = get_min_moves(*stack_b);
		next = get_next_number((*stack_b)->value, &*stack_a);
		check_moves(*stack_b, &side_b, &moves_b, &*stack_b);
		check_moves(next, &side_a, &moves_a, &*stack_a);
		// here I havee to check if both are going the same way, otherwise
		// make them rr/rrr the same distance and let the max finish the distance
		//
		if (list_size((*stack_b)->first))
			*stack_b = (*stack_b)->first;
		else
			break;
	}
}