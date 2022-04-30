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
	node *next_value;

	next = *stack_a;
	first_node = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->next == NULL)
			next_value = first_node;
		else
			next_value = (*stack_a)->next;
		if ((*stack_a)->value < value && next_value->value > value)
			next = next_value;
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

static void get_element_top(node **stack, int value, int side, int aorb)
{

	// I neeed to get an element to the top
	while ((*stack)->first > value != value)
	{
		if (!side)
		{
		}
	}
}

static int min_comp(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static void rotate(node **stack_a, node **stack_b, int side, int rotations)
{
	int i;

	i = 0;
	if (side)
	{
		while (i++ < rotations)
			rrr(&*stack_a, &*stack_b);
	}
	else
	{
		while (i++ < rotations)
			rr(&*stack_a, &*stack_b);
	}
}

static void rotate_0(node **stack, int aorb, int rotates)
{
	int i;

	i = 0;
	if (!aorb)
	{
		while (i < rotates)
		{
			ra(&*stack);
			i++;
		}
	}
	else
	{
		while (i < rotates)
		{
			rb(&*stack);
			i++;
		}
	}
}

static void rotate_1(node **stack, int aorb, int rotates)
{
	int i;

	i = 0;
	if (!aorb)
	{
		while (i < rotates)
		{
			rra(&*stack);
			i++;
		}
	}
	else
	{
		while (i < rotates)
		{
			rrb(&*stack);
			i++;
		}
	}
}

static void rotate_moves(node **stack_a, node **stack_b, int side_a, int min, int moves_a, int moves_b)
{
	if (!side_a)
	{
		rotate_0(&*stack_a, 0, moves_a - min);
		rotate_0(&*stack_b, 1, moves_b - min);
	}
	else
	{
		rotate_1(&*stack_a, 0, moves_a - min);
		rotate_1(&*stack_b, 1, moves_b - min);
	}
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

static void check_moves(node *nodec, int *side, int *moves, node *stack)
{
	if (((float)(nodec->position) / list_size(stack->first)) > 0.5)
	{
		*moves = list_size(stack->first) - nodec->position;
		*side = 1;
	}
	else
	{
		*moves = nodec->position;
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
	int i = 0;

	first_node_b = *stack_b;
	while (*stack_b && i < list_size((*stack_b)->first))
	{
		*stack_b = get_min_moves(*stack_b);
		next = get_next_number((*stack_b)->value, &*stack_a);

		check_moves(*stack_b, &side_b, &moves_b, (*stack_b)->first);
		check_moves(next, &side_a, &moves_a, *stack_a);
		ft_printf("*value_b:%d/side_b:%d/moves_b:%d|||value_a:%d/side_a:%d/moves_a:%d\n", (*stack_b)->value, side_b, moves_b, next->value, side_a, moves_a);

		// here I havee to check if both are going the same way, otherwise
		// make them rr/rrr the same distance and let the max finish the distance
		if (side_a == side_b)
		{
			// rr and rrr and ra/rb the rest
			rotate(&*stack_a, &*stack_b, side_a, min_comp(moves_a, moves_b));
			rotate_moves(&*stack_a, &*stack_b, side_a, min_comp(moves_a, moves_b), moves_a, moves_b);
		}
		else
		{
			// brute force single push
			classic_push(&*stack_b, &*stack_a, next);
			// I still neeed to make this function
			// Stopped on get element top line: 50
			// I have to get *stack_b to the top, and get next to top and then use pa
		}

		//----------------next element
		*stack_b = (*stack_b)->next;
		i++;
		// if (list_size((*stack_b)->first))
		// 	*stack_b = (*stack_b)->first;
		// else
		// 	break;
	}
	*stack_b = first_node_b;
}