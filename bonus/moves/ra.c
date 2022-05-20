/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:05:25 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/15 12:39:43 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	ra(t_node **stack_a)
{
	int		permut;
	int		bool_permut;
	t_node	*ptr;

	if (!*stack_a)
		return ;
	ptr = *stack_a;
	permut = (*stack_a)->value;
	bool_permut = (*stack_a)->bool_lis;
	while (*stack_a)
	{
		if (*stack_a == (*stack_a)->last)
		{
			(*stack_a)->value = permut;
			(*stack_a)->bool_lis = bool_permut;
			break ;
		}
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->bool_lis = (*stack_a)->next->bool_lis;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = ptr;
	ft_printf("ra\n");
}
