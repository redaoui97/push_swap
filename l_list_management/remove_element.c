#include "../header/push_swap.h"

//removes a node from the list

void	remove_element(node **stack_a, int position)
{
	node	*ptr;

	ptr = (*stack_a)->next;
	if (*stack_a == (*stack_a)->first)
	{
		(*stack_a)->next->previous = NULL;
		(*stack_a)->next->first
	}
	if else(*stack_a == (*stack_b)->last)
	{
		
	}
	else
	{
		while ((*stack_a)->position != position)
			*stack_a = (*stack_a)->next;
		(*stack_a)->previous->next = (*stack_a)->next;
		(*stack_a)->next->previous = (*stack_a)->previous;
	}
	free (*stack_a);
}

static void	increment_rest_stack_(node **stack_a)
{
	node	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		ptr->position--;
		ptr = ptr->next;
	}
}
