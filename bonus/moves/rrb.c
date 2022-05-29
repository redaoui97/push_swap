/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:57:39 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:36:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	rrb(t_node **stack_b)
{
	int		permut;
	int		bool_permut;
	t_node	*ptr;

	if (!*stack_b)
		return ;
	ptr = *stack_b;
	permut = (*stack_b)->last->value;
	bool_permut = (*stack_b)->last->bool_lis;
	*stack_b = (*stack_b)->last;
	while (*stack_b != (*stack_b)->first)
	{
		(*stack_b)->value = (*stack_b)->previous->value;
		(*stack_b)->bool_lis = (*stack_b)->previous->bool_lis;
		*stack_b = (*stack_b)->previous;
	}
	*stack_b = ptr;
	(*stack_b)->value = permut;
	(*stack_b)->bool_lis = bool_permut;
}
