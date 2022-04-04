/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:40:46 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/04 15:19:35 by rnabil           ###   ########.fr       */
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
	first_ptr = *stack_b;
	while (count < (size / 2))
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

int void	calc_moves_a(int	value, node **stack_a)
{
		
}

static void	second_calculation(node **stack_b, node **stack_b)
{
	int		count;
	int		size;
	node	*first_ptr;
	node	*first_ptr_a;

	count = 0;
	size = list_size(*stack_b);
	first_ptr = *stack_b;
	while (*stack_b)
	{
		(*stack_b)->moves_count += calc_moves_a((*stack_b)->value, first_ptr_a);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = first_ptr;
}

void	calculate_moves(node **stack_a, node **stack_b)
{
	first_calculation(&*stack_b);
	second_calculation(&*stack_a, &*stack_b);
}
