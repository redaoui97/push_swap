/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_lis_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:42:15 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/30 12:49:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static node	*get_lis(node *stack_a)
{
	node	*ptr;

	ptr = stack_a;
	while (stack_a)
	{
		if (stack_a->lis >= ptr->lis)
			ptr = stack_a;
		stack_a = stack_a->next;
	}
	ft_printf("\n-----------%d-----------\n",ptr->value);
	return (ptr);
}

void	bool_lis_calculator(node **stack_a)
{
	node	*ptr_first;
	int		i;
	int		value;
	
	i = 0;
	ptr_first = *stack_a;
	*stack_a = get_lis(*stack_a);
	value = (*stack_a)->value;
	while (i < list_size(ptr_first))
	{
		if ((*stack_a)->value >= value)
		{
			value = (*stack_a)->value;
			(*stack_a)->bool_lis++;
		}
		if((*stack_a)->next == NULL)
			*stack_a = (*stack_a)->first;
		else
			*stack_a = (*stack_a)->next;
		i++;
	}
	*stack_a = ptr_first;
}
