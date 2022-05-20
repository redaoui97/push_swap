/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:35:44 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 16:37:54 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	rb(t_node **stack_b)
{
	int		permut;
	int		bool_permut;
	t_node	*ptr;

	if (!*stack_b)
		return ;
	ptr = *stack_b;
	permut = (*stack_b)->value;
	bool_permut = (*stack_b)->bool_lis;
	while (*stack_b)
	{
		if (*stack_b == (*stack_b)->last)
		{
			(*stack_b)->value = permut;
			(*stack_b)->bool_lis = bool_permut;
			break ;
		}
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->bool_lis = (*stack_b)->next->bool_lis;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = ptr;
	ft_printf("rb\n");
}
