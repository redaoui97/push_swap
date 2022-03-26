/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:21 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/26 20:08:48 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void show_elements(node *stack_a)
{
	while (stack_a)
	{
		ft_printf("%p:%d:%d-lis:%d\n",stack_a,stack_a->position,stack_a->value,stack_a->lis);
		stack_a = stack_a->next;
	}
}
