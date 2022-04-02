/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:57 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 15:52:40 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//rrr : rra and rrb at the same time

static void	rra_cpy(node **stack_a)
{
	int		permut;
	int		permut2;
	node	*ptr;

	ptr = *stack_a;
	permut = (*stack_a)->last->value;
	*stack_a = (*stack_a)->last;
	while (*stack_a != (*stack_a)->first)
	{
		(*stack_a)->value = (*stack_a)->previous->value;
		*stack_a = (*stack_a)->previous;
	}
	*stack_a = ptr;
	(*stack_a)->value = permut;
}

static void	rrb_cpy(node **stack_b)
{
	int		permut;
	int		permut2;
	node	*ptr;

	ptr = *stack_b;
	permut = (*stack_b)->last->value;
	*stack_b = (*stack_b)->last;
	while (*stack_b != (*stack_b)->first)
	{
		(*stack_b)->value = (*stack_b)->previous->value;
		*stack_b = (*stack_b)->previous;
	}
	*stack_b = ptr;
	(*stack_b)->value = permut;
}

void	rrr(node **stack_a, node **stack_b)
{
	rra_cpy(&*stack_a);
	rrb_cpy(&*stack_b);
	ft_printf("rrr\n");
}
