/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:57 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:36:53 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	rra_cpy(node **stack_a)
{
	int		permut;
	int		bool_permut;
	node	*ptr;

	if (!*stack_a)
		return ;
	ptr = *stack_a;
	permut = (*stack_a)->last->value;
	bool_permut = (*stack_a)->last->bool_lis;
	*stack_a = (*stack_a)->last;
	while (*stack_a != (*stack_a)->first)
	{
		(*stack_a)->value = (*stack_a)->previous->value;
		(*stack_a)->bool_lis = (*stack_a)->previous->bool_lis;
		*stack_a = (*stack_a)->previous;
	}
	*stack_a = ptr;
	(*stack_a)->value = permut;
	(*stack_a)->bool_lis = bool_permut;
}

static void	rrb_cpy(node **stack_b)
{
	int		permut;
	int		bool_permut;
	node	*ptr;

	ptr = *stack_b;
	permut = (*stack_b)->last->value;
	bool_permut = (*stack_b)->last->bool_lis;
	*stack_b = (*stack_b)->last;
	while (*stack_b != (*stack_b)->first)
	{
		(*stack_b)->value = (*stack_b)->previous->value;
		(*stack_b)->bool_lis = (*stack_b)->previous->bool_lis;
		*stack_b = (*stack_b)->previous;
	}
	*stack_b = ptr;
	(*stack_b)->value = permut;
	(*stack_b)->bool_lis = bool_permut;
}

void	rrr(node **stack_a, node **stack_b)
{
	rra_cpy(&*stack_a);
	rrb_cpy(&*stack_b);
	ft_printf("rrr\n");
}
