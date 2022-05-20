/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:42:20 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 17:48:06 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	rra(t_node **stack_a)
{
	int		permut;
	int		bool_permut;
	t_node	*ptr;

	if (!*stack_a)
		return ;
	ptr = *stack_a;
	permut = (*stack_a)->last->value;
	bool_permut = (*stack_a)->last->bool_lis;
	*stack_a = (*stack_a)->last;
	while (*stack_a != (*stack_a)->first)
	{
		(*stack_a)->value = (*stack_a)->previous->value;
		(*stack_a)->bool_lis = (*stack_a)->previous->bool_lis;
		*stack_a = (*stack_a)->previous;
	}
	*stack_a = ptr;
	(*stack_a)->value = permut;
	(*stack_a)->bool_lis = bool_permut;
	ft_printf("rra\n");
}
