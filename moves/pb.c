/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:12 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/02 13:24:23 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	add_element(&*stack_b, (*stack_a)->value);
	remove_element(&*stack_a);
	ft_printf("pb\n");
}
