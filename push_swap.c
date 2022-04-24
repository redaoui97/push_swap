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

int main(int argc, char *argv[])
{
	node 	*stack_a;
	node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
		return (0);//IDK there was a condition like this when I used to play with arg
	i = 1;
	while (i < argc)
	{
		add_element(&stack_a, ft_atoi(argv[i++]));
	}

	ft_printf("----------------PUSH_SWAP--------------------\n");
	calculate_lis(&stack_a);	
	bool_lis_calculator(&stack_a);
	show_elements(stack_a);
	send_zeros(&stack_a,&stack_b);
	calculate_moves(&stack_a, &stack_b);
//	push_values(&stack_a, &stack_b);

	show_elements(stack_a);
	show_elements(stack_b);

	clear_elements(&stack_a);
	clear_elements(&stack_b);
	return 0;
}
