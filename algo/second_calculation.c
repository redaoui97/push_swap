/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:31:54 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/13 14:56:32 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
//calculate the moves necessary to above the right element in stack_a
static int	calculate_superior (node *stack_a, int value)
{
	int		count;

	count = 1;
	while (stack_a)
	{
		if (value < stack_a->value)
			break ;
		count++;
		stack_a = stack_a->next;
	}
	ft_printf("%d|%d\n",value,count);
	return (count);
}

//calculate the moves necessary to be below the right element in stack_a
static int calculate_inferior (node *stack_a, int value)
{
	 int	count;

	 count = 1;
	 while (stack_a)
	 {
		 if (stack_a->next)
		 	stack_a = stack_a->next;
		 else
			 break ;
	 } 
	 while (stack_a)
	 {
		 if (value > stack_a->value)
			 break ;
		 count++;
		 stack_a = stack_a->previous;
	 }
	 ft_printf("%d|%d\n",value,count);
	 return (count);
}*/

static node	*get_next_number(int value, node **stack_a)
{
	node	*next;
	node	*first_node;
	int		next_value;

	next = *stack_a;
	first_node = *stack_a;
	while (*stack_a)
	{
		if((*stack_a)->next == NULL)
			next_value = first_node->value;
		else
			next_value = (*stack_a)->next->value;
		if ((*stack_a)->value < value && next_value > value)
		{
			next = *stack_a;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first_node;
	return (next);
}

void second_calculation(node **stack_a, node **stack_b)
{
	node	*first_node_a;
	node	*first_node_b;
	node	*next;

	first_node_b = *stack_b;
	first_node_a = *stack_a;
	while (*stack_b)
	{
		//WAAAAAAAAAAAAAAA ADD += 
		
		next = get_next_number((*stack_b)->value, &*stack_a);
		if ((next->position + 1)/list_size(first_node_a) >= 0.5)
		{
			(*stack_b)->moves_count = next->position + 2;
			ft_printf("1\n");
		}
		else
		{
			(*stack_b)->moves_count = list_size(*stack_a) - (next->position);
			ft_printf("2\n");
		}
		*stack_b = (*stack_b)->next;
	}
	*stack_b = first_node_b;
}
