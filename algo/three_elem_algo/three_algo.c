/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:29:27 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/14 17:29:54 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int  check_sequence(node *stack, int a, int b, int c)
{
    if (stack->value == a && stack->next->value == b && 
    stack->next->next->value ==c)
        return (1);
    return (0);
}
void	three_algo(node **stack)
{
    if (check_sequence(*stack, 1, 3, 2))
    {
        ra(&stack);
        sa(&stack);
        return ;
    }
    if (check_sequence(*stack, 2, 1, 3))
    {
        sa(&stack);
        return ;
    }
    if (check_sequence(*stack, 3, 2, 1))
    {
        sa(&stack);
        ra(&stack);
        return ;
    }
}
