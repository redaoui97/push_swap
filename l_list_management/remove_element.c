/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:16 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 12:21:18 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//removes a node from the list

void	remove_element(node **stack_a)
{
	node	*ptr;
	node	*ptr_next;

	ptr = *stack_a;
	ptr_next = (*stack_a)->next;
	if (list_size(*stack_a) == 1)
	{
		free(*stack_a);
		*stack_a = NULL;
		return ;
	}
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
	while (*stack_a)
	{
		(*stack_a)->position--;
		(*stack_a)->first = ptr_next;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = ptr_next;
	free (ptr);
}
