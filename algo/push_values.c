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
    node    *next;
    node    *first_node;
    int     next_value;

    next = *stack_a;
    first_node = *stack_a;
    while (*stack_a)
    {
        if((*stack_a)->next == NULL)
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

static int	get_min_moves(node *stack_b)
{
	int	min;

	min = stack_b->moves_count;
	while (stack_b)
	{
		if (stack_b->moves_count < min)
			min = stack_b->moves_count;
		stack_b = stack_b->next;
	}
	return (min);
}

static int  get_min_index(node *stack_b)
{
    int min;
	int	position;

    min = stack_b->moves_count;
	position = stack_b->position;
    while (stack_b)
    {
        if (stack_b->moves_count < min)
		{
			position = stack_b->position;
            min = stack_b->moves_count;
		}
		stack_b = stack_b->next;
    }
    return (position);
}

static void	classic_sort(node **stack_a, node **stack_b)
{
	node	*first_node_a;
	node	*first_node_b;
	node	*next;
	int		i;
	int		j;

	i = 0;
	first_node_a = *stack_a;
	first_node_b = *stack_b;
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
		show_elements(*stack_a);
		show_elements(*stack_b);
	}
}

void	push_values(node **stack_a, node **stack_b)
{
	
	classic_sort(&*stack_a, &*stack_b);
	/*node	*first_node_a;
	node	*first_node_b;
	float	position_a;
	float	position_b;
	node	*next;

	first_node_a = *stack_a;
	first_node_b = *stack_b;
	while(*stack_b)
	{
		next = get_next_number((*stack_b)->value, &*stack_a);
		position_a = (next->position + 1) / list_size(first_node_a);
		position_b = ((*stack_b)->position / list_size(first_node_b);
		if(position_a <= 0.5)
			

	}*/
}