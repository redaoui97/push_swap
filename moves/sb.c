/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:23 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:37:39 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sb(t_node **stack_b)
{
	int	permu;
	int	bool_permut;

	if (list_size(*stack_b) < 2)
		return ;
	permu = (*stack_b)->value;
	bool_permut = (*stack_b)->bool_lis;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->bool_lis = (*stack_b)->next->bool_lis;
	(*stack_b)->next->value = permu;
	(*stack_b)->next->bool_lis = bool_permut;
	ft_printf("sb\n");
}
