/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:42:20 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 13:27:33 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//rra (reverse rotate a): Shifts down all elements of stack a by 1. The last element becomes the first one

void	rra(node **stack_a)
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
	ft_printf("rra\n");
}
