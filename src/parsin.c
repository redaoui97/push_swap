/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:19:19 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:48:31 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	has_non_num(char *arg)
{
	int	i;

	i = 1;
	if (arg[0] != '-' && arg[0] != '+' && !is_num(arg[0]))
		return (1);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	parsin(char *arg, node **stack_a)
{
	if (has_non_num(arg))
		error(&*stack_a);
	if (non_int(arg))
		error(&*stack_a);
}
