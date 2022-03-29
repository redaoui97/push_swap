/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:47:22 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/29 18:08:33 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void  calculate_lis(node **stack_a)
{
    node    *ptr_first;
    node    *ptr_a;
    int     i;
    int     count;
    int     value;

    i = 0;
    ptr_first = *stack_a;//can be edit at the end and replace with stack->first instead of doing all this shit
    ptr_a = *stack_a;
    while (ptr_a)
    {
        i = 0;
        count = 1;
        *stack_a = ptr_a;
        value = ptr_a->value;
        (*stack_a)->lis = 0;  //check if I have added it to the argument in header first, also I think I can delete this line
        while (i < list_size(ptr_first))
        {
            if((*stack_a)->value > value)
            {
                count++;
                value = (*stack_a)->value;
            }
            //------------getting to the next element
            if((*stack_a)->next == NULL)
                *stack_a = (*stack_a)->first;
            else
                *stack_a = (*stack_a)->next;
            i++;
        }
        ptr_a->lis = count;
        ptr_a = ptr_a->next;
    }
    *stack_a = ptr_first;
}

/*void	calculate_lis(node **stack_a)
{
	node	*ptr_first;
	node	*ptr_a;
	int		i;
	int		count;
	int		value;

	i = 0;
	ptr_first = *stack_a;//can be edit at the end and replace with stack->first instead of doing all this shit 
	ptr_a = *stack_a;
	while (ptr_a)
	{
		i = 0;
		count = 1;
		*stack_a = ptr_a;
		value = ptr_a->value;
		(*stack_a)->lis = 0;  //check if I have added it to the argument in header first, also I think I can delete this line
		while (i < list_size(ptr_first))
		{
			if ((*stack_a)->value < value && (*stack_a)->value > ptr_a->value)
				count = 1;
			else if((*stack_a)->value > value)
			{
				count++;
				value = (*stack_a)->value;
			}
			//------------getting to the next element
			if((*stack_a)->next == NULL)
				*stack_a = (*stack_a)->first;
			else
				*stack_a = (*stack_a)->next;
			i++;
		}
		ptr_a->lis = count;
		ptr_a = ptr_a->next;
	}
	*stack_a = ptr_first;
}*/
