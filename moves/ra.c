/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:05:25 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 12:19:41 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ra(node **stack_a)
{
	int		permut;
	node	*ptr;
	
	permut = str->value;
	while (ptr)
	{
		if (ptr == ptr->last)
		{
			ptr->value = permut;
			break ;
		}
		ptr->value = ptr->next->value;
		ptr = ptr->next;
	}
}
