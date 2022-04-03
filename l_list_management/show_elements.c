/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:21 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/03 18:16:02 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void show_elements(node *stack_a)
{
	ft_printf("-----------------------------------------------\n");
	ft_printf("|index |   address    |value|lis| bool| moves |\n");
	ft_printf("-----------------------------------------------\n");
	while (stack_a)
	{
		ft_printf("|   %d  |%p|  %d  | %d | %d  |  %d   |\n",stack_a->position, stack_a,stack_a->value,stack_a->lis,stack_a->bool_lis,stack_a->moves_count);
		ft_printf("-----------------------------------------------\n");
		stack_a = stack_a->next;
	}
}
