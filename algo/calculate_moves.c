/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:40:46 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/15 09:30:02 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	calculate_moves(node **stack_a, node **stack_b)
{
	first_calculation(&*stack_b);
	second_calculation(&*stack_a, &*stack_b);
}
