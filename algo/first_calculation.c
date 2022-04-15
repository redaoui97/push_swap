/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:27:20 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/15 09:29:58 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void first_calculation(node **stack_b)
{
    int     count;
    node    *first_ptr;

    count = 1;
    first_ptr = *stack_b;
    if (list_size(first_ptr) == 1)
        (*stack_b)->moves_count = 1;
    while (count <= (list_size(first_ptr) / 2))
    {
        (*stack_b)->moves_count = count++;
        *stack_b = (*stack_b)->next;
    }
    if ((list_size(first_ptr) % 2) == 1 && list_size(first_ptr) > 2)
    {
        (*stack_b)->moves_count = count;
        *stack_b = (*stack_b)->next;
    }
    while (count > 0 && *stack_b)
    {
        (*stack_b)->moves_count = count--;
        *stack_b = (*stack_b)->next;
    }
    *stack_b = first_ptr;
}
