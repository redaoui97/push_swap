/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:33:15 by rnabil            #+#    #+#             */
/*   Updated: 2022/04/15 13:10:27 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static node	*get_biggest(node **stack_a)
{
	node	*first_node;
	node	*biggest;

	biggest = *stack_a;
	first_node = *stack_a;
	while (*stack_a)
	{
		if((*stack_a)->value > biggest->value)
			biggest = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first_node;
	return (biggest);
}

static node	*get_next_number(int value, node **stack_a)
{
	node	*next;
	node	*first_node;
	int		next_value;

	next = get_biggest(&*stack_a);
	first_node = *stack_a;
	*stack_a = (*stack_a)->first;
	while (*stack_a)
	{
		if ((*stack_a)->value > value && (*stack_a)->value < next->value)
			next = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first_node;
		//ft_printf("gnn:value:%d:%d:%d\n",value, (*stack_a)->value, next->value);
	return (next);
}

static node *get_min_moves(node *stack_b)
{
	node *min;

	min = stack_b;
	while (stack_b)
	{
		if (stack_b->moves_count < min->moves_count)
			min = stack_b;
		stack_b = stack_b->next;
	}
	return (min);
}

static void get_element_top_a(node **stack, int value, int side)
{
	while ((*stack)->first->value != value)
	{
		if (!side)
			ra(&*stack);
		else
			rra(&*stack);
	}
}

static void get_element_top_b(node **stack, int value, int side)
{
	// I neeed to get an element to the top
	while ((*stack)->first->value != value)
	{
		if (!side)
			rb(&*stack);
		else
			rrb(&*stack);
	}
}

static int min_comp(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static void rotate(node **stack_a, node **stack_b, int next, int ptr_b, int side)
{
	while (((*stack_a)->first->value != next) && ((*stack_b)->first->value != ptr_b))
	{
		if (!side)
			rr(&*stack_a, &*stack_b);
		else
			rrr(&*stack_a, &*stack_b);
	}
	while ((*stack_a)->first->value != next)
	{
		if (!side)
			ra(&*stack_a);
		else
			rra(&*stack_a);
	}
	while ((*stack_b)->first->value != ptr_b)
	{
		if (!side)
			rb(&*stack_b);
		else
			rrb(&*stack_b);
	}
}

static void check_moves(node *nodec, int *side, node *stack)
{
	if (((float)(nodec->position) / list_size(stack->first)) > 0.5)
		*side = 1;
	else
		*side = 0;
}

void push_values(node **stack_a, node **stack_b) 
{
	int		side_a;
	int 	side_b;
	node	*next;
	node 	*next2;
	node 	*ptr_b;

	ft_printf("Dkhlna l lis\n");
	while (*stack_b)
	{
		ft_printf("bdina 1\n");
		show_elements(*stack_a);
		ft_printf("bdina 2\n");
		show_elements(*stack_b);
		ft_printf("bdina 3\n");
		calculate_moves(&*stack_a, &*stack_b);
		ptr_b = get_min_moves(*stack_b);
		next = get_next_number(ptr_b->value, &*stack_a);
		check_moves(ptr_b, &side_b, (*stack_b)->first);
		check_moves(next, &side_a, *stack_a);
		if (side_a == side_b)
			rotate(&*stack_a, &*stack_b, next->value, ptr_b->value, side_a);
		else
		{
			get_element_top_a(&*stack_a, next->value, side_a);
			get_element_top_b(&(*stack_b), ptr_b->value, side_b);
		}
		if(list_size(*stack_b) > 1)
			next2 = (*stack_b)->first->next;
		else
			break ;
		pa(&*stack_a, &*stack_b);
		*stack_b = next2;
	}
	next = get_next_number((*stack_b)->value, &*stack_a);
	get_element_top_a(&*stack_a, next->value, side_a);
	pa(&*stack_a, &*stack_b);
	set_min_first(&*stack_a);
	*stack_a = (*stack_a)->first;
}