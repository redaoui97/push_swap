/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:31:54 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/09 22:15:29 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
}

void second_calculation(node *stack_a, node **stack_b)
{
	node	*first_node;

	first_node = *stack_b;
	while (*stack_b)
	{
		//WAAAAAAAAAAAAAAA ADD += 
		

		if (calculate_superior(stack_a,(*stack_b)->value) > calculate_inferior(stack_a,(*stack_b)->value))
			(*stack_b)->moves_count = calculate_inferior(stack_a, (*stack_b)->value);
		else
			(*stack_b)->moves_count = calculate_superior(stack_a, (*stack_b)->value);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = first_node;
}
