/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:33:15 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/30 13:10:51 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static	void	helper(t_node **stack_a, t_node **stack_b, t_node **next2)
{
	*next2 = (*stack_b)->first->next;
	pa(&*stack_a, &*stack_b);
	*stack_b = *next2;
}

static void	helper2(t_node **stack_a, t_node **stack_b, t_node **next, int s)
{
	*next = get_next_number((*stack_b)->value, &*stack_a);
	get_element_top_a(&*stack_a, (*next)->value, s);
	pa(&*stack_a, &*stack_b);
	set_min_first(&*stack_a);
	*stack_a = (*stack_a)->first;
}

void	push_values(t_node **stack_a, t_node **stack_b)
{
	int		side_a;
	int		side_b;
	t_node	*next;
	t_node	*next2;
	t_node	*ptr_b;

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
		if (!(list_size(*stack_b) > 1))
			break ;
		helper(&*stack_a, &*stack_b, &next2);
	}
	helper2(&*stack_a, &*stack_b, &next, side_a);
}
