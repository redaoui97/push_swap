/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:23 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 15:54:11 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//Swaps the first 2 elements at the top of the stack b

void	sb(node **stack_b)
{
	int	permu;

	if (list_size(*stack_b) < 2)
		return;
	permu = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = permu;
	ft_printf("sb\n");
}
