/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:40:46 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/03 18:20:56 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	first_calculation(node **stack_b)
{
	int		count;
	int		size;
	node	*first_ptr;

	count = 0;
	size = list_size(*stack_b);
	ft_printf("%d\n",size);
	first_ptr = *stack_b;
	while (count <= (size / 2))
	{
		(*stack_b)->moves_count = count++;
		*stack_b = (*stack_b)->next;
	}
	if (!(size % 2))
	{
		(*stack_b)->moves_count = count--;
		*stack_b = (*stack_b)->next;
	}
	while (count > 0)
	{
		(*stack_b)->moves_count = count--;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = first_ptr;
}

void	calculate_moves(node **stack_b)
{
	first_calculation(&*stack_b);
}
