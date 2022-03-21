/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:05:25 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 13:52:45 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//ra (rotate a): shifts up all elements of stack a by 1. The first element becomes the last one

void	ra(node **stack_a)
{
	int		permut;
	node	*ptr;
	
	ptr = *stack_a;	
	permut = (*stack_a)->value;
	while (*stack_a)
	{
		if (*stack_a == (*stack_a)->last)
		{
			(*stack_a)->value = permut;
			break ;
		}
		(*stack_a)->value = (*stack_a)->next->value;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = ptr;
}
