/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:33:15 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 17:44:14 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	min_comp(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static void	rotate(node **s, node **stack_b, int next, int side)
{
	int	ptr_b;

	ptr_b = get_min_moves(*stack_b)->value;
	while (((*s)->first->value != next) && ((*stack_b)->first->value != ptr_b))
	{
		if (!side)
			rr(&*s, &*stack_b);
		else
			rrr(&*s, &*stack_b);
	}
	while ((*s)->first->value != next)
	{
		if (!side)
			ra(&*s);
		else
			rra(&*s);
	}
	while ((*stack_b)->first->value != ptr_b)
	{
		if (!side)
			rb(&*stack_b);
		else
			rrb(&*stack_b);
	}
}

static void	check_moves(node *nodec, int *side, node *stack)
{
	if (((float)(nodec->position) / list_size(stack->first)) > 0.5)
		*side = 1;
	else
		*side = 0;
}

void	push_values(node **stack_a, node **stack_b)
{
	int		side_a;
	int		side_b;
	node	*next;
	node	*next2;
	node	*ptr_b;

	while (*stack_b)
	{
		calculate_moves(&*stack_a, &*stack_b);
		ptr_b = get_min_moves(*stack_b);
		next = get_next_number(ptr_b->value, &*stack_a);
		check_moves(ptr_b, &side_b, (*stack_b)->first);
		check_moves(next, &side_a, *stack_a);
		if (side_a == side_b)
			rotate(&*stack_a, &*stack_b, next->value, side_a);
		else
		{
			get_element_top_a(&*stack_a, next->value, side_a);
			get_element_top_b(&(*stack_b), ptr_b->value, side_b);
		}
		if (list_size(*stack_b) > 1)
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
