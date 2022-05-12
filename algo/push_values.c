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
		//ft_printf("gnn:value:%d:%d:%d\n",value, (*stack_a)->value, next->value);
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

static void rotate(node **stack_a, node **stack_b, node *next, node *ptr_b, int side, int rotations)
{
	int i;

	i = 0;
	/*if (side)
	{
		while (i++ < rotations)
			rrr(&*stack_a, &*stack_b);
	}
	else
	{
		while (i++ < rotations)
			rr(&*stack_a, &*stack_b);
	}*/

	while ((*stack_a)->first->value != next->value && (*stack_b)->first->value != ptr_b->value)
	{
		if (!side)
		{
			rr(&*stack_a, &*stack_b);
		}
		else
		{
			rrr(&*stack_a, &*stack_b);
		}
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
	int	i;

	i = 0;
	while (i <= min)
	{
		//here------------------------------
		if(side_a)
			rrr(&*stack_a, &*stack_b);
		else
			rr(&*stack_a, &*stack_b);
		i++;
	}
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
	//this should be deleted
	get_element_top_a(&*stack_a, next->value, side);
	get_element_top_b(&((*stack_b)->first), (*stack_b)->value, side);
}

void push_values(node **stack_a, node **stack_b) 
{
	int	side_a;
	int side_b;
	int moves_a;
	int moves_b;
	node	*next;
	node *next2;
	node *ptr_b;
	int i;
	int size;

	i = 0;
	while (*stack_b)
	{
		calculate_moves(&*stack_a, &*stack_b);
		show_elements(*stack_a);
		show_elements(*stack_b);
		ptr_b = get_min_moves(*stack_b);
		next = get_next_number(ptr_b->value, &*stack_a);
		check_moves(ptr_b, &side_b, &moves_b, (*stack_b)->first);
		check_moves(next, &side_a, &moves_a, *stack_a);

		
		
		//everything is good now, I just need to optimize more and set the parsing 
		ft_printf("stack_a:%d|stack_b:%d\n",next->value, ptr_b->value);
		ft_printf("side_a:%d|move_a:%d||side_b:%d|move_b:%d\n",side_a,moves_a,side_b,moves_b);

		rotate(&*stack_a, &*stack_b, next, ptr_b, side_a, min_comp(moves_a, moves_b));
		rotate_moves(&*stack_a, &*stack_b, side_a, min_comp(moves_a, moves_b), moves_a, moves_b);
		//second condition is working good, first one not really
		/*if (side_a <= 0)//normally it's side_a = side_b
		{
			ft_printf("side_a:%d|move_a:%d||side_b:%d|move_b:%d\n",side_a,moves_a,side_b,moves_b);
			rotate(&*stack_a, &*stack_b, side_a, min_comp(moves_a, moves_b));
			rotate_moves(&*stack_a, &*stack_b, side_a, min_comp(moves_a, moves_b), moves_a, moves_b);
		}
		else
		{
			ft_printf("move2\n");
			get_element_top_a(&*stack_a, next->value, side_a);
			get_element_top_b(&(*stack_b), ptr_b->value, side_b);
		}*/
		if(list_size(*stack_b) > 1)
			next2 = (*stack_b)->first->next;
		else
			break ;
		pa(&*stack_a, &*stack_b);
		*stack_b = next2;
	}
	next = get_next_number((*stack_b)->value, &*stack_a);
	get_element_top_a(&*stack_a, next->value, side_a);
	pa(&*stack_a, &*stack_b);
	set_min_first(&*stack_a);
	*stack_a = (*stack_a)->first;
}