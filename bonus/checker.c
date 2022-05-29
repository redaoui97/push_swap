/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:35:56 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 23:36:36 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/checker.h"

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

static void error1(t_node **stack_a, t_node **stack_b)
{
    ft_printf("Error\n");
    clear_elements(&*stack_a);
    clear_elements(&*stack_b);
    exit(EXIT_FAILURE);
}

void parsing(char *line, t_node **stack_a, t_node **stack_b)
{
    if (ft_strcmp(line, "pa\n"))
        return (pa(&*stack_a, &*stack_b));
    if (ft_strcmp(line, "pb\n"))
        return (pb(&*stack_a, &*stack_b));
    if (ft_strcmp(line, "ra\n"))
        return (ra(&*stack_a));
    if (ft_strcmp(line, "rb\n"))
        return (rb(&*stack_b));
    if (ft_strcmp(line, "rr\n"))
        return (rr(&*stack_a, &*stack_b));
    if (ft_strcmp(line, "rra\n"))
        return (rra(&*stack_a));
    if (ft_strcmp(line, "rrb\n"))
        return (rrb(&*stack_b));
    if (ft_strcmp(line, "rrr\n"))
        return (rrr(&*stack_a, &*stack_b));
    if (ft_strcmp(line, "sa\n"))
        return (sa(&*stack_a));
    if (ft_strcmp(line, "sb\n"))
        return (sb(&*stack_b));
    if (ft_strcmp(line, "ss\n"))
        return (ss(&*stack_a, &*stack_b));
    error1(&*stack_a, &*stack_b);
}

int main(int argc, char **argv)
{
    t_node *stack_a;
    t_node *stack_b;

    char *line;
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
        stack_a = stack_a->first;
    }
    check_duplications(&stack_a);
    line = get_next_line(0);
    while (line)
    {
        ft_printf("%s",line);
        parsing(line, &stack_a, &stack_b);
        line = get_next_line(0);
    }
    if (is_sorted(&stack_a))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    clear_elements(&stack_a);
    clear_elements(&stack_b);
}