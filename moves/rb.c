/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:35:44 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 13:27:08 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//rb (rotate b) : does the same thing as ra : shifts up all elements of stack b by 1. the first element becomes the last one

void	rb(node **stack_b)
{
	int		permut;
	node	*ptr;

	ptr = *stack_b;
	permut = (*stack_b)->value;
	while (*stack_b)
	{
		if (*stack_b == (*stack_b)->last)
		{
			(*stack_b)->value = permut;
			break ;
		}
		(*stack_b)->value = (*stack_b)->next->value;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = ptr;
	ft_printf("rb\n");
}
