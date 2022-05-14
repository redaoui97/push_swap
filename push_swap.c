/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:30 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/15 12:30:33 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int main(int argc, char **argv)
{
	node *stack_a;
	node *stack_b;
	int i;

	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
		return (0);
	i = argc - 1;
	while (i) 
	{
		parsin(argv[i], &stack_a);
		add_element(&stack_a, ft_atoi(argv[i--]));
	}

	/*if (list_size(stack_a) == 3)
		three_algo(&stack_a);
	if (list_size(stack_a) == 5)
		five_algo(&stack_a);*/
	bool_lis_calculator(&stack_a);
	send_zeros(&stack_a, &stack_b);
	push_values(&stack_a, &stack_b);
	show_elements(stack_a);

	clear_elements(&stack_a);
	clear_elements(&stack_b);
	return 0;
}
