/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:16 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 12:21:18 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//removes a node from the list

void	remove_element(node **stack_a)
{
	node	*ptr;
	node	*ptr_next;

	ptr = *stack_a;
	ptr_next = (*stack_a)->next;
	if (list_size(*stack_a) == 1)
	{
		free(*stack_a);
		*stack_a = NULL;
		return ;
	}
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
	while (*stack_a)
	{
		(*stack_a)->position--;
		(*stack_a)->first = ptr_next;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = ptr_next;
	free (ptr);
}

/*int main(void)
{
	node *stack_a;

	stack_a = NULL;
	add_element(&stack_a, 5);
	add_element(&stack_a, 4);
	add_element(&stack_a, 3);
	add_element(&stack_a, 2);
	add_element(&stack_a, 1);
	add_element(&stack_a, 0);
	show_elements(stack_a);
	remove_element(&stack_a);
	remove_element(&stack_a);
	remove_element(&stack_a);
	remove_element(&stack_a);
	remove_element(&stack_a);
	remove_element(&stack_a);
	printf("---------------------\n");
	show_elements(stack_a);
	return 0;
}*/
