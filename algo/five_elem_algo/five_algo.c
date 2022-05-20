/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:28:19 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 05:48:42 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	five_algo(node **stack_a, node **stack_b)
{
	set_min_first (&*stack_a);
	pb (&*stack_a, &*stack_b);
	set_min_first (&*stack_a);
	pb (&*stack_a, &*stack_b);
	three_algo (&*stack_a);
	if ((*stack_b)->value > (*stack_b)->next->value)
	{
		pa(&*stack_a, &*stack_b);
		pa(&*stack_a, &*stack_b);
	}
	else
	{
		rb(&*stack_b);
		pa(&*stack_a, &*stack_b);
		pa(&*stack_a, &*stack_b);
	}
	*stack_a = (*stack_a)->first;
}
