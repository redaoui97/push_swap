/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:57:39 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 17:59:08 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//rrb (reverse rotate b): Shifts down all elements of stack b by 1. The last element becomes the first one

void	rrb(node **stack_b)
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
