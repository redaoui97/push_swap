/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:19:58 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 18:03:50 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of the stack a

void	sa(node **stack_a)
{
	int	permu;

	if (list_size(*stack_a) < 2)
		return;
	permu = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = permu;
}
