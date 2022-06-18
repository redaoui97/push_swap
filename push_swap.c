/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:30 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 20:11:27 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

static void	check_duplications(t_node **stack_a)
{
	t_node	*stack1;
	t_node	*stack2;
	int		count;

	stack1 = *stack_a;
	while (stack1)
	{
		stack2 = *stack_a;
		count = 0;
		while (stack2)
		{
			if (stack1->value == stack2->value)
				count++;
			stack2 = stack2->next;
		}
		if (count > 1)
			error(&*stack_a);
		stack1 = stack1->next;
	}
}

static void	check_algo(t_node **stack_a, t_node **stack_b)
{
	if (list_size(*stack_a) == 3)
		return (three_algo(&*stack_a));
	if (list_size(*stack_a) == 5)
		return (five_algo(&*stack_a, &*stack_b));
	bool_lis_calculator(&*stack_a);
	send_zeros(&*stack_a, &*stack_b);
	push_values(&*stack_a, &*stack_b);
}

static void	free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		words[i] = NULL;
		i++;
	}
	free(words);
	words = NULL;
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**words;
	int		i;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	i = argc - 1;
	while (i)
	{
		parsin(argv[i--], &stack_a);
		stack_a = stack_a->first;
	}
	check_duplications(&stack_a);
	if (!is_sorted(&stack_a))
		check_algo(&stack_a, &stack_b);
	else
		set_min_first(&stack_a);
	clear_elements(&stack_a);
	clear_elements(&stack_b);
	return (0);
}
