/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:47:22 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 06:18:25 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	sub_function(node **stack, int *value, int *count, int *i)
{
	if ((*stack)->value > *value)
	{
		(*count)++;
		*value = (*stack)->value;
	}
	if ((*stack)->next == NULL)
		*stack = (*stack)->first;
	else
		*stack = (*stack)->next;
	(*i)++;
}

void	calculate_lis(node **stack_a)
{
	node	*ptr_first;
	node	*ptr_a;
	int		i;
	int		count;
	int		value;

	i = 0;
	ptr_first = *stack_a;
	ptr_a = *stack_a;
	while (ptr_a)
	{
		i = 0;
		count = 1;
		*stack_a = ptr_a;
		value = ptr_a->value;
		(*stack_a)->lis = 0;
		while (i < list_size(ptr_first))
			sub_function(&*stack_a, &value, &count, &i);
		ptr_a->lis = count;
		ptr_a = ptr_a->next;
	}
	*stack_a = ptr_first;
}
