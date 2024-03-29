/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_zeros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:03:24 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/03 16:14:22 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	send_zeros(t_node **stack_a, t_node **stack_b)
{
	t_node	*ptr_start;
	int		size;
	int		i;

	i = 0;
	size = list_size(*stack_a);
	ptr_start = *stack_a;
	while (i < size)
	{
		if ((*stack_a)->bool_lis == 1)
			ra(&*stack_a);
		else
		{
			pb(&*stack_a, &*stack_b);
		}
		i++;
	}
}
