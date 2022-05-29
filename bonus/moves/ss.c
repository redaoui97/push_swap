/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:31 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:37:26 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

static void	sa_cpy(t_node **stack_a)
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
}

static void	sb_cpy(t_node **stack_b)
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
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa_cpy(&(*stack_a));
	sb_cpy(&(*stack_b));
}
