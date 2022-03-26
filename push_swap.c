/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:30 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/26 18:45:34 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int main(int argc, char *argv[])
{
	node *stack_a;
	node *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
		return (0);//IDK there was a condition like this when I used to play with argc
		
	add_element(&stack_a, 4);
		
	ft_printf("--------------------\n");
	show_elements(stack_b);
	clear_elements(&stack_a);
	clear_elements(&stack_b);
	return 0;
}
