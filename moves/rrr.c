/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:57 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 13:28:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//rrr : rra and rrb at the same time

void	rrr(node **stack_a, node **stack_b)
{
	rra(&*stack_a);
	rrb(&*stack_b);
	ft_printf("rrr\n");
}
