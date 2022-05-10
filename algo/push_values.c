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

static node	*get_next_number(int value, node **stack_a)
{
	node	*next;
	node	*first_node;
	int		next_value;

	next = *stack_a;
	first_node = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->value > value && (*stack_a)->value < next->value)
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

static void get_element_top_a(node **stack, int value, int side)
{
	// I neeed to get an element to the top
	while ((*stack)->first->value != value)
	{
		if (!side)
		{
			ra(&*stack);
		}
		else
		{
			rra(&*stack);
		}
	}
}

static void get_element_top_b(node **stack, int value, int side)
{
	// I neeed to get an element to the top
	while ((*stack)->first->value != value)
	{
		if (!side)
		{
			rb(&*stack);
		}
		else
		{
			rrb(&*stack);
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

static void classic_push(node **stack_a, node **stack_b, node *next, int side)
{
	get_element_top_a(&*stack_a, next->value, side);
	get_element_top_b(&((*stack_b)->first), (*stack_b)->value, side);
}

void push_values(node **stack_a, node **stack_b)
{
	int side_a;
	int side_b;
	int moves_a;
	int moves_b;
	node *next;
	node *next2;
	int i;
	int size;

	i = 0;
	while (*stack_b)
	{
		//there is a problem in get_next_number: it doesn't return the right next value sometimes
		show_elements(*stack_a);
		show_elements(*stack_b);
		ft_printf("----------\n");
		*stack_b = get_min_moves(*stack_b);
		next = get_next_number((*stack_b)->value, &*stack_a);

		ft_printf("pv|%d:%d\n",(*stack_b)->value, next->value);

		calculate_moves(&*stack_a, &*stack_b);
		check_moves(*stack_b, &side_b, &moves_b, (*stack_b)->first);
		check_moves(next, &side_a, &moves_a, *stack_a);
		
		//something is going on with the second condition move2, it's the one that probably causes the segfault
		if (side_a == side_b)
		{
			ft_printf("move1\n");
			rotate(&*stack_a, &*stack_b, side_a, min_comp(moves_a, moves_b));
			rotate_moves(&*stack_a, &*stack_b, side_a, min_comp(moves_a, moves_b), moves_a, moves_b);
		}
		else
		{
			ft_printf("move2\n");
			classic_push(&*stack_a, &*stack_b, next, side_a);
		}

		//--------------
		/*size = list_size(*stack_b);
		if (*stack_b == (*stack_b)->first)
			next2 = (*stack_b)->next;
		else
			next2 = (*stack_b)->first;
		//--------------
		if (size == 2) // something here; It segfaults when I use *stack_b=(*stack_b)->first so I have to usee something elsee to break the loop
		{
			ft_printf("hhhhh\n");
			*stack_b = next2;
			next = get_next_number((*stack_b)->value, &*stack_a);
			get_element_top_a(&*stack_a, next->value, 0);
			pa(&*stack_a, &*stack_b);
			break;
		}*/
		pa(&*stack_a, &*stack_b);
		*stack_b = (*stack_b)->first;
	}
	//ft_printf("hhfinished_\n");
}