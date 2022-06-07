/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_values_src.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:11:00 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/30 13:14:50 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	min_comp(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	rotate(t_node **s, t_node **stack_b, int next, int side)
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

void	check_moves(t_node *nodec, int *side, t_node *stack)
{
	if (((float)(nodec->position) / list_size(stack->first)) > 0.5)
		*side = 1;
	else
		*side = 0;
}
