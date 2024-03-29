/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:27:20 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 17:18:08 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	first_calculation(t_node **stack_b)
{
	int		count;
	t_node	*first_ptr;
	int		pos;

	count = 1;
	first_ptr = *stack_b;
	if (list_size(first_ptr) == 1)
		(*stack_b)->moves_count = 1;
	while (*stack_b)
	{
		if ((*stack_b)->position <= (list_size(first_ptr) / 2))
			(*stack_b)->moves_count = (*stack_b)->position;
		else
		{
			pos = (*stack_b)->position;
			(*stack_b)->moves_count = list_size(first_ptr) - pos;
		}
		*stack_b = (*stack_b)->next;
	}
	*stack_b = first_ptr;
}
