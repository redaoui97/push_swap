/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:19:58 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:37:03 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sa(t_node **stack_a)
{
	int	permu;
	int	bool_permut;

	if (list_size(*stack_a) < 2)
		return ;
	permu = (*stack_a)->value;
	bool_permut = (*stack_a)->bool_lis;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->bool_lis = (*stack_a)->next->bool_lis;
	(*stack_a)->next->value = permu;
	(*stack_a)->next->bool_lis = bool_permut;
	ft_printf("sa\n");
}
