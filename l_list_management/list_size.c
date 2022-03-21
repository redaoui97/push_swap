/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:06 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 12:21:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//returns the size of the list

int	list_size(node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}
