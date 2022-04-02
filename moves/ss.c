/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:31 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 15:59:33 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	sa_cpy(node **stack_a)
{
	int	permu;

	if (list_size(*stack_a) < 2)
		return;
	permu = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = permu;
}

static void	sb_cpy(node **stack_b)
{
	int	permu;

	if (list_size(*stack_b) < 2)
		return;
	permu = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = permu;
}

void	ss(node **stack_a, node **stack_b)
{
	sa_cpy(&(*stack_a));
	sb_cpy(&(*stack_b));
	ft_printf("ss\n");
}
