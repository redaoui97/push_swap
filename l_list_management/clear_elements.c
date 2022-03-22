/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:57 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 12:20:58 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//frees all the elements of the stack

void	clear_elements(node **stack_a)
{
	node *perm;
	
	while(*stack_a)
	{
		ft_printf("element at position: %d cleared\n",(*stack_a)->position);
		perm = (*stack_a)->next;
		free (*stack_a);
		*stack_a = perm;
	}
}
