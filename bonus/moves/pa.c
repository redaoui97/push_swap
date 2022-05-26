/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:06 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 13:25:11 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	add_element(&*stack_a, (*stack_b)->value);
	remove_element(&*stack_b);
	ft_printf("pa\n");
}