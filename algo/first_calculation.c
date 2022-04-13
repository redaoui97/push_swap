/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:27:20 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/13 17:46:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void first_calculation(node **stack_b)
{
    int     count;
    int     size;
    node    *first_ptr;

    count = 0;
    size = list_size(*stack_b);
    first_ptr = *stack_b;
    if (size == 1)
        (*stack_b)->moves_count = 1;
    while (count < (size / 2))
    {
		ft_printf("%d\n",count);
        (*stack_b)->moves_count = count++;
        *stack_b = (*stack_b)->next;
    }
    if ((size % 2) == 1 && size > 2)
    {
		ft_printf("--------%d\n",count);
        (*stack_b)->moves_count = count;
        *stack_b = (*stack_b)->next;
    }
    while (count > 0 && *stack_b)
    {
		ft_printf("%d\n",count);
        (*stack_b)->moves_count = count--;
        *stack_b = (*stack_b)->next;
    }
    *stack_b = first_ptr;
}
