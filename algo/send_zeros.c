/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_zeros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:03:24 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 16:23:12 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	send_zeros(node **stack_a, node **stack_b)
{
	node	*ptr_start;
	int		i;

	i = 0;
	ptr_start = *stack_a;
	while (i < list_size(*stack_a))
	{
		if ((*stack_a)->bool_lis == 1)
		{
			ra(&*stack_a);
			ft_printf("%d\n",(*stack_a)->bool_lis);
		}
		else
		{
			pb(&*stack_a, &*stack_b);
		}
		i++;
	}	
}
