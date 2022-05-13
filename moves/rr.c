/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:10:50 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 16:45:14 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"


static void	ra_cpy(node **stack_a)
{
	int		permut;
	int		bool_permut;
	node	*ptr;

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
}

static void	rb_cpy(node **stack_b)
{
	int		permut;
	int		bool_permut;
	node	*ptr;

	if (!stack_b)
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
}

void	rr(node **stack_a, node **stack_b)
{
	ra_cpy(&(*stack_a));
	rb_cpy(&(*stack_b));
	ft_printf("rr\n");
}
