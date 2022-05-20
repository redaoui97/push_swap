/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:52 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:21:13 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	add_element(t_node **stack_a, int value)
{
	t_node	*new;

	new = new_node(value);
	new->previous = NULL;
	new->first = new;
	if (!(*stack_a))
	{
		new->next = NULL;
		new->last = new;
		*stack_a = new;
		return ;
	}
	new->next = *stack_a;
	new->last = (*stack_a)->last;
	(*stack_a)->previous = new;
	while (*stack_a)
	{
		(*stack_a)->position++;
		(*stack_a)->first = new;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = new;
}
