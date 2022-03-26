/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:30 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/26 20:10:12 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int main(int argc, char *argv[])
{
	node 	*stack_a;
	int		i;

	stack_a = NULL;

	if (argc < 2)
		return (0);//IDK there was a condition like this when I used to play with arg
	i = 1;
	while (i < argc)
	{
		add_element(&stack_a, ft_atoi(argv[i++]));
	}
	calculate_lis(&stack_a);	
	ft_printf("--------------------\n");
	show_elements(stack_a);
	clear_elements(&stack_a);
	return 0;
}
