/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:31:58 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/12 15:20:12 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int  get_min(node *stack_a)
{
    int min;

    min = stack_a->value;
    while (stack_a)
    {
        if (stack_a->value < min)
            min = stack_a->value;
        stack_a = stack_a->next;
    }
    return (min);
}

static int  get_min_index(node *stack_a)
{
    int min;
    int index;
    int i;

    min = stack_a->value;
    i = 0;
    while (stack_a)
    {
        if (stack_a->value < min)
        {
            min = stack_a->value;
            index = i;
        }
        stack_a = stack_a->next;
        i++;
    }
    return (index);
}

void set_min_first(node **stack_a)
{
	node    *first_node;
    int     min;
    int     position;

    first_node = *stack_a;
    min = get_min(*stack_a);
    position = get_min_index(*stack_a);
    if ((position / list_size(*stack_a)) >= 0.5)
    {
        while (position--)
            ra(&*stack_a);
    }
    else
    {
        while((*stack_a)->value != min)
        {
            rra(&*stack_a);
			position--;
        }
    }
    *stack_a = first_node;
}

