/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:29:27 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 05:51:47 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	three_algo(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->last->value;
	if (a < c && c < b)
		return (ra(&*stack), sa(&*stack), rra(&*stack));
	if (b < a && a < c)
		return (sa(&*stack));
	if (c < b && b < a)
		return (sa(&*stack), ra(&*stack), ra(&*stack));
	set_min_first(&*stack);
}
