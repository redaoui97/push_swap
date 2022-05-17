/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:18:54 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/14 18:19:58 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_sorted(node **stack)
{
    node    *previous;
    node    *first_node;

    first_node = *stack;
    if (list_size(*stack) < 3)
        return (1);
    while (*stack)
    {
        if ((*stack)->position == 0)
            previous = *stack;
        else
            previous = (*stack)->previous;
        if ((*stack)->value < previous->value)
        {
            ft_printf("%d->%d",previous->value, (*stack)->value);
            *stack = first_node;
            return (0);
        }
        *stack = (*stack)->next;
    }
    *stack = first_node;
    return (1);
}
