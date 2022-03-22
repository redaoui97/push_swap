/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:30 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/21 12:21:31 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int main(void)
{
	node *stack_a;
	node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	add_element(&stack_a, 4);
	add_element(&stack_b, 4);
	
	add_element(&stack_a, 3);
	add_element(&stack_b, 3);

	add_element(&stack_a, 2);
	add_element(&stack_b, 2);

	add_element(&stack_a, 1);
	add_element(&stack_b, 1);

	add_element(&stack_a, 0);
	add_element(&stack_b, 0);
	
	rrr(&stack_a, &stack_b);
	show_elements(stack_a);
	ft_printf("--------------------\n");
	show_elements(stack_b);
	clear_elements(&stack_a);
	clear_elements(&stack_b);
	return 0;
}
